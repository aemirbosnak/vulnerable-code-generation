//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PhoneBook {
    char name[30];
    long int number;
}contact[100];

int main() {
    int i, n, choice,j;
    char searchName[30], delName[30];

    printf("\nHow many contacts you want to store? ");
    scanf("%d", &n);
    fflush(stdin);

    for (i = 0; i < n; i++) {
        printf("\nName: ");
        gets(contact[i].name);
        printf("Number: ");
        scanf("%ld", &contact[i].number);
        fflush(stdin);
    }

    printf("\n\n\t\tPhonebook\n\n");

    while (choice != 5) {
        printf("\n1. Search contact\n2. Delete contact\n3. Add contact\n4. Display all contacts\n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("\nEnter name to search: ");
                gets(searchName);

                for (i = 0; i < n; i++) {
                    if (strcmp(contact[i].name, searchName) == 0) {
                        printf("\nContact information of %s:\nNumber: %ld\n\n", contact[i].name, contact[i].number);
                        break;
                    }
                }

                if (i == n) {
                    printf("\nContact not found!\n");
                }
                break;

            case 2:
                printf("\nEnter name to delete: ");
                gets(delName);

                for (i = 0; i < n; i++) {
                    if (strcmp(contact[i].name, delName) == 0) {
                        printf("\nDeleted contact information:\nName: %s , Number: %ld\n\n", contact[i].name, contact[i].number);

                        for (j = i; j < n - 1; j++) {
                            strcpy(contact[j].name, contact[j + 1].name);
                            contact[j].number = contact[j + 1].number;
                        }
                        n--;
                        break;
                    }
                }

                if (i == n) {
                    printf("\nContact not found!\n");
                }
                break;

            case 3:
                printf("\nName: ");
                gets(contact[n].name);
                printf("Number: ");
                scanf("%ld", &contact[n].number);
                fflush(stdin);
                n++;
                printf("\nContact added successfully!\n");
                break;

            case 4:
                printf("\nContacts:\n\n");

                for (i = 0; i < n; i++) {
                    printf("%d. Name: %s\n   Number: %ld\n\n", i + 1, contact[i].name, contact[i].number);
                }
                break;

            case 5:
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}