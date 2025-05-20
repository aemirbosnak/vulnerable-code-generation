//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>

// declaring the main function
int main()
{
    // declaring the variables
    int totalVoters, option, votes[10] = {0};

    // getting the input from the user
    printf("Enter the total number of voters: ");
    scanf("%d", &totalVoters);

    // displaying the options to the user
    printf("\n----OPTIONS----\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");

    // loop to get all the votes from the voters
    for(int i=0; i<totalVoters; i++)
    {
        printf("\nVoter %d, please enter your choice: ", i+1);
        scanf("%d", &option);

        // validating the user input
        if(option > 0 && option < 4)
        {
            votes[option-1]++;
        }
        else
        {
            printf("\nInvalid choice! Please select from the given options.\n");
            i--;
        }
    }

    // displaying the results of the election
    printf("\n----ELECTION RESULTS----\n");
    printf("Candidate A: %d\n", votes[0]);
    printf("Candidate B: %d\n", votes[1]);
    printf("Candidate C: %d\n", votes[2]);

    // calculating and displaying the winner of the election
    if(votes[0] > votes[1] && votes[0] > votes[2])
    {
        printf("Candidate A wins!");
    }
    else if(votes[1] > votes[0] && votes[1] > votes[2])
    {
        printf("Candidate B wins!");
    }
    else if(votes[2] > votes[0] && votes[2] > votes[1])
    {
        printf("Candidate C wins!");
    }
    else
    {
        printf("The election is tied!");
    }

    return 0;
}