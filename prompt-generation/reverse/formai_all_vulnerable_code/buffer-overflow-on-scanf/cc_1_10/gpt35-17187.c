//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <pthread.h>

int candidateA = 0, candidateB = 0, candidateC = 0;

pthread_mutex_t mutex;

void *vote(void *arg){
    int *myVote = (int *)arg;
    pthread_mutex_lock(&mutex);
    if(*myVote == 1){
        candidateA++;
    }else if(*myVote == 2){
        candidateB++;
    }else{
        candidateC++;
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(){
    pthread_t tid[1000];
    int numOfVoters, i, voteChoice;

    printf("Enter the number of voters: ");
    scanf("%d", &numOfVoters);

    printf("Press 1 to vote for candidate A\nPress 2 to vote for candidate B\nPress 3 to vote for candidate C\n");

    for(i = 0; i < numOfVoters; i++){
        printf("\nVoter %d, Enter your vote: ", i+1);
        scanf("%d", &voteChoice);
        pthread_create(&tid[i], NULL, vote, &voteChoice);
    }

    for(i = 0; i < numOfVoters; i++){
        pthread_join(tid[i], NULL);
    }

    printf("\nTotal votes for candidate A: %d", candidateA);
    printf("\nTotal votes for candidate B: %d", candidateB);
    printf("\nTotal votes for candidate C: %d", candidateC);

    int maxVotes = candidateA;
    char winner = 'A';

    if(candidateB > maxVotes){
        maxVotes = candidateB;
        winner = 'B';
    }

    if(candidateC > maxVotes){
        maxVotes = candidateC;
        winner = 'C';
    }

    printf("\n\nThe winner is candidate %c, with a total of %d votes.\n\n", winner, maxVotes);

    return 0;
}