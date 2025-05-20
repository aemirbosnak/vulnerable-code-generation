//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct {
    char name[50];
    char email[100];
} subscriber;

int list_size = 0;
subscriber list[MAX_LIST_SIZE];

void add_subscriber(subscriber new_subscriber) {
    if (list_size == MAX_LIST_SIZE) {
        printf("List is full.\n");
        return;
    }
    strcpy(list[list_size].name, new_subscriber.name);
    strcpy(list[list_size].email, new_subscriber.email);
    list_size++;
}

void remove_subscriber(char* name) {
    int i;
    for (i = 0; i < list_size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            list_size--;
            break;
        }
    }
}

void send_email(char* name) {
    printf("Sending email to %s...\n", name);
}

int main() {
    subscriber new_subscriber;
    char choice;
    do {
        printf("Enter subscriber name: ");
        scanf("%s", new_subscriber.name);
        printf("Enter subscriber email: ");
        scanf("%s", new_subscriber.email);
        add_subscriber(new_subscriber);
        printf("Subscriber added.\n");
        printf("Enter 'a' to add another subscriber, 'r' to remove a subscriber,'s' to send an email, or 'q' to quit: ");
        scanf(" %c", &choice);
    } while (choice!= 'q');
    return 0;
}