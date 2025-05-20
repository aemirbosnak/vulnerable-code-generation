//Falcon-180B DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} email;

int main() {
    email inbox[10];
    int num_emails = 0;

    while(num_emails < 10) {
        printf("Enter the subject of the email (max %d characters): ", MAX_SUBJECT_LENGTH-1);
        scanf("%s", inbox[num_emails].subject);
        printf("Enter the body of the email (max %d characters): ", MAX_BODY_LENGTH-1);
        scanf("%s", inbox[num_emails].body);
        num_emails++;
    }

    int choice;
    do {
        printf("\nEmail Client Menu:\n");
        printf("1. View inbox\n");
        printf("2. Compose new email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nInbox:\n");
                for(int i=0; i<num_emails; i++) {
                    printf("Subject: %s\nBody: %s\n\n", inbox[i].subject, inbox[i].body);
                }
                break;
            case 2:
                printf("\nCompose new email:\n");
                printf("Enter the subject of the email (max %d characters): ", MAX_SUBJECT_LENGTH-1);
                scanf("%s", inbox[num_emails].subject);
                printf("Enter the body of the email (max %d characters): ", MAX_BODY_LENGTH-1);
                scanf("%s", inbox[num_emails].body);
                num_emails++;
                printf("\nEmail composed successfully!\n");
                break;
            case 3:
                printf("\nExiting email client...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}