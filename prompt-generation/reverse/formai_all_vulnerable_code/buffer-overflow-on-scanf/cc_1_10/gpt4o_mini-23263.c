//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    time_t timestamp;
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! No more entries can be added.\n");
        return;
    }
    
    printf("Enter your diary entry:\n");
    getchar(); // To consume the newline character left by previous scanf
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
    diary[entryCount].timestamp = time(NULL);
    entryCount++;
    
    printf("Your entry has been saved!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }
    
    printf("Your Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        char timeString[26];
        struct tm* tm_info;

        tm_info = localtime(&diary[i].timestamp);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("[%s] %s", timeString, diary[i].entry);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    printf("Enter the entry number to delete (0 to %d): ", entryCount - 1);
    int number;
    scanf("%d", &number);
    
    if (number < 0 || number >= entryCount) {
        printf("Invalid entry number.\n");
        return;
    }
    
    for (int i = number; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }

    entryCount--;
    printf("Entry deleted successfully.\n");
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Could not open diary.txt for writing.\n");
        return;
    }
    
    for (int i = 0; i < entryCount; i++) {
        char timeString[26];
        struct tm* tm_info;

        tm_info = localtime(&diary[i].timestamp);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);

        fprintf(file, "[%s] %s", timeString, diary[i].entry);
    }
    
    fclose(file);
    printf("Diary saved to diary.txt!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary found.\n");
        return;
    }
    
    while (!feof(file) && entryCount < MAX_ENTRIES) {
        fgets(diary[entryCount].entry, ENTRY_LENGTH, file);
        diary[entryCount].timestamp = time(NULL); // Just for display, if needed
        entryCount++;
    }
    fclose(file);
    printf("Diary loaded successfully!\n");
}

void displayMenu() {
    printf("\n================== Diary Menu ==================\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary\n");
    printf("5. Load Diary\n");
    printf("0. Exit\n");
    printf("==================================================\n");
}

int main() {
    loadDiary();

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: deleteEntry(); break;
            case 4: saveDiary(); break;
            case 5: loadDiary(); break;
            case 0: printf("Exiting the diary. Bye!\n"); break;
            default: printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 0);

    return 0;
}