//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: realistic
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

Entry entries[MAX_ENTRIES];
int entry_count = 0;

void print_menu() {
    printf("\nPassword Management System\n");
    printf("1. Add New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }

    Entry new_entry;
    printf("Enter Website: ");
    scanf("%s", new_entry.website);
    printf("Enter Username: ");
    scanf("%s", new_entry.username);
    printf("Enter Password: ");
    scanf("%s", new_entry.password);

    entries[entry_count++] = new_entry;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries available.\n");
        return;
    }

    printf("\nStored Password Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
                entries[i].website, entries[i].username, entries[i].password);
    }
}

void search_entry() {
    char website[MAX_LENGTH];
    printf("Enter the website to search: ");
    scanf("%s", website);

    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            printf("Entry found:\n");
            printf("Website: %s, Username: %s, Password: %s\n", 
                    entries[i].website, entries[i].username, entries[i].password);
            return;
        }
    }
    printf("No entry found for the website: %s\n", website);
}

void delete_entry() {
    char website[MAX_LENGTH];
    printf("Enter the website to delete: ");
    scanf("%s", website);

    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            for (int j = i; j < entry_count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            entry_count--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("No entry found for the website: %s\n", website);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting the Password Management System.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}