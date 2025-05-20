//FormAI DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct message {
    char sender[100];
    char recipient[100];
    char subject[100];
    char body[1000];
    struct message* next;
} Message;

Message* inbox = NULL;
Message* outbox = NULL;

void send_email() {
    Message* new_email = (Message*)malloc(sizeof(Message));
    printf("\nEnter sender's email address:\n");
    scanf("%s", new_email->sender);
    printf("\nEnter recipient's email address:\n");
    scanf("%s", new_email->recipient);
    printf("\nEnter email subject:\n");
    scanf("%s", new_email->subject);
    printf("\nEnter email body:\n");
    scanf("%s", new_email->body);
    new_email->next = NULL;

    if (outbox == NULL) {
        outbox = new_email;
    }
    else {
        Message* temp = outbox;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_email;
    }
    printf("\nEmail sent successfully!\n");
}

void check_inbox() {
    if (inbox == NULL) {
        printf("\nInbox empty!\n");
    }
    else {
        Message* temp = inbox;
        int i = 1;
        while (temp != NULL) {
            printf("\nEmail %d -\n", i);
            printf("Sender: %s\n", temp->sender);
            printf("Subject: %s\n", temp->subject);
            printf("Body: %s\n", temp->body);
            temp = temp->next;
            i++;
        }
    }
}

void check_outbox() {
    if (outbox == NULL) {
        printf("\nOutbox empty!\n");
    }
    else {
        Message* temp = outbox;
        int i = 1;
        while (temp != NULL) {
            printf("\nEmail %d -\n", i);
            printf("Recipient: %s\n", temp->recipient);
            printf("Subject: %s\n", temp->subject);
            printf("Body: %s\n", temp->body);
            temp = temp->next;
            i++;
        }
    }
}

void receive_email() {
    Message* new_email = (Message*)malloc(sizeof(Message));
    printf("\nEnter sender's email address:\n");
    scanf("%s", new_email->sender);
    printf("\nEnter recipient's email address:\n");
    scanf("%s", new_email->recipient);
    printf("\nEnter email subject:\n");
    scanf("%s", new_email->subject);
    printf("\nEnter email body:\n");
    scanf("%s", new_email->body);
    new_email->next = NULL;

    if (inbox == NULL) {
        inbox = new_email;
    }
    else {
        Message* temp = inbox;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_email;
    }
    printf("\nEmail received successfully!\n");
}

void delete_email() {
    int email_choice = 0;
    printf("\nEnter email type to delete - 1. Inbox 2. Outbox:\n");
    scanf("%d", &email_choice);
    if (email_choice == 1) {
        if (inbox == NULL) {
            printf("\nInbox empty!\n");
        }
        else {
            int email_num;
            printf("\nEnter email number to delete:\n");
            scanf("%d", &email_num);
            if (email_num == 1) {
                Message* temp = inbox;
                inbox = inbox->next;
                free(temp);
            }
            else {
                Message* temp1 = inbox;
                Message* temp2 = inbox->next;
                int i = 2;
                while (i != email_num) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    i++;
                }
                temp1->next = temp2->next;
                free(temp2);
            }
            printf("\nEmail deleted successfully!\n");
        }
    }
    else if (email_choice == 2) {
        if (outbox == NULL) {
            printf("\nOutbox empty!\n");
        }
        else {
            int email_num;
            printf("\nEnter email number to delete:\n");
            scanf("%d", &email_num);
            if (email_num == 1) {
                Message* temp = outbox;
                outbox = outbox->next;
                free(temp);
            }
            else {
                Message* temp1 = outbox;
                Message* temp2 = outbox->next;
                int i = 2;
                while (i != email_num) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    i++;
                }
                temp1->next = temp2->next;
                free(temp2);
            }
            printf("\nEmail deleted successfully!\n");
        }
    }
    else {
        printf("\nInvalid choice!\n");
    }
}

void display_menu() {
    printf("\n******************************");
    printf("\nWelcome to Sherlock Holmes Email Client");
    printf("\n******************************");
    printf("\n1. Send email");
    printf("\n2. Check inbox");
    printf("\n3. Check outbox");
    printf("\n4. Receive email");
    printf("\n5. Delete email");
    printf("\n6. Exit");
    printf("\n******************************");
}

int main() {
    int choice = 0;
    while (choice != 6) {
        display_menu();
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                check_inbox();
                break;
            case 3:
                check_outbox();
                break;
            case 4:
                receive_email();
                break;
            case 5:
                delete_email();
                break;
            case 6:
                printf("\nExiting Sherlock Holmes Email Client. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}