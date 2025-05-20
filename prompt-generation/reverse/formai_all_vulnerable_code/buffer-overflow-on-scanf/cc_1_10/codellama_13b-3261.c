//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: ephemeral
// A unique C Email Client example program in an ephemeral style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent an email
struct email {
    char subject[100];
    char sender[100];
    char body[1000];
};

// Define a structure to represent a list of emails
struct email_list {
    struct email *emails;
    int num_emails;
};

// Function to read a single email from stdin
struct email read_email() {
    struct email email;
    char subject[100];
    char sender[100];
    char body[1000];

    printf("Enter the subject: ");
    fgets(subject, 100, stdin);
    printf("Enter the sender: ");
    fgets(sender, 100, stdin);
    printf("Enter the body: ");
    fgets(body, 1000, stdin);

    strcpy(email.subject, subject);
    strcpy(email.sender, sender);
    strcpy(email.body, body);

    return email;
}

// Function to print a single email to stdout
void print_email(struct email email) {
    printf("Subject: %s\n", email.subject);
    printf("Sender: %s\n", email.sender);
    printf("Body: %s\n", email.body);
}

// Function to read a list of emails from stdin
struct email_list read_email_list() {
    struct email_list email_list;
    int num_emails;

    printf("Enter the number of emails: ");
    scanf("%d", &num_emails);

    email_list.emails = (struct email *)malloc(num_emails * sizeof(struct email));
    email_list.num_emails = num_emails;

    for (int i = 0; i < num_emails; i++) {
        email_list.emails[i] = read_email();
    }

    return email_list;
}

// Function to print a list of emails to stdout
void print_email_list(struct email_list email_list) {
    for (int i = 0; i < email_list.num_emails; i++) {
        print_email(email_list.emails[i]);
    }
}

int main() {
    struct email_list email_list = read_email_list();
    print_email_list(email_list);
    return 0;
}