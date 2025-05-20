//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define LIST_SIZE 100

typedef struct {
    char name[NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber *subscribers;
    int count;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->subscribers = malloc(LIST_SIZE * sizeof(Subscriber));
    list->count = 0;
}

void addSubscriber(MailingList *list, const char *name) {
    if (list->count < LIST_SIZE) {
        strcpy(list->subscribers[list->count].name, name);
        list->count++;
        printf("Wow! %s has been added to the mailing list!\n", name);
    } else {
        printf("Oh no! The mailing list is full. Can't add %s!\n", name);
    }
}

void removeSubscriber(MailingList *list, const char *name) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            found = 1;
            printf("Whoa! %s has been removed from the mailing list!\n", name);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            break;
        }
    }
    if (!found) {
        printf("Hmm... It seems that %s is not in the mailing list!\n", name);
    }
}

void displaySubscribers(const MailingList *list) {
    printf("Here are the current subscribers in the mailing list:\n");
    if (list->count == 0) {
        printf("Surprise! No subscribers yet!\n");
    } else {
        for (int i = 0; i < list->count; i++) {
            printf("%d. %s\n", i + 1, list->subscribers[i].name);
        }
    }
}

void cleanupMailingList(MailingList *list) {
    free(list->subscribers);
    list->subscribers = NULL;
}

int main() {
    MailingList mailingList;
    initializeMailingList(&mailingList);
    char command[10];
    char name[NAME_LENGTH];

    printf("Welcome to the Amazing Mailing List Manager! 🎉\n");

    while (1) {
        printf("\nChoose an option: [add/remove/display/exit] ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Who wants to join the mailing list? ");
            scanf("%s", name);
            addSubscriber(&mailingList, name);
        } else if (strcmp(command, "remove") == 0) {
            printf("Who should be removed from the mailing list? ");
            scanf("%s", name);
            removeSubscriber(&mailingList, name);
        } else if (strcmp(command, "display") == 0) {
            displaySubscribers(&mailingList);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the mailing list manager. Bye! 💌\n");
            break;
        } else {
            printf("What a twist! Unknown command. Please use add/remove/display/exit.\n");
        }
    }

    cleanupMailingList(&mailingList);
    return 0;
}