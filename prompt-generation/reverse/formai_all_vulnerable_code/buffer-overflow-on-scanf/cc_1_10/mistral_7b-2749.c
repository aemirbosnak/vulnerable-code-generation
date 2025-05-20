//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(const char *name, const char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Invalid index.\n");
        return;
    }
    memmove(&subscribers[index], &subscribers[index + 1],
            (num_subscribers - index - 1) * sizeof(Subscriber));
    num_subscribers--;
}

void print_subscribers() {
    printf("Subscribers:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

void subscribe(const char *name, const char *email) {
    char cleaned_name[50];
    char cleaned_email[100];
    bool name_valid = true, email_valid = true;

    strcpy(cleaned_name, name);
    for (int i = 0; cleaned_name[i] != '\0'; i++) {
        cleaned_name[i] = tolower(cleaned_name[i]);
        if (!isalnum(cleaned_name[i]) && cleaned_name[i] != ' ') {
            name_valid = false;
            break;
        }
    }

    strcpy(cleaned_email, email);
    for (int i = 0; cleaned_email[i] != '\0'; i++) {
        if (cleaned_email[i] == '.' && (i > 0 && cleaned_email[i-1] == '.')) {
            email_valid = false;
            break;
        }
    }

    if (!name_valid || !email_valid) {
        printf("Invalid name or email.\n");
        return;
    }

    add_subscriber(name, email);
    printf("Subscribed: %s (%s)\n", name, email);
}

int main() {
    char command[50];
    char name[50], email[100];
    int index;

    while (true) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %s", name, email);
            subscribe(name, email);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &index);
            remove_subscriber(index);
        } else if (strcmp(command, "list") == 0) {
            print_subscribers();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}