//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    char number[20];
} Contact;

void print_menu() {
    printf("\n-------------------------------------\n");
    printf("|      Welcome to Happy PhoneBook!     |\n");
    printf("|-------------------------------------|\n");
    printf("| Press 1 to Add a Contact            |\n");
    printf("| Press 2 to Search a Contact         |\n");
    printf("| Press 3 to Display All Contacts     |\n");
    printf("| Press 4 to Exit                     |\n");
    printf("-------------------------------------|\n");
}

void add_contact(Contact contacts[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("PhoneBook is Full! \n");
        return;
    }
    printf("Enter Contact Name: ");
    scanf("%s", contacts[*size].name);
    printf("Enter Contact Number: ");
    scanf("%s", contacts[*size].number);
    (*size)++;
}

bool search_contact(Contact contacts[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact Found! \n");
            printf("Name: %s \n", contacts[i].name);
            printf("Number: %s \n", contacts[i].number);
            return true;
        }
    }
    printf("\nContact not Found! \n");
    return false;
}

void display_all_contacts(Contact contacts[], int size) {
    printf("\n--------------- All Contacts ---------------\n");
    for (int i = 0; i < size; i++) {
        printf("\nName: %s \nNumber: %s", contacts[i].name, contacts[i].number);
    }
}

int main() {
    Contact contacts[MAX_SIZE];
    int size = 0;
    int choice;

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &size);
                break;
            case 2: {
                char name[50];
                printf("Enter Contact Name to Search: ");
                scanf("%s", name);
                search_contact(contacts, size, name);
                break;
            }
            case 3:
                display_all_contacts(contacts, size);
                break;
            case 4:
                printf("Exiting Happy PhoneBook... \n");
                exit(0);
            default:
                printf("Invalid Choice! \n");
        }
    }
    return 0;
}