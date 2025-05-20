//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone_number[20];
};

int main() {
    int choice, count = 0;
    struct contact phone_book[100];

    while (1) {
        printf("*** C PHONE BOOK ***\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                if (count < 100) {
                    printf("Enter name: ");
                    fgets(phone_book[count].name, 50, stdin);
                    phone_book[count].name[strcspn(phone_book[count].name, "\n")] = 0;

                    printf("Enter phone number: ");
                    fgets(phone_book[count].phone_number, 20, stdin);
                    phone_book[count].phone_number[strcspn(phone_book[count].phone_number, "\n")] = 0;

                    printf("Contact added successfully!\n\n");
                    count++;
                } else {
                    printf("Phone book is full!\n\n");
                }
                break;

            case 2:
                if (count > 0) {
                    char deletename[50];
                    int found = 0;
                    printf("Enter name to delete:");
                    fgets(deletename, 50, stdin);
                    deletename[strcspn(deletename, "\n")] = 0;

                    for (int i = 0; i < count; i++) {
                        if (strcmp(phone_book[i].name, deletename) == 0) {
                            found = 1;
                            for (int j = i; j < count - 1; j++) {
                                strcpy(phone_book[j].name, phone_book[j + 1].name);
                                strcpy(phone_book[j].phone_number, phone_book[j + 1].phone_number);
                            }
                            count--;
                            printf("%s deleted from phone book.\n\n", deletename);
                            break;
                        }
                    }

                    if (!found) {
                        printf("%s not found in phone book!\n\n", deletename);
                    }
                } else {
                    printf("Phone book is empty!\n\n");
                }
                break;

            case 3:
                if (count > 0) {
                    char searchname[50];
                    int found = 0;
                    printf("Enter name to search: ");
                    fgets(searchname, 50, stdin);
                    searchname[strcspn(searchname, "\n")] = 0;

                    for (int i = 0; i < count; i++) {
                        if (strcmp(phone_book[i].name, searchname) == 0) {
                            found = 1;
                            printf("%s - %s\n\n", phone_book[i].name, phone_book[i].phone_number);
                            break;
                        }
                    }

                    if (!found) {
                        printf("%s not found in phone book!\n\n", searchname);
                    }
                } else {
                    printf("Phone book is empty!\n\n");
                }
                break;

            case 4:
                if (count > 0) {
                    printf("All Contacts:\n\n");
                    for (int i = 0; i < count; i++) {
                        printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
                    }
                    printf("\n");
                } else {
                    printf("Phone book is empty!\n\n");
                }
                break;

            case 5:
                printf("Exiting Phone Book...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }

    return 0;
}