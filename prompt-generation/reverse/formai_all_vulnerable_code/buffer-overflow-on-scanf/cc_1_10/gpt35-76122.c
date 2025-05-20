//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_ENTRIES 100
#define ENTRY_LEN 250
#define PASSWORD "mySecurePassword123"

// Struct for a single diary entry
typedef struct {
    char date[11];
    char entry[ENTRY_LEN];
} DiaryEntry;

// Function prototypes
void clearConsole();
void login();
void menu();
void addEntry();
void printEntries();
void exitProgram();
void saveToFile();
void loadFromFile();
void encryptEntry(char *entry);
void decryptEntry(char *entry);

// Global variables
DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;
bool loggedIn = false;

int main() {
    loadFromFile();
    login();
    menu();
    return 0;
}

// Function to clear the console
void clearConsole() {
    system("clear || cls");
}

// Function to handle login
void login() {
    char passwordInput[20];
    printf("Please enter your password: ");
    scanf("%s", passwordInput);
    if (strcmp(passwordInput, PASSWORD) == 0) {
        loggedIn = true;
        printf("Login successful. Press any key to continue.\n");
        getchar();
        getchar();
        clearConsole();
    } else {
        printf("Incorrect password. Exiting program.\n");
        exitProgram();
    }
}

// Function to display menu and get user input
void menu() {
    int choice;
    while (loggedIn) {
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit program\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                printEntries();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid choice.\n");
        }

        saveToFile();
        getchar();
        clearConsole();
    }
}

// Function to add a new entry
void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Diary is full. No more entries can be added.\n");
        return;
    }

    DiaryEntry newEntry;
    printf("Please enter the date for this entry (MM/DD/YYYY): ");
    fgets(newEntry.date, sizeof(newEntry.date), stdin);
    printf("Please enter the diary entry text (250 character limit):\n");
    fgets(newEntry.entry, sizeof(newEntry.entry), stdin);
    encryptEntry(newEntry.entry);
    entries[numEntries] = newEntry;
    numEntries++;
    printf("Entry added successfully.\n");
}

// Function to print all entries
void printEntries() {
    for (int i=0; i<numEntries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: ");
        decryptEntry(entries[i].entry);
        printf("\n\n");
    }
}

// Function to exit the program
void exitProgram() {
    printf("Exiting program. Goodbye!\n");
    loggedIn = false;
}

// Function to save diary entries to a file
void saveToFile() {
    FILE *fp;
    fp = fopen("diary.dat", "wb");
    if (fp != NULL) {
        fwrite(&numEntries, sizeof(numEntries), 1, fp);
        for (int i=0; i<numEntries; i++) {
            fwrite(&entries[i], sizeof(DiaryEntry), 1, fp);
        }
        fclose(fp);
        printf("Diary saved to file.\n");
    } else {
        printf("Could not open file for writing.\n");
    }
}

// Function to load diary entries from a file
void loadFromFile() {
    FILE *fp;
    fp = fopen("diary.dat", "rb");
    if (fp != NULL) {
        fread(&numEntries, sizeof(numEntries), 1, fp);
        for (int i=0; i<numEntries; i++) {
            fread(&entries[i], sizeof(DiaryEntry), 1, fp);
        }
        fclose(fp);
        printf("Diary loaded from file.\n");
    } else {
        printf("Could not open file for reading.\n");
    }
}

// Function to encrypt diary entry text
void encryptEntry(char *entry) {
    for (int i=0; i<strlen(entry); i++) {
        entry[i] = entry[i] + 13; // Use Caesar cipher with shift of 13
    }
}

// Function to decrypt diary entry text
void decryptEntry(char *entry) {
    for (int i=0; i<strlen(entry); i++) {
        entry[i] = entry[i] - 13; // Use Caesar cipher with shift of 13 (inverse)
    }
}