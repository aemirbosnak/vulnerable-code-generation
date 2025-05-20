//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Declaring the structure for contact information*/

struct contacts {
    char name[50];
    char phone_num[20];
}contacts_info;

/*Declaring the file pointer*/

FILE *phone_book;

/*Function to add contact to the file*/

void add_contact() {
    printf("\nEnter the name:\n");
    scanf("%s", contacts_info.name);
    printf("Enter the phone number:\n");
    scanf("%s", contacts_info.phone_num);

    /*Open file in append mode*/

    phone_book = fopen("phonebook.txt", "a");

    /*Adding the record to the file*/

    fprintf(phone_book, "%s\t\t%s\n", contacts_info.name, contacts_info.phone_num);

    /*Close the file*/

    fclose(phone_book);

    printf("\nContact added successfully!\n");
}

/*Function to search for a contact in the file*/

void search_contact() {
    char name[50], line[100];

    printf("\nEnter the name to search:\n");
    scanf("%s", name);

    /*Open the file in read mode*/

    phone_book = fopen("phonebook.txt", "r");

    /*Search for the matching name in the file*/

    while(fgets(line, 100, phone_book) != NULL) {
        if(strstr(line, name) != NULL) {
            printf("%s", line);
            break;
        }
    }

    /*Close the file*/

    fclose(phone_book);
}

int main() {
    int choice;

    printf("\n********** Welcome to C Phone Book **********\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                printf("\nThank you for using C Phone Book!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}