//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct contact{
    char name[50], email[50], phone[13];
};

void addContact(struct contact *contacts, int count){
    printf("\nEnter contact details:");
    printf("\nName: ");
    scanf("%s", contacts[count].name);
    printf("\nEmail: ");
    scanf("%s", contacts[count].email);
    printf("\nPhone: ");
    scanf("%s", contacts[count].phone);
    printf("\nContact added successfully!\n");
}

void displayContacts(struct contact *contacts, int count){
    printf("\nCONTACTS:\n");
    for(int i=0; i<count; i++){
        printf("\n-------------------------\n");
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
        printf("Phone: %s\n", contacts[i].phone);
        printf("-------------------------\n");
    }
}

int main(){
    int choice = 0, count = 0;
    struct contact *contacts = (struct contact *)malloc(MAX * sizeof(struct contact));
    
    if(contacts == NULL){
        printf("Memory allocation error!\n");
        exit(0);
    }
    
    printf("Welcome to the mailing list manager!!\n");
    
    do{
        printf("\nMENU:\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                addContact(contacts, count);
                count++;
                break;
                
            case 2:
                displayContacts(contacts, count);
                break;
                
            case 3: 
                printf("\nThank you for using the mailing list manager!!\n");
                break;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }while(choice != 3);
    
    free(contacts);
    
    return 0;
}