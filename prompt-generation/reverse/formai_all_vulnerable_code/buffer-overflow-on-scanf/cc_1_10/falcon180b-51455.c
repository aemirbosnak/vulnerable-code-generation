//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i = 0;
    while (i < num_entries) {
        if (strcasecmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].number);
            break;
        }
        i++;
    }
}

void delete_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    int i = 0;
    while (i < num_entries) {
        if (strcasecmp(phonebook[i].name, search_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].number, phonebook[j+1].number);
            }
            num_entries--;
            break;
        }
        i++;
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
    } while(choice!= 4);

    return 0;
}