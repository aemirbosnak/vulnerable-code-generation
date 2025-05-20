//FormAI DATASET v1.0 Category: Phone Book ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store contact details
struct contact {
    char name[30];
    char email[30];
    char phone_num[15];
};

// Function to add a new contact to the phone book
void add_contact(struct contact *c, int *num_contacts) {
    printf("\nAdding a new contact...");
    printf("\nEnter name: ");
    scanf("%s", c[*num_contacts].name);
    printf("Enter email: ");
    scanf("%s", c[*num_contacts].email);
    printf("Enter phone number: ");
    scanf("%s", c[*num_contacts].phone_num);
    (*num_contacts)++;
    printf("Contact added successfully!\n");
}

// Function to search for a contact in the phone book
void search_contact(struct contact *c, int num_contacts) {
    char name[30];
    printf("\nEnter name to search: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<num_contacts; i++) {
        if(strcmp(c[i].name, name)==0) {
            printf("Name: %s\nEmail: %s\nPhone number: %s\n", c[i].name, c[i].email, c[i].phone_num);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found!\n");
    }
}

// Function to delete a contact from the phone book
void delete_contact(struct contact *c, int *num_contacts) {
    char name[30];
    printf("\nEnter name to delete: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<*num_contacts; i++) {
        if(strcmp(c[i].name, name)==0) {
            found = 1;
            for(int j=i; j<*num_contacts-1; j++) {
                strcpy(c[j].name, c[j+1].name);
                strcpy(c[j].email, c[j+1].email);
                strcpy(c[j].phone_num, c[j+1].phone_num);
            }
            (*num_contacts)--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Contact not found!\n");
    }
}

int main() {
    struct contact c[100];
    int num_contacts = 0;
    int choice;
    while(1) {
        printf("\nWelcome to the Phone Book!\n");
        printf("1) Add new contact\n");
        printf("2) Search for a contact\n");
        printf("3) Delete a contact\n");
        printf("4) Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(c, &num_contacts);
                break;
            case 2:
                search_contact(c, num_contacts);
                break;
            case 3:
                delete_contact(c, &num_contacts);
                break;
            case 4:
                printf("\nExiting the phone book...Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-4).\n");
        }
    }
    return 0;
}