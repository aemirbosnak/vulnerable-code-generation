//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
    char name[50];
    char phone[15];
} Contact;

typedef struct PhoneBook{
    Contact contacts[100];
    int size;
} PhoneBook;

void addContact(PhoneBook* phonebook){
    Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    phonebook->contacts[phonebook->size] = newContact;
    phonebook->size++;
    printf("Contact added successfully!\n\n");
}

void searchContact(PhoneBook* phonebook){
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    for(int i=0; i<phonebook->size; i++){
        if(strcmp(searchName, phonebook->contacts[i].name) == 0){
            printf("Name: %s\nPhone number: %s\n\n", phonebook->contacts[i].name, phonebook->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found\n\n");
}

void printPhonebook(PhoneBook* phonebook){
    if(phonebook->size == 0){
        printf("Phone book is empty\n\n");
        return;
    }
    printf("---------- Phone Book ----------\n");
    for(int i=0; i<phonebook->size; i++){
        printf("Name: %s\nPhone number: %s\n", phonebook->contacts[i].name, phonebook->contacts[i].phone);
    }
    printf("--------------------------------\n\n");
}

int main(){
    PhoneBook phonebook;
    phonebook.size = 0;
    int choice;
    while(1){
        printf("---------- Phone Book Menu ----------\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Print phone book\n");
        printf("4. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addContact(&phonebook);
                    break;
            case 2: searchContact(&phonebook);
                    break;
            case 3: printPhonebook(&phonebook);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n\n");
        }
    }
    return 0;
}