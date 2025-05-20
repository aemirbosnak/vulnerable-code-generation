//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,n,i,vote=0,votes[4]={0},max_votes=0,winner=0;
    char ch;
    printf("\n Welcome to Electronic Voting System\n");
    printf("\n####################################\n");

    printf("\n Please Enter the Number of Voters: \n");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("\n Voter: %d\n",i);
        printf("\n Enter Your Vote: \n");
        printf("\n1. Candidate A\n2. Candidate B\n3. Candidate C\n4. NOTA\n");
        scanf("%d",&vote);

        switch(vote){
            case 1: votes[0]++;
                    break;

            case 2: votes[1]++;
                    break;

            case 3: votes[2]++;
                    break;

            case 4: votes[3]++;
                    break;

            default: printf("\n Invalid Vote, Please Enter a Valid Vote\n");
                     i--;
                     break;
        }
    }
    printf("\n Number of Votes for Each Candidate\n");
    printf("\nCandidate A: %d\n",votes[0]);
    printf("\nCandidate B: %d\n",votes[1]);
    printf("\nCandidate C: %d\n",votes[2]);
    printf("\nNOTA: %d\n",votes[3]);

    max_votes=votes[0];

    for(i=0;i<4;i++){
        if(votes[i]>max_votes){
            max_votes=votes[i];
            winner=i;
        }
    }

    if(winner==0)
        printf("\n The Winner is Candidate A\n");

    else if(winner==1)
        printf("\n The Winner is Candidate B\n");

    else if(winner==2)
        printf("\n The Winner is Candidate C\n");

    else
        printf("\n NOTA has the Most Votes, Therefore No Candidate Won\n");

    printf("\n  Do You Want to Add More Votes?\n");
    printf("\n Press Y for Yes and N for No\n");
    scanf(" %c",&ch);

    if(ch=='y'||ch=='Y'){
        printf("\n Enter the Number of Voters to be Added: \n");
        scanf("%d",&a);

        for(i=1;i<=a;i++){
            printf("\n Voter: %d\n",i);
            printf("\n Enter Your Vote: \n");
            printf("\n1. Candidate A\n2. Candidate B\n3. Candidate C\n4. NOTA\n");
            scanf("%d",&vote);

            switch(vote){
                case 1: votes[0]++;
                        break;

                case 2: votes[1]++;
                        break;

                case 3: votes[2]++;
                        break;

                case 4: votes[3]++;
                        break;

                default: printf("\n Invalid Vote, Please Enter a Valid Vote\n");
                         i--;
                         break;
            }
            n+=1;
        }
        printf("\n The Updated Number of Votes for Each Candidate\n");
        printf("\nCandidate A: %d\n",votes[0]);
        printf("\nCandidate B: %d\n",votes[1]);
        printf("\nCandidate C: %d\n",votes[2]);
        printf("\nNOTA: %d\n",votes[3]);

        max_votes=votes[0];

        for(i=0;i<4;i++){
            if(votes[i]>max_votes){
                max_votes=votes[i];
                winner=i;
            }
        }

        if(winner==0)
            printf("\n The Winner is Candidate A\n");

        else if(winner==1)
            printf("\n The Winner is Candidate B\n");

        else if(winner==2)
            printf("\n The Winner is Candidate C\n");

        else
            printf("\n NOTA has the Most Votes, Therefore No Candidate Won\n");
    }
    else{
        printf("\nThank You for Using Electronic Voting System\n");
    }
    return 0;
}