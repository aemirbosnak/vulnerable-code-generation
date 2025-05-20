//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

typedef struct {
    char emails[MAX_EMAILS][EMAIL_LENGTH];
    int count;
} MailingList;

void initialize(MailingList *list) {
    list->count = 0;
}

int add_email(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) {
        return -1; // List is full
    }
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            return -2; // Email already in the list
        }
    }
    
    strncpy(list->emails[list->count], email, EMAIL_LENGTH);
    list->emails[list->count][EMAIL_LENGTH - 1] = '\0'; // Ensure null-termination
    list->count++;
    return 0; // Success
}

void list_emails(const MailingList *list) {
    printf("Currently subscribed emails:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

int remove_email(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift emails to fill the gap
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            return 0; // Success
        }
    }
    return -1; // Email not found
}

void send_update(const MailingList *list, const char *message) {
    printf("Sending update to all subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Sending to %s: %s\n", list->emails[i], message);
        // Here you would integrate with an email API or SMTP server in a real application
    }
}

void display_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Email\n");
    printf("2. List Emails\n");
    printf("3. Remove Email\n");
    printf("4. Send Update\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    MailingList list;
    initialize(&list);
    int choice;
    char email[EMAIL_LENGTH];
    char message[256];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                if (add_email(&list, email) == 0) {
                    printf("Email added successfully.\n");
                } else {
                    printf("Error: email could not be added (possibly full or duplicate).\n");
                }
                break;
            case 2:
                list_emails(&list);
                break;
            case 3:
                printf("Enter email to remove: ");
                scanf("%s", email);
                if (remove_email(&list, email) == 0) {
                    printf("Email removed successfully.\n");
                } else {
                    printf("Error: email not found.\n");
                }
                break;
            case 4:
                printf("Enter message to send: ");
                getchar(); // consume newline left by scanf
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // remove newline
                send_update(&list, message);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}