//Falcon-180B DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to remove whitespace from the beginning and end of a string
void trim(char *str) {
    char *end;

    // Remove whitespace from the end of the string
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }

    // Remove whitespace from the beginning of the string
    while (isspace(*str)) {
        str++;
    }
}

// Function to read a line of input from the user
char *readline() {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t bytes_read;

    // Read a line of input from the user
    while ((bytes_read = getline(&line, &capacity, stdin))!= -1) {
        // If the line is too long, allocate more memory and continue reading
        if (bytes_read >= capacity) {
            capacity += MAX_LINE_LENGTH;
            line = realloc(line, capacity);
        }
    }

    // Remove whitespace from the beginning and end of the line
    trim(line);

    return line;
}

// Function to send an email
void send_email(char *to, char *subject, char *body) {
    FILE *fp;
    char command[100];

    // Open a pipe to the sendmail command
    fp = popen("sendmail -t", "w");

    // Write the email headers to the pipe
    fprintf(fp, "To: %s\r\n", to);
    fprintf(fp, "Subject: %s\r\n", subject);
    fprintf(fp, "\r\n");

    // Write the email body to the pipe
    fprintf(fp, "%s", body);

    // Close the pipe
    pclose(fp);
}

// Function to main function
int main() {
    char *to, *subject, *body;

    // Read the recipient email address
    printf("Enter recipient email address: ");
    to = readline();

    // Read the email subject
    printf("Enter email subject: ");
    subject = readline();

    // Read the email body
    printf("Enter email body: ");
    body = readline();

    // Send the email
    send_email(to, subject, body);

    return 0;
}