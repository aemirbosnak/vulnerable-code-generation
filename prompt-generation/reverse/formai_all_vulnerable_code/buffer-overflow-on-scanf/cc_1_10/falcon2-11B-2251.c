//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MAIL_LENGTH 1000

int main() {
    char from[MAX_MAIL_LENGTH];
    char to[MAX_MAIL_LENGTH];
    char subject[MAX_MAIL_LENGTH];
    char message[MAX_MAIL_LENGTH];

    printf("Enter from address: ");
    scanf("%s", from);

    printf("Enter to address: ");
    scanf("%s", to);

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter message: ");
    scanf("%s", message);

    // Construct SMTP command
    char command[MAX_MAIL_LENGTH];
    strcpy(command, "HELO myhost");
    strcat(command, "\r\n");

    strcpy(command, "MAIL FROM:<");
    strcat(command, from);
    strcat(command, ">\r\n");

    strcpy(command, "RCPT TO:<");
    strcat(command, to);
    strcat(command, ">\r\n");

    strcpy(command, "DATA\r\n");
    strcat(command, "Subject: ");
    strcat(command, subject);
    strcat(command, "\r\n");
    strcat(command, "From: ");
    strcat(command, from);
    strcat(command, "\r\n");
    strcat(command, "To: ");
    strcat(command, to);
    strcat(command, "\r\n");
    strcat(command, "\r\n");
    strcat(command, "This is a test message.\r\n");
    strcat(command, ".\r\n");

    // Send the command
    FILE* connection = fopen("SMTP_connection.txt", "w");
    fprintf(connection, "%s", command);
    fclose(connection);

    return 0;
}