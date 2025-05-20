//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_EMAIL 100
#define MAX_SUBJECT 100
#define MAX_MESSAGE 500

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} contact;

void add_contact(contact* list, int size) {
    printf("Enter name: ");
    scanf("%s", list[size].name);
    printf("Enter email: ");
    scanf("%s", list[size].email);
}

void send_message(contact* list, int size, char* subject, char* message) {
    printf("Sending message to %d contacts...\n", size);
    for(int i = 0; i < size; i++) {
        printf("Sending message to %s...\n", list[i].name);
    }
}

int main() {
    int size;
    printf("Enter number of contacts: ");
    scanf("%d", &size);

    contact* list = malloc(sizeof(contact) * size);

    for(int i = 0; i < size; i++) {
        add_contact(list, i);
    }

    char subject[MAX_SUBJECT];
    printf("Enter subject: ");
    scanf("%s", subject);

    char message[MAX_MESSAGE];
    printf("Enter message: ");
    scanf("%s", message);

    send_message(list, size, subject, message);

    free(list);
    return 0;
}