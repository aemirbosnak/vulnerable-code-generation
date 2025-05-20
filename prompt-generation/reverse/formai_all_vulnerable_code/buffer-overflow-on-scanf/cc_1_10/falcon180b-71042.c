//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_MESSAGES 10
#define SUBJECT_LEN 80

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact recipient;
    char subject[SUBJECT_LEN];
    char message[MAX_MESSAGES][100];
    int num_messages;
} mailing_list;

void add_contact(mailing_list *list) {
    contact new_contact;

    printf("Enter name: ");
    scanf("%s", new_contact.name);

    printf("Enter email: ");
    scanf("%s", new_contact.email);

    list->recipient = new_contact;
}

void add_message(mailing_list *list) {
    int i;

    printf("Enter subject: ");
    scanf("%s", list->subject);

    for (i = 0; i < MAX_MESSAGES; i++) {
        printf("Enter message %d: ", i+1);
        scanf("%s", list->message[i]);
    }

    list->num_messages = i;
}

void send_message(mailing_list *list) {
    int i;
    FILE *fp;
    char filename[20];

    sprintf(filename, "%s.txt", list->recipient.name);
    fp = fopen(filename, "w");

    fprintf(fp, "From: %s\n", list->recipient.name);
    fprintf(fp, "To: %s\n", list->recipient.email);
    fprintf(fp, "Subject: %s\n", list->subject);

    for (i = 0; i < list->num_messages; i++) {
        fprintf(fp, "%s\n", list->message[i]);
    }

    fclose(fp);

    printf("Message sent to %s\n", list->recipient.name);
}

int main() {
    mailing_list list;

    add_contact(&list);
    add_message(&list);
    send_message(&list);

    return 0;
}