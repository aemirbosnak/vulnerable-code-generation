//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_EMAILS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

int addSubscriber(MailingList *list, const char *name, const char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("Error: Mailing list is full!\n");
        return -1;
    }
    strncpy(list->subscribers[list->count].name, name, MAX_NAME_LEN - 1);
    strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LEN - 1);
    list->count++;
    printf("Subscriber added: %s <%s>\n", name, email);
    return 0;
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Removing subscriber: %s <%s>\n", list->subscribers[i].name, email);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            return 0;
        }
    }
    printf("Subscriber with email %s not found!\n", email);
    return -1;
}

void printSubscribers(const MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s <%s>\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

int searchSubscriber(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Subscriber found: %s <%s>\n", list->subscribers[i].name, email);
            return 0;
        }
    }
    printf("Subscriber with email %s not found!\n", email);
    return -1;
}

void printMenu() {
    printf("\nMailing List Manager:\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Print Subscribers\n");
    printf("4. Search Subscriber\n");
    printf("5. Exit\n");
}

int main() {
    MailingList list;
    initializeList(&list);
    int choice;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    do {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline to avoid skipping input

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LEN, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                addSubscriber(&list, name, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LEN, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                removeSubscriber(&list, email);
                break;

            case 3:
                printSubscribers(&list);
                break;

            case 4:
                printf("Enter email to search: ");
                fgets(email, MAX_EMAIL_LEN, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                searchSubscriber(&list, email);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}