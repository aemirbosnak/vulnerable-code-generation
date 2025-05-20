//FormAI DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

struct contact {
    char name[30];
    char phone[15];
};

struct contact phone_book[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Phone book is full\n");
        return;
    }

    struct contact new_record;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter phone number: ");
    scanf("%s", new_record.phone);

    phone_book[num_records++] = new_record;

    printf("Record added successfully!\n");
}

void find_record() {
    char name[30];
    printf("Enter name to search for: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Phone number for %s is %s\n", name, phone_book[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found for %s\n", name);
    }
}

void display_records() {
    printf("Phone book contains %d records:\n\n", num_records);
    for (int i = 0; i < num_records; i++) {
        printf("%d. Name: %s\n   Phone: %s\n\n", i+1, phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    int choice;

    while(1) {
        printf("Phone Book Menu\n");
        printf("1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                find_record();
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("Exiting Phone Book\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}