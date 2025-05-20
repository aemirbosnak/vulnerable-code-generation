//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[20];
    int age;
    int votes;
} Candidate;

void castVote(Candidate candidates[], int size){
    int choice;
    printf("Enter the ID of the candidate you want to vote for: ");
    scanf("%d", &choice);
    for(int i = 0; i < size; i++){
        if(candidates[i].id == choice){
            candidates[i].votes++;
            printf("Your vote has been cast for %s\n", candidates[i].name);
            return;
        }
    }
    printf("Invalid candidate ID!\n");
}

void displayResults(Candidate candidates[], int size){
    printf("ID\tName\t\tAge\tVotes\n");
    for(int i = 0; i < size; i++){
        printf("%d\t%-10s\t%d\t%d\n", candidates[i].id, candidates[i].name, candidates[i].age, candidates[i].votes);
    }
}

int main(){
    int size = 5;
    Candidate candidates[size];
    candidates[0].id = 1;
    strcpy(candidates[0].name, "John");
    candidates[0].age = 35;
    candidates[0].votes = 0;
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Jane");
    candidates[1].age = 45;
    candidates[1].votes = 0;
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Tom");
    candidates[2].age = 40;
    candidates[2].votes = 0;
    candidates[3].id = 4;
    strcpy(candidates[3].name, "Mary");
    candidates[3].age = 30;
    candidates[3].votes = 0;
    candidates[4].id = 5;
    strcpy(candidates[4].name, "Bob");
    candidates[4].age = 50;
    candidates[4].votes = 0;
    
    int choice;
    do{
        printf("\nWelcome to the Electronic Voting System\n");
        printf("1. Cast vote\n");
        printf("2. Display results\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                castVote(candidates, size);
                break;
            case 2:
                displayResults(candidates, size);
                break;
            case 3:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 3);
    return 0;
}