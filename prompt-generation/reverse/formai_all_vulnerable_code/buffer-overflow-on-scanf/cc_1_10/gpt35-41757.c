//FormAI DATASET v1.0 Category: Phone Book ; Style: puzzling
#include<stdio.h>
#include<string.h>
#define MAX_CONTACTS 20

struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    printf("Welcome to the Phone Book!\n");
    int numContacts = 0;
    struct Contact contacts[MAX_CONTACTS];
    char selection;
    do{
        printf("Enter 'A' to add a contact\nEnter 'S' to search contacts\nEnter 'Q' to quit\n");
        scanf(" %c", &selection);
        switch(selection){
            case 'A':
                if(numContacts == MAX_CONTACTS){
                    printf("Phone book is full.\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", contacts[numContacts].name);
                printf("Enter phone number: ");
                scanf("%s", contacts[numContacts].phone);
                printf("Contact added!\n");
                numContacts++;
                break;
            case 'S':
                printf("Enter name to search: ");
                char searchName[50];
                scanf("%s", searchName);
                int searchIndex = -1;
                for(int i=0;i<numContacts;i++){
                    if(strcmp(searchName, contacts[i].name) == 0){
                        searchIndex = i;
                        break;
                    }
                }
                if(searchIndex == -1){
                    printf("Contact not found.\n");
                } else {
                    printf("Name: %s\nPhone: %s\n", contacts[searchIndex].name, contacts[searchIndex].phone);
                }
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection.\n");
        }
    }while(selection != 'Q');
    return 0;
}