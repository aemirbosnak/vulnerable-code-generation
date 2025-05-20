//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_ENTRY 3
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_ENTRY][20];
    int num_numbers;
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    int i = 0;
    while (i < MAX_NUMBERS_PER_ENTRY && phonebook[num_entries].num_numbers < MAX_NUMBERS_PER_ENTRY) {
        printf("Enter phone number %d: ", i + 1);
        scanf("%s", phonebook[num_entries].numbers[i]);
        i++;
    }
    phonebook[num_entries].num_numbers = i;
    num_entries++;
}

void search_entry() {
    printf("Enter name to search: ");
    char search_name[MAX_NAME_LENGTH];
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", phonebook[i].name);
            int j;
            for (j = 0; j < phonebook[i].num_numbers; j++) {
                printf("Phone number %d: %s\n", j + 1, phonebook[i].numbers[j]);
            }
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Quit\n");
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}