//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry;

int main() {
    entry phonebook[MAX_ENTRIES];
    int num_entries = 0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        system("clear");
        printf("Phonebook\n");
        printf("--------\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("\n");

        int choice_num;
        scanf("%d", &choice_num);

        switch (choice_num) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Phonebook is full.\n");
                } else {
                    printf("Enter name (up to 50 characters): ");
                    scanf("%s", phonebook[num_entries].name);
                    printf("Enter phone number (up to 15 characters): ");
                    scanf("%s", phonebook[num_entries].phone);
                    num_entries++;
                    printf("Entry added.\n");
                }
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                int found = 0;
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(phonebook[i].name, search_name) == 0) {
                        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                printf("Phonebook:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
                }
                break;
            case 4:
                choice = 'n';
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}