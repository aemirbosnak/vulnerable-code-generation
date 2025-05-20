//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_SIZE 100
#define MAX_CONTENT_SIZE 1000
#define DIARY_FILE "diary.txt"

typedef struct {
    char title[MAX_TITLE_SIZE];
    char content[MAX_CONTENT_SIZE];
} DiaryEntry;

void clearScreen() {
    printf("\033[H\033[J");
}

void displayMenu() {
    clearScreen();
    printf("=====================================================\n");
    printf("                   YOUR DIGITAL DIARY                 \n");
    printf("=====================================================\n");
    printf("1. Add a New Diary Entry\n");
    printf("2. View All Diary Entries\n");
    printf("3. Exit\n");
    printf("=====================================================\n");
    printf("Choose an option: ");
}

void addDiaryEntry() {
    DiaryEntry entry;
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        perror("Could not open diary file");
        return;
    }

    printf("Enter Title: ");
    fgets(entry.title, MAX_TITLE_SIZE, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0;  // Remove newline character

    printf("Enter Content (end with \\end):\n");
    char buffer[MAX_CONTENT_SIZE];
    entry.content[0] = '\0'; // Initialize content

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "\\end\n") == 0) {
            break;
        }
        strcat(entry.content, buffer);
    }

    fprintf(file, "Title: %s\n", entry.title);
    fprintf(file, "Content: %s\n", entry.content);
    fprintf(file, "=====================================================\n");
    fclose(file);
    printf("Diary entry saved successfully!\n");
    getchar(); // Pause before returning to menu
}

void viewDiaryEntries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        perror("Could not open diary file");
        return;
    }

    clearScreen();
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\nPress Enter to return to the menu...");
    getchar(); // Pause before returning to menu
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume left over newline character

        switch (choice) {
            case 1:
                addDiaryEntry();
                break;
            case 2:
                viewDiaryEntries();
                break;
            case 3:
                printf("Exiting the Digital Diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                getchar(); // Pause before returning to menu
        }
    }
    
    return 0;
}