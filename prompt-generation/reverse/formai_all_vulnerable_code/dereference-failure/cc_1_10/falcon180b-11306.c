//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DAYS 365
#define MIN_TEMP -30
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND 0
#define MAX_WIND 50
#define MIN_CLOUD 0
#define MAX_CLOUD 100
#define MIN_RAIN 0
#define MAX_RAIN 100

typedef struct {
    int day;
    int temperature;
    int humidity;
    int wind;
    int cloud;
    int rain;
} Weather;

Weather generate_weather() {
    Weather w;
    w.day = rand() % MAX_DAYS;
    w.temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    w.humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    w.wind = rand() % (MAX_WIND - MIN_WIND + 1) + MIN_WIND;
    w.cloud = rand() % (MAX_CLOUD - MIN_CLOUD + 1) + MIN_CLOUD;
    w.rain = rand() % (MAX_RAIN - MIN_RAIN + 1) + MIN_RAIN;
    return w;
}

void print_weather(Weather w) {
    printf("Day %d: Temperature %dC, Humidity %d%, Wind %dkm/h, Cloudiness %d%, Rain %dmm\n",
           w.day, w.temperature, w.humidity, w.wind, w.cloud, w.rain);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int days = rand() % MAX_DAYS + 1;
    Weather *weather = malloc(days * sizeof(Weather));
    printf("Simulating weather for %d days:\n", days);
    for (int i = 0; i < days; i++) {
        weather[i] = generate_weather();
        print_weather(weather[i]);
    }
    free(weather);
    return 0;
}