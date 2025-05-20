//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 250

void login(int *valid) {
    char email[50], password[20];
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);
    // Validate the email and password
    if (strcmp(email, "youremail@gmail.com") == 0 && strcmp(password, "yourpassword") == 0) {
        *valid = 1;
        printf("\n\t\t\tLogin Successful!\n\n");
    } else {
        printf("\n\t\t\tInvalid email or password.\n\n");
    }
}

void create_email() {
    char to[50], subject[100], body[MAX];
    printf("Enter recipient email: ");
    scanf("%s", to);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message below (max 250 characters):\n\n");
    getchar();  // Clear the input buffer
    fgets(body, MAX, stdin);  // Read the message body from stdin
    // Print the email details to the console
    printf("\n\nTo: %s\nSubject: %s\n\nMessage: %s\n", to, subject, body);
}

int main() {
    int option, valid = 0;
    do {
        printf("==== C Email Client ====\n");
        printf("1. Login\n");
        printf("2. Create Email\n");
        printf("3. Exit\n");
        printf("========================\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                login(&valid);
                break;
            case 2:
                if (valid) {
                    create_email();
                } else {
                    printf("\n\t\t\tPlease login first.\n\n");
                }
                break;
            case 3:
                printf("\n\t\t\tGoodbye!\n\n");
                break;
            default:
                printf("\n\t\t\tInvalid option.\n\n");
                break;
        }
    } while (option != 3);
    return 0;
}