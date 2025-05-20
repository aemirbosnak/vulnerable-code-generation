//FormAI DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STRUCT TO HOLD EMAIL INFORMATION*/
struct Email {
    char from[50];
    char to[50];
    char subject[50];
    char message[200];
};

int main() {
    int count = 0;
    int option;
    struct Email *emails = (struct Email*) malloc(sizeof(struct Email) * count);

    while(1) {
        printf("1. Compose an email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &option);

        if(option == 1) {
            struct Email new_email;

            printf("From: ");
            scanf("%s", new_email.from);

            printf("To: ");
            scanf("%s", new_email.to);

            printf("Subject: ");
            scanf("%s", new_email.subject);

            printf("Message: ");
            scanf("%s", new_email.message);

            count++;
            emails = (struct Email*) realloc(emails, sizeof(struct Email) * count);
            emails[count - 1] = new_email;

            printf("Email sent successfully.\n");

        } else if(option == 2) {

            if(count == 0) {
                printf("No emails to show.\n");
            } else {
                for(int i=0; i<count; i++) {
                    printf("------------------------------------------\n");
                    printf("From: %s\n", emails[i].from);
                    printf("To: %s\n", emails[i].to);
                    printf("Subject: %s\n", emails[i].subject);
                    printf("Message: %s\n", emails[i].message);
                }
                printf("------------------------------------------\n");
            }

        } else if(option == 3) {

            free(emails);
            printf("Goodbye.\n");
            return 0;

        } else {
            printf("Invalid option selected.\n");
        }
    }

    return 0;
}