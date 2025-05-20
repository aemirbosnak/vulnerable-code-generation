//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct candidate{
    char name[50];
    int votes;
};

void addcandidate(struct candidate *c, int *size){
    printf("Enter the name of the candidate: ");
    scanf("%s",c[*size].name);
    c[*size].votes=0;
    (*size)++;
}

void displaycandidates(struct candidate *c, int size){
    printf("The candidates are:\n");
    for(int i=0;i<size;i++){
        printf("%d. %s\n",i+1,c[i].name);
    }
}

void castvote(struct candidate *c, int size, int voterid){
    int choice;
    printf("Enter the voter id: ");
    scanf("%d",&voterid);
    printf("Enter the choice of the voter: ");
    scanf("%d",&choice);
    if(choice>=1 && choice<=size){
        c[choice-1].votes++;
    }else{
        printf("Invalid choice\n");
    }
}

void displayresults(struct candidate *c, int size){
    printf("The results are:\n");
    for(int i=0;i<size;i++){
        printf("%d. %s - %d votes\n",i+1,c[i].name,c[i].votes);
    }
}

int main(){
    struct candidate c[10];
    int size=0;
    addcandidate(c,&size);
    addcandidate(c,&size);
    addcandidate(c,&size);
    displaycandidates(c,size);
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    castvote(c,size,1);
    displayresults(c,size);
    return 0;
}