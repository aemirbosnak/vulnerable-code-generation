//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];  // Format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry();
void viewEntries();
void saveDiary();
void loadDiary();
void displayMenu();
void clearScreen();

int main() {
    loadDiary(); // Load the existing diary entries.

    int choice;
    do {
        clearScreen();
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after scanf

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveDiary();
                break;
            case 4:
                loadDiary();
                break;
            case 5:
                printf("Exiting the diary. Have a great day!\n");
                break; // Exit the application
            default:
                printf("Invalid choice, please select again!\n");
                break;
        }
        printf("\nPress Enter to continue...");
        getchar(); // Wait for the user to press Enter
    } while (choice != 5);

    return 0;
}

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    fgets(diary[numEntries].entry, MAX_LENGTH, stdin);
    diary[numEntries].entry[strcspn(diary[numEntries].entry, "\n")] = 0; // Remove trailing newline

    // Get the current date
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(diary[numEntries].date, sizeof(diary[numEntries].date), "%Y-%m-%d", tm_info);

    numEntries++;
    printf("Your entry has been recorded!\n");
}

void viewEntries() {
    clearScreen();
    if (numEntries == 0) {
        printf("No entries in the diary yet!\n");
        return;
    }
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("[%d] Date: %s\n", i + 1, diary[i].date);
        printf("   Entry: %s\n", diary[i].entry);
        printf("-----------------------\n");
    }
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error creating file!\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary saved successfully!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No previous diary found, starting fresh!\n");
        return;
    }

    while (fscanf(file, "%10s\n%255[^\n]\n", diary[numEntries].date, diary[numEntries].entry) == 2) {
        numEntries++;
        if (numEntries >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Diary loaded with %d entries!\n", numEntries);
}

void displayMenu() {
    printf("====== Digital Diary ======\n");
    printf("1. Add a New Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Diary\n");
    printf("4. Load Diary\n");
    printf("5. Exit\n");
    printf("===========================\n");
}

void clearScreen() {
    // This works for Linux-based systems.
    printf("\033[H\033[J");
}