//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t subscribed_time;
} Subscriber;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t sent_time;
} Email;

Subscriber subscribers[100];
int num_subscribers = 0;

Email emails[100];
int num_emails = 0;

void addSubscriber(Subscriber *newSubscriber) {
    num_subscribers++;
    subscribers[num_subscribers - 1] = *newSubscriber;
}

void sendEmail(Email *newEmail) {
    num_emails++;
    emails[num_emails - 1] = *newEmail;
}

int main() {
    Subscriber newSubscriber;
    Email newEmail;

    printf("Enter your name: ");
    scanf("%s", newSubscriber.name);

    printf("Enter your email address: ");
    scanf("%s", newSubscriber.email);

    newSubscriber.subscribed_time = time(NULL);
    addSubscriber(&newSubscriber);

    printf("Thank you for subscribing!\n");

    while (1) {
        printf("Enter subject: ");
        scanf("%s", newEmail.subject);

        printf("Enter message: ");
        scanf("%s", newEmail.message);

        newEmail.sent_time = time(NULL);
        sendEmail(&newEmail);

        printf("Email sent successfully.\n");
    }

    return 0;
}