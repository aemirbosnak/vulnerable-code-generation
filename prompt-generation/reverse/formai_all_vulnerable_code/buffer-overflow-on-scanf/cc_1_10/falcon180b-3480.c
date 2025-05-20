//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[100];
    char phone[20];
} contact;

int main() {
    contact phonebook[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the Surrealist Phonebook!\n");

    while (1) {
        printf("\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Phonebook is full!\n");
            } else {
                printf("Enter name: ");
                scanf("%s", phonebook[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", phonebook[num_entries].phone);
                num_entries++;
            }
            break;

        case 2:
            printf("Enter name to search for: ");
            char search_name[100];
            scanf("%s", search_name);

            for (int i = 0; i < num_entries; i++) {
                if (strcmp(search_name, phonebook[i].name) == 0) {
                    printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
                }
            }
            break;

        case 3:
            printf("\n");
            for (int i = 0; i < num_entries; i++) {
                printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
            }
            break;

        case 4:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}