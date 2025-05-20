//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 1000
#define MAX_EMAILS 100

typedef struct Email{
    char from[MAX_LEN];
    char to[MAX_LEN];
    char subject[MAX_LEN];
    char message[MAX_LEN];
}Email;

Email client_inbox[MAX_EMAILS];
int email_count = 0;

void compose_email(){
    printf("\nEnter recipient's email address:");
    char to[MAX_LEN];
    scanf("%s", to);
    getchar();

    printf("\nEnter subject of the email:");
    char subject[MAX_LEN];
    fgets(subject, MAX_LEN, stdin);

    printf("\nEnter your message:\n");
    char message[MAX_LEN];
    fgets(message, MAX_LEN, stdin);

    strcpy(client_inbox[email_count].to, to);
    strcpy(client_inbox[email_count].subject, subject);
    strcpy(client_inbox[email_count].message, message);

    email_count++;
    printf("\nEmail sent successfully!\n\n");
}

void display_inbox(){
    printf("\n");
    if(email_count == 0){
        printf("No emails to display.\n\n");
        return;
    }

    printf("%-20s %-20s %-30s\n", "From", "To", "Subject");
    printf("----------------------------------------------\n");

    for(int i=0; i<email_count; i++){
        printf("%-20s %-20s %-30s\n", client_inbox[i].from, client_inbox[i].to, client_inbox[i].subject);
    }

    printf("\n");
}

void search_inbox(){
    char keyword[MAX_LEN];
    printf("\nEnter keyword to be searched:");
    scanf("%s", keyword);
    getchar();

    int flag = 0;

    printf("\n");
    printf("%-20s %-20s %-30s\n", "From", "To", "Subject");
    printf("----------------------------------------------\n");

    for(int i=0; i<email_count; i++){
        if(strstr(client_inbox[i].from, keyword) || strstr(client_inbox[i].to, keyword) || strstr(client_inbox[i].message, keyword)){
            printf("%-20s %-20s %-30s\n", client_inbox[i].from, client_inbox[i].to, client_inbox[i].subject);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("No emails found containing the keyword '%s'.\n", keyword);
    }

    printf("\n");
}

int main(){
    printf("Welcome to GeniusMail!\n");

    while(1){
        printf("1. Compose email\n");
        printf("2. Display inbox\n");
        printf("3. Search inbox\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                compose_email();
                break;
            case 2:
                display_inbox();
                break;
            case 3:
                search_inbox();
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n\n");
        }
    }

    return 0;
}