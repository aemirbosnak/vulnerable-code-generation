//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SAMPLES 100

typedef struct {
    float temperature[MAX_SAMPLES];
    int count;
} TempRecord;

void initialize(TempRecord* record) {
    record->count = 0;
}

void record_temperature(TempRecord* record, float temp) {
    if (record->count < MAX_SAMPLES) {
        record->temperature[record->count] = temp;
        record->count++;
    } else {
        printf("Temperature record is full! Consider resetting.\n");
    }
}

float calculate_average(TempRecord* record) {
    float sum = 0.0;
    for (int i = 0; i < record->count; i++) {
        sum += record->temperature[i];
    }
    return sum / record->count;
}

void display_record(TempRecord* record) {
    printf("\nRecorded Temperatures: \n");
    for (int i = 0; i < record->count; i++) {
        printf("Sample %d: %.2f°C\n", i + 1, record->temperature[i]);
    }
    printf("Total Recorded Samples: %d\n", record->count);
}

void display_average(TempRecord* record) {
    if (record->count > 0) {
        printf("Average Temperature: %.2f°C\n", calculate_average(record));
    } else {
        printf("No temperatures recorded yet!\n");
    }
}

float get_random_temperature() {
    return (float)(rand() % 401 - 200) / 10.0; // Generates a temperature between -20.0°C and 20.0°C
}

void simulate_temperature_monitoring(TempRecord* record) {
    int choice;
    do {
        printf("\n--- Temperature Monitor ---\n");
        printf("Choose an option:\n");
        printf("1. Record Temperature\n");
        printf("2. Display All Recorded Temperatures\n");
        printf("3. Display Average Temperature\n");
        printf("4. Reset Temperature Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                {
                    float new_temp = get_random_temperature();
                    record_temperature(record, new_temp);
                    printf("New Temperature Recorded: %.2f°C\n", new_temp);
                }
                break;

            case 2:
                display_record(record);
                break;

            case 3:
                display_average(record);
                break;

            case 4:
                initialize(record);
                printf("Temperature records have been reset.\n");
                break;

            case 5:
                printf("Exiting the Temperature Monitor. Stay cool!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    TempRecord records;
    initialize(&records);
    
    printf("Welcome to the Temperature Monitoring System!\n");
    printf("Let's keep track of the blazing heats and freezing chills!\n");
    
    simulate_temperature_monitoring(&records);
    
    return 0;
}