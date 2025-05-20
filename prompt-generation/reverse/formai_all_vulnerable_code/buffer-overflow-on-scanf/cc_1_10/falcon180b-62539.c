//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

void add_entry(Entry entries[], int num_entries) {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("Enter number: ");
    fgets(number, MAX_NUMBER_LEN, stdin);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);

    num_entries++;
}

void display_entries(Entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

void search_entries(Entry entries[], int num_entries, char search_name[]) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("%s - %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        char choice;
        printf("Choose an option:\n1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_entry(entries, num_entries);
                break;
            case '2':
                display_entries(entries, num_entries);
                break;
            case '3':
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LEN];
                fgets(search_name, MAX_NAME_LEN, stdin);
                search_entries(entries, num_entries, search_name);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}