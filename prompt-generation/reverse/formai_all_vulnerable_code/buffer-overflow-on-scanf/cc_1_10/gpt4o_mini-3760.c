//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define USERNAME_LENGTH 50

void displayMenu();
void createDiaryEntry(const char *username);
void viewDiaryEntries(const char *username);
void deleteDiaryEntry(const char *username);
void clearInputBuffer();

int main() {
    int choice;
    char username[USERNAME_LENGTH];

    printf("Welcome to the Distributed Digital Diary\n");
    printf("Enter your username: ");
    fgets(username, USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Remove the newline character

    // Create a directory for the user's diary if it doesn't exist
    char diaryPath[USERNAME_LENGTH + 20];
    snprintf(diaryPath, sizeof(diaryPath), "diaries/%s_diary.txt", username);
    
    struct stat st = {0};
    if (stat("diaries", &st) == -1) {
        mkdir("diaries", 0700);
    }

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                createDiaryEntry(diaryPath);
                break;
            case 2:
                viewDiaryEntries(diaryPath);
                break;
            case 3:
                deleteDiaryEntry(diaryPath);
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
}

void createDiaryEntry(const char *username) {
    FILE *file = fopen(username, "a");
    if (!file) {
        perror("Error opening diary file");
        return;
    }

    char entry[ENTRY_LENGTH];
    printf("Write your diary entry (max %d characters): ", ENTRY_LENGTH - 1);
    fgets(entry, ENTRY_LENGTH, stdin);
    entry[strcspn(entry, "\n")] = 0; // Remove the newline character

    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Diary entry added successfully!\n");
}

void viewDiaryEntries(const char *username) {
    FILE *file = fopen(username, "r");
    if (!file) {
        perror("Error opening diary file");
        return;
    }

    char entry[ENTRY_LENGTH];
    printf("\nYour Diary Entries:\n");
    while (fgets(entry, ENTRY_LENGTH, file)) {
        printf("- %s", entry);
    }
    fclose(file);
}

void deleteDiaryEntry(const char *username) {
    FILE *file = fopen(username, "r");
    if (!file) {
        perror("Error opening diary file");
        return;
    }

    char entries[MAX_ENTRIES][ENTRY_LENGTH];
    int count = 0;

    while (fgets(entries[count], ENTRY_LENGTH, file) && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No entries to delete!\n");
        return;
    }

    printf("Current Diary Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i]);
    }

    int entryNumber;
    printf("Enter the number of the entry you want to delete: ");
    scanf("%d", &entryNumber);
    clearInputBuffer();

    if (entryNumber < 1 || entryNumber > count) {
        printf("Invalid entry number.\n");
        return;
    }

    entries[entryNumber - 1][0] = '\0'; // Mark the entry as deleted

    file = fopen(username, "w");
    for (int i = 0; i < count; i++) {
        if (entries[i][0] != '\0') {
            fputs(entries[i], file);
        }
    }
    fclose(file);
    printf("Entry deleted successfully!\n");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}