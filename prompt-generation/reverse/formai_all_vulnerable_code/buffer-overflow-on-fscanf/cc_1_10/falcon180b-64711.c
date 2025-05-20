//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MSG_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char msg[MAX_MSG_LEN];
    contact recipient;
} message;

int main() {
    FILE *fp;
    contact contacts[100];
    int num_contacts = 0;
    message messages[100];
    int num_messages = 0;

    fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open contacts file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    fclose(fp);

    printf("Enter the number of messages you would like to send:\n");
    scanf("%d", &num_messages);

    for (int i = 0; i < num_messages; i++) {
        printf("Enter the subject of message %d:\n", i+1);
        scanf("%s", messages[i].subject);

        printf("Enter the recipient's name:\n");
        scanf("%s", messages[i].recipient.name);

        for (int j = 0; j < num_contacts; j++) {
            if (strcmp(messages[i].recipient.name, contacts[j].name) == 0) {
                strcpy(messages[i].recipient.email, contacts[j].email);
                break;
            }
        }

        printf("Enter the message:\n");
        fgets(messages[i].msg, MAX_MSG_LEN, stdin);
        messages[i].msg[strcspn(messages[i].msg, "\n")] = '\0';
    }

    fp = fopen("messages.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open messages file.\n");
        exit(1);
    }

    for (int i = 0; i < num_messages; i++) {
        fprintf(fp, "Subject: %s\nTo: %s\n\n%s\n\n", messages[i].subject, messages[i].recipient.email, messages[i].msg);
    }

    fclose(fp);

    printf("Messages sent successfully!\n");

    return 0;
}