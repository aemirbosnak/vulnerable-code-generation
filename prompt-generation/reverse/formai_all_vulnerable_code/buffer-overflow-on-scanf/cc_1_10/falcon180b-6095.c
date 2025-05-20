//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 10

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int vote[MAX_CANDIDATES];
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

void create_candidates() {
    int i;
    for(i=0;i<MAX_CANDIDATES;i++) {
        printf("Enter the name of candidate %d: ",i+1);
        scanf("%s",candidates[i].name);
        candidates[i].votes=0;
    }
}

void create_voters() {
    int i;
    for(i=0;i<MAX_VOTERS;i++) {
        printf("Enter the name of voter %d: ",i+1);
        scanf("%s",voters[i].name);
        for(int j=0;j<MAX_CANDIDATES;j++) {
            voters[i].vote[j]=0;
        }
    }
}

void vote() {
    int i,j,k;
    for(i=0;i<MAX_VOTERS;i++) {
        printf("Voter %s has casted %d votes.\n",voters[i].name,0);
        for(int l=0;l<MAX_CANDIDATES;l++) {
            printf("Enter the vote for candidate %s (1 for yes, 0 for no): ",candidates[l].name);
            scanf("%d",&voters[i].vote[l]);
        }
        for(j=0;j<MAX_CANDIDATES;j++) {
            for(k=j+1;k<MAX_CANDIDATES;k++) {
                if(voters[i].vote[j]>voters[i].vote[k]) {
                    int temp=voters[i].vote[j];
                    voters[i].vote[j]=voters[i].vote[k];
                    voters[i].vote[k]=temp;
                }
            }
        }
        for(j=0;j<MAX_CANDIDATES;j++) {
            candidates[j].votes+=voters[i].vote[j];
        }
    }
}

void display_results() {
    int i;
    for(i=0;i<MAX_CANDIDATES;i++) {
        printf("Candidate %s got %d votes.\n",candidates[i].name,candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));
    create_candidates();
    create_voters();
    vote();
    display_results();
    return 0;
}