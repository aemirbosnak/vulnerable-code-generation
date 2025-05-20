//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBSCRIBERS 100
#define FILE_NAME "subscribers.txt"

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;

// Function to load subscribers from the file
void load_subscribers() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fgets(subscribers[subscriber_count].email, MAX_EMAIL_LENGTH, file) && subscriber_count < MAX_SUBSCRIBERS) {
            subscribers[subscriber_count].email[strcspn(subscribers[subscriber_count].email, "\n")] = 0; // Remove newline
            subscriber_count++;
        }
        fclose(file);
    }
}

// Function to save subscribers to the file
void save_subscribers() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < subscriber_count; i++) {
            fprintf(file, "%s\n", subscribers[i].email);
        }
        fclose(file);
    }
}

// Function to subscribe a new email
void subscribe(const char *email) {
    if (subscriber_count >= MAX_SUBSCRIBERS) {
        printf("Subscriber limit reached.\n");
        return;
    }
    for (int i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            printf("Email already subscribed.\n");
            return;
        }
    }
    strcpy(subscribers[subscriber_count].email, email);
    subscriber_count++;
    save_subscribers();
    printf("Subscribed: %s\n", email);
}

// Function to unsubscribe an email
void unsubscribe(const char *email) {
    for (int i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            // Remove subscriber by shifting subsequent emails
            for (int j = i; j < subscriber_count - 1; j++) {
                subscribers[j] = subscribers[j + 1];
            }
            subscriber_count--;
            save_subscribers();
            printf("Unsubscribed: %s\n", email);
            return;
        }
    }
    printf("Email not found.\n");
}

// Function to send broadcast email
void send_email(const char *message) {
    printf("Sending email to subscribers:\n");
    for (int i = 0; i < subscriber_count; i++) {
        printf("To: %s - Message: %s\n", subscribers[i].email, message);
        // Simulated sending; actual sending would require an SMTP library or API
    }
    printf("All emails sent!\n");
}

// Main function with a simple command loop
int main() {
    load_subscribers();
    char command[10];
    char email[MAX_EMAIL_LENGTH];
    char message[256];

    while (1) {
        printf("Enter command (subscribe, unsubscribe, send, exit): ");
        scanf("%s", command);

        if (strcmp(command, "subscribe") == 0) {
            printf("Enter email to subscribe: ");
            scanf("%s", email);
            subscribe(email);
        } else if (strcmp(command, "unsubscribe") == 0) {
            printf("Enter email to unsubscribe: ");
            scanf("%s", email);
            unsubscribe(email);
        } else if (strcmp(command, "send") == 0) {
            printf("Enter message to send: ");
            getchar(); // clear newline
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Remove newline
            send_email(message);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}