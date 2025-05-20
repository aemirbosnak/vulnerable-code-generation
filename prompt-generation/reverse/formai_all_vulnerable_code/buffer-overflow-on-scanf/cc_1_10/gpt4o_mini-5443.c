//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to hold diary entries
typedef struct DiaryEntry {
    int id;
    char date[11];
    char content[256];
} DiaryEntry;

// Function prototypes
void addEntry(DiaryEntry entries[], int *count);
void viewEntries(DiaryEntry entries[], int count);
void deleteEntry(DiaryEntry entries[], int *count);
void saveEntriesToFile(DiaryEntry entries[], int count);
void loadEntriesFromFile(DiaryEntry entries[], int *count);
void displayMenu();

int main() {
    DiaryEntry entries[100]; // Array to hold diary entries
    int entryCount = 0; // Current count of diary entries
    loadEntriesFromFile(entries, &entryCount); // Load existing entries from file

    int choice;
    while (1) {
        displayMenu(); // Show menu
        printf("What would you like to do? (Enter a number): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                viewEntries(entries, entryCount);
                break;
            case 3:
                deleteEntry(entries, &entryCount);
                break;
            case 4:
                saveEntriesToFile(entries, entryCount);
                break;
            case 5:
                printf("Exiting... Thanks for writing!\n");
                return 0;
            default:
                printf("Hmm, that's not a valid option. Try again!\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add a New Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete a Diary Entry\n");
    printf("4. Save Entries to File\n");
    printf("5. Exit\n");
}

// Function to add a new diary entry
void addEntry(DiaryEntry entries[], int *count) {
    if (*count >= 100) {
        printf("Whoa! Can't add more entries, diary is full!\n");
        return;
    }
    
    DiaryEntry newEntry;
    newEntry.id = *count + 1;

    printf("What's the date of this entry? (yyyy-mm-dd): ");
    scanf("%s", newEntry.date);
    
    printf("What's on your mind?\n");
    getchar(); // To consume the newline character
    fgets(newEntry.content, sizeof(newEntry.content), stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = '\0'; // Remove the newline character
    
    entries[*count] = newEntry;
    (*count)++;
    printf("Entry added! What a clever thing to do!\n");
}

// Function to view all diary entries
void viewEntries(DiaryEntry entries[], int count) {
    if (count == 0) {
        printf("Your diary is empty. How about writing something?\n");
        return;
    }
    
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("Entry #%d (Date: %s): %s\n", entries[i].id, entries[i].date, entries[i].content);
    }
}

// Function to delete a diary entry
void deleteEntry(DiaryEntry entries[], int *count) {
    if (*count == 0) {
        printf("No entries to delete! Write more to manage them!\n");
        return;
    }

    int entryID;
    printf("Which entry would you like to delete? (Enter Entry ID): ");
    scanf("%d", &entryID);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (entries[i].id == entryID) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1]; // Shift entries left
            }
            (*count)--; // Decrease the count
            printf("Entry #%d deleted! What a brave choice!\n", entryID);
            break;
        }
    }
    if (!found) {
        printf("Entry with ID #%d not found! How curious...\n", entryID);
    }
}

// Function to save entries to a file
void saveEntriesToFile(DiaryEntry entries[], int count) {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Failed to save your diary entries. Could it be a file issue?\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s\n", entries[i].id, entries[i].date, entries[i].content);
    }
    fclose(file);
    printf("Entries saved! Isn’t that a smart move!\n");
}

// Function to load entries from a file
void loadEntriesFromFile(DiaryEntry entries[], int *count) {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No previous entries found! Let's start fresh!\n");
        return;
    }
    
    while (fscanf(file, "%d,%10[^,],%255[^\n]\n", &entries[*count].id, entries[*count].date, entries[*count].content) == 3) {
        (*count)++;
    }
    fclose(file);
    printf("Loaded %d entries from your previous diary! How nostalgic!\n", *count);
}