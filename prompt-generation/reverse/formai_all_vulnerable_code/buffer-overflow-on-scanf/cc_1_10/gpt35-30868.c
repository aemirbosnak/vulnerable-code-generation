//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[500];
};

int main() {

    struct email new_email;

    printf("\nWelcome to My Email Client\n");

    printf("\nPlease enter the sender's email address: ");
    scanf("%s", new_email.sender);

    printf("\nPlease enter the recipient's email address: ");
    scanf("%s", new_email.recipient);

    printf("\nPlease enter the subject of the email: ");
    scanf("%s", new_email.subject);

    printf("\nPlease enter the message of the email: ");
    scanf("%s", new_email.message);

    char filename[50];
    strcpy(filename, new_email.recipient);
    strcat(filename, ".txt");

    FILE* fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("\nError: Could not open the file!\n");
        exit(1);
    }

    fprintf(fp, "\nFrom: %s", new_email.sender);
    fprintf(fp, "\nTo: %s", new_email.recipient);
    fprintf(fp, "\nSubject: %s", new_email.subject);
    fprintf(fp, "\nMessage: %s", new_email.message);

    fclose(fp);

    printf("\nEmail sent successfully!");

    return 0;
}