//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} subscriber;

int num_subscribers = 0;
subscriber *subscribers = NULL;

void add_subscriber(subscriber *new_sub) {
    subscribers = realloc(subscribers, sizeof(subscriber) * ++num_subscribers);
    subscribers[num_subscribers - 1] = *new_sub;
}

int is_valid_email(char *email) {
    int i;
    for (i = 0; email[i]!= '\0'; i++) {
        if (!isalpha(email[i]) &&!isdigit(email[i]) && email[i]!= '.' && email[i]!= '_' && email[i]!= '-') {
            return 0;
        }
    }
    return 1;
}

void send_email(char *subject, char *body, subscriber *to_sub) {
    printf("Sending email to %s (%s)\nSubject: %s\nBody:\n%s\n", to_sub->name, to_sub->email, subject, body);
}

void send_emails_to_subscribers(char *subject, char *body) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        send_email(subject, body, &subscribers[i]);
    }
}

int main() {
    FILE *file;
    char line[1024];
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    subscriber new_sub;

    file = fopen("subscribers.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open subscribers file.\n");
        return 1;
    }

    num_subscribers = 0;
    subscribers = NULL;

    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %s", name, email);
        strcpy(new_sub.name, name);
        strcpy(new_sub.email, email);
        if (is_valid_email(email)) {
            add_subscriber(&new_sub);
            num_subscribers++;
        } else {
            printf("Invalid email address: %s\n", email);
        }
    }

    fclose(file);

    send_emails_to_subscribers("Test Email", "Hello World!");

    return 0;
}