//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_EMAILS 100 //maximum number of emails that can be stored
#define MAX_EMAIL_LEN 50 //maximum length of email address
#define MAX_NAME_LEN 20 //maximum length of name

struct mailing_list{
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

int count_emails = 0;
struct mailing_list emails[MAX_EMAILS];

void add_email(){
    if(count_emails == MAX_EMAILS){
        printf("Can't add any more emails. Mailing list full.\n");
        return;
    }
    struct mailing_list new_email;
    printf("Enter name: ");
    scanf("%s", new_email.name);
    printf("Enter email: ");
    scanf("%s", new_email.email);
    emails[count_emails] = new_email;
    count_emails++;
    printf("Email added successfully!\n");
}

void remove_email(){
    if(count_emails == 0){
        printf("Mailing list is empty. Can't remove any emails.\n");
        return;
    }
    printf("Enter email address to remove: ");
    char email_to_remove[MAX_EMAIL_LEN];
    scanf("%s", email_to_remove);
    int i = 0;
    for(i = 0; i < count_emails; i++){
        if(strcmp(emails[i].email, email_to_remove) == 0){
            break;
        }
    }
    if(i == count_emails){
        printf("Email not found in mailing list.\n");
    }
    else{
        for(int j = i; j < count_emails - 1; j++){
            emails[j] = emails[j+1];
        }
        count_emails--;
        printf("Email removed successfully!\n");
    }
}

void view_emails(){
    if(count_emails == 0){
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Mailing List:\n");
    for(int i = 0; i < count_emails; i++){
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main(){
    printf("Welcome to the Mailing List Manager!\n");
    while(1){
        int choice;
        printf("\nMenu:\n1. Add email\n2. Remove email\n3. View Mailing List\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_email();
                break;
            case 2:
                remove_email();
                break;
            case 3:
                view_emails();
                break;
            case 4:
                printf("Exiting Mailing List Manager...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }
    return 0;
}