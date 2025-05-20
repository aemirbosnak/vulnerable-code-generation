//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[20];
    int mystic_number;
} PhoneBookEntry;

PhoneBookEntry phone_book[MAX_ENTRIES];
int num_entries = 0;

int find_entry(char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_entry(char *name, char *number, int mystic_number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].number, number);
    phone_book[num_entries].mystic_number = mystic_number;
    num_entries++;
}

void display_entry(int index) {
    printf("Name: %s\n", phone_book[index].name);
    printf("Number: %s\n", phone_book[index].number);
    printf("Mystic Number: %d\n", phone_book[index].mystic_number);
}

void display_phone_book() {
    printf("---------------------------------------------------\n");
    printf("| Name           | Number         | Mystic Number |\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        display_entry(i);
    }
    printf("---------------------------------------------------\n");
}

int main() {
    char name[50], number[20];
    int mystic_number;
    int choice;
    char search_name[50];

    while (1) {
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display Phone Book\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                printf("Enter mystic number: ");
                scanf("%d", &mystic_number);
                add_entry(name, number, mystic_number);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", search_name);
                int index = find_entry(search_name);
                if (index != -1) {
                    display_entry(index);
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                display_phone_book();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}