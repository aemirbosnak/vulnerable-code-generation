//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMPERATURE_SAMPLES 100
#define MAX_TEMPERATURE_CHANGE_RATE 5
#define MIN_TEMPERATURE_CHANGE_RATE -5
#define MAX_TEMPERATURE_ALERT_LEVEL 10
#define MIN_TEMPERATURE_ALERT_LEVEL -10
#define ALERT_INTERVAL_SECONDS 30

typedef struct {
    float temperature;
    time_t timestamp;
} TemperatureSample;

typedef struct {
    int alertLevel;
    time_t lastAlertTime;
} TemperatureAlert;

static TemperatureSample temperatureSamples[MAX_TEMPERATURE_SAMPLES];
static int currentTemperatureSampleIndex = 0;
static TemperatureAlert temperatureAlert = {0, 0};

static float calculateTemperatureChangeRate(int sampleIndex) {
    TemperatureSample currentSample = temperatureSamples[currentTemperatureSampleIndex];
    TemperatureSample previousSample = temperatureSamples[(currentTemperatureSampleIndex - 1) % MAX_TEMPERATURE_SAMPLES];
    float temperatureChange = currentSample.temperature - previousSample.temperature;
    float timeDifferenceSeconds = difftime(currentSample.timestamp, previousSample.timestamp);
    return temperatureChange / timeDifferenceSeconds;
}

static void checkTemperatureAlert(float temperatureChangeRate) {
    if (temperatureChangeRate > MAX_TEMPERATURE_CHANGE_RATE) {
        if (temperatureAlert.alertLevel < MAX_TEMPERATURE_ALERT_LEVEL) {
            temperatureAlert.alertLevel++;
            time_t currentTime = time(NULL);
            if (difftime(currentTime, temperatureAlert.lastAlertTime) > ALERT_INTERVAL_SECONDS) {
                printf("Temperature alert: Temperature is rising too fast (current rate: %.2f°C/s)!\n", temperatureChangeRate);
                temperatureAlert.lastAlertTime = currentTime;
            }
        }
    } else if (temperatureChangeRate < MIN_TEMPERATURE_CHANGE_RATE) {
        if (temperatureAlert.alertLevel > MIN_TEMPERATURE_ALERT_LEVEL) {
            temperatureAlert.alertLevel--;
            time_t currentTime = time(NULL);
            if (difftime(currentTime, temperatureAlert.lastAlertTime) > ALERT_INTERVAL_SECONDS) {
                printf("Temperature alert: Temperature is dropping too fast (current rate: %.2f°C/s)!\n", temperatureChangeRate);
                temperatureAlert.lastAlertTime = currentTime;
            }
        }
    }
}

static void recordTemperatureSample(float temperature) {
    TemperatureSample currentSample;
    currentSample.temperature = temperature;
    currentSample.timestamp = time(NULL);
    temperatureSamples[currentTemperatureSampleIndex] = currentSample;
    currentTemperatureSampleIndex = (currentTemperatureSampleIndex + 1) % MAX_TEMPERATURE_SAMPLES;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_TEMPERATURE_SAMPLES; i++) {
        temperatureSamples[i].temperature = rand() % 50 - 25;
        temperatureSamples[i].timestamp = time(NULL) - i * 60;
    }
    while (TRUE) {
        sleep(1);
        float temperature = rand() % 50 - 25;
        recordTemperatureSample(temperature);
        checkTemperatureAlert(calculateTemperatureChangeRate(currentTemperatureSampleIndex));
    }
    return 0;
}