//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 256

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initializeList(MailingList* list) {
    list->count = 0;
}

int isEmailValid(const char* email) {
    // Simple validation check
    return strchr(email, '@') != NULL && strchr(email, '.') != NULL;
}

int addSubscriber(MailingList* list, const char* email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return -1;
    }
    if (!isEmailValid(email)) {
        printf("Error: Invalid email format.\n");
        return -1;
    }

    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Subscriber %s added successfully.\n", email);
    return 0;
}

int removeSubscriber(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1]; // move last subscriber to the current position
            list->count--;
            printf("Subscriber %s removed successfully.\n", email);
            return 0;
        }
    }
    printf("Error: Subscriber %s not found.\n", email);
    return -1;
}

void displaySubscribers(const MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

void sendEmail(const MailingList* list, const char* subject, const char* message) {
    if (list->count == 0) {
        printf("No subscribers to send email.\n");
        return;
    }
    printf("Sending email with subject: %s\n", subject);
    printf("Message: %s\n", message);
    for (int i = 0; i < list->count; i++) {
        printf("Email sent to: %s\n", list->subscribers[i].email);
    }
}

int main() {
    MailingList mailingList;
    initializeList(&mailingList);

    int choice;
    char email[EMAIL_LENGTH];
    char subject[EMAIL_LENGTH];
    char message[512];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Send Email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline character
                addSubscriber(&mailingList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline character
                removeSubscriber(&mailingList, email);
                break;
            case 3:
                displaySubscribers(&mailingList);
                break;
            case 4:
                printf("Enter subject: ");
                fgets(subject, EMAIL_LENGTH, stdin);
                subject[strcspn(subject, "\n")] = '\0'; // Remove newline character
                printf("Enter message: ");
                fgets(message, 512, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character
                sendEmail(&mailingList, subject, message);
                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}