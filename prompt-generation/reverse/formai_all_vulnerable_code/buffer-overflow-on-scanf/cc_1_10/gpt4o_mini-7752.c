//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

// Function prototypes
void addSubscriber(MailingList *list);
void removeSubscriber(MailingList *list);
void displaySubscribers(const MailingList *list);
void sendEmailToAll(const MailingList *list);
void clearInputBuffer(void);

int main() {
    MailingList list = {.count = 0};
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Send Email to All\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear newline from buffer after scanf

        switch (choice) {
            case 1:
                addSubscriber(&list);
                break;
            case 2:
                removeSubscriber(&list);
                break;
            case 3:
                displaySubscribers(&list);
                break;
            case 4:
                sendEmailToAll(&list);
                break;
            case 5:
                printf("Exiting the program. Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addSubscriber(MailingList *list) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return;
    }

    Subscriber newSubscriber;
    printf("Enter name: ");
    fgets(newSubscriber.name, NAME_LENGTH, stdin);
    newSubscriber.name[strcspn(newSubscriber.name, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(newSubscriber.email, EMAIL_LENGTH, stdin);
    newSubscriber.email[strcspn(newSubscriber.email, "\n")] = '\0'; // Remove newline

    list->subscribers[list->count] = newSubscriber;
    list->count++;
    printf("Subscriber added!\n");
}

void removeSubscriber(MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers to remove.\n");
        return;
    }

    char email[EMAIL_LENGTH];
    printf("Enter email of subscriber to remove: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            // Shift remaining subscribers down
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Subscriber removed!\n");
            return;
        }
    }

    printf("No subscriber found with that email.\n");
}

void displaySubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }

    printf("\nSubscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s (%s)\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

void sendEmailToAll(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers to send email!\n");
        return;
    }

    char subject[100];
    char message[256];

    printf("Enter email subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0'; // Remove newline

    printf("Enter email message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline

    printf("\nSending email to all subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\nSubject: %s\nMessage: %s\n\n", list->subscribers[i].email, subject, message);
    }
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}