//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: imaginative
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
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void search_entry(void) {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i = 0;
    while (i < num_entries) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            break;
        }
        i++;
    }
}

void delete_entry(void) {
    char name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", name);

    int i = 0;
    while (i < num_entries) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                memcpy(&phonebook[j], &phonebook[j + 1], sizeof(entry_t));
            }
            num_entries--;
            break;
        }
        i++;
    }
}

void print_entries(void) {
    int i = 0;
    while (i < num_entries) {
        printf("Name: %s\nNumber: %s\n---\n", phonebook[i].name, phonebook[i].number);
        i++;
    }
}

int main(void) {
    int choice;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Print entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
            print_entries();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}