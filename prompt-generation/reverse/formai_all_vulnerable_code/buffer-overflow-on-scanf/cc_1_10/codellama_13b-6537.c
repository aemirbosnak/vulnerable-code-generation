//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
/// mailing_list_manager.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILING_LIST_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

void print_subscriber(Subscriber subscriber) {
    printf("Name: %s\n", subscriber.name);
    printf("Email: %s\n", subscriber.email);
}

void add_subscriber(Subscriber *subscribers, int *size, char *name, char *email) {
    Subscriber subscriber;
    strcpy(subscriber.name, name);
    strcpy(subscriber.email, email);
    subscribers[*size] = subscriber;
    *size += 1;
}

void remove_subscriber(Subscriber *subscribers, int *size, char *name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            subscribers[i] = subscribers[*size - 1];
            *size -= 1;
            break;
        }
    }
}

void update_subscriber(Subscriber *subscribers, int *size, char *name, char *email) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            strcpy(subscribers[i].email, email);
            break;
        }
    }
}

void print_mailing_list(Subscriber *subscribers, int size) {
    int i;
    for (i = 0; i < size; i++) {
        print_subscriber(subscribers[i]);
    }
}

int main() {
    Subscriber subscribers[MAX_MAILING_LIST_SIZE];
    int size = 0;

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    add_subscriber(subscribers, &size, name, email);

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    add_subscriber(subscribers, &size, name, email);

    printf("Enter name: ");
    scanf("%s", name);
    remove_subscriber(subscribers, &size, name);

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter new email: ");
    scanf("%s", email);
    update_subscriber(subscribers, &size, name, email);

    print_mailing_list(subscribers, size);

    return 0;
}