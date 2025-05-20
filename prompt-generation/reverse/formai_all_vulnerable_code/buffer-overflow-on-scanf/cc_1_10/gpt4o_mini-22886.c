//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char type[20];
    float distance; // in kilometers
    float time; // in minutes
} Activity;

Activity activities[MAX_ENTRIES];
int activityCount = 0;

void logActivity(const char* type, float distance, float time) {
    if (activityCount < MAX_ENTRIES) {
        strcpy(activities[activityCount].type, type);
        activities[activityCount].distance = distance;
        activities[activityCount].time = time;
        activityCount++;
    } else {
        printf("Activity log is full!\n");
    }
}

void displaySummary() {
    printf("\nFitness Activities Summary:\n");
    printf("Type\t\tDistance (km)\tTime (min)\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < activityCount; i++) {
        printf("%s\t\t%.2f\t\t%.2f\n", activities[i].type, activities[i].distance, activities[i].time);
    }
    printf("---------------------------------------------\n");
}

void calculateStats() {
    float totalDistance = 0;
    float totalTime = 0;

    for (int i = 0; i < activityCount; i++) {
        totalDistance += activities[i].distance;
        totalTime += activities[i].time;
    }

    if (totalTime > 0) {
        printf("\nTotal Distance: %.2f km\n", totalDistance);
        printf("Total Time: %.2f min\n", totalTime);
        printf("Average Speed: %.2f km/h\n", (totalDistance / totalTime) * 60);
    } else {
        printf("\nNo activities logged.\n");
    }
}

void shapeShift(char* activityType) {
    float distance, time;

    printf("Enter distance (in km) for %s: ", activityType);
    scanf("%f", &distance);
    printf("Enter time (in minutes) for %s: ", activityType);
    scanf("%f", &time);

    logActivity(activityType, distance, time);
}

int main() {
    int choice;

    do {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Log Running\n");
        printf("2. Log Cycling\n");
        printf("3. Log Walking\n");
        printf("4. Display Summary\n");
        printf("5. Calculate Stats\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shapeShift("Running");
                break;
            case 2:
                shapeShift("Cycling");
                break;
            case 3:
                shapeShift("Walking");
                break;
            case 4:
                displaySummary();
                break;
            case 5:
                calculateStats();
                break;
            case 6:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}