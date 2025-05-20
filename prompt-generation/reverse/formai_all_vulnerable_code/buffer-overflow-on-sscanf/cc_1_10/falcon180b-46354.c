//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 1000

typedef struct {
    char from[EMAIL_LENGTH];
    char subject[EMAIL_LENGTH];
    char body[EMAIL_LENGTH];
    char date[EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void read_emails() {
    FILE *file;
    file = fopen("emails.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open email file.\n");
        return;
    }
    char line[EMAIL_LENGTH];
    while (fgets(line, EMAIL_LENGTH, file)!= NULL) {
        Email email;
        sscanf(line, "%s %s %s %s", email.from, email.subject, email.body, email.date);
        strcpy(emails[num_emails].from, email.from);
        strcpy(emails[num_emails].subject, email.subject);
        strcpy(emails[num_emails].body, email.body);
        strcpy(emails[num_emails].date, email.date);
        num_emails++;
    }
    fclose(file);
}

void display_emails() {
    printf("Email Sender | Subject | Date\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%-20s %-25s %-20s\n", emails[i].from, emails[i].subject, emails[i].date);
    }
}

void search_emails() {
    char keyword[EMAIL_LENGTH];
    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);
    for (int i = 0; i < num_emails; i++) {
        if (strstr(emails[i].from, keyword)!= NULL || strstr(emails[i].subject, keyword)!= NULL || strstr(emails[i].body, keyword)!= NULL) {
            printf("%-20s %-25s %-20s\n", emails[i].from, emails[i].subject, emails[i].date);
        }
    }
}

int main() {
    read_emails();
    display_emails();
    search_emails();
    return 0;
}