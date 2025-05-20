//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50
#define DATE_LEN 11
#define INPUT_LEN 100

typedef struct {
    char name[NAME_LEN];
    int steps;
    float distance;
    time_t date;
} Entry;

Entry tracker[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("No more entries can be added.\n");
        return;
    }
    Entry e;
    printf("Enter name: ");
    fgets(e.name, NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = 0;  // Remove newline character
    printf("Enter steps: ");
    scanf("%d", &e.steps);
    printf("Enter distance (in km): ");
    scanf("%f", &e.distance);
    e.date = time(NULL);
    tracker[entryCount++] = e;
    printf("Entry added successfully!\n");
    getchar();  // To consume the newline left by scanf
}

void viewEntries() {
    printf("\n--- Fitness Tracker Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. Name: %s | Steps: %d | Distance: %.2f km | Date: %s", 
               i + 1, tracker[i].name, tracker[i].steps, tracker[i].distance, ctime(&tracker[i].date));
    }
}

void summary() {
    int totalSteps = 0;
    float totalDistance = 0.0;
    
    for (int i = 0; i < entryCount; i++) {
        totalSteps += tracker[i].steps;
        totalDistance += tracker[i].distance;
    }
    
    printf("\n--- Summary ---\n");
    printf("Total Entries: %d\n", entryCount);
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
}

void clearEntries() {
    entryCount = 0;
    printf("All entries cleared!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Summary\n");
        printf("4. Clear All Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline left by scanf

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: summary(); break;
            case 4: clearEntries(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}