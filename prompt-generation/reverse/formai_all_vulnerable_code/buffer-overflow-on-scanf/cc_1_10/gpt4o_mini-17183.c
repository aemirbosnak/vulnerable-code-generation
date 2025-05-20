//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_READINGS 100
#define TEMP_THRESHOLD 75.0

typedef struct {
    int id;
    float temperature;
    time_t timestamp;
} TempReading;

void generate_random_reading(TempReading *reading) {
    reading->id = rand() % 1000; // Random ID for the reading
    reading->temperature = (rand() % 10000) / 100.0; // Temperature in range of 0.0 - 100.0
    reading->timestamp = time(NULL);
}

void display_reading(const TempReading *reading) {
    char buffer[26];
    struct tm* tm_info;

    tm_info = localtime(&(reading->timestamp));
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("ID: %d | Temperature: %.2f°C | Time: %s\n", 
            reading->id, reading->temperature, buffer);
}

void check_temperature(const TempReading *reading) {
    if (reading->temperature > TEMP_THRESHOLD) {
        printf("⚠️ Alert! High temperature detected! ID: %d, Temp: %.2f°C\n", 
                reading->id, reading->temperature);
    }
}

void save_reading_to_file(const TempReading *reading, FILE *file) {
    fprintf(file, "%d,%.2f,%ld\n", reading->id, reading->temperature, reading->timestamp);
}

void display_menu() {
    printf("\n--- Temperature Monitor ---\n");
    printf("1. Generate a new temperature reading\n");
    printf("2. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

int main() {
    srand(time(NULL));
    TempReading readings[MAX_READINGS];
    int count = 0;
    int choice;
    FILE *file;
    
    file = fopen("temperature_readings.csv", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    
    fprintf(file, "ID,Temperature,Timestamp\n"); // CSV header
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (count >= MAX_READINGS) {
                    printf("Maximum number of readings reached.\n");
                    break;
                }
                generate_random_reading(&readings[count]);
                display_reading(&readings[count]);
                check_temperature(&readings[count]);
                save_reading_to_file(&readings[count], file);
                count++;
                break;
                
            case 2:
                fclose(file);
                printf("Exiting the program. Goodbye!\n");
                return EXIT_SUCCESS;
                
            default:
                printf("Invalid choice! Please select 1 or 2.\n");
        }
        
        sleep(1); // Introduce a delay for readability
    }
    
    fclose(file);
    return EXIT_SUCCESS;
}