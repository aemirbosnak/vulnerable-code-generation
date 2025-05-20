//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 100
#define LINE_LENGTH 255

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_subscriber(char *email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < num_subscribers - 1; j++) {
                strcpy(subscribers[j].email, subscribers[j + 1].email);
                strcpy(subscribers[j].name, subscribers[j + 1].name);
            }
            num_subscribers--;
            break;
        }
    }
}

void print_subscribers() {
    int i;

    printf("\nMailing List:\n");
    for (i = 0; i < num_subscribers; i++) {
        printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
    }
}

int main(int argc, char *argv[]) {
    char name[50];
    char email[100];
    char command[50];

    while (1) {
        printf("\nRetro Mailing List Manager\n"
               "1. Add subscriber\n"
               "2. Remove subscriber\n"
               "3. Print list\n"
               "4. Exit\n"
               "Enter command: ");

        scanf("%s", command);

        switch (*command) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case '2':
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case '3':
                print_subscribers();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}