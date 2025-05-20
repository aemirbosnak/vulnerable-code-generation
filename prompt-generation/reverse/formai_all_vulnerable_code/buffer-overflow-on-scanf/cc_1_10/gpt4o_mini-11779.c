//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LEN 50
#define MAX_CONTENT_LEN 500
#define DIARY_FILE "diary.txt"

typedef struct {
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
} DiaryEntry;

void addEntry();
void viewEntries();
void deleteEntry();
void clearScreen();
void pause();

int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("=========================================\n");
        printf("           Digital Diary Menu           \n");
        printf("=========================================\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Delete Diary Entry\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                pause();
                break;
        }
    }
    return 0;
}

void addEntry() {
    DiaryEntry entry;
    FILE *file;

    clearScreen();
    printf("Enter Title: ");
    fgets(entry.title, MAX_TITLE_LEN, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove newline

    printf("Write your Diary Entry (max %d characters):\n", MAX_CONTENT_LEN);
    fgets(entry.content, MAX_CONTENT_LEN, stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove newline

    file = fopen(DIARY_FILE, "a");
    if (file) {
        fprintf(file, "%s\n%s\n\n", entry.title, entry.content);
        fclose(file);
        printf("Diary Entry added successfully!\n");
    } else {
        printf("Error opening file for writing.\n");
    }
    pause();
}

void viewEntries() {
    FILE *file;
    char buffer[600]; // Buffer for reading file

    clearScreen();
    file = fopen(DIARY_FILE, "r");
    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
        printf("\nEnd of Entries.\n");
    } else {
        printf("No entries found or error opening file.\n");
    }
    pause();
}

void deleteEntry() {
    FILE *file, *tempFile;
    char titleToDelete[MAX_TITLE_LEN];
    char buffer[600];
    int found = 0;

    clearScreen();
    printf("Enter the title of the entry you want to delete: ");
    fgets(titleToDelete, MAX_TITLE_LEN, stdin);
    titleToDelete[strcspn(titleToDelete, "\n")] = 0; // Remove newline

    file = fopen(DIARY_FILE, "r");
    tempFile = fopen("temp.txt", "w");

    if (file && tempFile) {
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strstr(buffer, titleToDelete) == NULL) {
                fputs(buffer, tempFile);
            } else {
                found = 1;
                // Skipping the next two lines to delete the entry
                fgets(buffer, sizeof(buffer), file); // Skip content
                fgets(buffer, sizeof(buffer), file); // Skip new line
            }
        }
        fclose(file);
        fclose(tempFile);

        remove(DIARY_FILE);
        rename("temp.txt", DIARY_FILE);

        if (found) {
            printf("Diary Entry titled '%s' deleted successfully!\n", titleToDelete);
        } else {
            printf("No entry found with that title.\n");
        }
    } else {
        printf("Error opening files.\n");
    }
    pause();
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

void pause() {
    printf("Press Enter to continue...");
    getchar();
}