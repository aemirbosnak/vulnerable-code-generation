//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Email {
    char from[50];
    char to[50];
    char cc[50];
    char subject[100];
    char body[500];
};

int main() {
    struct Email email;
    char choice, temp;
    FILE *fp;

    printf("Welcome to Unique C Email Client\n");

    do {
        memset(&email, 0, sizeof(email));
        printf("\nEnter 's' to send an email or 'r' to read an email: ");
        scanf("%c", &choice);
        while ((temp = getchar()) != '\n' && temp != EOF) {}; // Clear Input Buffer

        switch (choice) {
            case 's':
                printf("\nEnter 'from' email address (max 50 characters): ");
                fgets(email.from, 50, stdin);
                email.from[strcspn(email.from, "\n")] = 0;

                printf("\nEnter 'to' email address (max 50 characters): ");
                fgets(email.to, 50, stdin);
                email.to[strcspn(email.to, "\n")] = 0;

                printf("\nEnter 'cc' email address (max 50 characters): ");
                fgets(email.cc, 50, stdin);
                email.cc[strcspn(email.cc, "\n")] = 0;

                printf("\nEnter 'subject' of email (max 100 characters): ");
                fgets(email.subject, 100, stdin);
                email.subject[strcspn(email.subject, "\n")] = 0;

                printf("\nEnter 'body' of email (max 500 characters): ");
                fgets(email.body, 500, stdin);
                email.body[strcspn(email.body, "\n")] = 0;

                fp = fopen("sent_emails.txt", "a");
                if(fp == NULL) {
                    perror("Error opening file");
                    exit(1);
                }

                fprintf(fp, "From: %s\n", email.from);
                fprintf(fp, "To: %s\n", email.to);
                fprintf(fp, "CC: %s\n", email.cc);
                fprintf(fp, "Subject: %s\n", email.subject);
                fprintf(fp, "Body: %s\n\n", email.body);

                printf("\nEmail sent successfully!");
                fclose(fp);
                break;

            case 'r':
                printf("\nList of Sent Emails:");
                fp = fopen("sent_emails.txt", "r");
                if(fp == NULL) {
                    perror("Error opening file");
                    exit(1);
                }

                int line_count = 0;
                char line[1000];
                while(fgets(line, 1000, fp)) {
                    if (!isspace(line[0])) { // Check if line is not whitespace
                        printf("\n\nEmail %d\n", ++line_count);
                    }
                    printf("%s", line); // Print the line
                }
                
                printf("\n\nEnter the email number to read: ");
                int email_num;
                scanf("%d", &email_num);
                while ((temp = getchar()) != '\n' && temp != EOF) {}; // Clear Input Buffer

                int num_emails_read = 0;
                rewind(fp);
                while(fgets(line, 1000, fp)) {
                    if (!isspace(line[0])) { // Check if line is not whitespace
                        num_emails_read++;
                    }
                    if (num_emails_read == email_num) {
                        printf("\n\n%s", line);
                        while(fgets(line, 1000, fp)) {
                            printf("%s", line);
                            if (isspace(line[0])) { // Check if line is whitespace
                                break;
                            }
                        }
                        break;
                    }
                }

                fclose(fp);
                break;

            default:
                printf("\nInvalid choice. Please enter 's' or 'r'.");
                break;
        }

        printf("\n\nWould you like to send or read another email? (y/n): ");
        scanf("%c", &choice);
        while ((temp = getchar()) != '\n' && temp != EOF) {}; // Clear Input Buffer

    } while (choice == 'y');

    printf("\nThank you for using Unique C Email Client!\n");
    return 0;
}