//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node {
    char name[MAX];
    int phone;
    struct node *next;
};

struct node *start = NULL;

void add_contact() {
    char name[MAX];
    int phone;

    printf("Enter the name of the contact: ");
    scanf("%s", name);

    printf("Enter the phone number of the contact: ");
    scanf("%d", &phone);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->phone = phone;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        struct node *temp = start;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("\nContact added successfully!\n");
}

void search_contact() {
    char name[MAX];

    printf("Enter the name of the contact to search: ");
    scanf("%s", name);

    struct node *temp = start;

    if (temp == NULL) {
        printf("\nNo contacts found.\n");
    } else {
        while (temp!= NULL) {
            if (strcmp(temp->name, name) == 0) {
                printf("\nName: %s\nPhone: %d\n", temp->name, temp->phone);
            }
            temp = temp->next;
        }
    }
}

void delete_contact() {
    char name[MAX];

    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    struct node *temp = start;
    struct node *prev = NULL;

    if (temp == NULL) {
        printf("\nNo contacts found.\n");
    } else if (strcmp(temp->name, name) == 0) {
        start = temp->next;
        free(temp);
        printf("\nContact deleted successfully!\n");
    } else {
        while (temp!= NULL && strcmp(temp->name, name)!= 0) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("\nContact not found.\n");
        } else {
            prev->next = temp->next;
            free(temp);
            printf("\nContact deleted successfully!\n");
        }
    }
}

void display_all_contacts() {
    struct node *temp = start;

    if (temp == NULL) {
        printf("\nNo contacts found.\n");
    } else {
        while (temp!= NULL) {
            printf("\nName: %s\nPhone: %d\n", temp->name, temp->phone);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
            display_all_contacts();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}