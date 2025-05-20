//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_ADDRESS 100
#define MAX_EMAIL 100
#define MAX_PHONE 12

struct Contact {
    char name[MAX_NAME];
    char address[MAX_ADDRESS];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
};

int main() {
    struct Contact *database;
    int num_contacts, choice, index;
    char search_name[MAX_NAME];
    FILE *fp;

    printf("Welcome to the Contact Database!\n");

    printf("Enter the number of contacts you would like to add: ");
    scanf("%d", &num_contacts);

    database = (struct Contact*) malloc(num_contacts * sizeof(struct Contact));

    for (int i = 0; i < num_contacts; i++) {
        printf("\nContact %d\n", i+1);

        printf("Name:");
        scanf("%s", database[i].name);

        printf("Address:");
        scanf("%s", database[i].address);

        printf("Email:");
        scanf("%s", database[i].email);

        printf("Phone:");
        scanf("%s", database[i].phone);
    }

    printf("\nDatabase successfully created!\n");

    fp = fopen("contacts.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    for (int i = 0; i < num_contacts; i++) {
        fprintf(fp, "%s|%s|%s|%s\n", database[i].name, database[i].address, database[i].email, database[i].phone);
    }

    fclose(fp);

    printf("\nDatabase successfully saved to file!\n");

    printf("\nWhat would you like to do now?\n");
    printf("1. Search for a contact\n");
    printf("2. Add a new contact\n");
    printf("3. Exit\n");
    printf("\nEnter your choice:");
    scanf("%d", &choice);

    while (choice != 3) {
        switch(choice) {
            case 1:
                printf("\nSearch for a contact\n");
                printf("Enter the name of the contact:");
                scanf("%s", search_name);

                index = -1; // initialize index to -1

                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(search_name, database[i].name) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nContact not found.\n");
                } else {
                    printf("\nContact found!\n");
                    printf("%s\n%s\n%s\n%s\n", database[index].name, database[index].address, database[index].email, database[index].phone);
                }

                break;
            case 2:
                num_contacts++; // increase the size of the database by 1

                database = (struct Contact*) realloc(database, num_contacts * sizeof(struct Contact));

                printf("\nContact %d\n", num_contacts);

                printf("Name:");
                scanf("%s", database[num_contacts-1].name);

                printf("Address:");
                scanf("%s", database[num_contacts-1].address);

                printf("Email:");
                scanf("%s", database[num_contacts-1].email);

                printf("Phone:");
                scanf("%s", database[num_contacts-1].phone);

                printf("\nNew contact added successfully!\n");

                fp = fopen("contacts.txt", "a");

                if (fp == NULL) {
                    printf("\nError opening file!");
                    exit(1);
                }

                fprintf(fp, "%s|%s|%s|%s\n", database[num_contacts-1].name, database[num_contacts-1].address, database[num_contacts-1].email, database[num_contacts-1].phone);

                fclose(fp);

                printf("\nDatabase successfully updated!\n");

                break;
            default:
                printf("\nInvalid choice. Try again!\n");
        }

        printf("\nWhat would you like to do now?\n");
        printf("1. Search for a contact\n");
        printf("2. Add a new contact\n");
        printf("3. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
    }

    printf("\nThank you for using the Contact Database!\n");

    free(database);

    return 0;
}