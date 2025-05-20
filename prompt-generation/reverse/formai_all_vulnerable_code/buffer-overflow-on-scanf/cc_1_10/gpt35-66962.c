//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BODY_LENGTH 1000

void print_menu();

int main() {
    char *current_user = "example@example.com";
    char recipient[50];
    char subject[100];
    char body[MAX_BODY_LENGTH];
    char filename[100];
    char line[100];
    char choice;

    while (1) {
        print_menu();

        scanf("%c", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case '1': // Compose email
                printf("From: %s\n", current_user);
                printf("To: ");
                scanf("%s", recipient);
                getchar(); // to consume the newline character

                printf("Subject: ");
                scanf("%s", subject);
                getchar(); // to consume the newline character

                printf("Body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);
                int len = strlen(body);
                if (body[len - 1] == '\n') {
                    body[len - 1] = '\0';
                }

                sprintf(filename, "%s - %s.txt", recipient, subject);
                FILE *file = fopen(filename, "w");
                fprintf(file, "From: %s\n", current_user);
                fprintf(file, "To: %s\n", recipient);
                fprintf(file, "Subject: %s\n", subject);
                fprintf(file, "\n%s\n\n", body);
                fclose(file);

                printf("\nEmail saved as %s\n\n", filename);
                break;

            case '2': // List emails
                system("ls -l *.txt");
                printf("\n");
                break;

            case '3': // Read email
                printf("Enter email filename: ");
                scanf("%s", filename);
                getchar(); // to consume the newline character

                file = fopen(filename, "r");
                while (fgets(line, 100, file)) {
                    printf("%s", line);
                }
                fclose(file);
                printf("\n");
                break;

            case '4': // Delete email
                printf("Enter email filename: ");
                scanf("%s", filename);
                getchar(); // to consume the newline character

                if (remove(filename) == 0) {
                    printf("\n%s successfully deleted.\n\n", filename);
                } else {
                    printf("\n%s could not be deleted.\n\n", filename);
                }
                break;

            case '5': // Change user
                printf("Enter new user email address: ");
                scanf("%s", current_user);
                getchar(); // to consume the newline character

                printf("\nUser changed to %s.\n\n", current_user);
                break;

            case '6': // Quit
                printf("Goodbye!\n");
                exit(0);

            default: // Invalid choice
                printf("Invalid choice! Please enter a number between 1-6.\n\n");
                break;
        }
    }
}

void print_menu() {
    printf("====================================================\n");
    printf("\t\tC Email Client\n");
    printf("====================================================\n");
    printf("1. Compose email\n");
    printf("2. List emails\n");
    printf("3. Read email\n");
    printf("4. Delete email\n");
    printf("5. Change user\n");
    printf("6. Quit\n");
    printf("====================================================\n");
    printf("Enter choice (1-6): ");
}