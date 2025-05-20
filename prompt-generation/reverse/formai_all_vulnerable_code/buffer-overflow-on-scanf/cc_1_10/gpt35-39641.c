//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

// Voter Structure
struct voter{
    char name[20];
    int age;
    char address[50];
    char vote[20];
};

// Function to Display Menu
void display_menu(){
    printf("\n");
    printf("Electronic Voting System\n");
    printf("------------------------\n");
    printf("1. Add Voter\n");
    printf("2. Display Voters\n");
    printf("3. Cast Vote\n");
    printf("4. Show Result\n");
    printf("5. Exit\n");
    printf("------------------------\n");
}

// Function to Add a Voter
void add_voter(struct voter v[], int *count){
    printf("\n");
    printf("Enter Voter Details\n");

    printf("Name: ");
    fflush(stdin);
    gets(v[*count].name);

    printf("Age: ");
    fflush(stdin);
    scanf("%d",&v[*count].age);
    while(v[*count].age<18){
        printf("Minimum Age should be 18\n");
        printf("Enter Age Again: ");
        fflush(stdin);
        scanf("%d",&v[*count].age);
    }

    printf("Address: ");
    fflush(stdin);
    gets(v[*count].address);

    strcpy(v[*count].vote,"Not Casted");
    (*count)++;
    printf("Voter Added Successfully!\n");
}

// Function to Display All Voters
void display_voters(struct voter v[], int *count){
    printf("\n");
    printf("All Voters\n");
    printf("----------\n");

    if(*count==0){
        printf("No Voters Added Yet!\n");
        return;
    }

    printf("S.No\tName\t\tAge\tAddress\t\tVote\n");
    for(int i=0; i<*count; i++){
        printf("%d\t",i+1);
        printf("%s\t\t",v[i].name);
        printf("%d\t",v[i].age);
        printf("%s\t",v[i].address);
        printf("%s\n",v[i].vote);
    }
}

// Function to Cast Vote
void cast_vote(struct voter v[], int *count){
    printf("\n");
    printf("Cast Your Vote\n");
    printf("--------------\n");

    char candidate[MAX][20]={"Candidate 1","Candidate 2","Candidate 3","Candidate 4","Candidate 5"};
    int votes[MAX]={0,0,0,0,0};

    printf("Select Your Candidate (Enter Candidate Number):\n");
    printf("1. Candidate 1\n2. Candidate 2\n3. Candidate 3\n4. Candidate 4\n5. Candidate 5\n");
    printf("Enter Candidate Number: ");
    int choice;
    scanf("%d",&choice);

    while(choice<1 || choice>5){
        printf("Invalid Choice!\n");
        printf("Enter Candidate Number Again: ");
        scanf("%d",&choice);
    }

    strcpy(v[*count-1].vote,candidate[choice-1]); // Add Vote to the Last Added Voter
    printf("Vote Casted Successfully!\n");
}

// Function to Show Result
void show_result(struct voter v[], int *count){
    printf("\n");
    printf("Election Result\n");
    printf("----------------\n");

    char candidate[MAX][20]={"Candidate 1","Candidate 2","Candidate 3","Candidate 4","Candidate 5"};
    int votes[MAX]={0,0,0,0,0};

    if(*count==0){
        printf("No Voters Added Yet!\n");
        return;
    }

    for(int i=0; i<*count; i++){
        for(int j=0; j<MAX; j++){
            if(strcmp(v[i].vote,candidate[j])==0){
                votes[j]++;
            }
        }
    }

    printf("Candidate\tVotes\n");
    for(int i=0; i<MAX; i++){
        printf("%s\t\t%d\n",candidate[i],votes[i]);
    }

    int winner=0;
    for(int i=0; i<MAX; i++){
        if(votes[i]>votes[winner]){
            winner=i;
        }
    }

    printf("Winner: %s\n",candidate[winner]);
}

// Main Function
int main(){
    struct voter v[MAX];
    int count=0;

    while(1){
        display_menu();

        int choice;
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_voter(v,&count);
                break;
            case 2:
                display_voters(v,&count);
                break;
            case 3:
                cast_vote(v,&count);
                break;
            case 4:
                show_result(v,&count);
                break;
            case 5:
                printf("Thank You for Using Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}