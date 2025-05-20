//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact phone_book[MAX_ENTRIES];
int num_entries = 0;

void display_menu() {
    printf("\n---------- Phone Book ----------\n");
    printf("1. Add Contact\n");
    printf("2. Remove Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Quit\n");
}

void add_contact() {
    if (num_entries >= MAX_ENTRIES) {
        printf("\nPhone Book is Full!\n");
        return;
    }

    printf("\nEnter Contact Name: ");
    scanf("%s", phone_book[num_entries].name);

    printf("Enter Contact Phone Number: ");
    scanf("%s", phone_book[num_entries].phone);

    num_entries++;
}

void remove_contact() {
    int index;
    char name[50];

    printf("\nEnter Contact Name to Remove: ");
    scanf("%s", name);

    for (index = 0; index < num_entries; index++) {
        if (strcmp(phone_book[index].name, name) == 0) {
            for (int i = index; i < num_entries - 1; i++) {
                phone_book[i] = phone_book[i + 1];
            }
            num_entries--;
            printf("\nContact Removed!\n");
            return;
        }
    }

    printf("\nContact Not Found!\n");
}

void search_contact() {
    char name[50];
    int index;

    printf("\nEnter Contact Name to Search: ");
    scanf("%s", name);

    for (index = 0; index < num_entries; index++) {
        if (strcmp(phone_book[index].name, name) == 0) {
            printf("\nContact Name: %s", phone_book[index].name);
            printf("\nContact Phone: %s", phone_book[index].phone);
            return;
        }
    }

    printf("\nContact Not Found!\n");
}

void display_all_contacts() {
    if (num_entries == 0) {
        printf("\nPhone Book is Empty!\n");
        return;
    }

    printf("\n---------- Phone Book ----------\n");
    printf("Name\tPhone\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_all_contacts();
                break;
            case 5:
                printf("\nQuitting Phone Book Program.\n");
                exit(0);
            default:
                printf("\nInvalid Option!\n");
        }
    }

    return 0;
}