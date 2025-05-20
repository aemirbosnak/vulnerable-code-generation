//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>

struct Vote {
    char candidate[50];
    int votes;
};

int main() {
    struct Vote vote1, vote2, vote3, vote4, vote5;

    printf("Welcome to the Electronic Voting System!\n");

    printf("Please enter the candidate's name:\n");
    scanf("%s", vote1.candidate);

    vote1.votes = 0;
    printf("Number of votes for %s: %d\n", vote1.candidate, vote1.votes);

    printf("-----------------------------\n");

    printf("Please enter the candidate's name:\n");
    scanf("%s", vote2.candidate);

    vote2.votes = 0;
    printf("Number of votes for %s: %d\n", vote2.candidate, vote2.votes);

    printf("-----------------------------\n");

    printf("Please enter the candidate's name:\n");
    scanf("%s", vote3.candidate);

    vote3.votes = 0;
    printf("Number of votes for %s: %d\n", vote3.candidate, vote3.votes);

    printf("-----------------------------\n");

    printf("Please enter the candidate's name:\n");
    scanf("%s", vote4.candidate);

    vote4.votes = 0;
    printf("Number of votes for %s: %d\n", vote4.candidate, vote4.votes);

    printf("-----------------------------\n");

    printf("Please enter the candidate's name:\n");
    scanf("%s", vote5.candidate);

    vote5.votes = 0;
    printf("Number of votes for %s: %d\n", vote5.candidate, vote5.votes);

    printf("-----------------------------\n");

    printf("Thank you for voting! Here are the results:\n");
    printf("Candidate 1: %s - %d\n", vote1.candidate, vote1.votes);
    printf("Candidate 2: %s - %d\n", vote2.candidate, vote2.votes);
    printf("Candidate 3: %s - %d\n", vote3.candidate, vote3.votes);
    printf("Candidate 4: %s - %d\n", vote4.candidate, vote4.votes);
    printf("Candidate 5: %s - %d\n", vote5.candidate, vote5.votes);

    return 0;
}