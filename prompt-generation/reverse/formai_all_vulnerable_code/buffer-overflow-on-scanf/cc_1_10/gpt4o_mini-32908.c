//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];        // Format: YYYY-MM-DD
    int steps;
    float distance;       // in kilometers
    int caloriesBurned;
} FitnessEntry;

FitnessEntry fitnessLog[MAX_ENTRIES];
int entryCount = 0;

// Function declarations
void addEntry();
void viewEntries();
void searchEntry();
void deleteEntry();
void displayMenu();
void saveEntries();
void loadEntries();
void clearBuffer();

int main() {
    loadEntries(); // Load existing entries at the start
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        clearBuffer();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                saveEntries();
                printf("Entries saved. Exiting program.\n");
                break;
            default:
                if(choice != 5) {
                    printf("Invalid choice, please try again.\n");
                }
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new entry to the fitness log
void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Log is full, cannot add more entries.\n");
        return;
    }

    FitnessEntry newEntry;

    printf("Enter the date (YYYY-MM-DD): ");
    clearBuffer();
    fgets(newEntry.date, sizeof(newEntry.date), stdin);
    newEntry.date[strcspn(newEntry.date, "\n")] = 0; // Remove newline character

    printf("Enter steps taken: ");
    scanf("%d", &newEntry.steps);

    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);

    printf("Enter calories burned: ");
    scanf("%d", &newEntry.caloriesBurned);

    fitnessLog[entryCount++] = newEntry;
    printf("Entry added successfully.\n");
}

// Function to view all entries in the fitness log
void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n--- Fitness Log Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s, Steps: %d, Distance: %.2f km, Calories Burned: %d\n", 
               fitnessLog[i].date, fitnessLog[i].steps, fitnessLog[i].distance, fitnessLog[i].caloriesBurned);
    }
}

// Function to search a specific entry by date
void searchEntry() {
    char searchDate[11];
    printf("Enter the date to search (YYYY-MM-DD): ");
    clearBuffer();
    fgets(searchDate, sizeof(searchDate), stdin);
    searchDate[strcspn(searchDate, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(fitnessLog[i].date, searchDate) == 0) {
            printf("Found Entry:\n");
            printf("Date: %s, Steps: %d, Distance: %.2f km, Calories Burned: %d\n", 
                   fitnessLog[i].date, fitnessLog[i].steps, fitnessLog[i].distance, fitnessLog[i].caloriesBurned);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found for the date: %s\n", searchDate);
    }
}

// Function to delete an entry by date
void deleteEntry() {
    char delDate[11];
    printf("Enter the date of the entry to delete (YYYY-MM-DD): ");
    clearBuffer();
    fgets(delDate, sizeof(delDate), stdin);
    delDate[strcspn(delDate, "\n")] = 0; // Remove newline character

    int found = -1;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(fitnessLog[i].date, delDate) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < entryCount - 1; i++) {
            fitnessLog[i] = fitnessLog[i + 1];
        }
        entryCount--;
        printf("Entry deleted successfully.\n");
    } else {
        printf("No entry found for the date: %s\n", delDate);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Delete Entry by Date\n");
    printf("5. Save and Exit\n");
}

// Function to save entries to a file
void saveEntries() {
    FILE *file = fopen("fitness_log.txt", "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s,%d,%.2f,%d\n", 
                fitnessLog[i].date, fitnessLog[i].steps, fitnessLog[i].distance, fitnessLog[i].caloriesBurned);
    }
    fclose(file);
}

// Function to load entries from a file
void loadEntries() {
    FILE *file = fopen("fitness_log.txt", "r");
    if (!file) {
        return; // If file does not exist, simply return
    }

    while (fscanf(file, "%10[^,],%d,%f,%d\n", 
                  fitnessLog[entryCount].date, &fitnessLog[entryCount].steps, 
                  &fitnessLog[entryCount].distance, &fitnessLog[entryCount].caloriesBurned) == 4) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            break; // Prevent overflow
        }
    }
    fclose(file);
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}