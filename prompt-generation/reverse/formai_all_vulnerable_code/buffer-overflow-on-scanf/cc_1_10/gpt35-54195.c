//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_EMAILS 10
#define MAX_LENGTH 50

typedef struct {
    char from[MAX_LENGTH];
    char to[MAX_LENGTH];
    char subject[MAX_LENGTH];
    char message[MAX_LENGTH];
} Email;

int main() {
    int choice, count = 0;
    Email emails[MAX_EMAILS];

    do {
        printf("\nChoose an option:\n");
        printf("1. Compose email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");

        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                if(count < MAX_EMAILS) {
                    Email email;
                    printf("From: ");
                    fgets(email.from, MAX_LENGTH, stdin);
                    printf("To: ");
                    fgets(email.to, MAX_LENGTH, stdin);
                    printf("Subject: ");
                    fgets(email.subject, MAX_LENGTH, stdin);
                    printf("Message: ");
                    fgets(email.message, MAX_LENGTH, stdin);
                    emails[count] = email;
                    count++;
                }
                else {
                    printf("Inbox full!\n");
                }
                break;
            }
            case 2: {
                if(count > 0) {
                    for(int i = 0; i < count; i++) {
                        printf("\nEmail %d:\n", i+1);
                        printf("From: %s", emails[i].from);
                        printf("To: %s", emails[i].to);
                        printf("Subject: %s", emails[i].subject);
                        printf("Message: %s", emails[i].message);
                    }
                }
                else {
                    printf("Inbox empty!\n");
                }
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid input!\n");
                break;
            }
        }
    } while(choice != 3);
    
    return 0;
}