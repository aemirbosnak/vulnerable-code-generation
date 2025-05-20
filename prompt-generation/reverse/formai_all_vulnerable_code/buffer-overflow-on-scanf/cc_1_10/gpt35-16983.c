//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
/* Welcome to the unique C Phone Book example program! */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* defining a structure named 'contact' for phone book */

struct contact {
    char name[20];
    char phone[10];
    char email[30];
};

/* function to add a contact to phone book */

void add_contact(struct contact *phonebook, int *count) {
    printf("Enter contact name: ");
    scanf("%s", phonebook[*count].name);
    printf("Enter contact phone number: ");
    scanf("%s", phonebook[*count].phone);
    printf("Enter contact email: ");
    scanf("%s", phonebook[*count].email);
    (*count)++;
    printf("Contact added successfully!\n");
}

/* function to display all contacts in phone book */

void display_contacts(struct contact *phonebook, int count) {
    printf("Name\tPhone Number\tEmail\n");
    for(int i=0;i<count;i++) {
        printf("%s\t%s\t\t%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }
}

/* function to search for a contact in phone book */

void search_contact(struct contact *phonebook, int count) {
    char name[20];
    printf("Enter name to search: ");
    scanf("%s", name);
    for(int i=0;i<count;i++) {
        if(strcmp(name,phonebook[i].name)==0) {
            printf("Name: %s\nPhone Number: %s\nEmail: %s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}

/* function to delete a contact from phone book */

void delete_contact(struct contact *phonebook, int *count) {
    char name[20];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for(int i=0;i<*count;i++) {
        if(strcmp(name,phonebook[i].name)==0) {
            for(int j=i+1;j<*count;j++) {
                strcpy(phonebook[j-1].name,phonebook[j].name);
                strcpy(phonebook[j-1].phone,phonebook[j].phone);
                strcpy(phonebook[j-1].email,phonebook[j].email);
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

/* main function */

int main() {
    struct contact phonebook[100];
    int count=0;
    int option;
    while(1) {
        printf("\nWelcome to Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_contact(phonebook,&count);
                break;
            case 2:
                display_contacts(phonebook,count);
                break;
            case 3:
                search_contact(phonebook,count);
                break;
            case 4:
                delete_contact(phonebook,&count);
                break;
            case 5:
                printf("Thank you for using Phone Book!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}