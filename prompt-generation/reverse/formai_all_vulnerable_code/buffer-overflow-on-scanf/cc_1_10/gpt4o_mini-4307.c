//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[NUMBER_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void displayEntries();
void searchEntry();
void deleteEntry();
void saveToFile();
void loadFromFile();
void clearScreen();
void displayMenu();

int main() {
    loadFromFile();
    int choice;

    while (1) {
        clearScreen();
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                saveToFile();
                printf("Exiting... All entries saved.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Phone book is full! Cannot add more entries.\n");
        return;
    }
    Entry newEntry;
    printf("Enter Name: ");
    fgets(newEntry.name, NAME_LENGTH, stdin);
    newEntry.name[strcspn(newEntry.name, "\n")] = 0; // Remove newline
    printf("Enter Phone Number: ");
    fgets(newEntry.phone, NUMBER_LENGTH, stdin);
    newEntry.phone[strcspn(newEntry.phone, "\n")] = 0; // Remove newline

    phoneBook[entryCount++] = newEntry;
    printf("Entry added!\n");
    getchar();
}

void displayEntries() {
    if (entryCount == 0) {
        printf("Your phone book is empty. Surviving alone in this wasteland, I see.\n");
        return;
    }
    printf("\n--- Phone Book Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d: %s - %s\n", i+1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("\nPress Enter to go back.");
    getchar();
}

void searchEntry() {
    char searchTerm[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchTerm, NAME_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < entryCount; i++) {
        if (strstr(phoneBook[i].name, searchTerm) != NULL) {
            printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found matching '%s'. Wandering alone, are we?\n", searchTerm);
    }
    printf("\nPress Enter to go back.");
    getchar();
}

void deleteEntry() {
    int index;
    displayEntries();
    
    printf("Enter the number of the entry to delete: ");
    scanf("%d", &index);
    getchar(); // Clear newline

    if (index < 1 || index > entryCount) {
        printf("Invalid index. Nothing to delete.\n");
    } else {
        for (int i = index - 1; i < entryCount - 1; i++) {
            phoneBook[i] = phoneBook[i + 1];
        }
        entryCount--;
        printf("Entry deleted.\n");
    }
    printf("\nPress Enter to go back.");
    getchar();
}

void saveToFile() {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error saving phonebook. Lost another memory.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s\n%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("No previous records found... Just ashes of memories.\n");
        return;
    }
    while (fgets(phoneBook[entryCount].name, NAME_LENGTH, file) != NULL) {
        phoneBook[entryCount].name[strcspn(phoneBook[entryCount].name, "\n")] = 0; // Remove newline
        fgets(phoneBook[entryCount].phone, NUMBER_LENGTH, file);
        phoneBook[entryCount].phone[strcspn(phoneBook[entryCount].phone, "\n")] = 0; // Remove newline
        entryCount++;
    }
    fclose(file);
}

void displayMenu() {
    printf("--- Post-Apocalyptic Phone Book ---\n");
    printf("1. Add new entry\n");
    printf("2. Display entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
}

void clearScreen() {
    // This function may not fully clear the screen on all systems, 
    // but gives the feeling of a new environment.
    system("clear || cls");
}