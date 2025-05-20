//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Subscriber {
        char name[100];
        char email[100];
    };

    struct MailingList {
        int num_subscribers;
        struct Subscriber *subscribers;
    };

    void add_subscriber(struct MailingList *list, char *name, char *email) {
        list->num_subscribers++;
        list->subscribers = realloc(list->subscribers, list->num_subscribers * sizeof(struct Subscriber));
        strcpy(list->subscribers[list->num_subscribers - 1].name, name);
        strcpy(list->subscribers[list->num_subscribers - 1].email, email);
    }

    void remove_subscriber(struct MailingList *list, char *name) {
        int i;
        for (i = 0; i < list->num_subscribers; i++) {
            if (strcmp(list->subscribers[i].name, name) == 0) {
                list->num_subscribers--;
                for (int j = i; j < list->num_subscribers; j++) {
                    list->subscribers[j] = list->subscribers[j + 1];
                }
                break;
            }
        }
    }

    void send_email(struct MailingList *list, char *subject, char *body) {
        int i;
        for (i = 0; i < list->num_subscribers; i++) {
            printf("Sending email to %s\n", list->subscribers[i].email);
        }
    }

    int main() {
        struct MailingList list;
        list.num_subscribers = 0;
        list.subscribers = NULL;

        add_subscriber(&list, "John Doe", "john.doe@example.com");
        add_subscriber(&list, "Jane Doe", "jane.doe@example.com");
        remove_subscriber(&list, "John Doe");

        send_email(&list, "Welcome to our mailing list!", "Welcome to our mailing list!");

        return 0;
    }