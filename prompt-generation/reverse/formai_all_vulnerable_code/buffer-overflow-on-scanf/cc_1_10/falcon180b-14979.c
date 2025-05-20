//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void remove_entry() {
    int i = 0;
    while (i < num_entries) {
        printf("%s\n", phonebook[i].name);
        i++;
    }
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice >= 0 && choice < num_entries) {
        memmove(&phonebook[choice], &phonebook[choice + 1], sizeof(entry) * (num_entries - choice - 1));
        num_entries--;
    } else {
        printf("Invalid choice.\n");
    }
}

void search_entry() {
    char search[50];
    printf("Enter name to search: ");
    scanf("%s", search);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(phonebook[i].name, search) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
        }
        i++;
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Remove entry\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                remove_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}