//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[100];
    struct subscriber *next;
};

struct subscriber *head = NULL;

void add_subscriber(char name[], char email[]) {
    struct subscriber *new_subscriber = (struct subscriber*) malloc(sizeof(struct subscriber));
    if (new_subscriber == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for subscriber.\n");
        return;
    }
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    if (head == NULL) {
        head = new_subscriber;
    } else {
        struct subscriber *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
}

void remove_subscriber(char name[], char email[]) {
    struct subscriber *current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0 && strcmp(current->email, email) == 0) {
            if (current->next == NULL) {
                head = NULL;
            } else {
                struct subscriber *temp = current->next;
                free(current);
                current = temp;
            }
            return;
        }
        current = current->next;
    }
    fprintf(stderr, "Error: Subscriber not found.\n");
}

void list_subscribers() {
    struct subscriber *current = head;
    while (current!= NULL) {
        printf("Name: %s, Email: %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char name[50], email[100];
    printf("Enter subscriber name: ");
    scanf("%s", name);
    printf("Enter subscriber email: ");
    scanf("%s", email);

    add_subscriber(name, email);

    list_subscribers();

    remove_subscriber(name, email);

    list_subscribers();

    return 0;
}