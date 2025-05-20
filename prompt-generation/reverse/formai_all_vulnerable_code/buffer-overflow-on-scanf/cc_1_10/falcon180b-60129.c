//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct contact{
    char name[50];
    char phone[15];
    char email[30];
}contact;

contact phonebook[MAX];
int count = 0;

void add_contact(){
    printf("Enter name: ");
    scanf("%s", phonebook[count].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[count].phone);
    printf("Enter email: ");
    scanf("%s", phonebook[count].email);
    count++;
    printf("\nContact added successfully!\n");
}

void view_contacts(){
    int i;
    for(i=0;i<count;i++){
        printf("Name: %s\nPhone number: %s\nEmail: %s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
        printf("\n");
    }
}

void search_contact(){
    char name[50];
    int i;
    printf("Enter name to search: ");
    scanf("%s", name);
    for(i=0;i<count;i++){
        if(strcmp(phonebook[i].name, name) == 0){
            printf("Name: %s\nPhone number: %s\nEmail: %s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
        }
    }
}

void delete_contact(){
    char name[50];
    int i, found = FALSE;
    printf("Enter name to delete: ");
    scanf("%s", name);
    for(i=0;i<count;i++){
        if(strcmp(phonebook[i].name, name) == 0){
            found = TRUE;
            break;
        }
    }
    if(found == TRUE){
        for(i=0;i<count-1;i++){
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].phone, phonebook[i+1].phone);
            strcpy(phonebook[i].email, phonebook[i+1].email);
        }
        count--;
        printf("\nContact deleted successfully!\n");
    }
    else{
        printf("\nContact not found!\n");
    }
}

void main(){
    int choice;
    while(TRUE){
        printf("\n1. Add contact\n2. View contacts\n3. Search contact\n4. Delete contact\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
}