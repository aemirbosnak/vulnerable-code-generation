//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

typedef struct {
    subscriber subscribers[MAX_LIST_SIZE];
    int num_subscribers;
} mailing_list;

void add_subscriber(mailing_list *list, const char *name, const char *email) {
    if (list->num_subscribers >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

void remove_subscriber(mailing_list *list, const char *email) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->num_subscribers--;
            for (; i < list->num_subscribers; i++) {
                list->subscribers[i] = list->subscribers[i + 1];
            }
            return;
        }
    }

    printf("Error: Subscriber not found.\n");
}

void send_message(mailing_list *list, const char *message) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("%s\n\n", message);
    }
}

int main() {
    mailing_list list;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char message[1000];
    int choice;

    memset(&list, 0, sizeof(mailing_list));

    do {
        printf("Sherlock Holmes Mailing List Manager\n");
        printf("---------------------------------\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send message\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(&list, name, email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                remove_subscriber(&list, email);
                break;
            case 3:
                printf("Enter message: ");
                scanf("%s", message);
                send_message(&list, message);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}