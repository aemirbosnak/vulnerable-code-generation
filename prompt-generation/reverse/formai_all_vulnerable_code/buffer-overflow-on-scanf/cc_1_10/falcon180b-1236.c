//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 100
#define MAX_NAME 50
#define MAX_NUMBER 20

typedef struct {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
} contact;

void add_contact(contact *book, int size, char *name, char *number) {
    int i;
    for(i = 0; i < size; i++) {
        if(strcmp(book[i].name, name) == 0) {
            strcpy(book[i].number, number);
            return;
        }
    }
    strcpy(book[size].name, name);
    strcpy(book[size].number, number);
    size++;
}

void print_contacts(contact *book, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%s - %s\n", book[i].name, book[i].number);
    }
}

void search_contact(contact *book, int size, char *name) {
    int i;
    for(i = 0; i < size; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("%s - %s\n", book[i].name, book[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int size = 0;
    contact book[MAX_LINE];

    while(1) {
        printf("1. Add contact\n2. Print contacts\n3. Search contact\n4. Exit\n");
        char choice[MAX_LINE];
        scanf("%s", choice);

        switch(atoi(choice)) {
            case 1:
                printf("Enter name: ");
                scanf("%s", book[size].name);
                printf("Enter number: ");
                scanf("%s", book[size].number);
                size++;
                break;
            case 2:
                print_contacts(book, size);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", book[size].name);
                search_contact(book, size, book[size].name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}