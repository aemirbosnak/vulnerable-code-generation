//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_ACTIVITY_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float steps;
    float distance; // in kilometers
    float calories;
    time_t timestamp;
} FitnessData;

FitnessData tracker[MAX_RECORDS];
int recordCount = 0;

void add_record(char *name, float steps, float distance, float calories) {
    if (recordCount < MAX_RECORDS) {
        strncpy(tracker[recordCount].name, name, MAX_NAME_LENGTH);
        tracker[recordCount].steps = steps;
        tracker[recordCount].distance = distance;
        tracker[recordCount].calories = calories;
        tracker[recordCount].timestamp = time(NULL);
        recordCount++;
    } else {
        printf("Error: Maximum records reached.\n");
    }
}

void display_records() {
    printf("-------- Cyberpunk Fitness Tracker --------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", tracker[i].name);
        printf("Steps: %.2f\n", tracker[i].steps);
        printf("Distance: %.2f km\n", tracker[i].distance);
        printf("Calories Burned: %.2f\n", tracker[i].calories);
        printf("Timestamp: %s", ctime(&tracker[i].timestamp));
        printf("-------------------------------------------\n");
    }
}

void filter_records_by_name(char *name) {
    printf("Filtered Records for %s:\n", name);
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(tracker[i].name, name) == 0) {
            printf("Record %d:\n", i + 1);
            printf("Steps: %.2f\n", tracker[i].steps);
            printf("Distance: %.2f km\n", tracker[i].distance);
            printf("Calories Burned: %.2f\n", tracker[i].calories);
            printf("Timestamp: %s", ctime(&tracker[i].timestamp));
            printf("-------------------------------------------\n");
        }
    }
}

void total_stats() {
    float totalSteps = 0, totalDistance = 0, totalCalories = 0;
    for (int i = 0; i < recordCount; i++) {
        totalSteps += tracker[i].steps;
        totalDistance += tracker[i].distance;
        totalCalories += tracker[i].calories;
    }
    printf("Total Steps: %.2f\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
}

void print_welcome_message() {
    printf("Welcome to the Cyberpunk Fitness Tracker!\n");
    printf("Track your fitness in the neon-lit streets of the dystopian future.\n");
}

int main() {
    char name[MAX_NAME_LENGTH];
    float steps, distance, calories;
    int choice;
    
    print_welcome_message();

    while (1) {
        printf("1. Add Fitness Record\n");
        printf("2. Display All Records\n");
        printf("3. Filter Records by Name\n");
        printf("4. Total Stats\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter steps: ");
                scanf("%f", &steps);
                printf("Enter distance (km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%f", &calories);
                add_record(name, steps, distance, calories);
                printf("Record added successfully!\n");
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Enter name to filter by: ");
                scanf("%s", name);
                filter_records_by_name(name);
                break;
            case 4:
                total_stats();
                break;
            case 5:
                printf("Exiting the Cyberpunk Fitness Tracker. Keep hustling in the neon glow!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}