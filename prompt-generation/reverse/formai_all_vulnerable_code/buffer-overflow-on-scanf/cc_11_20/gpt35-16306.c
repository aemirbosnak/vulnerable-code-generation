//FormAI DATASET v1.0 Category: Phone Book ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//creating structure for storing phonebook contacts
struct contacts{
    char name[50];
    long int phone_no;
    char email[100];
}contact[100];

int main(){
    int option;
    int count = 0;

    while(1){
        printf("Welcome to MyPhoneBook. Please select an option.\n");
        printf("1. Add a contact\n");
        printf("2. View contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch(option){
            case 1:{
                printf("Enter contact name: ");
                scanf(" %[^\n]", contact[count].name);
                printf("Enter phone number: ");
                scanf("%ld", &contact[count].phone_no);
                printf("Enter email address: ");
                scanf(" %[^\n]", contact[count].email);

                printf("\nContact successfully added!\n");

                count++;
                break;
            }
            
            case 2:{
                printf("Your Contacts:\n");
                printf("****************\n");
                for(int i=0; i<count; i++){
                    printf("%d. Name: %s\n", i+1, contact[i].name);
                    printf("   Phone: %ld\n", contact[i].phone_no);
                    printf("   Email: %s\n", contact[i].email);
                    printf("\n");
                }
                break;
            }

            case 3:{
                char search[50];
                int flag = 0;

                printf("Enter name to search: ");
                scanf(" %[^\n]", search);

                for(int i=0; i<count; i++){
                    if(strcmp(search, contact[i].name) == 0){
                        printf("Name: %s\n", contact[i].name);
                        printf("Phone: %ld\n", contact[i].phone_no);
                        printf("Email: %s\n", contact[i].email);
                        printf("\n");

                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    printf("No contact found!\n");
                }
                break;
            }

            case 4:{
                char delete_name[50];
                int flag = 0;

                printf("Enter name to delete: ");
                scanf(" %[^\n]", delete_name);

                for(int i=0; i<count; i++){
                    if(strcmp(delete_name, contact[i].name) == 0){
                        for(int j=i; j<count-1; j++){
                            strcpy(contact[j].name, contact[j+1].name);
                            contact[j].phone_no = contact[j+1].phone_no;
                            strcpy(contact[j].email, contact[j+1].email);
                        }
                        count--;
                        flag = 1;
                        printf("\nContact deleted successfully!\n");
                        break;
                    }
                }

                if(flag == 0){
                    printf("No contact found!\n");
                }
                break;
            }

            case 5:{
                printf("Thank you for using MyPhoneBook!\n");
                exit(0);
            }

            default:{
                printf("Invalid option! Please try again.\n");
            }
        }
    }

    return 0;
}