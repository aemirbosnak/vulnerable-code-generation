#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compose_email(char recipient[100], char subject[100], char body[500]);
void display_menu();

int main() {
    char choice;
    char recipient[100];
    char subject[100];
    char body[500];

    do {
        display_menu();
        scanf("%c", &choice);

        switch (choice) {
            case 'C':
                printf("Recipient: ");
                scanf("%s", recipient);
                printf("Subject: ");
                scanf("%s", subject);
                printf("Body: ");
                scanf("%s", body);
                compose_email(recipient, subject, body);
                break;
            case 'E':
                // Email list
                break;
            case 'S':
                // Settings
                break;
            case 'Q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 'Q');

    return 0;
}

void compose_email(char recipient[], char subject[], char body[]) {
    printf("Composing email to %s with subject: %s\n", recipient, subject);
    printf("Email body:\n%s\n", body);

    // Vulnerable to buffer overflow in the input handling
    char email[1000];
    strcpy(email, recipient);
    strcat(email, " ");
    strcat(email, subject);
    strcat(email, "\n");
    strcat(email, body);

    // Send email
}

void display_menu() {
    printf("\nEmail Client Menu:\n");
    printf("C - Compose Email\n");
    printf("E - Email List\n");
    printf("S - Settings\n");
    printf("Q - Quit\n");
}
