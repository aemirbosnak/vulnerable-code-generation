//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact_info {
    char name[50];
    char phone_number[12];
};

int main() {
    int choice, count = 0, max_count = 100;
    struct contact_info *contacts = (struct contact_info *)malloc(sizeof(struct contact_info) * max_count);

    printf("Welcome to your Phone Book!\n");

    while(1) {
        printf("\n\nWhat would you like to do?\n\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Update an existing contact\n");
        printf("4. Delete a contact\n");
        printf("5. Search contacts\n");
        printf("6. Exit\n\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n\nEnter the name of the contact : ");
                scanf("%s", contacts[count].name);

                printf("Enter the phone number of the contact : ");
                scanf("%s", contacts[count].phone_number);

                printf("\n\nContact added successfully!\n\n");

                count++;

                if(count == max_count) {
                    max_count += 10;
                    contacts = (struct contact_info *)realloc(contacts, sizeof(struct contact_info) * max_count);
                }

                break;

            case 2:
                if(count == 0) {
                    printf("\n\nYour Phone Book is empty!\n\n");
                    break;
                }

                printf("\n\nYour contacts:\n\n");

                printf("Name\t\tPhone Number\n");

                for(int i = 0; i < count; i++) {
                    printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone_number);
                }

                break;

            case 3:
                if(count == 0) {
                    printf("\n\nYour Phone Book is empty!\n\n");
                    break;
                }

                printf("\n\nEnter the name of the contact you want to update : ");
                char name_to_update[50];
                scanf("%s", name_to_update);

                int found = 0;

                for(int i = 0; i < count; i++) {
                    if(strcmp(name_to_update, contacts[i].name) == 0) {
                        printf("\n\nEnter the new phone number for %s : ", name_to_update);
                        scanf("%s", contacts[i].phone_number);
                        printf("\n\nContact updated successfully!\n\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("\n\nContact not found!\n\n");
                }

                break;

            case 4:
                if(count == 0) {
                    printf("\n\nYour Phone Book is empty!\n\n");
                    break;
                }

                printf("\n\nEnter the name of the contact you want to delete : ");
                char name_to_delete[50];
                scanf("%s", name_to_delete);

                int index_to_delete = -1;

                for(int i = 0; i < count; i++) {
                    if(strcmp(name_to_delete, contacts[i].name) == 0) {
                        index_to_delete = i;
                        break;
                    }
                }

                if(index_to_delete == -1) {
                    printf("\n\nContact not found!\n\n");
                } else {
                    for(int i = index_to_delete; i < count - 1; i++) {
                        contacts[i] = contacts[i+1];
                    }
                    count--;
                    printf("\n\nContact deleted successfully!\n\n");
                }

                break;

            case 5:
                if(count == 0) {
                    printf("\n\nYour Phone Book is empty!\n\n");
                    break;
                }

                printf("\n\nEnter the name of the contact you want to search : ");
                char name_to_search[50];
                scanf("%s", name_to_search);

                int found_contact = 0;

                for(int i = 0; i < count; i++) {
                    if(strcmp(name_to_search, contacts[i].name) == 0) {
                        printf("\n\n%s\t\t%s\n\n", contacts[i].name, contacts[i].phone_number);
                        found_contact = 1;
                    }
                }

                if(!found_contact) {
                    printf("\n\nNo contacts found with the name %s\n\n", name_to_search);
                }

                break;

            case 6:
                printf("\n\nThank you for using your Phone Book!\n\n");
                free(contacts);
                exit(0);

            default:
                printf("\n\nInvalid choice!\n\n");
                break;
        }

    }
    return 0;
}