//FormAI DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone{
    char name[30];
    char number[11];
};

int main(){
    struct phone phonebook[100];
    int choice = 0, n = 0, i;
    char search_name[30], delete_name[30];

    printf("Welcome to the Phonebook Puzzle Program\n");

    while (choice != 5){
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Edit a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nEnter name: ");
                scanf("%s", phonebook[n].name);
                printf("Enter number: ");
                scanf("%s", phonebook[n].number);
                printf("Contact added!");
                n++;
                break;

            case 2:
                printf("\nEnter name to search for: ");
                scanf("%s", search_name);
                for (i = 0; i < n; i++){
                    if (strcmp(phonebook[i].name, search_name) == 0){
                        printf("\n%s's number is: %s\n", phonebook[i].name, phonebook[i].number);
                        break;
                    }
                }

                if (i == n){
                    printf("\n%s not found in phonebook.\n", search_name);
                }
                break;

            case 3:
                printf("\nEnter name to edit: ");
                scanf("%s", search_name);
                for (i = 0; i < n; i++){
                    if (strcmp(phonebook[i].name, search_name) == 0){
                        printf("\nEnter new name: ");
                        scanf("%s", phonebook[i].name);
                        printf("Enter new number: ");
                        scanf("%s", phonebook[i].number);
                        printf("\n%s's contact is updated.\n", search_name);
                        break;
                    }
                }
                if (i == n){
                    printf("\n%s not found in the phonebook.\n", search_name);
                }
                break;

            case 4:
                printf("\nEnter name to delete: ");
                scanf("%s", delete_name);
                for (i = 0; i < n; i++){
                    if (strcmp(phonebook[i].name, delete_name) == 0){
                        strcpy(phonebook[i].name, phonebook[n-1].name);
                        strcpy(phonebook[i].number, phonebook[n-1].number);
                        printf("\n%s's contact is deleted.\n", delete_name);
                        n--;
                        break;
                    }
                }
                if (i == n){
                    printf("\n%s not found in the phonebook.\n", delete_name);
                }
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}