//Falcon-180B DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT 100
#define MAX_BODY 1000

struct Email {
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    time_t timestamp;
};

int email_count = 0;
struct Email emails[MAX_EMAILS];

void print_email(int index) {
    printf("Subject: %s\n", emails[index].subject);
    printf("Body:\n%s\n", emails[index].body);
    printf("Timestamp: %s\n", ctime(&emails[index].timestamp));
}

int main() {
    char input[1000];
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Compose email\n");
        printf("2. Read emails\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter subject: ");
                scanf("%[^\n]", emails[email_count].subject);
                printf("Enter body: ");
                fgets(emails[email_count].body, MAX_BODY, stdin);
                emails[email_count].timestamp = time(NULL);
                email_count++;
                break;
            case 2:
                printf("You have %d unread emails:\n", email_count);
                for(int i=0; i<email_count; i++) {
                    printf("%d. ", i+1);
                }
                printf("\n");
                int index;
                scanf("%d", &index);
                print_email(index-1);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}