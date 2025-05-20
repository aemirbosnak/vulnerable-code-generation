//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_EMAILS 100      /* Maximum number of emails */
#define MAX_SUBJECT_LEN 100 /* Maximum length of email subject */
#define MAX_BODY_LEN 1000   /* Maximum length of email body */

typedef struct {
    char name[100];
    char email[100];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    Contact from;
    Contact to;
} Email;

int main() {
    Email inbox[MAX_EMAILS];
    int inbox_count = 0;

    Email sent[MAX_EMAILS];
    int sent_count = 0;

    int choice;
    do {
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. View Sent Emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: /* Compose Email */
            {
                Email new_email;
                printf("Enter subject: ");
                scanf("%s", new_email.subject);
                printf("Enter body: ");
                scanf("%s", new_email.body);

                printf("Enter sender name: ");
                scanf("%s", new_email.from.name);
                printf("Enter sender email: ");
                scanf("%s", new_email.from.email);

                printf("Enter recipient name: ");
                scanf("%s", new_email.to.name);
                printf("Enter recipient email: ");
                scanf("%s", new_email.to.email);

                sent[sent_count++] = new_email;
                break;
            }
            case 2: /* View Inbox */
            {
                if(inbox_count == 0) {
                    printf("Inbox is empty.\n");
                    break;
                }

                printf("Unread emails in inbox: %d\n", inbox_count);
                for(int i = 0; i < inbox_count; i++) {
                    printf("*********** Email %d ***********\n", i+1);
                    printf("From: %s <%s>\n", inbox[i].from.name, inbox[i].from.email);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("%s\n", inbox[i].body);
                }

                printf("Enter email number to mark as read (0 to cancel): ");
                int email_num;
                scanf("%d", &email_num);
                if(email_num > 0 && email_num <= inbox_count) {
                    email_num--; /* convert from 1-indexed to 0-indexed */
                    printf("You have read email %d:\n", email_num+1);
                    printf("*********** Email %d ***********\n", email_num+1);
                    printf("From: %s <%s>\n", inbox[email_num].from.name, inbox[email_num].from.email);
                    printf("Subject: %s\n", inbox[email_num].subject);
                    printf("%s\n", inbox[email_num].body);

                    /* Mark email as read */
                    for(int i = email_num; i < inbox_count-1; i++) {
                        inbox[i] = inbox[i+1]; /* shift emails down one index */
                    }
                    inbox_count--;
                }
                break;
            }
            case 3: /* View Sent Emails */
            {
                if(sent_count == 0) {
                    printf("No emails sent yet.\n");
                    break;
                }

                printf("Sent emails: %d\n", sent_count);
                for(int i = 0; i < sent_count; i++) {
                    printf("*********** Email %d ***********\n", i+1);
                    printf("To: %s <%s>\n", sent[i].to.name, sent[i].to.email);
                    printf("Subject: %s\n", sent[i].subject);
                    printf("%s\n", sent[i].body);
                }
                break;
            }
            case 4: /* Exit */
            {
                printf("Goodbye!\n");
                break;
            }
            default:
            {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    } while(choice != 4);

    return 0;
}