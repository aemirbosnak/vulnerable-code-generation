//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15

typedef struct phoneBook {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    struct phoneBook *next;
} PhoneBook;

void insertPhoneBook(PhoneBook **p, char *name, char *phone) {
    if (*p == NULL) {
        *p = (PhoneBook*)malloc(sizeof(PhoneBook));
        strncpy((*p)->name, name, MAX_NAME_LENGTH);
        strncpy((*p)->phone, phone, MAX_PHONE_LENGTH);
        (*p)->next = NULL;
    }
    else {
        insertPhoneBook(&((*p)->next), name, phone);
    }
}

void displayPhoneBookList(PhoneBook *p) {
    while (p != NULL) {
        printf("Name: %s \t Phone: %s\n", p->name, p->phone);
        p = p->next;
    }
}

void searchPhoneBook(PhoneBook *p, char *name) {
    if (p != NULL) {
        if (strncmp(p->name, name, MAX_NAME_LENGTH) == 0) {
            printf("Name: %s \t Phone: %s\n", p->name, p->phone);
        }
        searchPhoneBook(p->next, name);
    }
}

int main() {
    PhoneBook *p = NULL;
    int choice;
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];

    do {
        printf("1. Insert a Phone Book Record\n");
        printf("2. Display Phone Book Records\n");
        printf("3. Search Phone Book Record\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%s", phone);
                insertPhoneBook(&p, name, phone);
                printf("\nRecord Inserted Successfully!\n");
                break;
            case 2:
                if (p == NULL) {
                    printf("\nPhone Book is empty!\n");
                    break;
                }
                printf("\nPhone Book Records:\n");
                displayPhoneBookList(p);
                break;
            case 3:
                if (p == NULL) {
                    printf("\nPhone Book is empty!\n");
                    break;
                }
                printf("\nEnter Name to search: ");
                scanf("%s", name);
                printf("\nPhone Book Records:\n");
                searchPhoneBook(p, name);
                break;
            case 4:
                printf("\nExiting Phone Book Program!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (1);

    return 0;
}