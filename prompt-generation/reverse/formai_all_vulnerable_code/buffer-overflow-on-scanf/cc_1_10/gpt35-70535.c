//FormAI DATASET v1.0 Category: Phone Book ; Style: random
#include<stdio.h>
#include<string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void printContacts(struct PhoneBook *book) {
    printf("CONTACTS:\n");
    for(int i = 0; i < book->count; i++) {
        printf("%d) %s - %s\n", i+1, book->contacts[i].name, book->contacts[i].phone);
    }
}

int addContact(struct PhoneBook *book, char *name, char *phone) {
    if(book->count == MAX_CONTACTS) {
        printf("Phonebook full!\n");
        return 0;
    }

    for(int i = 0; i < book->count; i++) {
        if(strcmp(name, book->contacts[i].name) == 0 || strcmp(phone, book->contacts[i].phone) == 0) {
            printf("Contact already exists!\n");
            return 0;
        }
    }

    strcpy(book->contacts[book->count].name, name);
    strcpy(book->contacts[book->count].phone, phone);
    book->count++;
    printf("Contact added!\n");
    return 1;
}

int searchContact(struct PhoneBook *book, char *query) {
    printf("SEARCH RESULTS:\n");
    int found = 0;
    for(int i = 0; i < book->count; i++) {
        if(strstr(book->contacts[i].name, query) != NULL || strstr(book->contacts[i].phone, query) != NULL) {
            printf("%d) %s - %s\n", found+1, book->contacts[i].name, book->contacts[i].phone);
            found++;
        }
    }
    if(found == 0) {
        printf("No contacts found!\n");
    }
    return found;
}

int main() {
    struct PhoneBook book;
    book.count = 0;
    int option;
    do {
        printf("MENU\n");
        printf("1. Add contact\n");
        printf("2. Search contacts\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        printf("\n");
        switch(option) {
            case 1: {
                char name[50];
                char phone[15];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(&book, name, phone);
                break;
            }
            case 2: {
                char query[50];
                printf("Enter query: ");
                scanf("%s", query);
                searchContact(&book, query);
                break;
            }
            case 3: {
                printContacts(&book);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid option!\n");
                break;
            }
        }
        printf("\n");
    } while(option != 4);
    return 0;
}