//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 100

int main()
{
   int choice,i,j,k,insert_success;
   char emails[MAX_EMAILS][EMAIL_LENGTH],new_email[EMAIL_LENGTH];
   int count=0;

   while(1)
   {
      printf("\nEnter your choice:\n");
      printf("1. Add email to mailing list\n");
      printf("2. Remove email from mailing list\n");
      printf("3. Print all emails in mailing list\n");
      printf("4. Exit program\n");
      printf("Choice : ");
      scanf("%d",&choice);

      switch(choice)
      {
         case 1: printf("\nEnter the new email to be inserted : ");
                 scanf("%s",new_email);
                 if(count==MAX_EMAILS)
                    printf("Mailing list is full. Cannot insert new email.\n");
                 else
                 {
                    insert_success=0;
                    for(i=0;i<count;i++)
                    {
                       if(strcmp(emails[i],new_email)==0)
                       {
                          printf("Email already exists in mailing list.\n");
                          insert_success=1;
                          break;
                       }
                    }
                    if(!insert_success)
                    {
                       strcpy(emails[count],new_email);
                       count++;
                       printf("Email successfully inserted in mailing list.\n");
                    }
                 }
                 break;

         case 2: if(count==0)
                    printf("Mailing list is empty. Cannot delete any email.\n");
                 else
                 {
                    printf("\nEnter email to be deleted : ");
                    scanf("%s",new_email);
                    for(i=0;i<count;i++)
                    {
                       if(strcmp(emails[i],new_email)==0)
                       {
                          for(j=i;j<count-1;j++)
                             strcpy(emails[j],emails[j+1]);
                          count--;
                          printf("Email successfully deleted from mailing list.\n");
                          break;
                       }
                    }
                    if(i==count)
                       printf("Email does not exist in mailing list.\n");
                 }
                 break;

         case 3: if(count==0)
                    printf("Mailing list is empty.\n");
                 else
                 {
                    printf("\nEmails in mailing list are : \n");
                    for(i=0;i<count;i++)
                       printf("%d. %s\n",i+1,emails[i]);
                 }
                 break;

         case 4: exit(0);
         default: printf("\nInvalid choice. Please enter a valid choice.\n");
      }
   }
   return 0;
}