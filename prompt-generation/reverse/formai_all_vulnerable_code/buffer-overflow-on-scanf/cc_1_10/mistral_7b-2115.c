//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char name[50];
    char number[15];
} Contact;

void print_menu() {
    printf("\n-------------------\n");
    printf("| Phone Book Menu  |\n");
    printf("-------------------|\n");
    printf("| 1. Add Contact   |\n");
    printf("| 2. Delete Contact|\n");
    printf("| 3. Search Contact|\n");
    printf("| 4. Display All   |\n");
    printf("| 5. Exit          |\n");
    printf("-------------------|\n");
}

void add_contact(Contact contacts[], int *size) {
    if (*size == MAX_SIZE) {
        printf("\nPhone Book is Full!\n");
        return;
    }

    printf("\nEnter Contact Name: ");
    scanf("%s", contacts[*size].name);

    printf("Enter Contact Number: ");
    scanf("%s", contacts[*size].number);

    (*size)++;
}

void delete_contact(Contact contacts[], int *size, char name[]) {
    int i;

    for (i = 0; i < *size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            printf("\nContact Deleted Successfully!\n");
            return;
        }
    }

    printf("\nContact Not Found!\n");
}

void search_contact(Contact contacts[], int size, char name[]) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nName: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("\nContact Not Found!\n");
}

void display_all(Contact contacts[], int size) {
    int i;

    if (size == 0) {
        printf("\nPhone Book is Empty!\n");
        return;
    }

    printf("\n-----------------------\n");
    printf("| Phone Book Contacts |\n");
    printf("-----------------------|\n");

    for (i = 0; i < size; i++) {
        printf("\nName: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
    }

    printf("-----------------------|\n");
}

int main() {
    Contact contacts[MAX_SIZE];
    int size = 0;

    while (1) {
        print_menu();
        int choice;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &size);
                break;
            case 2: {
                char name[50];
                printf("Enter Name of Contact to Delete: ");
                scanf("%s", name);
                delete_contact(contacts, &size, name);
                break;
            }
            case 3: {
                char name[50];
                printf("Enter Name of Contact to Search: ");
                scanf("%s", name);
                search_contact(contacts, size, name);
                break;
            }
            case 4:
                display_all(contacts, size);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Option! Try Again.\n");
        }
    }

    return 0;
}