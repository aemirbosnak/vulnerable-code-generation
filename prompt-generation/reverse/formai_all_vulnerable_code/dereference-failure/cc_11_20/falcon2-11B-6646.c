//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SUBSCRIBERS 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 5000

// data structure to hold the list of subscribers
struct Subscriber {
    char name[MAX_SUBJECT_LEN];
    char email[MAX_SUBJECT_LEN];
};

// global variable to hold the list of subscribers
struct Subscriber subscribers[MAX_SUBSCRIBERS];

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <subscribe|unsubscribe|list> <name> <email>\n", argv[0]);
        return 1;
    }

    char command[100];
    strcpy(command, argv[1]);
    if (strcmp(command, "subscribe") == 0) {
        if (argc < 3 || argc > 3) {
            printf("Usage: %s subscribe <name> <email>\n", argv[0]);
            return 1;
        }

        strcpy(subscribers[MAX_SUBSCRIBERS-1].name, argv[2]);
        strcpy(subscribers[MAX_SUBSCRIBERS-1].email, argv[3]);
        printf("Successfully subscribed %s (%s) to the mailing list.\n", subscribers[MAX_SUBSCRIBERS-1].name, subscribers[MAX_SUBSCRIBERS-1].email);
    } else if (strcmp(command, "unsubscribe") == 0) {
        if (argc < 3 || argc > 3) {
            printf("Usage: %s unsubscribe <name>\n", argv[0]);
            return 1;
        }

        for (int i = 0; i < MAX_SUBSCRIBERS; i++) {
            if (strcmp(subscribers[i].name, argv[2]) == 0) {
                memset(subscribers[i].name, '\0', sizeof(subscribers[i].name));
                memset(subscribers[i].email, '\0', sizeof(subscribers[i].email));
                printf("Successfully unsubscribed %s (%s) from the mailing list.\n", subscribers[i].name, subscribers[i].email);
                return 0;
            }
        }
        printf("User '%s' not found in the mailing list.\n", argv[2]);
    } else if (strcmp(command, "list") == 0) {
        for (int i = 0; i < MAX_SUBSCRIBERS; i++) {
            printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
        }
    } else {
        printf("Unknown command: %s\n", command);
    }

    return 0;
}