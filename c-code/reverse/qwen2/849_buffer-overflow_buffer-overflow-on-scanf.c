#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1024

void composeEmail() {
    char to[100], subject[100], body[MAX_EMAIL_LENGTH];
    printf("Enter recipient's email: ");
    fgets(to, sizeof(to), stdin);
    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    printf("Compose your message (type 'end' on a new line when finished):\n");
    int i = 0;
    while (i < MAX_EMAIL_LENGTH - 1) {
        if (fgets(body + i, sizeof(body) - i, stdin) == NULL) break;
        i += strlen(body + i);
        if (strstr(body + i - 3, "end\n") != NULL) break;
    }
    body[i] = '\0';
    printf("Sending email to %s with subject '%s'\n", to, subject);
    // Here you would add code to send the email using SMTP or another protocol
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
