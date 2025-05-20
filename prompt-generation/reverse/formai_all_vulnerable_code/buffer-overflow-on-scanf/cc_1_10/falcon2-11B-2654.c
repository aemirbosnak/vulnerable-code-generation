//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_NAMES 50
#define MAX_PHONES 15

struct phone_book_entry {
    char name[MAX_NAMES];
    char phone[MAX_PHONES];
};

struct phone_book_entry phone_book[MAX_NAMES];
int num_entries = 0;

void add_entry(char *name, char *phone) {
    if (num_entries == MAX_NAMES) {
        printf("Phone book is full. Cannot add another entry.\n");
        return;
    }

    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].phone, phone);
    num_entries++;
}

void search_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone: %s\n", phone_book[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void display_all_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone: %s\n", phone_book[i].phone);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Display All Entries\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", phone_book[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", phone_book[num_entries].phone);
                add_entry(phone_book[num_entries].name, phone_book[num_entries].phone);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", phone_book[num_entries].name);
                search_entry(phone_book[num_entries].name);
                break;
            case 3:
                display_all_entries();
                break;
            case 4:
                printf("Thank you for using the phone book.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}