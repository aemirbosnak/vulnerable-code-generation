//Falcon-180B DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024 // Maximum line size
#define MAX_EMAIL_SIZE 2048 // Maximum email size
#define MAX_SUBJECT_SIZE 256 // Maximum subject size

typedef struct {
    char from[MAX_LINE_SIZE]; // From address
    char to[MAX_LINE_SIZE]; // To address
    char subject[MAX_SUBJECT_SIZE]; // Subject
    char body[MAX_EMAIL_SIZE]; // Body
} Email;

Email read_email(FILE *file) {
    Email email;
    char line[MAX_LINE_SIZE];
    int i = 0;

    // Read from address
    fgets(line, MAX_LINE_SIZE, file);
    strcpy(email.from, line);

    // Read to address
    fgets(line, MAX_LINE_SIZE, file);
    strcpy(email.to, line);

    // Read subject
    fgets(line, MAX_SUBJECT_SIZE, file);
    strcpy(email.subject, line);

    // Read body
    while (fgets(line, MAX_EMAIL_SIZE, file)!= NULL) {
        strcat(email.body, line);
        i++;
        if (i == 10) { // Limit body to 10 lines
            break;
        }
    }

    return email;
}

void send_email(Email email) {
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Email email = read_email(file);
    send_email(email);

    fclose(file);
    return 0;
}