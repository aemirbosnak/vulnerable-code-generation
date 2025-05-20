//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_LINE_LENGTH 256

typedef struct Subscriber {
    char name[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
    struct Subscriber *next;
} Subscriber;

Subscriber *subscribers = NULL;
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *) malloc(sizeof(Subscriber));
    if (!new_subscriber) {
        printf("Error: unable to allocate memory for new subscriber\n");
        return;
    }
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = subscribers;
    subscribers = new_subscriber;
    num_subscribers++;
}

void remove_subscriber(char *name) {
    Subscriber *current = subscribers;
    Subscriber *previous = NULL;
    while (current != NULL) {
        if (strcasecmp(current->name, name) == 0) {
            if (previous == NULL) {
                subscribers = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            num_subscribers--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void print_subscribers() {
    Subscriber *current = subscribers;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

void process_command(char *command) {
    char name[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
    char action[MAX_LINE_LENGTH];
    sscanf(command, "%s %s %s", action, name, email);

    if (strcasecmp(action, "add") == 0) {
        add_subscriber(name, email);
    } else if (strcasecmp(action, "remove") == 0) {
        remove_subscriber(name);
    } else if (strcasecmp(action, "list") == 0) {
        print_subscribers();
    } else {
        printf("Error: invalid command\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [add name email | remove name | list | quit]\n", argv[0]);
        return 1;
    }

    char command[MAX_LINE_LENGTH];
    while (fgets(command, MAX_LINE_LENGTH, stdin) != NULL) {
        command[strcspn(command, "\n")] = '\0';
        process_command(command);
    }

    return 0;
}