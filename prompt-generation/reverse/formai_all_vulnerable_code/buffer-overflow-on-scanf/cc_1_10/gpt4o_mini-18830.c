//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTS 10
#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char subscribers[MAX_SUBSCRIBERS][EMAIL_LENGTH];
    int subscriber_count;
} MailingList;

void initialize_list(MailingList *list, const char *name) {
    strncpy(list->name, name, NAME_LENGTH);
    list->subscriber_count = 0;
}

void add_subscriber(MailingList *list, const char *email) {
    if (list->subscriber_count >= MAX_SUBSCRIBERS) {
        printf("Cannot add subscriber, list is full.\n");
        return;
    }
    strncpy(list->subscribers[list->subscriber_count], email, EMAIL_LENGTH);
    list->subscriber_count++;
    printf("Subscriber %s added to %s list.\n", email, list->name);
}

void remove_subscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->subscriber_count; i++) {
        if (strcmp(list->subscribers[i], email) == 0) {
            for (int j = i; j < list->subscriber_count - 1; j++) {
                strncpy(list->subscribers[j], list->subscribers[j + 1], EMAIL_LENGTH);
            }
            list->subscriber_count--;
            printf("Subscriber %s removed from %s list.\n", email, list->name);
            return;
        }
    }
    printf("Subscriber %s not found in %s list.\n", email, list->name);
}

void display_subscribers(const MailingList *list) {
    printf("Subscribers for %s:\n", list->name);
    for (int i = 0; i < list->subscriber_count; i++) {
        printf(" - %s\n", list->subscribers[i]);
    }
}

int main() {
    MailingList mailingLists[MAX_LISTS];
    int list_count = 0;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Create Mailing List\n");
        printf("2. Add Subscriber\n");
        printf("3. Remove Subscriber\n");
        printf("4. Display Subscribers\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline from the input buffer

        switch (choice) {
            case 1: {
                if (list_count >= MAX_LISTS) {
                    printf("Maximum number of mailing lists reached!\n");
                    break;
                }
                char list_name[NAME_LENGTH];
                printf("Enter mailing list name: ");
                fgets(list_name, NAME_LENGTH, stdin);
                list_name[strcspn(list_name, "\n")] = 0; // Remove newline
                initialize_list(&mailingLists[list_count], list_name);
                list_count++;
                break;
            }
            case 2: {
                if (list_count == 0) {
                    printf("No mailing lists available. Create a list first.\n");
                    break;
                }
                char email[EMAIL_LENGTH];
                printf("Select mailing list (0 to %d): ", list_count - 1);
                int list_index;
                scanf("%d", &list_index);
                getchar(); // Clear newline
                if (list_index < 0 || list_index >= list_count) {
                    printf("Invalid mailing list index.\n");
                    break;
                }
                printf("Enter subscriber email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_subscriber(&mailingLists[list_index], email);
                break;
            }
            case 3: {
                if (list_count == 0) {
                    printf("No mailing lists available. Create a list first.\n");
                    break;
                }
                printf("Select mailing list (0 to %d): ", list_count - 1);
                int list_index;
                scanf("%d", &list_index);
                getchar(); // Clear newline
                if (list_index < 0 || list_index >= list_count) {
                    printf("Invalid mailing list index.\n");
                    break;
                }
                char email[EMAIL_LENGTH];
                printf("Enter subscriber email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                remove_subscriber(&mailingLists[list_index], email);
                break;
            }
            case 4: {
                if (list_count == 0) {
                    printf("No mailing lists available.\n");
                    break;
                }
                printf("Select mailing list (0 to %d): ", list_count - 1);
                int list_index;
                scanf("%d", &list_index);
                if (list_index < 0 || list_index >= list_count) {
                    printf("Invalid mailing list index.\n");
                    break;
                }
                display_subscribers(&mailingLists[list_index]);
                break;
            }
            case 5: {
                printf("Exiting program.\n");
                exit(0);
            }
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}