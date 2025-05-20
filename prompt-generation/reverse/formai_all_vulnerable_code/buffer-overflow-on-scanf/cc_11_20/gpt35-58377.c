//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 50

typedef struct{
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
}Email;

int main(){
    Email mailingList[MAX_EMAILS];
    int numEmails = 0;
    int choice = -1;

    printf("Welcome to the Happy Mailing List Manager!\n");

    while(choice != 0){
        printf("\nEnter 1 to add an email\nEnter 2 to remove an email\nEnter 3 to display all emails\nEnter 0 to exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(numEmails >= MAX_EMAILS){
                    printf("\nSorry, the mailing list is full!\n");
                }
                else{
                    printf("\nEnter name: ");
                    scanf("%s", mailingList[numEmails].name);
                    printf("Enter email: ");
                    scanf("%s", mailingList[numEmails].email);
                    numEmails++;
                    printf("\nEmail added to mailing list!\n");
                }
                break;
            case 2:
                if(numEmails <= 0){
                    printf("\nSorry, the mailing list is empty!\n");
                }
                else{
                    char emailToRemove[MAX_LENGTH];
                    printf("\nEnter email to remove: ");
                    scanf("%s", emailToRemove);
                    int emailIndex = -1;

                    //find index of email to remove
                    for(int i=0; i<numEmails; i++){
                        if(strcmp(mailingList[i].email, emailToRemove) == 0){
                            emailIndex = i;
                            break;
                        }
                    }

                    if(emailIndex == -1){
                        printf("\nSorry, that email is not in the mailing list.\n");
                    }
                    else{
                        //shift all emails after the removed email down by one index
                        for(int i=emailIndex; i<numEmails-1; i++){
                            strcpy(mailingList[i].name, mailingList[i+1].name);
                            strcpy(mailingList[i].email, mailingList[i+1].email);
                        }
                        numEmails--;
                        printf("\nEmail removed from mailing list!\n");
                    }
                }
                break;
            case 3:
                if(numEmails <= 0){
                    printf("\nSorry, the mailing list is empty!\n");
                }
                else{
                    printf("\nMailing List:\n");
                    for(int i=0; i<numEmails; i++){
                        printf("%s - %s\n", mailingList[i].name, mailingList[i].email);
                    }
                }
                break;
            case 0:
                printf("\nThank you for using the Happy Mailing List Manager!\n");
                break;
            default:
                printf("\nSorry, that is an invalid choice!\n");
                break;
        }
    }
    return 0;
}