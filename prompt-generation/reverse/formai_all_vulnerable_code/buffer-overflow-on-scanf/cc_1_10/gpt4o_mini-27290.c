//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Entry;

Entry passwords[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if(entry_count >= MAX_ENTRIES) {
        printf("Password storage is full!\n");
        return;
    }
    Entry new_entry;

    printf("Enter website: ");
    scanf("%s", new_entry.website);
    
    printf("Enter username: ");
    scanf("%s", new_entry.username);
    
    printf("Enter password: ");
    scanf("%s", new_entry.password);
    
    passwords[entry_count++] = new_entry;
    printf("Entry added successfully!\n");
}

void display_entries() {
    if(entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for(int i = 0; i < entry_count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
               passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void delete_entry() {
    char website[MAX_LENGTH];
    printf("Enter website to delete: ");
    scanf("%s", website);

    for(int i = 0; i < entry_count; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            for(int j = i; j < entry_count - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            entry_count--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("No entry found for this website.\n");
}

void search_entry() {
    char website[MAX_LENGTH];
    printf("Enter website to search: ");
    scanf("%s", website);

    for(int i = 0; i < entry_count; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            printf("Website: %s, Username: %s, Password: %s\n",
                   passwords[i].website, passwords[i].username, passwords[i].password);
            return;
        }
    }
    printf("No entry found for this website.\n");
}

void menu() {
    while(1) {
        printf("\nPassword Manager\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Search Entry\n");
        printf("5. Exit\n");
        
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                search_entry();
                break;
            case 5:
                printf("Exiting the Password Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Password Manager!\n");
    menu();
    
    return 0;
}