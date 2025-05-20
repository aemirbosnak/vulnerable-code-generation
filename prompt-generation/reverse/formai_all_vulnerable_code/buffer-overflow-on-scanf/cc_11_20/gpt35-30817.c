//FormAI DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10
#define MAX_RECORDS 25

struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

int main() {
    struct PhoneBookEntry phonebook[MAX_RECORDS];
    int numRecords = 0;

    printf("Welcome to my Statistical Phone Book program!\n");

    while (1) {
        printf("\nMENU: \n");
        printf("1. Add a New Entry\n");
        printf("2. Search for an Entry\n");
        printf("3. Display All Entries\n");
        printf("4. Quit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numRecords == MAX_RECORDS) {
                    printf("Phone Book is full! Cannot add more entries.\n");
                    break;
                }

                printf("\nEnter name (max %d characters): ", MAX_NAME_LENGTH - 1);
                scanf("%s", phonebook[numRecords].name);

                printf("Enter phone number (max %d characters): ", MAX_PHONE_LENGTH - 1);
                scanf("%s", phonebook[numRecords].phone);

                numRecords++;
                printf("\nNew entry added successfully!\n");

                break;

            case 2:
                printf("\nEnter name to search: ");
                char searchName[MAX_NAME_LENGTH];
                scanf("%s", searchName);

                int found = 0;

                for (int i = 0; i < numRecords; i++) {
                    if (strcmp(phonebook[i].name, searchName) == 0) {
                        printf("\n%s:\t%s\n", phonebook[i].name, phonebook[i].phone);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("\nNo record found for %s\n", searchName);
                }

                break;

            case 3:
                if (numRecords == 0) {
                    printf("\nPhone Book is empty!\n");
                    break;
                }

                printf("\n%-20s\t%-10s\n", "NAME", "PHONE");
                printf("------------------------------------------------------\n");

                for (int i = 0; i < numRecords; i++) {
                    printf("%-20s\t%-10s\n", phonebook[i].name, phonebook[i].phone);
                }

                break;

            case 4:
                printf("\nThank you for using my program! Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}