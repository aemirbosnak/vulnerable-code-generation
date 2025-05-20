//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char entry[MAX_LENGTH];
    int moodRating; // Scale from 1 to 10
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int totalEntries = 0;

// Function prototypes
void addEntry();
void displayEntries();
double calculateAverageMood();
void displayEntryStats();

int main() {
    int choice;
    
    do {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Diary Entry\n");
        printf("2. Display Diary Entries\n");
        printf("3. Entry Statistics\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                displayEntryStats();
                break;
            case 4:
                printf("Exiting the diary. Have a good day!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void addEntry() {
    if (totalEntries >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    DiaryEntry newEntry;
    printf("Enter your diary entry: ");
    fgets(newEntry.entry, MAX_LENGTH, stdin);
    newEntry.entry[strcspn(newEntry.entry, "\n")] = 0; // Remove newline
    
    printf("Rate your mood (1-10): ");
    scanf("%d", &newEntry.moodRating);
    while (newEntry.moodRating < 1 || newEntry.moodRating > 10) {
        printf("Invalid rating! Please enter a mood rating between 1 and 10: ");
        scanf("%d", &newEntry.moodRating);
    }
    
    diary[totalEntries] = newEntry;
    totalEntries++;
    
    printf("Entry added successfully!\n");
}

void displayEntries() {
    if (totalEntries == 0) {
        printf("No diary entries to display.\n");
        return;
    }
    
    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < totalEntries; i++) {
        printf("Entry %d: %s (Mood Rating: %d)\n", i + 1, diary[i].entry, diary[i].moodRating);
    }
}

double calculateAverageMood() {
    if (totalEntries == 0) {
        return 0.0;
    }
    
    int sum = 0;
    for (int i = 0; i < totalEntries; i++) {
        sum += diary[i].moodRating;
    }
    
    return (double)sum / totalEntries;
}

void displayEntryStats() {
    double averageMood = calculateAverageMood();
    
    printf("\nDiary Entry Statistics:\n");
    printf("Total Entries: %d\n", totalEntries);
    if (totalEntries > 0) {
        printf("Average Mood Rating: %.2f\n", averageMood);
    } else {
        printf("No mood ratings available.\n");
    }
}