//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000 // Maximum Contacts that can be stored in the Phone Book

// Structure to hold the contact information
struct Contact{
    char firstName[20];
    char lastName[20];
    char phoneNumber[11];
} contacts[max];

int count = 0; // To keep the track of number of Contacts in the phone book

// Function prototype declarations
void addContact();
void deleteContact();
void searchContact();
void displayAllContacts();
void displayContactDetails(struct Contact);

int main(){
    int choice;
    printf("\n Welcome to the Phone Book program!\n");
    while(1){
        printf("\nPress 1 to add a contact\n");
        printf("Press 2 to delete a contact\n");
        printf("Press 3 to search a contact\n");
        printf("Press 4 to display all contacts\n");
        printf("Press 5 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                displayAllContacts();
                break;
            case 5:
                printf("\nThank you for using the Phone Book program!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid Choice! Please enter a valid choice between 1 to 5.\n");
                break;
        }
    }
    return 0;
}

// Function to add a new contact to the phone book
void addContact(){
    if(count == max){
        printf("\nSorry! The Phone Book is Full. You cannot add more contacts.\n");
        return;
    }
    else{
        printf("\nEnter the details of the new contact:\n");
        printf("First Name: ");
        scanf("%s", contacts[count].firstName);
        printf("Last Name: ");
        scanf("%s", contacts[count].lastName);
        printf("Phone Number: ");
        scanf("%s", contacts[count].phoneNumber);
        printf("\nContact Added Successfully!\n");
        count++;
    }
}

// Function to delete an existing contact from the phone book
void deleteContact(){
    char phone[11];
    int i, j, flag=0;
    if(count == 0){
        printf("\nSorry! There are no Contacts in the Phone Book to delete.\n");
        return;
    }
    else{
        printf("\nEnter the Phone Number of the Contact to be deleted: ");
        scanf("%s", phone);
        for(i=0; i<count; i++){
            if(strcmp(phone, contacts[i].phoneNumber) == 0){
                flag = 1;
                printf("\nDetails of the Contact to be deleted:\n");
                displayContactDetails(contacts[i]);
                for(j=i; j<count-1; j++){
                    strcpy(contacts[j].firstName, contacts[j+1].firstName);
                    strcpy(contacts[j].lastName, contacts[j+1].lastName);
                    strcpy(contacts[j].phoneNumber, contacts[j+1].phoneNumber);
                }
                count--;
                printf("\nContact Deleted Successfully!\n");
                break;
            }
        }
        if(flag == 0){
            printf("\nSorry! No Contact found with the given Phone Number.\n");
            return;
        }
    }
}

// Function to search for a contact in the phone book
void searchContact(){
    char phone[11];
    int i, flag=0;
    if(count == 0){
        printf("\nSorry! There are no Contacts in the Phone Book to search.\n");
        return;
    }
    else{
        printf("\nEnter the Phone Number of the Contact to be searched: ");
        scanf("%s", phone);
        for(i=0; i<count; i++){
            if(strcmp(phone, contacts[i].phoneNumber) == 0){
                flag = 1;
                printf("\nDetails of the Contact found:\n");
                displayContactDetails(contacts[i]);
                break;
            }
        }
        if(flag == 0){
            printf("\nSorry! No Contact found with the given Phone Number.\n");
            return;
        }
    }
}

// Function to display all the contacts in the phone book
void displayAllContacts(){
    int i;
    if(count == 0){
        printf("\nSorry! There are no Contacts in the Phone Book to display.\n");
        return;
    }
    else{
        printf("\nList of all Contacts:\n");
        for(i=0; i<count; i++){
            displayContactDetails(contacts[i]);
            printf("------------------------------------------\n");
        }
    }
}

// Function to display the details of a contact
void displayContactDetails(struct Contact contact){
    printf("\nFirst Name: %s\n", contact.firstName);
    printf("Last Name: %s\n", contact.lastName);
    printf("Phone Number: %s\n", contact.phoneNumber);
}