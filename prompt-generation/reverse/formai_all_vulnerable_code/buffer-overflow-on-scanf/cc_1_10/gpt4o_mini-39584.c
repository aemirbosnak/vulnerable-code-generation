//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

DiaryEntry diaryEntries[MAX_ENTRIES];
int entryCount = 0;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void displayTitle() {
    printf("*************************************\n");
    printf("*          My Digital Diary         *\n");
    printf("*************************************\n");
}

void addDiaryEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    printf("Enter the title of your entry: ");
    fgets(diaryEntries[entryCount].title, MAX_TITLE_LENGTH, stdin);
    diaryEntries[entryCount].title[strcspn(diaryEntries[entryCount].title, "\n")] = 0; // remove newline

    printf("Now, express your thoughts:\n");
    fgets(diaryEntries[entryCount].content, MAX_CONTENT_LENGTH, stdin);
    diaryEntries[entryCount].content[strcspn(diaryEntries[entryCount].content, "\n")] = 0; // remove newline

    entryCount++;
    printf("Your entry has been added successfully!\n");
}

void viewDiaryEntries() {
    if (entryCount == 0) {
        printf("No diary entries available yet. Write something!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("\nEntry %d\n", i + 1);
        printf("Title: %s\n", diaryEntries[i].title);
        printf("Content: %s\n", diaryEntries[i].content);
        printf("----------------------------------------\n");
    }
}

void saveToFile() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (file == NULL) {
        printf("Could not open file for saving!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Entry %d\n", i + 1);
        fprintf(file, "Title: %s\n", diaryEntries[i].title);
        fprintf(file, "Content: %s\n", diaryEntries[i].content);
        fprintf(file, "----------------------------------------\n");
    }

    fclose(file);
    printf("Diary entries saved to diary_entries.txt!\n");
}

void loadFromFile() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No saved diary found. Start writing!\n");
        return;
    }

    while (fgetc(file) != EOF) {
        ungetc(fgetc(file), file);
        if (entryCount >= MAX_ENTRIES) {
            break;
        }
        
        fgets(diaryEntries[entryCount].title, MAX_TITLE_LENGTH, file);
        diaryEntries[entryCount].title[strcspn(diaryEntries[entryCount].title, "\n")] = 0;

        fgets(diaryEntries[entryCount].content, MAX_CONTENT_LENGTH, file);
        diaryEntries[entryCount].content[strcspn(diaryEntries[entryCount].content, "\n")] = 0;

        entryCount++;
    }

    fclose(file);
    printf("Diary entries loaded successfully!\n");
}

int main() {
    int choice;

    loadFromFile();
    
    while (1) {
        clearScreen();
        displayTitle();
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Save Diary Entries\n");
        printf("4. Load Diary Entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice) {
            case 1:
                addDiaryEntry();
                break;
            case 2:
                viewDiaryEntries();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                loadFromFile();
                break;
            case 5:
                saveToFile();
                printf("Thank you for using My Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("Press Enter to continue...\n");
        getchar(); // wait for user input
    }

    return 0;
}