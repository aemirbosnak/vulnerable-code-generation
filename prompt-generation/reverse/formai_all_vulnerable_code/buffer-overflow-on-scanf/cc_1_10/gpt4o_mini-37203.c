//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_PASSWORD_LENGTH 256
#define MAX_URL_LENGTH 512

typedef struct {
    char url[MAX_URL_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

Entry passwordManager[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("The universe is full of passwords. Cannot add more.\n");
        return;
    }

    Entry newEntry;
    printf("Enter the URL of the celestial portal: ");
    scanf("%s", newEntry.url);
    printf("Enter the username that belongs among the stars: ");
    scanf("%s", newEntry.username);
    printf("Enter the password that guards your dreams: ");
    scanf("%s", newEntry.password);

    passwordManager[entryCount] = newEntry;
    entryCount++;
    printf("A new entry has been stitched into the fabric of cyberspace!\n");
}

void displayEntries() {
    if (entryCount == 0) {
        printf("The void is empty. No secrets to unveil.\n");
        return;
    }

    printf("\n--- Password Vault ---\n");
    for (int i = 0; i < entryCount; i++) {
        Entry e = passwordManager[i];
        printf("Entry %d:\n", i + 1);
        printf("    URL: %s\n", e.url);
        printf("    Username: %s\n", e.username);
        printf("    Password: %s\n", e.password);
    }
    printf("----------------------\n");
}

void searchEntry() {
    char url[MAX_URL_LENGTH];
    printf("Whisper the URL you seek in the shadows of cyberspace: ");
    scanf("%s", url);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordManager[i].url, url) == 0) {
            printf("The secrets of %s:\n", passwordManager[i].url);
            printf("    Username: %s\n", passwordManager[i].username);
            printf("    Password: %s\n", passwordManager[i].password);
            return;
        }
    }
    printf("The echoes of that URL do not resonate in this realm.\n");
}

void deleteEntry() {
    char url[MAX_URL_LENGTH];
    printf("Which URL shall we banish from this realm? Speak its name: ");
    scanf("%s", url);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordManager[i].url, url) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            entryCount--;
            printf("The memory of %s has been erased from existence.\n", url);
            return;
        }
    }
    printf("The URL was elusive and danced away from us, not to be found.\n");
}

void helpMenu() {
    printf("In this realm of forgotten keys and portals, you may:\n");
    printf("1. Add a password entry.\n");
    printf("2. Display all password entries.\n");
    printf("3. Search for a specific entry.\n");
    printf("4. Delete an entry from the cosmos.\n");
    printf("5. Exit this dream.\n");
}

int main() {
    int choice;

    while (1) {
        helpMenu();
        printf("Choose your path (1-5): ");
        scanf("%d", &choice);

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
                printf("As you exit this realm, may your passwords be strong and your dreams unbroken.\n");
                exit(0);
            default:
                printf("The choice you made has no grounding in reality. Try again.\n");
                break;
        }
    }
    return 0;
}