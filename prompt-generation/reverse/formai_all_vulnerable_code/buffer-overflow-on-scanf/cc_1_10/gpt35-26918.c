//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializing the structure for Contacts
struct Contact{
    char name[20],
         phone_num[11],
         email_id[25];
} contacts[10];
int num_of_contacts = 0;

// Function Prototypes
void add_contact();
void view_contact();
void search_contact();
void delete_contact();

// Main Function
int main(){
    int choice;
    while(1){
        printf("\n***Welcome to the Contact Simulator***\n");
        printf("1. Add a New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search for a Contact\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_contact();
                    break;
            case 2: view_contact();
                    break;
            case 3: search_contact();
                    break;
            case 4: delete_contact();
                    break;
            case 5: printf("Thanks for using Contact Simulator\n");
                    exit(0);
                    break;
            default: printf("Invalid input, please enter again\n");
                     break;
        }
    }
    return 0;
}

// Function Definitions
void add_contact(){
    if(num_of_contacts == 10){
        printf("Contact list is full, Cannot add anymore\n");
        return;
    }
    printf("Enter Name of contact:\n");
    scanf("%s", contacts[num_of_contacts].name);
    printf("Enter Phone Number of contact:\n");
    scanf("%s", contacts[num_of_contacts].phone_num);
    printf("Enter Email-ID of contact:\n");
    scanf("%s", contacts[num_of_contacts].email_id);
    printf("Contact added successfully\n");
    num_of_contacts++;
}

void view_contact(){
    if(num_of_contacts == 0){
        printf("You have no contacts in your list\n");
        return;
    }
    printf("Contacts List:\n");
    for(int i=0; i<num_of_contacts; i++){
        printf("Name: %s\n", contacts[i].name);
        printf("Phone Number: %s\n", contacts[i].phone_num);
        printf("Email-ID: %s\n", contacts[i].email_id);
        printf("\n");
    }
}

void search_contact(){
    if(num_of_contacts == 0){
        printf("You have no contacts in your list\n");
        return;
    }
    char name[20];
    printf("Enter the Name of the contact you want to search:\n");
    scanf("%s", name);
    for(int i=0; i<num_of_contacts; i++){
        if(strcmp(name,contacts[i].name) == 0){
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_num);
            printf("Email-ID: %s\n", contacts[i].email_id);
            return;
        }
    }
    printf("Contact not found\n");
}

void delete_contact(){
    if(num_of_contacts == 0){
        printf("You have no contacts in your list\n");
        return;
    }
    char name[20];
    printf("Enter the Name of the contact you want to delete:\n");
    scanf("%s", name);
    for(int i=0; i<num_of_contacts; i++){
        if(strcmp(name,contacts[i].name) == 0){
            for(int j=i; j<num_of_contacts-1; j++){
                strcpy(contacts[j].name,contacts[j+1].name);
                strcpy(contacts[j].phone_num,contacts[j+1].phone_num);
                strcpy(contacts[j].email_id,contacts[j+1].email_id);
            }
            num_of_contacts--;
            printf("Contact deleted successfully\n");
            return;
        }
    }
    printf("Contact not found\n");
}