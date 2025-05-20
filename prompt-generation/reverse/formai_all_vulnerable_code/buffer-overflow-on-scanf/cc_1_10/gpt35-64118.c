//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // maximum number of contacts in the phone book

typedef struct{
    char name[30];
    char phone[15];
} Contact;

void addContact(Contact* book, int* count);
void searchContact(Contact* book, int count);
void deleteContact(Contact* book, int* count);

int main(){
    Contact phonebook[MAX_CONTACTS]; // an array of Contacts
    int count = 0; // current number of contacts

    printf("Welcome to My Phone Book\n");

    while(1){
        printf("\nChoose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addContact(phonebook, &count);
                break;
            
            case 2:
                searchContact(phonebook, count);
                break;

            case 3:
                deleteContact(phonebook, &count);
                break;

            case 4:
                printf("Exiting Phone Book...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addContact(Contact* book, int* count){
    if(*count >= MAX_CONTACTS){
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", book[*count].name);
    printf("Enter phone number: ");
    scanf("%s", book[*count].phone);
    printf("Contact added successfully.\n");

    (*count)++; // increment count by 1
}

void searchContact(Contact* book, int count){
    if(count == 0){
        printf("Phone book is empty.\n");
        return;
    }

    char name[30];
    printf("Enter name to search: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0; i<count; i++){
        if(strcmp(name, book[i].name) == 0){
            printf("Name: %s\nPhone Number: %s\n", book[i].name, book[i].phone);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Contact not found.\n");
}

void deleteContact(Contact* book, int* count){
    if(*count == 0){
        printf("Phone book is empty.\n");
        return;
    }

    char name[30];
    printf("Enter name to delete: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0; i<*count; i++){
        if(strcmp(name, book[i].name) == 0){
            // shift all contacts after this one back by one index
            for(int j=i+1; j<*count; j++){
                strcpy(book[j-1].name, book[j].name);
                strcpy(book[j-1].phone, book[j].phone);
            }

            (*count)--; // decrement count by 1
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Contact not found.\n");
}