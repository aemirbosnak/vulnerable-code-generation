//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

struct candidate {       // defining structure of candidate
    int id;
    char name[30];
    int votes;
}c[100];

int main() {
    int num;  //number of candidates
    int ch;  //user choice
    int i, j; //iterators 
    int flag = 0; 
    int max_votes = 0, winner = 0; //max_votes - maximum votes, winner - candidate id of the winner
    char loop; //yes or no

    printf("\nEnter the number of candidates participating in the election:");
    scanf("%d", &num);

    // Initialise candidate details
    for(i=0; i<num; i++) {
        printf("\n\nCandidate no. %d\n", i+1);
        c[i].id = i+1;
        printf("Enter the name of the candidate: ");
        scanf("%s", &c[i].name);
        c[i].votes = 0;
    }

    do {
        printf("\n\nElectronic Voting System\n");
        printf("\n1. Cast your vote\n");
        printf("2. View result\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nCandidates List\n");
                for(i=0; i<num; i++) {
                    printf("%d. %s\n", c[i].id, c[i].name);
                }

                //Input candidate votings from user
                printf("\nEnter the candidate number for whom you want to vote: ");
                scanf("%d", &j);

                if(j>0 && j<=num) {
                    c[j-1].votes++;
                    printf("Thank you for voting!\n");
                }
                else {
                    printf("Invalid candidate number.\n");
                }
                break;

            case 2:
                printf("\n\nCandidate Details\n");
                printf("Candidate name \t\t No. of Votes\n");

                for(i=0; i<num; i++) {
                    printf("\n%-20s\t\t %d\n", c[i].name, c[i].votes);
                    
                    // Calculate winner
                    if(c[i].votes > max_votes) {
                        max_votes = c[i].votes;
                        winner = i;
                    }
                    else if(c[i].votes == max_votes) {
                        flag = 1;  // If there is a tie
                    }
                }

                if(flag == 1) {
                    printf("\n\nIt's a TIE!!");
                }
                else {
                    printf("\n\nThe winner is %s with %d votes\n", c[winner].name, c[winner].votes);
                }
                break;

            case 3:
                printf("\n\nThank you for using Electronic Voting system!\n\n");
                exit(0);

            default:
                printf("\n\nInvalid choice, please try again!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &loop);

    }while(loop=='y' || loop=='Y');

    return 0;
}