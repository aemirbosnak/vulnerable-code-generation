//Falcon-180B DATASET v1.0 Category: Email Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_RECIPIENTS 10
#define MAX_RECIPIENT_LENGTH 256
#define MAX_BODY_LENGTH 4096

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email* read_email_from_file(FILE* fp) {
    Email* email = malloc(sizeof(Email));
    fscanf(fp, "From: %s\nTo: %s\nSubject: %s\n\n%[^\n]", email->from, email->to, email->subject, email->body);
    email->timestamp = time(NULL);
    return email;
}

void write_email_to_file(FILE* fp, Email* email) {
    fprintf(fp, "From: %s\nTo: %s\nSubject: %s\n\n%s", email->from, email->to, email->subject, email->body);
}

int main() {
    FILE* fp;
    char filename[MAX_EMAIL_LENGTH];
    Email* email;
    
    // Open the mailbox file
    printf("Enter mailbox file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r+");
    
    // Read the first email
    email = read_email_from_file(fp);
    
    // Display the email details
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s", email->body);
    printf("Timestamp: %s", ctime(&email->timestamp));
    
    // Close the mailbox file
    fclose(fp);
    
    return 0;
}