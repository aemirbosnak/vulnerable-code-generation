//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int vote1=0,vote2=0,vote3=0,vote4=0;
    int num_voters, i, voter_ID, choice;
    srand(time(0));
    
    printf("Oh Romeo, Romeo! Why is everyone in the town square?\n");
    printf("My dear Juliet, it's the election day. Citizens come to cast their vote.\n");
    printf("Election? What is that?\n");
    printf("It's a way for the people to choose their leader, my fair lady.\n");
    
    printf("How many citizens are there to vote today?\n");
    scanf("%d", &num_voters);
    printf("Great! Let's get started.\n");
    
    for(i=0; i<num_voters; i++){
        voter_ID = (rand() % 1000) + 1;
        printf("Voter %d, please enter your vote.\n", voter_ID);
        printf("1. Romeo and Juliet as leaders.\n");
        printf("2. Tybalt and Mercutio as leaders.\n");
        printf("3. Rosaline and Benvolio as leaders.\n");
        printf("4. Paris and Escalus as leaders.\n");
        scanf("%d", &choice);
        
        switch(choice){
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
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("The voting has ended, my love. Here are the results:\n");
    printf("Romeo and Juliet - %d votes.\n", vote1);
    printf("Tybalt and Mercutio - %d votes.\n", vote2);
    printf("Rosaline and Benvolio - %d votes.\n", vote3);
    printf("Paris and Escalus - %d votes.\n", vote4);
    
    if(vote1 > vote2 && vote1 > vote3 && vote1 > vote4){
        printf("Romeo and Juliet have won the election!\n");
    }else if(vote2 > vote1 && vote2 > vote3 && vote2 > vote4){
        printf("Tybalt and Mercutio has won the election!\n");
    }else if(vote3 > vote1 && vote3 > vote2 && vote3 > vote4){
        printf("Rosaline and Benvolio have won the election!\n");
    }else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3){
        printf("Paris and Escalus have won the election!\n");
    }else{
        printf("The election resulted in a tie! We'll have to hold another round.\n");
    }
    
    return 0;
}