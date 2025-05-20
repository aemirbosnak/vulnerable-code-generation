//Falcon-180B DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char* from;
    char* to;
    char* subject;
    char* message;
    time_t timestamp;
} Email;

Email* create_email(char* from, char* to, char* subject, char* message) {
    Email* email = (Email*)malloc(sizeof(Email));
    email->from = from;
    email->to = to;
    email->subject = subject;
    email->message = message;
    email->timestamp = time(NULL);
    return email;
}

void print_email(Email* email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Message:\n%s\n", email->message);
    printf("Timestamp: %s\n\n", ctime(&email->timestamp));
}

int compare_emails(Email* a, Email* b) {
    return strcmp(a->to, b->to);
}

void sort_emails(Email* emails, int count) {
    qsort(emails, count, sizeof(Email), compare_emails);
}

int main() {
    Email* emails = NULL;
    int count = 0;
    char buffer[1024];
    FILE* fp;

    fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error: emails.txt not found.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        char* line = strdup(buffer);
        char* delimiter = ",";
        char* token = strtok(line, delimiter);

        if (token == NULL) {
            free(line);
            continue;
        }

        Email* email = create_email(token, strtok(NULL, delimiter), strtok(NULL, delimiter), strtok(NULL, delimiter));
        emails = (Email*)realloc(emails, sizeof(Email) * ++count);
        emails[count-1] = *email;
        free(email);
    }

    fclose(fp);

    sort_emails(emails, count);

    for (int i = 0; i < count; i++) {
        print_email(&emails[i]);
    }

    free(emails);
    return 0;
}