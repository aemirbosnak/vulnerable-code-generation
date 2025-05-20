//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(void) {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    printf("Enter name: ");
    scanf("%s", name);
    strncpy(phonebook[num_entries].name, name, MAX_NAME_LEN);

    printf("Enter number: ");
    scanf("%s", number);
    strncpy(phonebook[num_entries].number, number, MAX_NUMBER_LEN);

    num_entries++;
}

void search_entry(void) {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
        }
    }
}

void delete_entry(void) {
    char name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

int main(void) {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}