//FormAI DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact {
    char name[50];
    char number[15];
};

void add_contact(struct Contact phone_book[], int num_of_contacts) {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);
    strcpy(phone_book[num_of_contacts].name, name);
    char number[15];
    printf("Enter number: ");
    scanf("%s", number);
    strcpy(phone_book[num_of_contacts].number, number);
    printf("Contact added!\n");
}

int search_contact(struct Contact phone_book[], int num_of_contacts) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i=0; i<num_of_contacts; i++) {
        if (strcmp(phone_book[i].name, name)==0) {
            printf("%s's number is: %s\n", name, phone_book[i].number);
            return i;
        }
    }
    printf("Contact not found!\n");
    return -1;
}

void delete_contact(struct Contact phone_book[], int num_of_contacts) {
    int index = search_contact(phone_book, num_of_contacts);
    if (index!=-1) {
        for (int i=index; i<num_of_contacts-1; i++) {
            strcpy(phone_book[i].name, phone_book[i+1].name);
            strcpy(phone_book[i].number, phone_book[i+1].number);
        }
        printf("Contact deleted!\n");
    }
}

void display_all_contacts(struct Contact phone_book[], int num_of_contacts) {
    printf("All Contacts:\n");
    for (int i=0; i<num_of_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    int num_of_contacts = 0;
    struct Contact phone_book[100];
    int choice;
    while (1) {
        printf("\n1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(phone_book, num_of_contacts);
                num_of_contacts++;
                break;
            case 2:
                search_contact(phone_book, num_of_contacts);
                break;
            case 3:
                delete_contact(phone_book, num_of_contacts);
                num_of_contacts--;
                break;
            case 4:
                display_all_contacts(phone_book, num_of_contacts);
                break;
            case 5:
                printf("Exiting Phone Book program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}