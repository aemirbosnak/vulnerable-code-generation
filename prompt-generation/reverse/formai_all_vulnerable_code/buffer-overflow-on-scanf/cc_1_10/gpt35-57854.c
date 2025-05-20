//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_SUBJECT 100
#define MAX_BODY 500

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

int main() {
    Email myEmail;
    char choice;
    FILE* file_pointer;
    int i;

    printf("***Welcome to the C Email Client!***\n");

    printf("\nEnter your name: ");
    fgets(myEmail.name, MAX_NAME, stdin);

    printf("\nEnter your email address: ");
    fgets(myEmail.email, MAX_EMAIL, stdin);

    printf("\nDo you want to write an email? [Y/N]: ");
    scanf("%c", &choice);
    getchar();

    if (choice == 'Y' || choice == 'y') {
        printf("\nEnter the subject: ");
        fgets(myEmail.subject, MAX_SUBJECT, stdin);

        printf("\nEnter the body (Max characters - 500): ");
        fgets(myEmail.body, MAX_BODY, stdin);

        /* write email to file */
        file_pointer = fopen("sent_emails.txt", "a");
        if (file_pointer == NULL) {
            printf("\nError! Could not open file.\n");
            exit(1);
        }

        fprintf(file_pointer, "\n*** Email Sent Successfully! ***\n\nFrom: %s\nTo: %s\nSubject: %s\nBody: %s", 
                myEmail.email, "to be decided", myEmail.subject, myEmail.body);
        
        fclose(file_pointer);
    }
    else {
        printf("\nNo email was sent.\n");
    }

    return 0;
}