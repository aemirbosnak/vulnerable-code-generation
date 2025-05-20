//FormAI DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100

struct subscriber {
    char name[50];
    char email[50];
};

struct mailing_list {
    struct subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers;
};

void add_subscriber(struct mailing_list* list, char* name, char* email) {
    if (list->num_subscribers == MAX_SUBSCRIBERS) {
        printf("Mailing list is full!");
        return;
    }
    struct subscriber new_subscriber;
    strcpy(new_subscriber.name, name);
    strcpy(new_subscriber.email, email);
    list->subscribers[list->num_subscribers++] = new_subscriber;
    printf("Subscriber %s <%s> added successfully!\n", name, email);
}

void display_list(struct mailing_list list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list.num_subscribers; i++) {
        printf("%s <%s>\n", list.subscribers[i].name, list.subscribers[i].email);
    }
    printf("\n");
}

void delete_subscriber(struct mailing_list* list, char* email) {
    int found_index = -1;
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            found_index = i;
            break;
        }
    }
    if (found_index == -1) {
        printf("Subscriber with email %s not found!\n", email);
        return;
    }
    for (int i = found_index; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }
    list->num_subscribers--;
    printf("Subscriber with email %s deleted successfully!\n", email);
}

void send_email(struct mailing_list list, char* subject, char* body) {
    printf("Sending email to %d subscribers...\n", list.num_subscribers);
    for (int i = 0; i < list.num_subscribers; i++) {
        printf("To: %s <%s>\nSubject: %s\n%s\n\n", list.subscribers[i].name, list.subscribers[i].email, subject, body);
    }
    printf("Email sent successfully!\n");
}

int main() {
    struct mailing_list list;
    list.num_subscribers = 0;
    char command[50];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[50], email[50];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_subscriber(&list, name, email);
        }

        else if (strcmp(command, "display") == 0) {
            display_list(list);
        }

        else if (strcmp(command, "delete") == 0) {
            char email[50];
            printf("Enter email: ");
            scanf("%s", email);
            delete_subscriber(&list, email);
        }

        else if (strcmp(command, "send") == 0) {
            char subject[100], body[1000];
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter body: ");
            scanf("%s", body);
            send_email(list, subject, body);
        }

        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}