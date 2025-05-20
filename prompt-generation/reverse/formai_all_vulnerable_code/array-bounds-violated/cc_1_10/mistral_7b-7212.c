//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

Contact contacts[MAX_ENTRIES];
int num_contacts = 0;

void read_file(FILE *fp) {
    while (fscanf(fp, "%s %s", contacts[num_contacts].name, contacts[num_contacts].phone) != EOF) {
        num_contacts++;
    }
}

void write_file(FILE *fp) {
    for (int i = 0; i < num_contacts; i++) {
        fprintf(fp, "%s %s\n", contacts[i].name, contacts[i].phone);
    }
}

void add_contact() {
    if (num_contacts >= MAX_ENTRIES) {
        error("Phone book is full.");
    }

    printf("Enter name: ");
    fgets(contacts[num_contacts].name, NAME_LENGTH, stdin);
    contacts[num_contacts].name[strlen(contacts[num_contacts].name) - 1] = '\0'; // remove newline character

    printf("Enter phone number: ");
    fgets(contacts[num_contacts].phone, PHONE_LENGTH, stdin);
    contacts[num_contacts].phone[strlen(contacts[num_contacts].phone) - 1] = '\0'; // remove newline character

    num_contacts++;
}

void search_contact() {
    char name[NAME_LENGTH];

    printf("Enter name to search for: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strlen(name) - 1] = '\0'; // remove newline character

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    FILE *fp;

    if ((fp = fopen("phonebook.txt", "r")) != NULL) {
        read_file(fp);
        fclose(fp);
    }

    while (1) {
        printf("\nPhonebook\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                write_file(fp);
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}