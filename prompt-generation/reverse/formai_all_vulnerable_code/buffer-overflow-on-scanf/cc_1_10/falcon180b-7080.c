//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} recipient;

int main() {
    int choice, num_recipients;
    char input[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    recipient recipients[MAX_RECIPIENTS];

    printf("Welcome to RetroMailing, the coolest mailing list manager around!\n");
    printf("What would you like to do?\n");
    printf("1. Add recipient\n");
    printf("2. Remove recipient\n");
    printf("3. Send email\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter recipient name (max %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", recipients[0].name);

            printf("Enter recipient email (max %d characters): ", MAX_EMAIL_LENGTH - 1);
            scanf("%s", recipients[0].email);

            printf("Recipient added successfully!\n");
            break;

        case 2:
            printf("Enter recipient name to remove (max %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", input);

            for (int i = 0; i < MAX_RECIPIENTS; i++) {
                if (strcmp(input, recipients[i].name) == 0) {
                    recipients[i] = (recipient) { "", "" };
                    printf("Recipient removed successfully!\n");
                    break;
                }
            }

            break;

        case 3:
            printf("Enter email subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
            scanf("%s", input);

            printf("Enter email body (max %d characters): ", MAX_BODY_LENGTH - 1);
            scanf("%s", body);

            for (int i = 0; i < MAX_RECIPIENTS; i++) {
                if (strcmp(recipients[i].email, "")!= 0) {
                    printf("Sending email to %s...\n", recipients[i].name);
                }
            }

            break;

        case 4:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}