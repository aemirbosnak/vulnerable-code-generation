//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAMES 100
#define MAX_NUMBERS 20
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS][MAX_NUMBER_LENGTH];
    int num_numbers;
} contact;

void add_contact(contact *phonebook) {
    char name[MAX_NAME_LENGTH];
    int num_numbers = 0;
    printf("Enter name: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        char number[MAX_NUMBER_LENGTH];
        printf("Enter number %d: ", i+1);
        scanf("%s", number);
        if (strlen(number) > 0) {
            strcpy(phonebook->numbers[num_numbers], number);
            num_numbers++;
        }
    }
    strcpy(phonebook->name, name);
    phonebook->num_numbers = num_numbers;
}

void search_contact(contact *phonebook) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < MAX_NAMES; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            for (int j = 0; j < phonebook[i].num_numbers; j++) {
                printf("Number %d: %s\n", j+1, phonebook[i].numbers[j]);
            }
        }
    }
}

int main() {
    contact phonebook[MAX_NAMES];
    int num_contacts = 0;

    while (num_contacts < MAX_NAMES) {
        printf("1. Add contact\n2. Search contact\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(&phonebook[num_contacts]);
                num_contacts++;
                break;
            case 2:
                search_contact(phonebook);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}