//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100 //maximum size of phone book

struct Contact{
    char name[30]; //stores name
    char number[15]; //stores phone number
}phonebook[MAX_SIZE]; //declare an array of contacts to store phone book data

int num_contacts = 0; //stores the number of contacts currently in the phone book

//function to add a new contact to the phone book
void add_contact(){
    printf("\nEnter name: ");
    scanf("%s", phonebook[num_contacts].name); //read name
    
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_contacts].number); //read phone number
    
    num_contacts++; //increment number of contacts in phone book
    printf("\nContact added successfully!\n");
}

//function to display all contacts in the phone book
void display_contacts(){
    if(num_contacts == 0){ //if phone book is empty
        printf("\nPhone book is empty!\n");
        return;
    }
    printf("\n\n%-30s%s\n", "Name", "Number"); //header row
    for(int i = 0; i < num_contacts; i++){
        printf("%-30s%s\n", phonebook[i].name, phonebook[i].number); //display contact info
    }
}

//function to search for a contact by name
void search_contact(){
    if(num_contacts == 0){ //if phone book is empty
        printf("\nPhone book is empty!\n");
        return;
    }
    char name_to_find[30]; //stores name to search for
    int found = 0; //flag to indicate if contact was found or not
    
    printf("\nEnter name to search for: ");
    scanf("%s", name_to_find); //read name to search for
    
    for(int i = 0; i < num_contacts; i++){
        if(strcmp(phonebook[i].name, name_to_find) == 0){
            printf("\n%-30s%s\n", "Name", "Number"); //header row
            printf("%-30s%s\n", phonebook[i].name, phonebook[i].number); //display contact info
            found = 1; //contact found
            break;
        }
    }
    if(!found) printf("\nContact not found!\n"); //if contact not found
}

//main function
int main(){
    int choice;
    while(1){ //loop until user chooses to exit
        printf("\n\nC Phone Book\n");
        printf("============\n");
        printf("1. Add new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice); //read user's choice
        
        switch(choice){
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}