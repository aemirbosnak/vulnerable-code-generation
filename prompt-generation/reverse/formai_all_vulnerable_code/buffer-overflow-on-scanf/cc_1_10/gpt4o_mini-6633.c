//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define PASSWORD_LENGTH 16

typedef struct {
    char website[100];
    char username[100];
    char password[PASSWORD_LENGTH + 1];
} Entry;

Entry vault[MAX_ENTRIES];
int total_entries = 0;

void surreal_prompt() {
    printf("\nThe shimmering portal of surrealism opens...\n");
    printf("Within its depths, time has no tether.\n");
    printf("What whispers shall we weave today? \n");
}

void add_entry() {
    if (total_entries >= MAX_ENTRIES) {
        printf("A phoenix cannot rise more than { %d } times.\n", MAX_ENTRIES);
        return;
    }
    Entry new_entry;
    printf("Enter the website: ");
    scanf("%s", new_entry.website);
    printf("Enter the username: ");
    scanf("%s", new_entry.username);
    
    // Generate a surreal password
    srand(time(NULL) + total_entries);
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int r = rand() % 4;
        if (r == 0) {
            new_entry.password[i] = 'a' + rand() % 26;  // Lowercase
        } else if (r == 1) {
            new_entry.password[i] = 'A' + rand() % 26;  // Uppercase
        } else if (r == 2) {
            new_entry.password[i] = '0' + rand() % 10;  // Numbers
        } else {
            new_entry.password[i] = "!@#$%^&*"[rand() % 8]; // Symbols
        }
    }
    new_entry.password[PASSWORD_LENGTH] = '\0'; // Null terminate
    
    vault[total_entries++] = new_entry;
    
    printf("An entry for %s has been penned, with username %s and password %s etched in starlight.\n", 
            new_entry.website, new_entry.username, new_entry.password);
}

void view_entries() {
    if (total_entries == 0) {
        printf("The void awaits your offerings, but none have been bestowed.\n");
        return;
    }
    printf("The annals of your dreams:\n");
    for (int i = 0; i < total_entries; i++) {
        printf("[%d] %s - %s : %s\n", i + 1, vault[i].website, vault[i].username, vault[i].password);
    }
}

void delete_entry() {
    if (total_entries == 0) {
        printf("A garden with no blossoms can offer no pluck.\n");
        return;
    }
    
    int index;
    printf("Select the entry to remove (1 - %d): ", total_entries);
    scanf("%d", &index);
    if (index < 1 || index > total_entries) {
        printf("The void does not acknowledge this choice.\n");
        return;
    }
    
    // Move entries to fill the void
    for (int i = index - 1; i < total_entries - 1; i++) {
        vault[i] = vault[i + 1];
    }
    
    total_entries--;
    
    printf("The entry has evaporated, like a fleeting dream.\n");
}

void surreal_menu() {
    int choice;
    do {
        surreal_prompt();
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit this realm\n");
        printf("Here lies your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("The realm of passwords fades into oblivion...\n");
                break;
            default:
                printf("That path is shrouded in mystery.\n");
        }
    } while (choice != 4);
}

int main() {
    surreal_menu();
    return 0;
}