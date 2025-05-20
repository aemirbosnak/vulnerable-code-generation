//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void castVote(int a, int b, int c, int d, int e);

int main() {

    int vote1=0, vote2=0, vote3=0, vote4=0, vote5=0;

    int option=0;
    while(option != 2) {

        printf("\nWelcome to the Electronic Voting System\n");
        printf("1) Cast your vote\n");
        printf("2) Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nCast your vote:\n");
                int vote;
                printf("1) Party A\n2) Party B\n3) Party C\n4) Party D\n5) Party E\n");
                printf("Enter your choice: ");
                scanf("%d", &vote);
                switch(vote) {
                    case 1:
                        vote1++;
                        break;
                    case 2:
                        vote2++;
                        break;
                    case 3:
                        vote3++;
                        break;
                    case 4:
                        vote4++;
                        break;
                    case 5:
                        vote5++;
                        break;
                    default:
                        printf("Invalid vote.");
                }
                printf("\nThank you for casting your vote!\n");
                sleep(1);
                break;

            case 2:
                printf("\nThank you for using the Electronic Voting System.\n");
                break;

            default:
                printf("Invalid option.");
                break;
        }
    }

    printf("\nResults:\n");
    printf("Party A: %d\n", vote1);
    printf("Party B: %d\n", vote2);
    printf("Party C: %d\n", vote3);
    printf("Party D: %d\n", vote4);
    printf("Party E: %d\n", vote5);

    if(vote1 > vote2 && vote1 > vote3 && vote1 > vote4 && vote1 > vote5) {
        printf("\nParty A has won the election!\n");
        castVote(vote1, vote2, vote3, vote4, vote5);
    }
    else if(vote2 > vote1 && vote2 > vote3 && vote2 > vote4 && vote2 > vote5) {
        printf("\nParty B has won the election!\n");
        castVote(vote1, vote2, vote3, vote4, vote5);
    }
    else if(vote3 > vote1 && vote3 > vote2 && vote3 > vote4 && vote3 > vote5) {
        printf("\nParty C has won the election!\n");
        castVote(vote1, vote2, vote3, vote4, vote5);
    }
    else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3 && vote4 > vote5) {
        printf("\nParty D has won the election!\n");
        castVote(vote1, vote2, vote3, vote4, vote5);
    }
    else if(vote5 > vote1 && vote5 > vote2 && vote5 > vote3 && vote5 > vote4) {
        printf("\nParty E has won the election!\n");
        castVote(vote1, vote2, vote3, vote4, vote5);
    }
    else {
        printf("\nIt is a tie. Retry Voting\n");
    }

    return 0;
}

void castVote(int a, int b, int c, int d, int e) {

    int total = a+b+c+d+e;

    printf("\nTotal number of votes casted : %d\n", total);

    float vote1_percent = (float)a/total * 100;
    float vote2_percent = (float)b/total * 100;
    float vote3_percent = (float)c/total * 100;
    float vote4_percent = (float)d/total * 100;
    float vote5_percent = (float)e/total * 100;

    printf("Party A: %d votes, Percentage : %.2f%%\n", a, vote1_percent);
    printf("Party B: %d votes, Percentage : %.2f%%\n", b, vote2_percent);
    printf("Party C: %d votes, Percentage : %.2f%%\n", c, vote3_percent);
    printf("Party D: %d votes, Percentage : %.2f%%\n", d, vote4_percent);
    printf("Party E: %d votes, Percentage : %.2f%%\n", e, vote5_percent);
}