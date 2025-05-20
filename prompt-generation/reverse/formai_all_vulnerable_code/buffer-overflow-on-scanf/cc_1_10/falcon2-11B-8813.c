//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char number[20];
};

typedef struct Contact Contact;

Contact contacts[MAX_CONTACTS];
int count = 0;

void add_contact(char name[], char number[]) {
    Contact temp = {.name = name,.number = number};
    if (count < MAX_CONTACTS) {
        contacts[count] = temp;
        count++;
    }
    else {
        printf("The phone book is full.\n");
    }
}

void search_contact(char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact(char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    char name[50];
    char number[20];
    char operation;

    printf("Phone Book\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                printf("Enter name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter number: ");
                fgets(number, 20, stdin);
                number[strcspn(number, "\n")] = '\0';
                add_contact(name, number);
                break;
            case 2:
                printf("Enter name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                search_contact(name);
                break;
            case 3:
                printf("Enter name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                delete_contact(name);
                break;
            case 4:
                printf("Thank you for using the phone book!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (operation!= 4);

    return 0;
}