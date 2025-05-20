//Falcon-180B DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100

struct Email {
    char sender[50];
    char subject[100];
    char body[1000];
    time_t timestamp;
};

int emailCount = 0;
struct Email emails[MAX_EMAILS];

void addEmail() {
    if (emailCount >= MAX_EMAILS) {
        printf("Sorry, email limit reached.\n");
        return;
    }

    printf("Enter the sender's email address: ");
    scanf("%s", emails[emailCount].sender);

    printf("Enter the email subject: ");
    scanf("%s", emails[emailCount].subject);

    printf("Enter the email body: ");
    scanf("%[^\n]", emails[emailCount].body);

    emails[emailCount].timestamp = time(NULL);
    emailCount++;
}

void viewEmail(int index) {
    if (index >= 0 && index < emailCount) {
        printf("Sender: %s\n", emails[index].sender);
        printf("Subject: %s\n", emails[index].subject);
        printf("Body: %s\n", emails[index].body);
        printf("Timestamp: %s", ctime(&emails[index].timestamp));
    } else {
        printf("Invalid email index.\n");
    }
}

void deleteEmail(int index) {
    if (index >= 0 && index < emailCount) {
        memmove(&emails[index], &emails[index + 1], (emailCount - index - 1) * sizeof(struct Email));
        emailCount--;
    } else {
        printf("Invalid email index.\n");
    }
}

int main() {
    while (1) {
        printf("\nEmail Client\n");
        printf("1. Add email\n");
        printf("2. View emails\n");
        printf("3. Delete email\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmail();
                break;
            case 2:
                printf("Enter email index: ");
                int index;
                scanf("%d", &index);
                viewEmail(index);
                break;
            case 3:
                printf("Enter email index: ");
                int index2;
                scanf("%d", &index2);
                deleteEmail(index2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}