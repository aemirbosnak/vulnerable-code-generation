//FormAI DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

int main() {
    srand(time(NULL));
    char email_list[MAX_EMAILS][20];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_emails = 0;
    bool done = false;

    printf("Welcome to the cryptic email client!\n");

    while (!done) {
        printf("\nMENU\n");
        printf("1. Compose new email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        printf("> ");

        int selection;
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                printf("\nEnter recipient email: ");
                char recipient[20];
                scanf("%s", recipient);

                // check if recipient already exists in email list
                bool found = false;
                for (int i = 0; i < num_emails; i++) {
                    if (strcmp(email_list[i], recipient) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    strcpy(email_list[num_emails], recipient);
                    num_emails++;
                }

                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);

                // encrypt email body using key
                int key = rand() % 26;
                for (int i = 0; i < strlen(body); i++) {
                    if (body[i] >= 'a' && body[i] <= 'z') {
                        body[i] = (body[i] - 'a' + key) % 26 + 'a';
                    } else if (body[i] >= 'A' && body[i] <= 'Z') {
                        body[i] = (body[i] - 'A' + key) % 26 + 'A';
                    }
                }

                printf("Email sent successfully!\n");
                break;

            case 2:
                printf("\nINBOX\n");

                for (int i = 0; i < num_emails; i++) {
                    printf("From: %s\n", email_list[i]);

                    char decrypted_body[MAX_BODY_LENGTH];
                    strcpy(decrypted_body, body);

                    // decrypt email body using key
                    for (int j = 0; j < strlen(decrypted_body); j++) {
                        if (decrypted_body[j] >= 'a' && decrypted_body[j] <= 'z') {
                            decrypted_body[j] = (decrypted_body[j] - 'a' - key + 26) % 26 + 'a';
                        } else if (decrypted_body[j] >= 'A' && decrypted_body[j] <= 'Z') {
                            decrypted_body[j] = (decrypted_body[j] - 'A' - key + 26) % 26 + 'A';
                        }
                    }

                    printf("Subject: %s\n", subject);
                    printf("Body: %s\n", decrypted_body);
                }

                break;

            case 3:
                printf("\nGoodbye!\n");
                done = true;
                break;

            default:
                printf("\nInvalid selection.\n");
        }
    }

    return 0;
}