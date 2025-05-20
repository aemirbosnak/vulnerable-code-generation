//FormAI DATASET v1.0 Category: Phone Book ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[20];
    char phone_number[15];
    char email[50];
};

int main() {
    struct contact phone_book[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    printf("Welcome to the C Phone Book\n\n");
    
    while(1) {
        printf("Choose an option:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(num_contacts == MAX_CONTACTS) {
                    printf("\n\nPhone book is full!\n\n");
                    break;
                }
                struct contact new_contact;
                printf("\nEnter Contact Name: ");
                scanf("%s", new_contact.name);
                printf("Enter Phone Number: ");
                scanf("%s", new_contact.phone_number);
                printf("Enter Email Address: ");
                scanf("%s", new_contact.email);

                phone_book[num_contacts] = new_contact;
                num_contacts++;
                printf("\nContact Added Successfully\n\n");
                break;
            }
            case 2: {
                if(num_contacts == 0) {
                    printf("\n\nPhone book is empty!\n\n");
                    break;
                }
                printf("\nContacts\n");
                printf("Name\t\tPhone Number\t\tEmail\n");
                for(int i = 0; i < num_contacts; i++) {
                    printf("%-20s%-20s%-50s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
                }
                printf("\n\n");
                break;
            }
            case 3: {
                if(num_contacts == 0) {
                    printf("\n\nPhone book is empty!\n\n");
                    break;
                }
                char search_name[20];
                printf("\nEnter name to search: ");
                scanf("%s", search_name);
                int found = 0;
                for(int i = 0; i < num_contacts; i++) {
                    if(strcmp(phone_book[i].name, search_name) == 0) {
                        printf("\nContact Found!\nName\t\tPhone Number\t\tEmail\n");
                        printf("%-20s%-20s%-50s\n\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("\n\nContact not found!\n\n");
                }
                break;
            }
            case 4: {
                if(num_contacts == 0) {
                    printf("\n\nPhone book is empty!\n\n");
                    break;
                }
                char delete_name[20];
                printf("\nEnter name to delete: ");
                scanf("%s", delete_name);
                int found = 0;
                for(int i = 0; i < num_contacts; i++) {
                    if(strcmp(phone_book[i].name, delete_name) == 0) {
                        found = 1;
                        for(int j = i; j < num_contacts - 1; j++) {
                            phone_book[j] = phone_book[j+1];
                        }
                        num_contacts--;
                        printf("\nContact Deleted Successfully\n\n");
                        break;
                    }
                }
                if(!found) {
                    printf("\n\nContact not found!\n\n");
                }
                break;
            }
            case 5: {
                printf("\n\nGoodbye!\n\n");
                return 0;
            }
            default: {
                printf("\n\nInvalid Choice!\n\n");
            }
        } // end of switch
    } //end of while

    return 0;
}