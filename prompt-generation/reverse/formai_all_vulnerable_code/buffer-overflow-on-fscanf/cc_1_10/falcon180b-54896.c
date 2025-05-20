//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

int main()
{
    int i,j,num_candidates,choice,count=0,index;
    char candidates[100][20],candidate_name[100][20];
    char password[10];
    FILE *fp;

    printf("Enter the number of candidates: ");
    scanf("%d",&num_candidates);

    for(i=0;i<num_candidates;i++)
    {
        printf("Enter candidate name: ");
        scanf("%s",candidates[i]);
    }

    fp=fopen("password.txt","r");
    fscanf(fp,"%s",password);
    fclose(fp);

    printf("Enter the password: ");
    scanf("%s",password);

    if(strcmp(password,"Turing")==0)
    {
        printf("Welcome to the Electronic Voting System\n");
        printf("----------------------------------------\n");
        printf("Please select your candidate:\n");
        for(i=0;i<num_candidates;i++)
        {
            printf("%d. %s\n",i+1,candidates[i]);
        }
        printf("----------------------------------------\n");
        scanf("%d",&choice);
        index=choice-1;
        count++;
        printf("You have voted for %s\n",candidates[index]);
        printf("----------------------------------------\n");
        printf("Thank you for voting\n");
        printf("----------------------------------------\n");
    }
    else
    {
        printf("Invalid password\n");
    }

    return 0;
}