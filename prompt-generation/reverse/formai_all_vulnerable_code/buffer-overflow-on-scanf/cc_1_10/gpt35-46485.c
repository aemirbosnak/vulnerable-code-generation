//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct{
    char name[20];
    char phone[15];
} contact;

void addContact(contact contacts[], int* numContacts){
    char name[20], phone[15];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    strcpy(contacts[*numContacts].name, name);
    strcpy(contacts[*numContacts].phone, phone);
    (*numContacts)++;
}

void displayContacts(contact contacts[], int numContacts){
    printf("%-20s%-15s\n", "Name", "Phone");
    for(int i=0; i<numContacts; i++){
        printf("%-20s%-15s\n", contacts[i].name, contacts[i].phone);
    }
}

int main(){
    contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    while(1){
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addContact(contacts, &numContacts);
                    break;
            case 2: displayContacts(contacts, numContacts);
                    break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}