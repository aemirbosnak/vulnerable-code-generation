//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} Message;

void add_contact(Contact* contacts, int num_contacts, char* name, char* email) {
    int i;
    for(i=0; i<num_contacts; i++) {
        if(strcmp(contacts[i].name, name) == 0 && strcmp(contacts[i].email, email) == 0) {
            printf("Contact already exists!\n");
            return;
        }
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_message(Contact* contacts, int num_contacts, char* subject, char* message) {
    int i;
    for(i=0; i<num_contacts; i++) {
        Message msg;
        strcpy(msg.subject, subject);
        strcpy(msg.message, message);
        printf("Sending message to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    Contact contacts[100];
    int num_contacts = 0;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];

    while(1) {
        printf("Enter 'a' to add contact,'s' to send message, 'q' to quit: ");
        scanf("%s", name);

        if(strcmp(name, "a") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(contacts, num_contacts, name, email);
        }
        else if(strcmp(name, "s") == 0) {
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter message: ");
            scanf("%s", message);
            send_message(contacts, num_contacts, subject, message);
        }
        else if(strcmp(name, "q") == 0) {
            break;
        }
    }

    return 0;
}