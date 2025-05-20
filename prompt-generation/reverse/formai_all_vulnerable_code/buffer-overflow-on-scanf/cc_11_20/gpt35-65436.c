//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int voters = 1000, votes = 0;
    int candidate1 = 0, candidate2 = 0, candidate3 = 0;
    char password[20], result[100];
    int i, vote;
    printf("Welcome to Medieval Voting System\n");

    //Authenticate the voter
    printf("Enter your password: ");
    scanf("%s", password);
    
    if(strcmp(password, "password123") == 0){
        printf("Authentication successful.\n\n");

        //Display the candidates
        printf("Choose your candidate:\n");
        printf("1. Sir John\n");
        printf("2. Lady Mary\n");
        printf("3. Sir William\n");

        //Get the vote
        printf("Enter your choice: ");
        scanf("%d", &vote);

        //Count the vote
        switch(vote){
            case 1: candidate1++; break;
            case 2: candidate2++; break;
            case 3: candidate3++; break;
            default: printf("Invalid choice\n");
        }

        //Update the vote count
        votes++;

        //Print the voting result
        printf("Your vote has been recorded for candidate %d\n\n", vote);

        //Check if all voters have voted
        if(votes == voters){
            //Find the winner
            if(candidate1 > candidate2 && candidate1 > candidate3){
                sprintf(result, "Sir John is the winner with %d votes.", candidate1);
            }
            else if(candidate2 > candidate1 && candidate2 > candidate3){
                sprintf(result, "Lady Mary is the winner with %d votes.", candidate2);
            }
            else if(candidate3 > candidate1 && candidate3 > candidate2){
                sprintf(result, "Sir William is the winner with %d votes.", candidate3);
            }
            else{
                sprintf(result, "It's a tie!");
            }

            //Print the voting result
            printf("Voting is now closed.\n");
            printf("%s\n", result);
        }
        else{
            printf("%d votes out of %d have been counted\n\n", votes, voters);
        }
    }
    else{
        printf("Invalid password. Access denied.");
    }

    return 0;
}