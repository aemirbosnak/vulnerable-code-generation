//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct {
    char name[50];
    char number[15];
} phone;

void add(phone *book, int n) {
    printf("\nEnter the name: ");
    scanf("%s", book[n].name);

    printf("\nEnter the phone number: ");
    scanf("%s", book[n].number);
}

void view(phone *book, int n) {
    printf("\nName: %s\nPhone number: %s", book[n].name, book[n].number);
}

void search(phone *book, int n, char name[50]) {
    int i;
    for(i=0; i<n; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("\nName: %s\nPhone number: %s", book[i].name, book[i].number);
            return;
        }
    }
    printf("\nNo contact found with that name!");
}

void delete(phone *book, int n) {
    printf("\nEnter the name to delete: ");
    char name[50];
    scanf("%s", name);
    int i;
    for(i=0; i<n; i++) {
        if(strcmp(book[i].name, name) == 0) {
            strcpy(book[i].name, "");
            strcpy(book[i].number, "");
            printf("\nContact deleted!");
            return;
        }
    }
    printf("\nNo contact found with that name!");
}

int main() {
    int n, choice;
    phone book[MAX];

    printf("\nEnter the number of contacts to store: ");
    scanf("%d", &n);

    printf("\nEnter 1 to add contact\nEnter 2 to view contact\nEnter 3 to search contact\nEnter 4 to delete contact\nEnter 0 to exit");
    scanf("%d", &choice);

    while(choice!= 0) {
        switch(choice) {
            case 1:
                add(&book, n);
                break;
            case 2:
                printf("\nEnter the contact number to view: ");
                int num;
                scanf("%d", &num);
                view(&book[num-1], num);
                break;
            case 3:
                printf("\nEnter the name to search: ");
                char name[50];
                scanf("%s", name);
                search(&book[0], n, name);
                break;
            case 4:
                printf("\nEnter the name to delete: ");
                char delname[50];
                scanf("%s", delname);
                delete(&book[0], n);
                break;
            case 0:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice!");
        }
        printf("\n\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}