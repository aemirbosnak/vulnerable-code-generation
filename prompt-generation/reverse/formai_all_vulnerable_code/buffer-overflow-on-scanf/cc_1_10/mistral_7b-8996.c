//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBSCRIBERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int subscribed;
} Subscriber;

Subscriber mailing_list[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Alas, our list is full!\n");
        return;
    }
    strcpy(mailing_list[num_subscribers].name, name);
    mailing_list[num_subscribers].subscribed = 1;
    num_subscribers++;
    printf("Thy name is added to our list, %s.\n", name);
}

void remove_subscriber(char *name) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(mailing_list[i].name, name) == 0) {
            mailing_list[i].subscribed = 0;
            num_subscribers--;
            printf("%s hath left our list.\n", name);
            break;
        }
    }
    if (i == num_subscribers) {
        printf("No such subscriber in our list, %s.\n", name);
    }
}

void print_subscribers() {
    int i;
    printf("Our fair mailing list:\n");
    for (i = 0; i < num_subscribers; i++) {
        if (mailing_list[i].subscribed == 1) {
            printf("- %s\n", mailing_list[i].name);
        }
    }
}

int main() {
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    int choice;

    while (1) {
        printf("1. Add a subscriber\n");
        printf("2. Remove a subscriber\n");
        printf("3. Print subscribers\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a name: ");
                scanf("%s", name1);
                add_subscriber(name1);
                break;
            case 2:
                printf("Enter a name: ");
                scanf("%s", name1);
                remove_subscriber(name1);
                break;
            case 3:
                print_subscribers();
                break;
            case 4:
                printf("Farewell, dear user.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}