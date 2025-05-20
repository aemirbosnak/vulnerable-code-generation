//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
    int num_recipients;
    recipient recipients[MAX_RECIPIENTS];
} email;

int main() {
    int choice;
    email email;

    do {
        printf("Mailing List Manager\n");
        printf("1. Add recipient\n");
        printf("2. Remove recipient\n");
        printf("3. Compose email\n");
        printf("4. Send email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter recipient name: ");
                scanf("%s", email.recipients[email.num_recipients].name);
                printf("Enter recipient email: ");
                scanf("%s", email.recipients[email.num_recipients].email);
                email.num_recipients++;
                break;
            case 2:
                printf("Enter recipient email to remove: ");
                scanf("%s", email.recipients[email.num_recipients-1].email);
                for(int i=0; i<email.num_recipients-1; i++) {
                    email.recipients[i] = email.recipients[i+1];
                }
                email.num_recipients--;
                break;
            case 3:
                printf("Enter email subject: ");
                scanf("%s", email.subject);
                printf("Enter email message: ");
                scanf("%s", email.message);
                break;
            case 4:
                for(int i=0; i<email.num_recipients; i++) {
                    printf("Sending email to %s (%s)\n", email.recipients[i].name, email.recipients[i].email);
                }
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 5);

    return 0;
}