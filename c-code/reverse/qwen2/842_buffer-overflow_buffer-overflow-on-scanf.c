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

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter body (up to %d characters): ", MAX_EMAIL_LENGTH);
    scanf("%[^\n]", body); // Vulnerable to buffer overflow

    printf("Email composed:\n");
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Compose Email\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            composeEmail();
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
