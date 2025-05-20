//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n, i, j, choice;
    int counter = 0;
    int yesvote = 0;
    int novote = 0;
    int abstainvote = 0;
    char name[20];
    printf("Enter the number of voters: ");
    scanf("%d", &n);
    srand(time(NULL));
    printf("The following are the candidates:\n");
    printf("1. Romeo\n2. Juliet\n3. Abstain\n\n");
    for(i=1; i<=n; i++){
        printf("Voter %d, please enter your name: ", i);
        scanf("%s", name);
        printf("Hello %s, please cast your vote:\n", name);
        printf("1. Romeo\n2. Juliet\n3. Abstain\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            yesvote++;
            printf("Thank you for casting your vote for Romeo.\n\n");
        } else if(choice == 2){
            novote++;
            printf("Thank you for casting your vote for Juliet.\n\n");
        } else if(choice == 3){
            abstainvote++;
            printf("Thank you for abstaining from voting.\n\n");
        } else {
            printf("Invalid choice.\n\n");
        }
    }
    printf("The voting is now closed.\n");
    printf("Results:\n");
    printf("Number of votes for Romeo: %d\n", yesvote);
    printf("Number of votes for Juliet: %d\n", novote);
    printf("Number of abstentions: %d\n", abstainvote);
    if(yesvote > novote){
        printf("Romeo is the winner!\n");
    } else if(novote > yesvote){
        printf("Juliet is the winner!\n");
    } else {
        printf("The voting is tied.\n");
    }
    return 0;
}