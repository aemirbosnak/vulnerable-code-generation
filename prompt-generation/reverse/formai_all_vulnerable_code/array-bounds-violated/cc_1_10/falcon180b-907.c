//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

// Struct to hold email addresses and names
typedef struct {
    char name[50];
    char email[100];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    printf("Enter the name: ");
    scanf("%s", emails[num_emails].name);
    
    printf("Enter the email address: ");
    scanf("%s", emails[num_emails].email);
    
    num_emails++;
}

void remove_email() {
    int index;
    printf("Enter the email address to remove: ");
    scanf("%s", emails[0].email);
    
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, emails[0].email) == 0) {
            index = i;
            break;
        }
    }
    
    for (int i = index; i < num_emails - 1; i++) {
        emails[i] = emails[i+1];
    }
    
    num_emails--;
}

void send_email() {
    int index;
    printf("Enter the email address to send to: ");
    scanf("%s", emails[0].email);
    
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, emails[0].email) == 0) {
            index = i;
            break;
        }
    }
    
    printf("Email sent to %s\n", emails[index].name);
}

void view_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    int choice;
    
    do {
        printf("1. Add Email\n2. Remove Email\n3. Send Email\n4. View Emails\n5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                remove_email();
                break;
            case 3:
                send_email();
                break;
            case 4:
                view_emails();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    
    return 0;
}