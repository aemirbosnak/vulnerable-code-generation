//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 200

struct contact{
    char name[MAX];
    int phone_no;
    char email[MAX];
};

void add_contact(struct contact *book, int size){
    printf("\nEnter name: ");
    scanf("%s", &book[size].name);
    printf("Enter phone number: ");
    scanf("%d", &book[size].phone_no);
    printf("Enter email: ");
    scanf("%s", &book[size].email);
}

void view_contacts(struct contact *book, int size){
    printf("\nName\tPhone Number\tEmail\n");
    for(int i=0; i<size; i++){
        printf("%s\t%d\t%s\n", book[i].name, book[i].phone_no, book[i].email);
    }
}

void search_contact(struct contact *book, int size, char name[MAX]){
    printf("\nEnter name to search: ");
    scanf("%s", name);
    for(int i=0; i<size; i++){
        if(strcmp(book[i].name, name)==0){
            printf("\nName: %s\nPhone Number: %d\nEmail: %s\n", book[i].name, book[i].phone_no, book[i].email);
        }
    }
}

int main(){
    struct contact book[MAX];
    int size=0;
    char choice;
    do{
        printf("\n1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice){
            case '1':
                if(size==MAX){
                    printf("\nPhone book is full!");
                }
                else{
                    add_contact(book, size);
                    size++;
                }
                break;
            case '2':
                if(size==0){
                    printf("\nPhone book is empty!");
                }
                else{
                    view_contacts(book, size);
                }
                break;
            case '3':
                if(size==0){
                    printf("\nPhone book is empty!");
                }
                else{
                    printf("\nEnter name to search: ");
                    char name[MAX];
                    scanf("%s", name);
                    search_contact(book, size, name);
                }
                break;
            case '4':
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    }while(choice!='4');
    return 0;
}