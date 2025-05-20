//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void add_subscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Email already subscribed: %s\n", email);
            return;
        }
    }

    strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("Subscribed: %s\n", email);
}

void display_subscribers(const MailingList *list) {
    printf("Current subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->subscribers[i].email);
    }
}

void remove_subscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1];
            list->count--;
            printf("Unsubscribed: %s\n", email);
            return;
        }
    }

    printf("Email not found in the list: %s\n", email);
}

void send_email(const MailingList *list, const char *subject, const char *message) {
    printf("Sending email...\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\nSubject: %s\nMessage: %s\n", 
               list->subscribers[i].email, subject, message);
    }
}

void save_to_file(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->subscribers[i].email);
    }

    fclose(file);
    printf("Mailing list saved to %s\n", filename);
}

void load_from_file(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char email[MAX_EMAIL_LENGTH];
    while (fgets(email, sizeof(email), file) != NULL) {
        email[strcspn(email, "\n")] = '\0'; // Remove newline character
        add_subscriber(list, email);
    }

    fclose(file);
    printf("Mailing list loaded from %s\n", filename);
}

int main() {
    MailingList list;
    list.count = 0;
    
    int choice;
    char email[MAX_EMAIL_LENGTH];
    char subject[100];
    char message[500];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Display Subscribers\n");
        printf("3. Remove Subscriber\n");
        printf("4. Send Email\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice) {
            case 1:
                printf("Enter email to subscribe: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline character
                add_subscriber(&list, email);
                break;
            case 2:
                display_subscribers(&list);
                break;
            case 3:
                printf("Enter email to unsubscribe: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline character
                remove_subscriber(&list, email);
                break;
            case 4:
                printf("Enter email subject: ");
                fgets(subject, sizeof(subject), stdin);
                subject[strcspn(subject, "\n")] = '\0'; // Remove newline character
                printf("Enter email message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character
                send_email(&list, subject, message);
                break;
            case 5:
                save_to_file(&list, "mailing_list.txt");
                break;
            case 6:
                load_from_file(&list, "mailing_list.txt");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}