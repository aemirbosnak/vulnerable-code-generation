#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_EMAIL_LENGTH 100

void composeEmail() {
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];

    printf("Enter email subject: ");
    scanf("%99s", subject); // Vulnerable to buffer overflow

    printf("Enter email body: ");
    scanf("%99[^\n]%*c", body); // Vulnerable to buffer overflow

    printf("Email composed:\n");
    printf("Subject: %s\nBody: %s\n", subject, body);
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n1. Compose Email\n2. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
