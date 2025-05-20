//Falcon-180B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 5000
#define MAX_RECIPIENTS 100

typedef struct {
    char name[50];
    char email[100];
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_recipients;
    recipient recipients[MAX_RECIPIENTS];
} email;

void read_recipients_from_file(char* filename, recipient* recipients, int max_recipients) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    int num_recipients = 0;
    while (fscanf(file, "%s %s\n", recipients[num_recipients].name, recipients[num_recipients].email)!= EOF) {
        num_recipients++;
        if (num_recipients == max_recipients) {
            break;
        }
    }

    fclose(file);
}

void send_email(email* msg) {
    time_t now = time(NULL);
    char* date_str = ctime(&now);
    date_str[strcspn(date_str, "\n")] = '\0';

    printf("Sending email:\n");
    printf("  Subject: %s\n", msg->subject);
    printf("  Body:\n%s\n", msg->body);
    printf("  Recipients:\n");
    for (int i = 0; i < msg->num_recipients; i++) {
        printf("    %s <%s>\n", msg->recipients[i].name, msg->recipients[i].email);
    }

    printf("Email sent on %s\n", date_str);
}

int main() {
    email msg;
    strcpy(msg.subject, "Test Email");
    strcpy(msg.body, "Hello, world!");

    recipient recipients[MAX_RECIPIENTS];
    read_recipients_from_file("recipients.txt", recipients, MAX_RECIPIENTS);
    msg.num_recipients = 0;
    for (int i = 0; i < MAX_RECIPIENTS && msg.num_recipients < MAX_RECIPIENTS; i++) {
        if (strcmp(recipients[i].email, "")!= 0) {
            strcpy(msg.recipients[msg.num_recipients].name, recipients[i].name);
            strcpy(msg.recipients[msg.num_recipients].email, recipients[i].email);
            msg.num_recipients++;
        }
    }

    send_email(&msg);

    return 0;
}