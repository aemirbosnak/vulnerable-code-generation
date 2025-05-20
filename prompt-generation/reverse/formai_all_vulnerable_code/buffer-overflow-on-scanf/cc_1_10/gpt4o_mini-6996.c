//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum size for diary entries and usernames
#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 256
#define MAX_USERNAME_LENGTH 50
#define DIARY_FILE "diary.txt"

// Structure to represent a diary entry
typedef struct {
    int id;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to write a diary entry to a user's file
void writeEntry(const char *username) {
    char entry[MAX_ENTRY_LENGTH];
    FILE *file;

    printf("Enter your diary entry: ");
    getchar();  // Clear input buffer
    fgets(entry, sizeof(entry), stdin);

    file = fopen(username, "a");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    
    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Entry saved successfully!\n");
}

// Function to read diary entries from a user's file
void readEntries(const char *username) {
    char buffer[MAX_ENTRY_LENGTH];
    FILE *file;

    file = fopen(username, "r");
    if (!file) {
        printf("No entries found for user %s.\n", username);
        return;
    }
    
    printf("Your Diary Entries:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("- %s", buffer);
    }
    
    fclose(file);
}

// Function to handle user actions
void diaryMenu(const char *username) {
    int choice;
    do {
        printf("\nDiary Menu for %s:\n", username);
        printf("1. Write a new entry\n");
        printf("2. Read your entries\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                writeEntry(username);
                break;
            case 2:
                readEntries(username);
                break;
            case 3:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 3);
}

// Function to handle user login
void userLogin() {
    char username[MAX_USERNAME_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    // User diary file will be based on username
    diaryMenu(username);
}

int main() {
    printf("Welcome to the Multiplayer Digital Diary!\n");
    userLogin();
    return 0;
}