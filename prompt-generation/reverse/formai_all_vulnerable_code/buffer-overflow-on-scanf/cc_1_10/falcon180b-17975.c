//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100
#define SUBJECT_LENGTH 50
#define BODY_LENGTH 1000

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber(Subscriber* new_subscriber) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, new_subscriber->name);
    strcpy(subscribers[num_subscribers].email, new_subscriber->email);

    num_subscribers++;
}

void remove_subscriber(char* email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            strcpy(subscribers[i].name, "");
            strcpy(subscribers[i].email, "");
            num_subscribers--;
            break;
        }
    }
}

void send_email(char* subject, char* body) {
    FILE* fp;
    int i;

    fp = fopen("mail.txt", "w");

    fprintf(fp, "To: ");

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, "")!= 0) {
            fprintf(fp, "%s <%s>,", subscribers[i].name, subscribers[i].email);
        }
    }

    fprintf(fp, "\nSubject: %s\n", subject);
    fprintf(fp, "\n%s", body);

    fclose(fp);

    system("mail -s \"$SUBJECT\" $(cat mail.txt)");
}

int main() {
    Subscriber new_subscriber;

    printf("Enter your name: ");
    scanf("%s", new_subscriber.name);

    printf("Enter your email: ");
    scanf("%s", new_subscriber.email);

    add_subscriber(&new_subscriber);

    printf("Thank you for subscribing!\n");

    return 0;
}