//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#define MAX_EMAILS 100

struct mailing_list {
    char name[50];
    char email[50];
    int age;
    char gender[10];
};

struct mailing_list email_list[MAX_EMAILS]; // initialize an array of mailing_list structs

int num_emails = 0; // number of total emails in the list

void add_email() {
    if (num_emails < MAX_EMAILS) { // check if the list is not full
        printf("Enter name: ");
        scanf("%s", email_list[num_emails].name);
        printf("Enter email: ");
        scanf("%s", email_list[num_emails].email);
        printf("Enter age: ");
        scanf("%d", &email_list[num_emails].age);
        printf("Enter gender: ");
        scanf("%s", email_list[num_emails].gender);
        num_emails++;
        printf("Successfully added email to the list!\n");
    } else {
        printf("Sorry, the email list is full!\n");
    }
}

void print_emails() {
    printf("Printing all emails:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("Name: %s\n", email_list[i].name);
        printf("Email: %s\n", email_list[i].email);
        printf("Age: %d\n", email_list[i].age);
        printf("Gender: %s\n", email_list[i].gender);
    }
}

void search_email() {
    char search[50];
    printf("Enter email to search: ");
    scanf("%s", search);
    int found = 0;
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(search, email_list[i].email) == 0) {
            printf("Name: %s\n", email_list[i].name);
            printf("Email: %s\n", email_list[i].email);
            printf("Age: %d\n", email_list[i].age);
            printf("Gender: %s\n", email_list[i].gender);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Email not found in the list!\n");
    }
}

void delete_email() {
    char delete[50];
    printf("Enter email to delete: ");
    scanf("%s", delete);
    int found = 0;
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(delete, email_list[i].email) == 0) {
            for (int j = i; j < num_emails - 1; j++) {
                email_list[j] = email_list[j + 1]; // shift all elements to the left
            }
            printf("Successfully deleted email from the list!\n");
            found = 1;
            num_emails--;
            break;
        }
    }
    if (!found) {
        printf("Email not found in the list!\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add an email\n");
        printf("2. Print all emails\n");
        printf("3. Search for an email\n");
        printf("4. Delete an email\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                print_emails();
                break;
            case 3:
                search_email();
                break;
            case 4:
                delete_email();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}