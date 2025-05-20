#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1024

void composeEmail() {
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];

    printf("Enter recipient's email: ");
    fgets(to, sizeof(to), stdin);
    to[strcspn(to, "\n")] = '\0';

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter email body (type 'end' on a new line when finished):\n");
    int i = 0;
    while (i < sizeof(body) - 1 && fgets(&body[i], sizeof(body) - i, stdin)) {
        if (strcmp(body + i, "end\n") == 0) {
            break;
        }
        i += strlen(body + i);
    }

    // Simulate sending the email
    printf("Sending email to %s with subject '%s':\n%s\n", to, subject, body);
}

int main() {
    int choice;

    while (1) {
        printf("\nEmail Client Menu:\n");
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
