#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256

void composeEmail() {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];

    printf("Enter recipient: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter body: ");
    scanf("%[^\n]", body);

    printf("\nEmail Composed:\n");
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
}

int main() {
    int choice;

    while (1) {
        printf("\nEmail Client Menu:\n");
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
