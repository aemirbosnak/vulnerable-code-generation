//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <string.h>

struct contact {
    char name[50];
    char phone_number[15];
};

void add_contact(struct contact *book, int *num_contacts);
void search_contact(struct contact *book, int num_contacts, char name[]);
void display_phonebook(struct contact *book, int num_contacts);
void delete_contact(struct contact *book, int *num_contacts, char name[]);

int main() {
    struct contact phonebook[100];
    int num_contacts = 0;
    int running = 1;

    while (running) {
        int option;
        printf("\n\t\tPersonal Phone Book\n\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Phone Book\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_contact(phonebook, &num_contacts);
                break;
            case 2: {
                char name[50];
                printf("\nEnter name to search: ");
                scanf("%s", name);
                search_contact(phonebook, num_contacts, name);
                break;
            }
            case 3:
                display_phonebook(phonebook, num_contacts);
                break;
            case 4: {
                char name[50];
                printf("\nEnter name to delete: ");
                scanf("%s", name);
                delete_contact(phonebook, &num_contacts, name);
                break;
            }
            case 5:
                running = 0;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;

        }
    }

    return 0;
}

void add_contact(struct contact *book, int *num_contacts) {
    printf("\nEnter name: ");
    scanf("%s", book[*num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", book[*num_contacts].phone_number);
    printf("\nContact added successfully!\n");
    (*num_contacts)++;
}

void search_contact(struct contact *book, int num_contacts, char name[]) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("\n%s\t\t%s\n", book[i].name, book[i].phone_number);
            return;
        }
    }
    printf("\nContact not found.\n");
}

void display_phonebook(struct contact *book, int num_contacts) {
    if (num_contacts == 0) {
        printf("\nThe phone book is empty.\n");
        return;
    }
    printf("\nName\t\tPhone Number\n\n");
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s\t\t%s\n", book[i].name, book[i].phone_number);
    }
}

void delete_contact(struct contact *book, int *num_contacts, char name[]) {
    int i, j;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(book[i].name, name) == 0) {
            for (j = i; j < *num_contacts - 1; j++) {
                strcpy(book[j].name, book[j+1].name);
                strcpy(book[j].phone_number, book[j+1].phone_number);
            }
            strcpy(book[j].name, "");
            strcpy(book[j].phone_number, "");
            (*num_contacts)--;
            printf("\nContact deleted successfully!\n");
            return;
        }
    }
    printf("\nContact not found.\n");
}