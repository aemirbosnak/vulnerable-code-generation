//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WEATHER_DATA_SIZE 100

typedef struct {
    time_t timestamp;
    char condition[10];
    float temperature;
    float humidity;
    float precipitation;
} WeatherData;

void print_weather_data(WeatherData data) {
    time_t now = time(NULL);
    char *condition_str;

    if (data.timestamp == -1) {
        printf("Invalid weather data.\n");
        return;
    }

    strftime(ctime(&data.timestamp), sizeof(ctime(&data.timestamp)), "%Y-%m-%d %H:%M:%S", localtime(&data.timestamp));
    printf("%s - ", ctime(&data.timestamp));

    switch (data.condition[0]) {
        case 'S':
            condition_str = "Sunny";
            break;
        case 'R':
            condition_str = "Rainy";
            break;
        case 'C':
            condition_str = "Cloudy";
            break;
        case 'F':
            condition_str = "Foggy";
            break;
        default:
            condition_str = "Unknown";
            break;
    }

    printf("%s, Temperature: %.1f°C, Humidity: %.1f%%, Precipitation: %.1fmm\n", condition_str, data.temperature, data.humidity, data.precipitation);
}

void load_weather_data(const char *filename, WeatherData data[]) {
    FILE *file = fopen(filename, "r");
    int i = 0;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while (fscanf(file, "%ld %s %f %f %f", &data[i].timestamp, data[i].condition, &data[i].temperature, &data[i].humidity, &data[i].precipitation) != EOF) {
        i++;
    }

    fclose(file);
}

int main() {
    WeatherData data[WEATHER_DATA_SIZE];
    int days = 7;
    char filename[50];

    printf("Enter the location and file name: ");
    scanf("%s", filename);

    load_weather_data(filename, data);

    printf("\nWeather report for the next %d days:\n", days);

    for (int i = 0; i < days && i < WEATHER_DATA_SIZE; i++) {
        if (data[i].timestamp == -1) {
            printf("No weather data available for day %d.\n", i + 1);
            continue;
        }
        print_weather_data(data[i]);
        time_t next_day = data[i].timestamp + 86400; // One day in seconds
        i++;

        if (i < days && data[i].timestamp != -1) {
            data[i - 1].timestamp = -1; // Mark the previous day as invalid
        }
    }

    return 0;
}