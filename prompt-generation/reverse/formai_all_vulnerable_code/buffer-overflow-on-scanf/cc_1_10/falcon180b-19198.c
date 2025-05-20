//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct contact {
    char name[50];
    char number[15];
};

struct contact phonebook[MAX];
int count = 0;

void add_contact() {
    char choice;
    printf("\nEnter 1 to add contact\n");
    scanf("%d", &choice);

    if(choice == 1) {
        int i;
        printf("\nEnter the name of the contact: ");
        scanf("%s", phonebook[count].name);

        printf("\nEnter the phone number of the contact: ");
        scanf("%s", phonebook[count].number);

        count++;
        printf("\nContact added successfully!");
    }
    else {
        printf("\nInvalid choice!");
    }
}

void search_contact() {
    char search_name[50], choice;
    int i;

    printf("\nEnter the name of the contact you want to search: ");
    scanf("%s", search_name);

    for(i=0; i<count; i++) {
        if(strcmp(phonebook[i].name, search_name) == 0) {
            printf("\nName: %s", phonebook[i].name);
            printf("\nPhone number: %s", phonebook[i].number);
        }
    }

    printf("\nDo you want to search another contact? (y/n)");
    scanf("%s", &choice);

    if(choice == 'y' || choice == 'Y') {
        search_contact();
    }
    else {
        printf("\nExiting program...");
        exit(0);
    }
}

void delete_contact() {
    char choice;
    int i, found = 0;

    printf("\nEnter 2 to delete contact\n");
    scanf("%d", &choice);

    if(choice == 2) {
        printf("\nEnter the name of the contact you want to delete: ");
        scanf("%s", phonebook[0].name);

        for(i=0; i<count; i++) {
            if(strcmp(phonebook[i].name, phonebook[0].name) == 0) {
                found = 1;
                break;
            }
        }

        if(found == 1) {
            for(i=0; i<count-1; i++) {
                strcpy(phonebook[i].name, phonebook[i+1].name);
                strcpy(phonebook[i].number, phonebook[i+1].number);
            }
            count--;
            printf("\nContact deleted successfully!");
        }
        else {
            printf("\nContact not found!");
        }
    }
    else {
        printf("\nInvalid choice!");
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("\n1. Add contact");
        printf("\n2. Search contact");
        printf("\n3. Delete contact");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }while(1);

    return 0;
}