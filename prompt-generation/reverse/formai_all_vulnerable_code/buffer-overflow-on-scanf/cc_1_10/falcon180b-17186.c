//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} entry;

void add_entry(entry entries[], int num_entries) {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter email: ");
    scanf("%s", email);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].email, email);

    num_entries++;
}

void remove_entry(entry entries[], int num_entries) {
    int choice;

    printf("Enter the index of the entry you want to remove: ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < num_entries) {
        for (int i = choice; i < num_entries - 1; i++) {
            strcpy(entries[i].name, entries[i + 1].name);
            strcpy(entries[i].email, entries[i + 1].email);
        }
        num_entries--;
    } else {
        printf("Invalid choice.\n");
    }
}

void display_entries(entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].email);
    }
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Display entries\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Maximum number of entries reached.\n");
                } else {
                    add_entry(entries, num_entries);
                }
                break;
            case 2:
                if (num_entries == 0) {
                    printf("No entries to remove.\n");
                } else {
                    remove_entry(entries, num_entries);
                }
                break;
            case 3:
                if (num_entries == 0) {
                    printf("No entries.\n");
                } else {
                    display_entries(entries, num_entries);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}