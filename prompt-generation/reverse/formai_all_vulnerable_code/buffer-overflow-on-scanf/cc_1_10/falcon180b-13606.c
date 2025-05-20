//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

void add_entry(entry_t entries[], int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry(entry_t entries[], int num_entries, char search_name[]) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void delete_entry(entry_t entries[], int num_entries, char search_name[]) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            num_entries--;
            break;
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    srand(time(NULL));

    do {
        printf("Phone book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_entry(entries, num_entries);
                break;
            case '2':
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LEN];
                scanf("%s", search_name);
                search_entry(entries, num_entries, search_name);
                break;
            case '3':
                printf("Enter name to delete: ");
                char del_name[MAX_NAME_LEN];
                scanf("%s", del_name);
                delete_entry(entries, num_entries, del_name);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= '4');

    return 0;
}