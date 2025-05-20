//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact{
    char name[100];
    char phone[20];
};

typedef struct contact Contact;

int totalContacts = 0;

void addContact(Contact *contacts){
    printf("\nName: ");
    scanf("%s", contacts[totalContacts].name);
    printf("Phone: ");
    scanf("%s", contacts[totalContacts].phone);
    totalContacts++;
    printf("Contact added successfully!\n");
}

void searchContact(Contact *contacts){
    char name[100];
    printf("\nEnter the name to search: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<totalContacts; i++){
        if(strcmp(name, contacts[i].name)==0){
            printf("\nName: %s", contacts[i].name);
            printf("\nPhone: %s\n", contacts[i].phone);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nNo contact found with that name.\n");
    }
}

void showContacts(Contact *contacts){
    printf("\nContacts:\n");
    for(int i=0; i<totalContacts; i++){
        printf("\nName: %s", contacts[i].name);
        printf("\nPhone: %s\n", contacts[i].phone);
    }
}

int main(){
    int option;
    Contact contacts[100];
    printf("Welcome to C Phone Book\n");
    do{
        printf("\nChoose an option:");
        printf("\n1-Add contact\n2-Search contact\n3-Show all contacts\n4-Exit\n");
        printf("\nOption: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                if(totalContacts >= 100){
                    printf("\nPhone book is full!\n");
                }
                else{
                    addContact(contacts);
                }
                break;
            case 2:
                if(totalContacts == 0){
                    printf("\nPhone book is empty!\n");
                }
                else{
                    searchContact(contacts);
                }
                break;
            case 3:
                if(totalContacts == 0){
                    printf("\nPhone book is empty!\n");
                }
                else{
                    showContacts(contacts);
                }
                break;
            case 4:
                printf("\nThank you for using C Phone Book!\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    }while(option != 4);
    return 0;
}