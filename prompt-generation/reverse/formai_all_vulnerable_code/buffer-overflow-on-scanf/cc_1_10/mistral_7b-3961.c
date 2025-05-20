//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 100

typedef struct subscriber {
    char name[50];
    char email[100];
} Subscriber;

Subscriber list[MAX_SUBSCRIBERS];
int count = 0;

void add_subscriber(char *name, char *email) {
    if (count >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strcpy(list[count].name, name);
    strcpy(list[count].email, email);

    printf("Subscriber %s (%s) added successfully.\n", name, email);
    count++;
}

void remove_subscriber(char *name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(list[j].name, list[j+1].name);
                strcpy(list[j].email, list[j+1].email);
            }

            count--;
            printf("Subscriber %s removed successfully.\n", name);
            return;
        }
    }

    printf("Error: Subscriber %s not found.\n", name);
}

void view_subscribers() {
    int i;

    printf("Current mailing list:\n");

    for (i = 0; i < count; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }
}

int main(int argc, char *argv[]) {
    char command[50], name[50], email[100];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_subscriber(name, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            remove_subscriber(name);
        } else if (strcmp(command, "view") == 0) {
            view_subscribers();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}