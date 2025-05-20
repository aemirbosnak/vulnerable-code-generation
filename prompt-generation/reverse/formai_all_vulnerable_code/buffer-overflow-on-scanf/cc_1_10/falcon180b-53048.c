//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure of a contact
typedef struct contact{
    char name[50];
    int phone_number;
    char email[100];
}contact;

//Function to add a new contact to the phone book
void add_contact(contact phonebook[], int size, int index){
    printf("Enter the name of the contact: ");
    scanf("%s",&phonebook[index].name);
    printf("Enter the phone number of the contact: ");
    scanf("%d",&phonebook[index].phone_number);
    printf("Enter the email of the contact: ");
    scanf("%s",&phonebook[index].email);
    printf("\nContact added successfully!\n");
}

//Function to display all the contacts in the phone book
void display_contacts(contact phonebook[], int size){
    printf("\nPhone Book:\n");
    for(int i=0;i<size;i++){
        printf("%d. %s - %d - %s\n",i+1,phonebook[i].name,phonebook[i].phone_number,phonebook[i].email);
    }
}

//Function to search for a contact in the phone book
void search_contact(contact phonebook[], int size){
    char search_name[50];
    printf("\nEnter the name of the contact to search: ");
    scanf("%s",&search_name);
    for(int i=0;i<size;i++){
        if(strcmp(phonebook[i].name,search_name)==0){
            printf("\nContact found:\n");
            printf("%s - %d - %s\n",phonebook[i].name,phonebook[i].phone_number,phonebook[i].email);
        }
    }
    if(strcmp(search_name,"")==0){
        printf("\nNo contact found.\n");
    }
}

//Main function
int main(){
    contact phonebook[100]; //Initializing the phone book with 100 contacts
    int size=0; //Initializing the size of the phone book to 0
    int choice; //Variable to store the user's choice
    do{
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the size of the phone book (1-100): ");
                scanf("%d",&size);
                for(int i=0;i<size;i++){
                    add_contact(phonebook,size,i);
                }
                break;
            case 2:
                display_contacts(phonebook,size);
                break;
            case 3:
                search_contact(phonebook,size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!=4);
    return 0;
}