//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_email(int index) {
    printf("Subject: %s\n", emails[index].subject);
    printf("Body:\n%s\n", emails[index].body);
    printf("Timestamp: %s\n", ctime(&emails[index].timestamp));
}

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Sorry, the inbox is full.\n");
        return;
    }

    printf("Enter the subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    scanf("%s", emails[num_emails].subject);

    printf("Enter the body (max %d characters): ", MAX_BODY_LENGTH - 1);
    scanf("%[^\n]", emails[num_emails].body);

    emails[num_emails].timestamp = time(NULL);
    num_emails++;
}

void delete_email(int index) {
    if (index < 0 || index >= num_emails) {
        printf("Invalid email index.\n");
        return;
    }

    num_emails--;
    memmove(&emails[index], &emails[index + 1], sizeof(Email) * (num_emails - index));
}

int main() {
    char choice;

    do {
        printf("Cyberpunk Email Client\n");
        printf("A - Add email\n");
        printf("D - Delete email\n");
        printf("P - Print email\n");
        printf("Q - Quit\n");
        printf("> ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                add_email();
                break;
            case 'D':
                printf("Enter the index of the email to delete: ");
                scanf("%d", &choice);
                delete_email(choice - 1);
                break;
            case 'P':
                printf("Enter the index of the email to print: ");
                scanf("%d", &choice);
                print_email(choice - 1);
                break;
            case 'Q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}