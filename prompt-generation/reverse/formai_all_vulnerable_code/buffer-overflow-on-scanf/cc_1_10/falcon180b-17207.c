//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int length;
} email;

int main() {
    email inbox[10];
    int num_emails = 0;
    char choice;

    while(1) {
        printf("\nWelcome to your surreal inbox!\n");
        printf("You have %d unread emails.\n", num_emails);
        printf("What would you like to do?\n");
        printf("a) Read an email\n");
        printf("b) Delete an email\n");
        printf("c) Exit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                if(num_emails == 0) {
                    printf("You have no emails to read.\n");
                } else {
                    int index;
                    printf("Which email would you like to read?\n");
                    for(index = 0; index < num_emails; index++) {
                        printf("%d) %s\n", index+1, inbox[index].subject);
                    }
                    scanf(" %d", &index);
                    printf("\nSubject: %s\n", inbox[index-1].subject);
                    printf("Body:\n%s\n", inbox[index-1].body);
                }
                break;
            case 'b':
                if(num_emails == 0) {
                    printf("You have no emails to delete.\n");
                } else {
                    int index;
                    printf("Which email would you like to delete?\n");
                    for(index = 0; index < num_emails; index++) {
                        printf("%d) %s\n", index+1, inbox[index].subject);
                    }
                    scanf(" %d", &index);
                    memset(&inbox[index-1], 0, sizeof(email));
                    num_emails--;
                }
                break;
            case 'c':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}