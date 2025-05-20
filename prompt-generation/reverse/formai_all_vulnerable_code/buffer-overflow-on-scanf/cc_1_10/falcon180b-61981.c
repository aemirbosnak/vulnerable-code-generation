//Falcon-180B DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

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

void read_recipients(email* e) {
    char input[100];
    int i = 0;

    printf("Enter recipient name and email (format: name@domain.com): ");
    scanf("%s", input);

    while (i < MAX_RECIPIENTS && strcmp(input, "")!= 0) {
        strcpy(e->recipients[i].name, input);
        strcpy(e->recipients[i].email, input);
        i++;
        printf("Enter another recipient name and email (format: name@domain.com): ");
        scanf("%s", input);
    }

    e->num_recipients = i;
}

void send_email(email* e) {
    FILE* fp;
    char filename[50];
    int i;

    sprintf(filename, "email_%d.txt", time(NULL));
    fp = fopen(filename, "w");

    fprintf(fp, "To: %s\r\n", e->recipients[0].email);
    for (i = 1; i < e->num_recipients; i++) {
        fprintf(fp, "Cc: %s\r\n", e->recipients[i].email);
    }
    fprintf(fp, "Subject: %s\r\n", e->subject);
    fprintf(fp, "\r\n");
    fprintf(fp, "%s", e->body);

    fclose(fp);

    system("mail -s \"Subject\" recipient@domain.com < email_*.txt");
    remove(filename);
}

int main() {
    email e;

    printf("Enter email subject: ");
    scanf("%s", e.subject);

    printf("Enter email body: ");
    fgets(e.body, MAX_BODY_LENGTH, stdin);

    read_recipients(&e);

    send_email(&e);

    return 0;
}