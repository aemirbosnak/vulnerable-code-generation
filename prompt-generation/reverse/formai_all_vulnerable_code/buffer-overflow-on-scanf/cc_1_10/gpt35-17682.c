//FormAI DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CONTACTS 100
typedef struct contact{
    char name[30];
    char phone_number[15];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact(){
    if(num_contacts >= MAX_CONTACTS){
        printf("Phone book is full!\n");
        return;
    }
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone_number);
    contacts[num_contacts++] = new_contact;
    printf("Contact added successfully!\n");
}

void search_contact(){
    printf("Enter name to search: ");
    char name[30];
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<num_contacts; i++){
        if(strcmp(contacts[i].name,name)==0){
            printf("Name: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone_number);
            found = 1;
        }
    }
    if(!found){
        printf("Contact not found!\n");
    }
}

void delete_contact(){
    printf("Enter name to delete: ");
    char name[30];
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<num_contacts; i++){
        if(strcmp(contacts[i].name,name)==0){
            for(int j=i; j<num_contacts-1; j++){
                contacts[j] = contacts[j+1];
            }
            num_contacts--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Contact not found!\n");
    }
}

void display_contacts(){
    if(num_contacts == 0){
        printf("Phone book is empty!\n");
        return;
    }
    for(int i=0; i<num_contacts; i++){
        printf("Name: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone_number);
    }   
}

int main(){
    int choice;
    do{
        printf("\n-----Menu-----\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Display All Contacts\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_contact(); break;
            case 2: search_contact(); break;
            case 3: delete_contact(); break;
            case 4: display_contacts(); break;
            case 5: printf("Exiting..."); break;
            default: printf("Invalid choice!\n"); break;
        }
    }while(choice!=5);
    return 0;
}