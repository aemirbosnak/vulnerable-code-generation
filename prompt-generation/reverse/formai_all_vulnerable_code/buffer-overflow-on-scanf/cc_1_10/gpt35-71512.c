//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(FILE *fp) {
    Contact contact;
    printf("Enter name: ");
    fgets(contact.name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(contact.email, MAX_EMAIL_LENGTH, stdin);
    printf("Enter phone: ");
    fgets(contact.phone, MAX_PHONE_LENGTH, stdin);
    fwrite(&contact, sizeof(Contact), 1, fp);
    printf("Contact added successfully.\n");
}

void search_contact(FILE *fp) {
    char search_term[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(search_term, MAX_NAME_LENGTH, stdin);
    Contact contact;
    int found = 0;
    while (fread(&contact, sizeof(Contact), 1, fp)) {
        if (strcmp(search_term, contact.name) == 0) {
            printf("Name: %sEmail: %sPhone: %s", contact.name, contact.email, contact.phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen("contacts.bin", "ab+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    int choice;
    do {
        printf("\n1. Add contact\n2. Search contact\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_contact(fp);
                break;
            case 2:
                search_contact(fp);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
    fclose(fp);
    return 0;
}