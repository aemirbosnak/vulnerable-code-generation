//Falcon-180B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAILS 20
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email inbox is full.\n");
        return;
    }

    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
    scanf("%49s", emails[num_emails].subject);

    printf("Enter body (max %d characters): ", MAX_BODY_LENGTH - 1);
    scanf("%499s", emails[num_emails].body);

    time(&emails[num_emails].timestamp);
    num_emails++;

    printf("Email added successfully.\n");
}

void view_email(int index) {
    if (index < 0 || index >= num_emails) {
        printf("Error: Invalid email index.\n");
        return;
    }

    printf("Subject: %s\n", emails[index].subject);
    printf("Body: %s\n", emails[index].body);
    printf("Timestamp: %s", ctime(&emails[index].timestamp));
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nPost-Apocalyptic Email Client\n");
        printf("1. Add email\n");
        printf("2. View email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                printf("Enter email index: ");
                int index;
                scanf("%d", &index);
                view_email(index - 1);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}