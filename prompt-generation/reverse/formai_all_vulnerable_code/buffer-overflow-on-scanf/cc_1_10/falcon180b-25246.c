//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum number of subscribers
#define MAX_NAME_LENGTH 50 // Maximum length of subscriber's name
#define MAX_EMAIL_LENGTH 100 // Maximum length of subscriber's email address

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SIZE];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

void send_email(char* subject, char* message) {
    printf("Sending email with subject: %s\n", subject);
    printf("Message:\n%s\n", message);
}

void main() {
    int choice;
    while(1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Send Email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                printf("Enter subject: ");
                char subject[MAX_NAME_LENGTH];
                scanf("%s", subject);
                printf("Enter message: ");
                char message[MAX_NAME_LENGTH];
                scanf("%s", message);
                send_email(subject, message);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}