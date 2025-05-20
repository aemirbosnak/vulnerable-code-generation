//FormAI DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[500];
    struct email *next;
} email_t;

email_t *inbox, *outbox;

void compose_email();
void send_email();
void view_inbox();
void view_outbox();

int main() {
    inbox = outbox = NULL;
    int choice;
    
    do {
        printf("\n**********************************");
        printf("\n             EMAIL CLIENT          ");
        printf("\n**********************************\n");
        printf("\n1. Compose Email");
        printf("\n2. Send Email");
        printf("\n3. View Inbox");
        printf("\n4. View Outbox");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                compose_email();
                break;
            case 2:
                send_email();
                break;
            case 3:
                view_inbox();
                break;
            case 4:
                view_outbox();
                break;
            case 5:
                printf("\nExiting Email Client...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while(choice != 5);
    
    return 0;
}

void compose_email() {
    email_t *new_email = (email_t*) malloc(sizeof(email_t));
    fflush(stdin);
    printf("\nEnter Sender: ");
    scanf("%s", new_email->sender);
    fflush(stdin);
    printf("Enter Recipient: ");
    scanf("%s", new_email->recipient);
    fflush(stdin);
    printf("Enter Subject: ");
    scanf("%s", new_email->subject);
    fflush(stdin);
    printf("Enter Message: ");
    scanf("%s", new_email->message);
    
    if(outbox == NULL) {
        outbox = new_email;
        outbox->next = NULL;
    } else {
        new_email->next = outbox;
        outbox = new_email;
    }
    printf("\nEmail added to Outbox successfully.\n");
}

void send_email() {
    if(outbox == NULL) {
        printf("\nOutbox is empty. Nothing to send.\n");
        return;
    }
    email_t *current_email = outbox;
    outbox = outbox->next;
    
    if(inbox == NULL) {
        inbox = current_email;
        inbox->next = NULL;
    } else {
        current_email->next = inbox;
        inbox = current_email;
    }
    printf("\nMessage sent successfully.\n");
}

void view_inbox() {
    if(inbox == NULL) {
        printf("\nInbox is empty. Nothing to show.\n");
        return;
    }
    printf("\n************  INBOX ************\n");
    email_t *current_email = inbox;
    int count = 1;
    while(current_email != NULL) {
        printf("\n***** Email %d *****", count++);
        printf("\nFrom: %s", current_email->sender);
        printf("\nSubject : %s", current_email->subject);
        printf("\nMessage : %s", current_email->message);
        current_email = current_email->next;
    }
}

void view_outbox() {
    if(outbox == NULL) {
        printf("\nOutbox is empty. Nothing to show.\n");
        return;
    }
    printf("\n***********  OUTBOX ************\n");
    email_t *current_email = outbox;
    int count = 1;
    while(current_email != NULL) {
        printf("\n***** Email %d *****", count++);
        printf("\nTo: %s", current_email->recipient);
        printf("\nSubject : %s", current_email->subject);
        printf("\nMessage : %s", current_email->message);
        current_email = current_email->next;
    }
}