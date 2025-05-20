//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void search_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(phonebook[i].name, 0, strlen(phonebook[i].name));
            memset(phonebook[i].number, 0, strlen(phonebook[i].number));

            printf("Entry deleted.\n");
            num_entries--;

            return;
        }
    }

    printf("Entry not found.\n");
}

void print_phonebook() {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;

    system("clear");
    printf("Phonebook\n");

    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Print phonebook\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);

            printf("Enter number: ");
            char number[MAX_NUM_LEN];
            scanf("%s", number);

            add_entry(name, number);
            break;

        case 2:
            printf("Enter name to search: ");
            char search_name[MAX_NAME_LEN];
            scanf("%s", search_name);

            search_entry(search_name);
            break;

        case 3:
            printf("Enter name to delete: ");
            char delete_name[MAX_NAME_LEN];
            scanf("%s", delete_name);

            delete_entry(delete_name);
            break;

        case 4:
            print_phonebook();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}