//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DAYS 100

typedef struct {
    char date[11];
    float temperature;
    int isRainy; // 1 for true, 0 for false
} WeatherData;

int readWeatherData(const char *filename, WeatherData data[], int max_days) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && count < max_days) {
        sscanf(line, "%[^,],%f,%d", data[count].date, &data[count].temperature, &data[count].isRainy);
        count++;
    }

    fclose(file);
    return count;
}

void analyzeWeatherData(WeatherData data[], int size, float *avgTemp, int *rainyDaysCount) {
    float totalTemp = 0.0;
    *rainyDaysCount = 0;

    for (int i = 0; i < size; i++) {
        totalTemp += data[i].temperature;
        if (data[i].isRainy) {
            (*rainyDaysCount)++;
        }
    }

    *avgTemp = totalTemp / size;
}

void printAnalysis(float avgTemp, int rainyDaysCount, int totalDays) {
    printf("Total number of days: %d\n", totalDays);
    printf("Average Temperature: %.2f°C\n", avgTemp);
    printf("Number of Rainy Days: %d\n", rainyDaysCount);
}

int main() {
    WeatherData weatherData[MAX_DAYS];
    float avgTemp = 0.0;
    int rainyDaysCount = 0;

    const char *filename = "weather_data.csv";
    int totalDays = readWeatherData(filename, weatherData, MAX_DAYS);

    if (totalDays < 0) {
        return EXIT_FAILURE; // File read error
    }

    analyzeWeatherData(weatherData, totalDays, &avgTemp, &rainyDaysCount);
    printAnalysis(avgTemp, rainyDaysCount, totalDays);

    return EXIT_SUCCESS;
}