//FormAI DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define MAX_EMAIL_LEN 100
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_SERVER_LEN 50

typedef struct Email {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char sender[MAX_EMAIL_LEN];
    char recipient[MAX_EMAIL_LEN];
} Email;

typedef struct Account {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char server[MAX_SERVER_LEN];
} Account;

Email emails[MAX_EMAILS];
int num_emails = 0;

void display_menu(Account account);
void display_emails();
void compose_email(Account account);
void send_email(Account account);
void authenticate(Account account);

int main() {
    Account account;
    printf("Enter your email username: ");
    fgets(account.username, MAX_USERNAME_LEN, stdin);
    printf("Enter your email password: ");
    fgets(account.password, MAX_PASSWORD_LEN, stdin);
    printf("Enter your email server: ");
    fgets(account.server, MAX_SERVER_LEN, stdin);

    authenticate(account);
    display_menu(account);

    return 0;
}

void display_menu(Account account) {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Compose an email\n");
        printf("2. Send an email\n");
        printf("3. Display emails\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                compose_email(account);
                break;
            case 2:
                send_email(account);
                break;
            case 3:
                display_emails();
                break;
            case 4:
                printf("\nLogging out...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 4);
}

void display_emails() {
    if (num_emails == 0) {
        printf("\nNo emails.\n");
        return;
    }

    printf("\nList of emails:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("[%d] %s\n", i+1, emails[i].subject);
    }

    int choice;
    do {
        printf("Enter email number to read (0 to go back): ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        if (choice < 0 || choice > num_emails) {
            printf("\nInvalid email selected.\n");
        } else if (choice != 0) {
            printf("\nEmail:\n");
            printf("Subject: %s\n", emails[choice-1].subject);
            printf("Body: %s\n", emails[choice-1].body);
            printf("From: %s\n", emails[choice-1].sender);
            printf("To: %s\n", emails[choice-1].recipient);
        }
    } while (choice != 0);
}

void compose_email(Account account) {
    if (num_emails == MAX_EMAILS) {
        printf("\nCannot compose more emails. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter email details:\n");
    printf("Recipient email: ");
    fgets(emails[num_emails].recipient, MAX_EMAIL_LEN, stdin);
    printf("Subject: ");
    fgets(emails[num_emails].subject, MAX_SUBJECT_LEN, stdin);
    printf("Body: ");
    fgets(emails[num_emails].body, MAX_BODY_LEN, stdin);
    printf("From: %s\n", account.username);

    strcpy(emails[num_emails].sender, account.username);
    num_emails++;

    printf("\nEmail has been composed.\n");
}

void send_email(Account account) {
    if (num_emails == 0) {
        printf("\nNo emails to send.\n");
        return;
    }

    printf("\nSending email:\n");
    printf("\nSMTP server: %s\n", account.server);
    printf("Username: %s\n", account.username);
    printf("Password: %s\n", account.password);

    int choice;
    printf("\nEnter email number to send: ");
    scanf("%d", &choice);
    getchar(); // consume the newline character

    if (choice < 1 || choice > num_emails) {
        printf("\nInvalid email selected.\n");
        return;
    }

    Email *email = &emails[choice-1];
    char command[MAX_BODY_LEN];
    sprintf(command, "echo 'To: %s\nFrom: %s\nSubject: %s\n%s\n' | "
            "openssl s_client -starttls smtp -crlf -connect %s:587 -quiet \
            -CAfile /etc/ssl/certs/ca-certificates.crt \
            -ign_eof -tls1_2 -verify_hostname %s -auth \
            -login -user \"%s\" -password \"%s\"",
            email->recipient, email->sender, email->subject, email->body,
            account.server, account.server, account.username, account.password);

    int status = system(command);
    if (status != 0) {
        printf("\nError sending email. Error code: %d\n", status);
    } else {
        printf("\nEmail sent successfully.\n");
    }
}

void authenticate(Account account) {
    printf("\nAuthenticating...\n");
    char command[MAX_BODY_LEN];
    sprintf(command, "ping -c 1 %s > /dev/null", account.server);
    int status = system(command);

    if (status != 0) {
        printf("\nCannot connect to server. Error code: %d\n", status);
        exit(EXIT_FAILURE);
    }

    printf("\nConnected successfully.\n");
}