//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate{
    char name[100];
    int votes;
};

int main(){
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d",&num_candidates);
    struct candidate* list_of_candidates = malloc(num_candidates * sizeof(struct candidate));
    for(int i = 0; i < num_candidates; i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s",list_of_candidates[i].name);
        list_of_candidates[i].votes = 0;
    }
    printf("Enter the number of voters: ");
    scanf("%d",&num_voters);
    char** voter_list = malloc(num_voters * sizeof(char*));
    for(int i = 0; i < num_voters; i++){
        voter_list[i] = malloc(100 * sizeof(char));
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s",voter_list[i]);
    }
    printf("Voting has begun!\n");
    while(num_voters > 0){
        char voter[100];
        printf("Enter the name of the voter: ");
        scanf("%s",voter);
        int valid_vote = 0;
        for(int i = 0; i < num_voters; i++){
            if(strcmp(voter_list[i], voter) == 0){
                valid_vote = 1;
                for(int j = 0; j < num_candidates; j++){
                    printf("%d. %s\n",j+1,list_of_candidates[j].name);
                }
                int choice;
                printf("Choose your candidate (Enter the number): ");
                scanf("%d",&choice);
                if(choice > 0 && choice <= num_candidates){
                    list_of_candidates[choice-1].votes++;
                    printf("Thank you for voting!\n");
                    num_voters--;
                    for(int k = i; k < num_voters; k++){
                        strcpy(voter_list[k], voter_list[k+1]);
                    }
                    voter_list = realloc(voter_list, num_voters * sizeof(char*));
                    break;
                }
                else{
                    printf("Invalid choice!\n");
                    break;
                }
            }
        }
        if(!valid_vote){
            printf("Invalid voter!\n");
        }
    }
    printf("Voting has ended!\n");
    printf("Results:\n");
    for(int i = 0; i < num_candidates; i++){
        printf("%s: %d\n",list_of_candidates[i].name, list_of_candidates[i].votes);
    }
    free(list_of_candidates);
    for(int i = 0; i < num_voters; i++){
        free(voter_list[i]);
    }
    free(voter_list);
    return 0;
}