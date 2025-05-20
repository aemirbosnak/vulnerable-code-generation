//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories;
} FitnessEntry;

FitnessEntry fitnessLog[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *date, int steps, float distance, int calories) {
    if (entryCount < MAX_ENTRIES) {
        strcpy(fitnessLog[entryCount].date, date);
        fitnessLog[entryCount].steps = steps;
        fitnessLog[entryCount].distance = distance;
        fitnessLog[entryCount].calories = calories;
        entryCount++;
        printf("🎉 Entry added: %s | Steps: %d | Distance: %.2f km | Calories: %d\n", date, steps, distance, calories);
    } else {
        printf("⚠️ Fitness log is full! Can't add more entries.\n");
    }
}

void viewLog() {
    if (entryCount == 0) {
        printf("📜 Your fitness log is empty!\n");
        return;
    }
    printf("📊 Fitness Log:\n");
    printf("Date       | Steps | Distance (km) | Calories\n");
    printf("-----------|-------|---------------|---------\n");
    
    for (int i = 0; i < entryCount; i++) {
        printf("%-11s | %-5d | %-13.2f | %-7d\n", fitnessLog[i].date, fitnessLog[i].steps, fitnessLog[i].distance, fitnessLog[i].calories);
    }
}

void viewSummary() {
    if (entryCount == 0) {
        printf("📈 No data to summarize! Log some entries first.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += fitnessLog[i].steps;
        totalDistance += fitnessLog[i].distance;
        totalCalories += fitnessLog[i].calories;
    }

    printf("📅 Summary:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void displayMenu() {
    printf("\n🌟 Welcome to Your Fitness Tracker! 🌟\n");
    printf("1. Add a New Entry\n");
    printf("2. View Log\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int main() {
    int choice;
    char date[11];
    int steps;
    float distance;
    int calories;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                printf("Enter distance (km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                addEntry(date, steps, distance, calories);
                break;
            case 2:
                viewLog();
                break;
            case 3:
                viewSummary();
                break;
            case 4:
                printf("🚪 Exiting the Fitness Tracker. Keep moving! 💪\n");
                break;
            default:
                printf("❌ Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}