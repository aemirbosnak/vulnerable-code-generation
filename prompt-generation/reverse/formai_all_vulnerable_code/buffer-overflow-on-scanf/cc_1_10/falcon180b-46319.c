//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 100
#define MAX_ADDRESS_SIZE 200
#define MAX_PHONE_SIZE 20
#define MAX_EMAIL_SIZE 50
#define MAX_ROWS 100
#define MAX_COLS 4

typedef struct {
    char name[MAX_NAME_SIZE];
    char address[MAX_ADDRESS_SIZE];
    char phone[MAX_PHONE_SIZE];
    char email[MAX_EMAIL_SIZE];
} Person;

Person people[MAX_ROWS];
int num_people = 0;

void add_person() {
    printf("Enter name: ");
    scanf("%s", people[num_people].name);

    printf("Enter address: ");
    scanf("%s", people[num_people].address);

    printf("Enter phone number: ");
    scanf("%s", people[num_people].phone);

    printf("Enter email address: ");
    scanf("%s", people[num_people].email);

    num_people++;
}

void display_people() {
    printf("Name\tAddress\tPhone\tEmail\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%s\t%s\t%s\n", people[i].name, people[i].address, people[i].phone, people[i].email);
    }
}

void search_people(char *name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Name: %s\nAddress: %s\nPhone: %s\nEmail: %s\n", people[i].name, people[i].address, people[i].phone, people[i].email);
        }
    }
}

int main() {
    printf("Welcome to the database simulation!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add person\n2. Display all people\n3. Search for person by name\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_person();
            break;
        case 2:
            display_people();
            break;
        case 3:
            printf("Enter name to search for: ");
            char name[MAX_NAME_SIZE];
            scanf("%s", name);
            search_people(name);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}