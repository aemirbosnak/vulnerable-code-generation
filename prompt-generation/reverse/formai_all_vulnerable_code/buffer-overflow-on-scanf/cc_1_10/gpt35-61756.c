//FormAI DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char to[50];
    char cc[50];
    char subject[100];
    char message[500];
} Email;

int main() {
    char choice;
    Email email;
    FILE *fptr;

    fptr = fopen("email.txt","w");

    if(fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("Enter recipient's email address: ");
    fgets(email.to, 50, stdin);

    printf("Do you want to add a cc? (y/n): ");
    scanf("%c", &choice);

    if(choice == 'y') {
        printf("Enter cc's email address: ");
        fgets(email.cc, 50, stdin);
    } else {
        strcpy(email.cc, "");
    }

    printf("Enter email subject: ");
    fgets(email.subject, 100, stdin);

    printf("Type your message: ");
    fgets(email.message, 500, stdin);

    fprintf(fptr,"%s\n",email.to);
    fprintf(fptr,"%s\n",email.cc);
    fprintf(fptr,"%s\n",email.subject);
    fprintf(fptr,"%s\n",email.message);

    fclose(fptr);

    printf("Email has been sent!");

    return 0;
}