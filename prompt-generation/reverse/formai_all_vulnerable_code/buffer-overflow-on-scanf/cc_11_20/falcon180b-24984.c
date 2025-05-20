//Falcon-180B DATASET v1.0 Category: Email Client ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX 1000

struct mail
{
    char from[50];
    char to[50];
    char subject[100];
    char message[1000];
    time_t time;
};

void main()
{
    int choice,i,j,k=0;
    char ch;
    struct mail m[MAX];

    printf("\n\n\t\tEmail Client\n");
    printf("\n1. Compose Mail");
    printf("\n2. Inbox");
    printf("\n3. Sent Items");
    printf("\n4. Drafts");
    printf("\n5. Trash");
    printf("\n6. Logout");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the recipient's email address: ");
                scanf("%s",m[k].to);
                printf("\nEnter the subject: ");
                scanf("%s",m[k].subject);
                printf("\nEnter your message: ");
                fgets(m[k].message,1000,stdin);
                m[k].time=time(0);
                k++;
                break;

            case 2:
                system("clear");
                printf("\n\nInbox\n");
                for(i=0;i<k;i++)
                {
                    if(strcmp(m[i].to,"Inbox")==0)
                    {
                        printf("\nFrom: %s",m[i].from);
                        printf("\nSubject: %s",m[i].subject);
                        printf("\nMessage: %s",m[i].message);
                        printf("\nTime: %s",ctime(&m[i].time));
                    }
                }
                break;

            case 3:
                system("clear");
                printf("\n\nSent Items\n");
                for(i=0;i<k;i++)
                {
                    if(strcmp(m[i].to,"Sent Items")==0)
                    {
                        printf("\nTo: %s",m[i].to);
                        printf("\nSubject: %s",m[i].subject);
                        printf("\nMessage: %s",m[i].message);
                        printf("\nTime: %s",ctime(&m[i].time));
                    }
                }
                break;

            case 4:
                system("clear");
                printf("\n\nDrafts\n");
                for(i=0;i<k;i++)
                {
                    if(strcmp(m[i].to,"Drafts")==0)
                    {
                        printf("\nTo: %s",m[i].to);
                        printf("\nSubject: %s",m[i].subject);
                        printf("\nMessage: %s",m[i].message);
                        printf("\nTime: %s",ctime(&m[i].time));
                    }
                }
                break;

            case 5:
                system("clear");
                printf("\n\nTrash\n");
                for(i=0;i<k;i++)
                {
                    if(strcmp(m[i].to,"Trash")==0)
                    {
                        printf("\nFrom: %s",m[i].from);
                        printf("\nSubject: %s",m[i].subject);
                        printf("\nMessage: %s",m[i].message);
                        printf("\nTime: %s",ctime(&m[i].time));
                    }
                }
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
}