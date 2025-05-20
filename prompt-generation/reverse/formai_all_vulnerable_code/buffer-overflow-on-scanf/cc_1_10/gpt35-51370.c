//FormAI DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_EMAILS];
int numSubscribers = 0;

void addSubscriber(char* name, char* email) {
    Subscriber subscriber;
    strcpy(subscriber.name, name);
    strcpy(subscriber.email, email);
    subscribers[numSubscribers++] = subscriber;
    printf("%s has been added to the mailing list.\n", name);
}

void removeSubscriber(char* email) {
    int index = -1;
    for (int i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("%s has been removed from the mailing list.\n", subscribers[index].name);
        for (int i = index; i < numSubscribers-1; i++) {
            subscribers[i] = subscribers[i+1];
        }
        numSubscribers--;
    } else {
        printf("No subscriber found with that email address.\n");
    }
}

void printSubscribers() {
    if (numSubscribers == 0) {
        printf("There are no subscribers.\n");
    } else {
        printf("Mailing List:\n");
        for (int i = 0; i < numSubscribers; i++) {
            printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
        }
    }
}

int main() {
    while (1) {
        printf("Enter a command (add, remove, print, quit): ");
        char command[10];
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            printf("Enter email: ");
            char email[MAX_EMAIL_LENGTH];
            scanf("%s", email);
            addSubscriber(name, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email: ");
            char email[MAX_EMAIL_LENGTH];
            scanf("%s", email);
            removeSubscriber(email);
        } else if (strcmp(command, "print") == 0) {
            printSubscribers();
        } else if (strcmp(command, "quit") == 0) {
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}