//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate
{
    int id;
    char name[30];
    char party[30];
    int votes;
};

int main()
{
    int n, i, j, k;
    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    struct candidate list[n], winner;

    for(i=0;i<n;i++)
    {
        printf("Enter the id of candidate %d: ", i+1);
        scanf("%d",&list[i].id);

        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s",list[i].name);

        printf("Enter the party of candidate %d: ", i+1);
        scanf("%s",list[i].party);

        list[i].votes=0; 
    }

    int choice, flag;
    int voter_id;
    do
    {
        flag = 0;
        printf("\nWelcome to the Electronic Voting System\n");
        printf("Enter 1 to cast your vote\n");
        printf("Enter 2 to view the candidate list\n");
        printf("Enter 3 to view the election results\n");
        printf("Enter 4 to exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter your Voter ID: ");
                    scanf("%d",&voter_id);
                    for(i=0;i<n;i++)
                    {
                        if(voter_id == list[i].id)
                        {
                            printf("Please select a candidate to vote for:\n");
                            for(j=0;j<n;j++)
                            {
                                printf("Enter %d to vote for %s of %s\n", j+1, list[j].name, list[j].party);
                            }
                            scanf("%d",&k);
                            list[k-1].votes++;
                            printf("Thank you for your vote!\n");
                            flag = 1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        printf("Invalid Voter ID\n");
                    }
                    break;
                    
            case 2: printf("Candidate List:\n");
                    for(i=0;i<n;i++)
                    {
                        printf("ID: %d\tName: %s\tParty: %s\n", list[i].id, list[i].name, list[i].party);
                    }
                    break;

            case 3: winner = list[0];
                    for(i=0;i<n;i++)
                    {
                        if(list[i].votes>winner.votes)
                        {
                            winner = list[i];
                        }
                    }
                    printf("Election Results:\n");
                    printf("Winner is %s of %s with %d votes\n", winner.name, winner.party, winner.votes);
                    break;

            case 4: printf("Goodbye!\n");
                    break;

            default:printf("Invalid choice\n");
                    break;
        }
    }while(choice != 4);
    return 0;
}