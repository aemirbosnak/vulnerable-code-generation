//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBSCRIBERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void initializeMailingList(MailingList* list) {
    list->count = 0;
}

void addSubscriber(MailingList* list, const char* name, const char* email) {
    if (list->count < MAX_SUBSCRIBERS) {
        strncpy(list->subscribers[list->count].name, name, MAX_NAME_LENGTH - 1);
        strncpy(list->subscribers[list->count].email, email, MAX_EMAIL_LENGTH - 1);
        list->count++;
        printf("Subscriber added: %s <%s>\n", name, email);
    } else {
        printf("Error: Mailing list is full!\n");
    }
}

void removeSubscriber(MailingList* list, const char* email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Subscriber removed: <%s>\n", email);
            break;
        }
    }
    if (!found) {
        printf("Error: No subscriber found with email <%s>\n", email);
    }
}

void displaySubscribers(const MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
    } else {
        printf("Subscribers List:\n");
        for (int i = 0; i < list->count; i++) {
            printf("%d. %s <%s>\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
        }
    }
}

int findSubscriber(const MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    MailingList mailingList;
    initializeMailingList(&mailingList);

    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Display Subscribers\n");
        printf("4. Find Subscriber\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                addSubscriber(&mailingList, name, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                removeSubscriber(&mailingList, email);
                break;
            case 3:
                displaySubscribers(&mailingList);
                break;
            case 4:
                printf("Enter email to find: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline
                int index = findSubscriber(&mailingList, email);
                if (index != -1) {
                    printf("Subscriber found: %s <%s>\n", mailingList.subscribers[index].name, mailingList.subscribers[index].email);
                } else {
                    printf("Subscriber not found with email <%s>\n", email);
                }
                break;
            case 0:
                printf("Exiting the Mailing List Manager.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}