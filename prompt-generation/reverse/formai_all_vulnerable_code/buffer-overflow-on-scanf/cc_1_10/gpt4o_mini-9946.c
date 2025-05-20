//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 512

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Oh no! Your diary is full! Can't add more entries.\n");
        return;
    }
    
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[entryCount].date);
    
    printf("Write your diary entry: ");
    getchar();  // Clears the newline character left in the buffer
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);

    // Remove newline character from entry
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;

    entryCount++;
    printf("Your entry has been saved beautifully! 🌟\n\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("Your diary is empty! Write something lovely! 📖\n\n");
        return;
    }
    
    printf("Here's what you've written in your diary:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("[%s] %s\n", diary[i].date, diary[i].entry);
    }
    printf("\n");
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete! 😢\n\n");
        return;
    }

    viewEntries();
    
    int index;
    printf("Enter the entry number you want to delete (1 to %d): ", entryCount);
    scanf("%d", &index);

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number! Please try again. 🙁\n\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Your entry has been elegantly erased from existence! 🥲\n\n");
}

void menu() {
    int choice;
    do {
        printf("Welcome to Your Digital Diary! 😄\n");
        printf("1. Add a new entry\n");
        printf("2. View entries\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        
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
                printf("Exiting. May your thoughts be as colorful as a sunset! 🌅\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Try again! 🙃\n\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}