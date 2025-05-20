//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int vote;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

void add_candidate(candidate* c) {
    int i;
    for(i=0;i<MAX_CANDIDATES;i++) {
        if(strcmp(c->name,"")==0) break;
    }
    strcpy(candidates[i].name,c->name);
    candidates[i].votes = 0;
}

void add_voter(voter* v) {
    int i;
    for(i=0;i<MAX_VOTERS;i++) {
        if(strcmp(v->name,"")==0) break;
    }
    strcpy(voters[i].name,v->name);
    voters[i].vote = -1;
}

int main() {
    int i,j,k,n,m,choice;
    char name[50];

    printf("Enter number of candidates: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        printf("Enter candidate name: ");
        scanf("%s",name);
        add_candidate(&(candidates[i]));
    }

    printf("Enter number of voters: ");
    scanf("%d",&m);

    for(i=0;i<m;i++) {
        printf("Enter voter name: ");
        scanf("%s",name);
        add_voter(&(voters[i]));
    }

    printf("Candidates:\n");
    for(i=0;i<n;i++) {
        printf("%s\n",candidates[i].name);
    }

    printf("Voters:\n");
    for(i=0;i<m;i++) {
        printf("%s\n",voters[i].name);
    }

    printf("Voting started...\n");

    for(i=0;i<m;i++) {
        printf("Voter %s is voting...\n",voters[i].name);
        for(j=0;j<n;j++) {
            printf("%s got %d votes\n",candidates[j].name,candidates[j].votes);
        }
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice>=0 && choice<n) {
            voters[i].vote = choice;
            candidates[choice].votes++;
        }
    }

    printf("Voting ended...\n");

    for(i=0;i<n;i++) {
        printf("%s got %d votes\n",candidates[i].name,candidates[i].votes);
    }

    return 0;
}