//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct Contact {            // structure for contact information
    char name[MAX];
    char email[MAX];
};

int main() {
    int choice, i, count = 0;
    struct Contact list[MAX];   // array of structure to store contact info
    printf("Welcome to the Mailing List Manager \n");

    while(1) {                   // infinite loop until user exits
        printf("\nPlease select an option: \n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:                 // adding a contact
                if(count >= MAX) {
                    printf("Error: Mailing list is full\n");
                    break;
                }
                printf("\nEnter name: ");
                scanf("%s", list[count].name);
                printf("Enter email: ");
                scanf("%s", list[count].email);
                count++;
                printf("\nContact added successfully!\n");
                break;

            case 2:                // viewing all contacts
                if(count == 0) {
                    printf("\nNo contact found!\n");
                    break;
                }
                printf("\nList of contacts:\n");
                for(i = 0; i < count; i++) {
                    printf("%d. %s - %s\n", i+1, list[i].name, list[i].email);
                }
                break;

            case 3:                // searching for a contact
                if(count == 0) {
                    printf("\nNo contact found!\n");
                    break;
                }
                char search_name[MAX];
                printf("\nEnter name to search: ");
                scanf("%s", search_name);
                for(i=0; i<count; i++) {
                    if(strcmp(list[i].name, search_name) == 0) {
                        printf("\nContact found at index %d\n%s - %s\n", i+1, list[i].name, list[i].email);
                        break;
                    }
                }
                if(i == count)
                    printf("\nContact not found!");
                break;

            case 4:                // deleting a contact
                if(count == 0) {
                    printf("\nNo contact found!\n");
                    break;
                }
                char delete_name[MAX];
                int j;
                printf("\nEnter name to delete: ");
                scanf("%s", delete_name);
                for(i = 0; i < count; i++) {
                    if(strcmp(list[i].name, delete_name) == 0) {
                        printf("\nContact found at index %d\n%s - %s\n", i+1, list[i].name, list[i].email);
                        printf("Do you want to delete this contact? Press 1 to confirm deletion, 2 to cancel: ");
                        scanf("%d", &j);
                        if(j == 1) {
                            for(j = i; j < count-1; j++) {
                                strcpy(list[j].name, list[j+1].name);
                                strcpy(list[j].email, list[j+1].email);
                            }
                            count--;
                            printf("\nContact deleted successfully!\n");
                        }
                        break;
                    }
                }
                if(i == count)
                    printf("\nContact not found!");
                break;

            case 5:                // exiting the program
                printf("\nThank you for using Mailing List Manager!\n");
                exit(0);

            default:               // handling invalid choice
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    }

    return 0;
}