//FormAI DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

struct contact {
    char name[50];
    char phone[20];
    char email[50];
};

void add_contact(struct contact *book) {
    printf("Enter name: ");
    scanf("%s", book[size].name);
    printf("Enter phone: ");
    scanf("%s", book[size].phone);
    printf("Enter email: ");
    scanf("%s", book[size].email);
    size++;
}

void print_contact(struct contact c) {
    printf("Name: %s\n", c.name);
    printf("Phone: %s\n", c.phone);
    printf("Email: %s\n", c.email);
    printf("\n");
}

void print_all_contacts(struct contact *book){
    if(size==0) {
        printf("Phone book is empty!\n");
    }
    else {
        printf("All Contacts:\n\n");
        for(int i=0;i<size;i++) {
            print_contact(book[i]);
        }
    }
}

void delete_contact(struct contact *book){
    char name[50];
    printf("Enter the name of contact you want to delete: ");
    scanf("%s", name);
    int pos=-1;
    for(int i=0;i<size;i++) {
        if(strcmp(name, book[i].name)==0) {
            pos=i;
            break;
        }
    }
    if(pos==-1) {
        printf("Contact not found\n");
    }
    else {

        for(int i=pos+1;i<size;i++) {
            book[i-1]=book[i];
        }
        size--;
        printf("Contact successfully deleted\n");
    }
}

void search_contact(struct contact *book){
    char name[50];
    printf("Enter the name of contact you want to search: ");
    scanf("%s", name);
    int pos=-1;
    for(int i=0;i<size;i++) {
        if(strcmp(name, book[i].name)==0) {
            pos=i;
            break;
        }
    }
    if(pos==-1) {
        printf("Contact not found\n");
    }
    else {
        printf("Contact Details:\n\n");
        print_contact(book[pos]);
    }
}

int main() {
    struct contact phone_book[100];
    int choice;

    while(1) {
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Print all Contacts\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: add_contact(phone_book);
                    break;

            case 2: delete_contact(phone_book);
                    break;

            case 3: search_contact(phone_book);
                    break;

            case 4: print_all_contacts(phone_book);
                    break;

            case 5: exit(0);

            default: printf("Invalid choice\n");
        }
        printf("\n");
    }

    return 0;
}