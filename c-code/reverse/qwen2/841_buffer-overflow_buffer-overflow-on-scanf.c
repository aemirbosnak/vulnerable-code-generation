#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMAIL_LENGTH 256

void composeEmail() {
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];

    printf("Enter recipient's email: ");
    fgets(to, sizeof(to), stdin);
    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    printf("Enter body of the email: ");
    fgets(body, sizeof(body), stdin);

    printf("\nSending email...\n");
    printf("To: %s", to);
    printf("Subject: %s", subject);
    printf("Body: %s", body);
}

int main() {
    int choice;

    while (1) {
        printf("\nEmail Client Menu\n");
        printf("1. Compose Email\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
