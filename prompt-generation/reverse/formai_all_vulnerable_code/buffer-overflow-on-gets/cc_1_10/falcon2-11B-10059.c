//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

int main() {
    char username[100];
    char password[100];
    char recipient[100];
    char subject[100];
    char message[10000];
    char email_header[10000];

    printf("Please enter your email address: ");
    gets(username);
    printf("Please enter your password: ");
    gets(password);
    printf("Please enter the recipient's email address: ");
    gets(recipient);
    printf("Please enter the subject: ");
    gets(subject);
    printf("Please enter the message: ");
    gets(message);

    strcpy(email_header, "From: ");
    strcat(email_header, username);
    strcat(email_header, "\r\n");
    strcat(email_header, "To: ");
    strcat(email_header, recipient);
    strcat(email_header, "\r\n");
    strcat(email_header, "Subject: ");
    strcat(email_header, subject);
    strcat(email_header, "\r\n");
    strcat(email_header, "Message-Id: ");
    strcat(email_header, "IMG_");
    strcat(email_header, username);
    strcat(email_header, "@");
    strcat(email_header, time(NULL));
    strcat(email_header, ".txt\r\n\r\n");

    strcat(email_header, message);

    FILE *fp = fopen("email.txt", "w");
    if (fp == NULL) {
        perror("Unable to open file");
        exit(1);
    }

    fputs(email_header, fp);
    fclose(fp);

    system("mail -s \"Email from C Client\" -a email.txt ");

    return 0;
}