//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct {
    char name[50];
    int isSubscribed;
} ListMember;

ListMember list[MAX_LIST_SIZE];
int numSubscribers = 0;

void subscribe(char *name) {
    if (numSubscribers >= MAX_LIST_SIZE) {
        printf("Oops! Our list is full. Come back another time.\n");
        return;
    }
    strcpy(list[numSubscribers].name, name);
    list[numSubscribers].isSubscribed = 1;
    printf("%s, you have been added to our Funny List! Yay!\n", name);
    numSubscribers++;
}

void unsubscribe(char *name) {
    int i;
    for (i = 0; i < numSubscribers; i++) {
        if (strcmp(list[i].name, name) == 0) {
            list[i].isSubscribed = 0;
            printf("%s, you have been unsubscribed from our Funny List. Boo!\n", name);
            numSubscribers--;
            i--;
            break;
        }
    }
    if (i == numSubscribers) {
        printf("%s, we're sorry but we couldn't find your name on our list.\n", name);
    }
}

int main() {
    char command[20], name[50];

    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "subscribe") == 0) {
            printf("Enter your name: ");
            scanf("%s", name);
            subscribe(name);
        } else if (strcmp(command, "unsubscribe") == 0) {
            printf("Enter your name: ");
            scanf("%s", name);
            unsubscribe(name);
        } else {
            printf("Sorry, we don't support that command yet. Try 'subscribe' or 'unsubscribe'.\n");
        }
    }

    return 0;
}