//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct candidate{
    char name[50];
    int votes;
};

void add_candidate(struct candidate* c, int n){
    printf("Enter the name of the candidate: ");
    scanf("%s",c[n].name);
    c[n].votes = 0;
}

void display_candidates(struct candidate c[], int n){
    printf("\nList of Candidates:\n");
    for(int i=0; i<n; i++){
        printf("%d. %s\n",i+1,c[i].name);
    }
}

void cast_vote(struct candidate c[], int n){
    int choice;
    printf("\nEnter the number of the candidate you want to vote for: ");
    scanf("%d",&choice);
    if(choice >= 1 && choice <= n){
        c[choice-1].votes++;
    }
    else{
        printf("Invalid choice!\n");
    }
}

void show_results(struct candidate c[], int n){
    printf("\nResults:\n");
    for(int i=0; i<n; i++){
        printf("%s: %d votes\n",c[i].name,c[i].votes);
    }
}

int main(){
    struct candidate c[MAX];
    int n = 0;
    printf("How many candidates are there? ");
    scanf("%d",&n);
    add_candidate(c,n);
    display_candidates(c,n);
    int vote;
    do{
        printf("\nDo you want to cast a vote? (y/n): ");
        scanf(" %c",&vote);
        if(vote == 'y' || vote == 'Y'){
            cast_vote(c,n);
        }
    }while(vote == 'y' || vote == 'Y');
    show_results(c,n);
    return 0;
}