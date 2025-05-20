//FormAI DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mail structure
typedef struct {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[500];
} Mail;

// function prototypes
void send_mail(Mail);
void read_mail(Mail*);

int main() {
    Mail mail;
    char choice;

    printf("Greetings noble user! Welcome to Ye Olde Email Client!\n");
    printf("What wouldst thou like to do?\n");

    do {
        printf("\n[1] - Sendeth mail\n[2] - Readeth mail\n[3] - Exiteth program\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("Compose thy message:\n");
                printf("From: ");
                scanf("%s", mail.sender);
                printf("To: ");
                scanf("%s", mail.recipient);
                printf("Subject: ");
                scanf("%s", mail.subject);
                printf("Message: ");
                getchar(); // clear buffer
                fgets(mail.message, 500, stdin);
                send_mail(mail);
                break;
            case '2':
                printf("Thy mailbox:\n");
                read_mail(&mail);
                break;
            case '3':
                printf("Fare thee well, noble user!\n");
                break;
            default:
                printf("That is not a valid option. Choose again!\n");
                break;
        }
    } while(choice != '3');

    return 0;
}

void send_mail(Mail mail) {
    FILE *fp;
    fp = fopen("mailbox.txt", "a");

    if(fp == NULL) {
        printf("Error: could not open mailbox.\n");
        return;
    }

    fprintf(fp, "From: %s\n", mail.sender);
    fprintf(fp, "To: %s\n", mail.recipient);
    fprintf(fp, "Subject: %s\n", mail.subject);
    fprintf(fp, "Message: %s\n", mail.message);
    fprintf(fp, "~~~\n");

    printf("Thy message hath been senteth!\n");

    fclose(fp);
}

void read_mail(Mail *mail) {
    FILE *fp;
    char line[500];

    fp = fopen("mailbox.txt", "r");

    if(fp == NULL) {
        printf("No messages in thy mailbox.\n");
        return;
    }

    while(fgets(line, 500, fp)) {
        if(strcmp(line, "~~~\n") == 0) {
            printf("\n");
            continue;
        }

        // get rid of "From: "
        if(strncmp(line, "From: ", 6) == 0) {
            strcpy(mail->sender, line + 6);
            mail->sender[strlen(mail->sender) - 1] = '\0'; // remove newline
            printf("From: %s\n", mail->sender);
        }

        // get rid of "To: "
        if(strncmp(line, "To: ", 4) == 0) {
            strcpy(mail->recipient, line + 4);
            mail->recipient[strlen(mail->recipient) - 1] = '\0';
            printf("To: %s\n", mail->recipient);
        }

        // get rid of "Subject: "
        if(strncmp(line, "Subject: ", 9) == 0) {
            strcpy(mail->subject, line + 9);
            mail->subject[strlen(mail->subject) - 1] = '\0';
            printf("Subject: %s\n", mail->subject);
        }

        // get rid of "Message: "
        if(strncmp(line, "Message: ", 9) == 0) {
            strcpy(mail->message, line + 9);
            mail->message[strlen(mail->message) - 1] = '\0';
            printf("Message: %s\n", mail->message);
        }
    }

    fclose(fp);
}