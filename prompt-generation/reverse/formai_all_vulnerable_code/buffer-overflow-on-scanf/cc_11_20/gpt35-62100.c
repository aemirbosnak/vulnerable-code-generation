//FormAI DATASET v1.0 Category: Phone Book ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact{
    char name[20];
    char phone[15];
    char email[30];
};

int main(){
    int choice = 0, count = 0, i, j;
    struct contact phonebook[100];
    char search[20];

    printf("\t\tWelcome to the Phone Book\n\n");

    while(choice != 6){
        printf("Please choose one of the following options:\n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Modify a contact\n");
        printf("5. Delete a contact\n");
        printf("6. Exit\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter name: ");
                scanf("%s", phonebook[count].name);

                printf("Enter phone number: ");
                scanf("%s", phonebook[count].phone);

                printf("Enter email address: ");
                scanf("%s", phonebook[count].email);

                count++;
                break;

            case 2:
                printf("\n%-20s %-15s %-30s\n\n", "Name", "Phone", "Email");

                for(i = 0; i < count; i++){
                    printf("%-20s %-15s %-30s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
                }

                printf("\n");
                break;

            case 3:
                printf("\nEnter the name to search for: ");
                scanf("%s", search);

                for(i = 0; i < count; i++){
                    if(strcmp(search, phonebook[i].name) == 0){
                        printf("\n%-20s %-15s %-30s\n\n", "Name", "Phone", "Email");
                        printf("%-20s %-15s %-30s\n\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
                        break;
                    }
                }

                if(i == count){
                    printf("\nContact not found!\n\n");
                }

                break;

            case 4:
                printf("\nEnter the name to modify: ");
                scanf("%s", search);

                for(i = 0; i < count; i++){
                    if(strcmp(search, phonebook[i].name) == 0){
                        printf("Enter new name: ");
                        scanf("%s", phonebook[i].name);

                        printf("Enter new phone number: ");
                        scanf("%s", phonebook[i].phone);

                        printf("Enter new email address: ");
                        scanf("%s", phonebook[i].email);

                        printf("\nContact modified successfully!\n\n");
                        break;
                    }
                }
                
                if(i == count){
                    printf("\nContact not found!\n\n");
                }

                break;

            case 5:
                printf("\nEnter the name to delete: ");
                scanf("%s", search);

                for(i = 0; i < count; i++){
                    if(strcmp(search, phonebook[i].name) == 0){
                        for(j = i; j < count - 1; j++){
                            strcpy(phonebook[j].name, phonebook[j+1].name);
                            strcpy(phonebook[j].phone, phonebook[j+1].phone);
                            strcpy(phonebook[j].email, phonebook[j+1].email);
                        }

                        count--;

                        printf("\nContact deleted successfully!\n\n");
                        break;
                    }
                }

                if(i == count){
                    printf("\nContact not found!\n\n");
                }

                break;

            case 6:
                printf("\nThank you for using the Phone Book. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}