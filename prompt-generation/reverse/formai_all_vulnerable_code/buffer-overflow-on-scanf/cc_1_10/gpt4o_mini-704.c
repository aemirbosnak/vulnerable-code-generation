//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_MAILS];
    int count;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *name, const char *email) {
    if (list->count >= MAX_MAILS) {
        return -1; // Mailing list is full
    }
    strncpy(list->subscribers[list->count].name, name, MAX_NAME_LENGTH);
    strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    return 0;
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return 0; // Successfully removed
        }
    }
    return -1; // Subscriber not found
}

void displaySubscribers(const MailingList *list) {
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s <%s>\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

void sendNewsletter(const MailingList *list, const char *newsletter) {
    printf("Sending Newsletter:\n%s\n", newsletter);
    for (int i = 0; i < list->count; i++) {
        printf("Sending to %s at %s\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

void showMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Send Newsletter\n");
    printf("5. Exit\n");
}

int main() {
    MailingList myMailingList;
    initializeMailingList(&myMailingList);
    
    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    char newsletter[256];

    do {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter subscriber name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                
                printf("Enter subscriber email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline

                if (addSubscriber(&myMailingList, name, email) == 0) {
                    printf("Subscriber added successfully!\n");
                } else {
                    printf("Mailing list is full!\n");
                }
                break;

            case 2:
                printf("Enter email of subscriber to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline

                if (removeSubscriber(&myMailingList, email) == 0) {
                    printf("Subscriber removed successfully!\n");
                } else {
                    printf("Subscriber not found!\n");
                }
                break;

            case 3:
                displaySubscribers(&myMailingList);
                break;

            case 4:
                printf("Enter newsletter content: ");
                fgets(newsletter, sizeof(newsletter), stdin);
                newsletter[strcspn(newsletter, "\n")] = 0; // Remove newline
                
                sendNewsletter(&myMailingList, newsletter);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}