//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define TITLE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char title[TITLE_LENGTH];
    char phoneNumber[15];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n--- The Grand Phone Book of the Kingdom ---\n");
    printf("1. Record the name of a noble or villager\n");
    printf("2. Seek the number of a noble or villager\n");
    printf("3. Remove a name from the scrolls\n");
    printf("4. Display all entries in the grand book\n");
    printf("5. Exit the realm\n");
    printf("Choose thy action: ");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("O fair one, the phone book hath reached its limits!\n");
        return;
    }
    
    printf("Enter the name of the noble or villager: ");
    getchar();  // Clear the newline character from the buffer
    fgets(phoneBook[entryCount].name, NAME_LENGTH, stdin);
    strtok(phoneBook[entryCount].name, "\n"); // Remove newline
    
    printf("What title dost thou bestow upon them? ");
    fgets(phoneBook[entryCount].title, TITLE_LENGTH, stdin);
    strtok(phoneBook[entryCount].title, "\n"); // Remove newline

    printf("Enter thy phone number: ");
    fgets(phoneBook[entryCount].phoneNumber, 15, stdin);
    strtok(phoneBook[entryCount].phoneNumber, "\n"); // Remove newline

    entryCount++;
    printf("The valiant knight %s hath been recorded!\n", phoneBook[entryCount - 1].name);
}

void searchEntry() {
    char name[NAME_LENGTH];
    printf("Whose number dost thou seek? ");
    getchar();  // Clear the newline character from the buffer
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Hark! The number for %s, the %s, is: %s\n", phoneBook[i].name, phoneBook[i].title, phoneBook[i].phoneNumber);
            return;
        }
    }
    printf("Alas! The noble %s is not found in our scrolls!\n", name);
}

void deleteEntry() {
    char name[NAME_LENGTH];
    printf("Which name dost thou wish to erase? ");
    getchar();  // Clear the newline character from the buffer
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline

    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift entries left
            }
            entryCount--;
            printf("The name of %s hath been removed from the grand book!\n", name);
            return;
        }
    }
    printf("Alas! There is no entry for %s in our records!\n", name);
}

void displayEntries() {
    if (entryCount == 0) {
        printf("The grand book is empty. Not a single entry remains!\n");
        return;
    }

    printf("\n--- The Grand Entries of the Kingdom ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s, the %s: %s\n", i + 1, phoneBook[i].name, phoneBook[i].title, phoneBook[i].phoneNumber);
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                displayEntries();
                break;
            case 5:
                printf("Farewell, noble traveler! Until we meet again.\n");
                break;
            default:
                printf("Pray, enter a valid number from the options given!\n");
        }
    } while (choice != 5);

    return 0;
}