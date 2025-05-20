//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define DELIMITER ","
#define EMAIL_ADDRESS "@"

typedef struct {
    char name[MAX_LINE];
    char email[MAX_LINE];
} contact;

void read_csv(FILE *file, contact contacts[]) {
    int i = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file)!= NULL) {
        int j = 0;
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (j == 0) {
                strcpy(contacts[i].name, token);
            } else if (j == 1) {
                strcpy(contacts[i].email, token);
            }
            j++;
            token = strtok(NULL, DELIMITER);
        }
        i++;
    }
}

void send_email(contact recipient, char subject[], char message[]) {
    printf("Sending email to %s (%s)\n", recipient.name, recipient.email);
    printf("Subject: %s\n", subject);
    printf("Message:\n%s\n", message);
}

void main() {
    FILE *file;
    contact contacts[MAX_LINE];
    int num_contacts = 0;
    char filename[MAX_LINE];
    printf("Enter CSV file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    read_csv(file, contacts);
    fclose(file);
    printf("Enter number of contacts to email: ");
    scanf("%d", &num_contacts);
    for (int i = 0; i < num_contacts; i++) {
        printf("Enter email subject: ");
        char subject[MAX_LINE];
        scanf("%s", subject);
        printf("Enter email message: ");
        char message[MAX_LINE];
        scanf("%s", message);
        send_email(contacts[i], subject, message);
    }
}