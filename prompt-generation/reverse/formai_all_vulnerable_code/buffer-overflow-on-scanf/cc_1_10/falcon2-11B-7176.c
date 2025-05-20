//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username[50];
    char password[50];
    char recipient[50];
    char message[500];
} Email;

int main() {
    Email email;

    printf("Enter your email username: ");
    scanf("%s", email.username);

    printf("Enter your email password: ");
    scanf("%s", email.password);

    printf("Enter the recipient's email address: ");
    scanf("%s", email.recipient);

    printf("Enter your email message: ");
    scanf("%s", email.message);

    // Calculate the length of the message
    int length = strlen(email.message);

    // Create a new file to store the email
    FILE *file = fopen("email.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write the email information to the file
    fprintf(file, "From: %s\n", email.username);
    fprintf(file, "To: %s\n", email.recipient);
    fprintf(file, "Subject: %s\n", email.message);
    fprintf(file, "Content-Type: text/plain\n\n");
    fprintf(file, "%s", email.message);

    // Close the file
    fclose(file);

    printf("Email sent successfully.\n");

    return 0;
}