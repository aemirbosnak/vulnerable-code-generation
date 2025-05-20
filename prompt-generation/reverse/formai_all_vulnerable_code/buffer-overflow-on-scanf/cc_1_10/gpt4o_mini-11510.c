//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define MESSAGE_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
} LoveLetter;

LoveLetter database[MAX_ENTRIES];
int current_size = 0;

void addLetter(const char *name, const char *message) {
    if (current_size < MAX_ENTRIES) {
        strncpy(database[current_size].name, name, NAME_LENGTH);
        strncpy(database[current_size].message, message, MESSAGE_LENGTH);
        current_size++;
        printf("A new letter hath been added, sweet words from %s.\n", name);
    } else {
        printf("Alack! The database is full, cannot add more letters.\n");
    }
}

void displayLetters() {
    if (current_size == 0) {
        printf("No letters to display, thy hearts lie still.\n");
        return;
    }
    
    printf("\n--- Love Letters Database ---\n");
    for (int i = 0; i < current_size; i++) {
        printf("Letter %d:\n", i + 1);
        printf("From: %s\n", database[i].name);
        printf("Message: %s\n", database[i].message);
        printf("---------------------------\n");
    }
}

void searchLettersByName(const char *name) {
    int found = 0;
    printf("\nSearching letters from %s...\n", name);
    for (int i = 0; i < current_size; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Letter %d:\n", i + 1);
            printf("From: %s\n", database[i].name);
            printf("Message: %s\n", database[i].message);
            printf("---------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No letters found from %s, a love lost in the fabric of time.\n", name);
    }
}

int main() {
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
    int choice;

    printf("Welcome to the Love Letters Database, a tale of hearts entwined.\n");

    while (1) {
        printf("\nSelect thy action:\n");
        printf("1. Add a Love Letter\n");
        printf("2. Display All Love Letters\n");
        printf("3. Search Love Letters by Name\n");
        printf("4. Exit\n");
        printf("Enter thy choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline after choice input

        switch (choice) {
            case 1:
                printf("Enter thy name (Romeo, Juliet, etc.): ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline char

                printf("Enter thy heart's message: ");
                fgets(message, MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // remove newline char

                addLetter(name, message);
                break;
            case 2:
                displayLetters();
                break;
            case 3:
                printf("Whose letters dost thou seek? ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline char
                
                searchLettersByName(name);
                break;
            case 4:
                printf("Farewell! Thy heart's desires linger on...\n");
                return 0;
            default:
                printf("Soft! An invalid choice, choose wisely.\n");
        }
    }

    return 0;
}