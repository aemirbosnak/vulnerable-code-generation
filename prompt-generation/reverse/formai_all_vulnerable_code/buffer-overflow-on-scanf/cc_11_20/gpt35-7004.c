//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include<stdio.h>
#include<string.h>

struct phonebook{
    char name[50];
    char number[15];
};

int main(){

    struct phonebook pb[100];
    int option = 0;
    int num_entries = 0;

    do{
        printf("Welcome to your Phone Book\n");
        printf("Please select an option:\n");
        printf("1. Add new entry\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        switch(option){

            case 1:
                printf("Please enter the contact name (max 50 characters): ");
                scanf("%s", pb[num_entries].name);

                printf("Please enter the contact number (max 15 digits): ");
                scanf("%s", pb[num_entries].number);

                printf("Contact added successfully!\n");
                num_entries++;
                break;

            case 2:
                printf("Please enter the name of the contact you are looking for: ");
                char search_name[50];
                scanf("%s", search_name);

                int i;
                int found_flag = 0;
                for(i = 0; i < num_entries; i++){
                    if(strcmp(pb[i].name, search_name) == 0){
                        printf("Name: %s\n", pb[i].name);
                        printf("Number: %s\n", pb[i].number);
                        found_flag = 1;
                        break;
                    }
                }
                if(found_flag == 0){
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                if(num_entries == 0){
                    printf("No contacts to display.\n");
                    break;
                }

                printf("Contacts:\n");
                for(i = 0; i < num_entries; i++){
                    printf("Name: %s\n", pb[i].name);
                    printf("Number: %s\n", pb[i].number);
                }
                break;

            case 4:
                printf("Thank you for using the Phone Book!\n");
                break;

            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }

    }while(option != 4);

    return 0;
}