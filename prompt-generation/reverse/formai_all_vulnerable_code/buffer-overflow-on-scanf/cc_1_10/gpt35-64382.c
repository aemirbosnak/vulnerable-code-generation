//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact *phone_book;
int num_contacts = 0;

void add_contact() {
    printf("\n");
    printf("Enter contact name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[num_contacts].phone);
    num_contacts++;
    printf("\nContact added successfully!\n");
}

void display_contacts() {
    if(num_contacts == 0) {
        printf("Phone book is empty.\n");
    }
    else {
        printf("\nContacts:\n");
        for(int i=0; i<num_contacts; i++) {
            printf("%s\t%s\n", phone_book[i].name, phone_book[i].phone);
        }
    }
}

void search_contact() {
    char search_term[50];
    printf("\nEnter name or phone number to search: ");
    scanf("%s", search_term);
    int flag = 0;
    printf("\nSearch Results:\n");
    for(int i=0; i<num_contacts; i++) {
        if(strcmp(phone_book[i].name, search_term) == 0 || strcmp(phone_book[i].phone, search_term) == 0) {
            printf("%s\t%s\n", phone_book[i].name, phone_book[i].phone);
            flag = 1;
        }
    }
    if(flag == 0) {
        printf("No results found for %s.\n", search_term);
    }
}

int main() {
    printf("Welcome to C Phone Book!\n");
    int choice;
    phone_book = malloc(sizeof(Contact)*100);
    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_contact();
                    break;
            case 2: display_contacts();
                    break;
            case 3: search_contact();
                    break;
            case 4: printf("\nThank you for using C Phone Book!\n");
                    exit(0);
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}