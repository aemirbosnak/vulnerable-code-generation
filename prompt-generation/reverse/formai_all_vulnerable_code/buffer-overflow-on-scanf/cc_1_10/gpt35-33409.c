//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#define MAX_EMAILS 100
#define MAX_ID_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500
// defining email structure
struct email{
    char id[MAX_ID_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};
// defining email client structure
struct email_client{
    struct email emails[MAX_EMAILS];
    int count;
};
// function to fetch emails from server
void fetch_emails(struct email_client *client){
    if(client->count == MAX_EMAILS){
        printf("Inbox full. Cannot fetch more emails\n");
        return;
    }
    printf("Fetching emails from server...\n");
    // code to fetch emails from server goes here
    // for demo purpose, let's add some demo emails
    struct email e1 = {"123","Hello","Hi there, how are you doing?"};
    client->emails[client->count++] = e1;
    struct email e2 = {"456","Meeting reminder","This is a reminder for our meeting tomorrow."};
    client->emails[client->count++] = e2;
    printf("Fetched %d emails\n", client->count);
}
// function to send email
void send_email(struct email_client *client, char *id, char *subject, char *body){
    if(client->count == MAX_EMAILS){
        printf("Inbox full. Cannot send email\n");
        return;
    }
    if(client->count == 0){
        printf("Inbox empty. Cannot reply to email\n");
        return;
    }
    printf("Sending email...\n");
    // code to send email goes here
    struct email e = {id,subject,body};
    client->emails[client->count++] = e;
    printf("Email sent successfully\n");
}
// function to read email
void read_email(struct email_client *client, char *id){
    if(client->count == 0){
        printf("Inbox empty. No emails to read\n");
        return;
    }
    struct email *e = NULL;
    for(int i = 0; i < client->count; i++){
        if(strcmp(client->emails[i].id,id) == 0){
            e = &client->emails[i];
            break;
        }
    }
    if(e == NULL){
        printf("Email with id %s not found\n", id);
        return;
    }
    printf("Subject: %s\n", e->subject);
    printf("Body: %s\n", e->body);
}
int main(){
    struct email_client client = {0};
    int choice;
    char id[MAX_ID_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    while(1){
        printf("Enter your choice:\n");
        printf("1. Fetch emails\n");
        printf("2. Send email\n");
        printf("3. Read email\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                fetch_emails(&client);
                break;
            case 2:
                printf("Enter recipient id:\n");
                scanf("%s",id);
                printf("Enter subject:\n");
                scanf("%s",subject);
                printf("Enter body:\n");
                scanf("%s",body);
                send_email(&client,id,subject,body);
                break;
            case 3:
                printf("Enter email id:\n");
                scanf("%s",id);
                read_email(&client,id);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}