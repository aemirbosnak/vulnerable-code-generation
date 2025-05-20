//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate {
    char name[30];
    int votes;
};

int main() {
    int num_candidates, num_voters, choice, i, j, k, l;
    int *voter_id, **vote_list, *vote_flag;
    struct candidate *candidates;
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("How many candidates are there in the election? ");
    scanf("%d", &num_candidates);
    
    candidates = (struct candidate*) malloc(num_candidates * sizeof(struct candidate));
    
    for (i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    printf("\n");
    printf("How many voters are there in the election? ");
    scanf("%d", &num_voters);
    
    voter_id = (int*) malloc(num_voters * sizeof(int));
    vote_flag = (int*) malloc(num_voters * sizeof(int));
    vote_list = (int**) malloc(num_voters * sizeof(int*));
    
    for (i = 0; i < num_voters; i++) {
        vote_list[i] = (int*) malloc(num_candidates * sizeof(int));
        vote_flag[i] = 0;
    }
    
    printf("\n");
    printf("Registering voters...\n");
    
    for (i = 0; i < num_voters; i++) {
        printf("Enter ID of voter %d: ", i+1);
        scanf("%d", &voter_id[i]);
    }
    
    printf("\n");
    printf("Voting process begins...\n");
    
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d, please make a choice:\n", voter_id[i]);
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (vote_flag[i] == 1) {
            printf("You have already voted. Your vote will not be counted.\n");
            continue;
        }
        
        if (choice < 1 || choice > num_candidates) {
            printf("Invalid choice. Please enter a valid choice.\n");
            continue;
        }
        
        vote_list[i][choice-1] = 1;
        vote_flag[i] = 1;
        
        for (k = 0; k < num_voters; k++) {
            int count = 0;
            for (l = 0; l < num_candidates; l++) {
                if (vote_list[k][l] == 1) {
                    count++;
                }
            }
            if (count > 1) {
                printf("Sorry, you can only vote for one candidate.\n");
                vote_list[k][choice-1] = 0;
                vote_flag[k] = 0;
            }
        }
    }
    
    printf("\n\n");
    printf("Vote counting begins...\n\n");
    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < num_candidates; j++) {
            if (vote_list[i][j] == 1) {
                candidates[j].votes++;
            }
        }
    }
    
    printf("Results are as follows:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    return 0;
}