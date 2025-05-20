//FormAI DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 50
#define MAX_EMAIL 50

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} Contact;

void add_contact(FILE *fp);
void display_contacts(FILE *fp);

int main() {
    FILE *fp;
    int choice;

    fp = fopen("contacts.txt", "a+");

    do {
        printf("\n===== Contact List =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(fp);
                break;
            case 2:
                display_contacts(fp);
                break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 3);

    fclose(fp);
    return 0;
}

void add_contact(FILE *fp) {
    Contact c;

    printf("\nEnter name: ");
    scanf("%s", c.name);
    printf("Enter email: ");
    scanf("%s", c.email);

    fprintf(fp, "%s %s\n", c.name, c.email);
    printf("Contact added successfully.");
}

void display_contacts(FILE *fp) {
    Contact c;

    printf("\n======= Contacts =======\n");
    printf("Name\t\t\tEmail\n");

    rewind(fp);

    while (fscanf(fp, "%s %s", c.name, c.email) != EOF) {
        printf("%-20s %s\n", c.name, c.email);
    }
}