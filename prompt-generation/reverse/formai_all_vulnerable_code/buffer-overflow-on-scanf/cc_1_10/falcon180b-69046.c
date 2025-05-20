//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
#define MAX_EMAIL_SIZE 100
#define MAX_SUBJECT_SIZE 200
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} contact;

void add_contact(contact *list, int *size) {
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    printf("Enter email: ");
    scanf("%s", list[*size].email);
    (*size)++;
}

void print_contacts(contact *list, int size) {
    printf("Name\tEmail\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\n", list[i].name, list[i].email);
    }
}

void send_message(contact *list, int size, char *subject, char *message) {
    printf("Sending message to %d contacts...\n", size);
    for (int i = 0; i < size; i++) {
        printf("Sending message to %s...\n", list[i].email);
    }
}

int main() {
    contact *list = malloc(sizeof(contact));
    int size = 0;

    add_contact(list, &size);
    add_contact(list, &size);

    print_contacts(list, size);

    char subject[MAX_SUBJECT_SIZE] = "Important Message from Romeo";
    char message[MAX_MESSAGE_SIZE] = "Dear %s,\n\nThis is an important message from Romeo. I hope this finds you well.\n\nBest regards,\nRomeo";

    send_message(list, size, subject, message);

    free(list);
    return 0;
}