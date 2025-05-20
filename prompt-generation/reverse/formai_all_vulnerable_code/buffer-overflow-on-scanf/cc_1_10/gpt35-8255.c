//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of email addresses that can be stored
#define MAX_EMAILS 100

// Struct to store email addresses
typedef struct email {
    char name[50];
    char address[100];
} Email;

// Struct to store email list
typedef struct email_list {
    int count; // Count of emails in the list
    Email list[MAX_EMAILS]; // Array of emails
} EmailList;

// Function prototypes
void print_menu();
void add_email(EmailList* list);
void remove_email(EmailList* list);
void display_emails(EmailList* list);
void save_to_file(EmailList* list);
void load_from_file(EmailList* list);

int main() {
    EmailList list = {0}; // Initialize list with 0 emails
    int choice;

    printf("Welcome to the Genius Email List Manager\n\n");

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(&list);
                break;
            case 2:
                remove_email(&list);
                break;
            case 3:
                display_emails(&list);
                break;
            case 4:
                save_to_file(&list);
                break;
            case 5:
                load_from_file(&list);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

// Print main menu
void print_menu() {
    printf("Main Menu\n");
    printf("1. Add email\n");
    printf("2. Remove email\n");
    printf("3. Display emails\n");
    printf("4. Save list to file\n");
    printf("5. Load list from file\n");
    printf("6. Exit\n");
}

// Add a new email to the list
void add_email(EmailList* list) {
    if (list->count >= MAX_EMAILS) {
        printf("Email list is full, cannot add any more emails\n");
        return;
    }

    Email email;

    printf("\nEnter name: ");
    getchar();
    fgets(email.name, sizeof(email.name), stdin);

    printf("Enter address: ");
    fgets(email.address, sizeof(email.address), stdin);

    // Remove newline character from inputs
    email.name[strcspn(email.name, "\n")] = '\0';
    email.address[strcspn(email.address, "\n")] = '\0';

    list->list[list->count] = email;
    list->count++;

    printf("Email added successfully!\n");
}

// Remove an email from the list
void remove_email(EmailList* list) {
    if (list->count == 0) {
        printf("Email list is empty, cannot remove any emails\n");
        return;
    }

    printf("\nEnter name of email to remove: ");
    getchar();
    char name[50];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int index = -1; // Initialize index as invalid value

    // Find index of email with matching name
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->list[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Shift all emails after the removed email back by one
        for (int i = index; i < list->count - 1; i++) {
            list->list[i] = list->list[i+1];
        }

        list->count--;

        printf("Email removed successfully!\n");
    } else {
        printf("Email with name '%s' not found in the list\n", name);
    }
}

// Display all emails in the list
void display_emails(EmailList* list) {
    if (list->count == 0) {
        printf("Email list is empty\n");
        return;
    }

    printf("\nEmail list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->list[i].name, list->list[i].address);
    }
}

// Save email list to a file
void save_to_file(EmailList* list) {
    if (list->count == 0) {
        printf("Email list is empty, nothing to save\n");
        return;
    }

    printf("\nEnter name of file to save list to: ");
    getchar();
    char filename[100];
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error creating file\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(fp, "%s,%s\n", list->list[i].name, list->list[i].address);
    }

    fclose(fp);

    printf("Email list saved to file '%s' successfully!\n", filename);
}

// Load email list from a file
void load_from_file(EmailList* list) {
    printf("\nEnter name of file to load list from: ");
    getchar();
    char filename[100];
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[150];
    int count = 0;

    // Read file line by line and store each email in the list
    while (fgets(line, sizeof(line), fp) != NULL) {
        strtok(line, ",\n"); // Get name from line
        strcpy(list->list[count].name, line);

        strtok(NULL, ",\n"); // Get address from line
        strcpy(list->list[count].address, line);

        count++;
    }

    fclose(fp);

    list->count = count;

    printf("Email list loaded from file '%s' successfully!\n", filename);
}