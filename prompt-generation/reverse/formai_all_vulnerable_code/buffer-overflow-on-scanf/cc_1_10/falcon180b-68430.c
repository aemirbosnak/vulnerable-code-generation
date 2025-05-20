//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void view_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    printf("Name: %s\n", phonebook[index].name);
    printf("Number: %s\n", phonebook[index].number);
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < num_entries - 1; i++) {
        strcpy(phonebook[i].name, phonebook[i + 1].name);
        strcpy(phonebook[i].number, phonebook[i + 1].number);
    }

    num_entries--;
}

int search_entry(char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    int choice;

    do {
        printf("\nPhonebook:\n");
        printf("1. Add entry\n");
        printf("2. View entry\n");
        printf("3. Delete entry\n");
        printf("4. Search entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;

        case 2:
            printf("Enter index: ");
            scanf("%d", &choice);
            view_entry(choice);
            break;

        case 3:
            printf("Enter index: ");
            scanf("%d", &choice);
            delete_entry(choice);
            break;

        case 4:
            printf("Enter name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);

            int index = search_entry(name);
            if (index!= -1) {
                view_entry(index);
            } else {
                printf("Entry not found.\n");
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}