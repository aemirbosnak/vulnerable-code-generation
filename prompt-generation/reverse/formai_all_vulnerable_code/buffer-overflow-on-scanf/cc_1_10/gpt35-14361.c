//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    char email[100];
    char phone[100];
} Record;

void insert(Record *database, int *count) {
    printf("Great! Let's insert a new record!\n\n");

    printf("Enter ID: ");
    scanf("%d", &database[*count].id);

    printf("Enter name: ");
    scanf("%s", database[*count].name);

    printf("Enter email: ");
    scanf("%s", database[*count].email);

    printf("Enter phone: ");
    scanf("%s", database[*count].phone);

    *count += 1;

    printf("\nRecord successfully added!\n\n");
}

void view(Record *database, int count) {
    if (count == 0) {
        printf("Oops! No records found.\n\n");
    } else {
        printf("Here are all the records in the database:\n\n");
        for (int i = 0; i < count; i++) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Email: %s\n", database[i].email);
            printf("Phone: %s\n\n", database[i].phone);
        }
    }
}

int main() {
    Record database[100];
    int choice, count = 0;

    printf("Welcome to the C Database simulation!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Insert new record\n");
        printf("2. View all records\n");
        printf("3. Exit\n\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(database, &count);
                break;
            case 2:
                view(database, count);
                break;
            case 3:
                printf("\nThank you for using C Database simulation!\n");
                return 0;
            default:
                printf("Oops! Invalid option selected. Please try again.\n\n");
        }
    } while (1);
}