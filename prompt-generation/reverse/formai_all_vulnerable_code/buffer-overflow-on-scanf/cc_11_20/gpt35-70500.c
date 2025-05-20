//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include<stdio.h> 
#include<string.h> 

struct candidate { 
    int id; 
    char name[50]; 
    int votes; 
}; 

int main() 
{ 
    int total_candidates, total_voters, i, j, candidate_id, voter_id; 
    int valid_voters_count = 0, vote = 0, invalid_votes = 0; 
    
    printf("========== Welcome to the Electronic Voting System ==========\n\n"); 

    printf("Enter total number of candidates: "); 
    scanf("%d", &total_candidates); 

    struct candidate candidates[total_candidates]; 

    for (i = 0; i < total_candidates; i++) { 
        candidates[i].id = i + 1; 

        printf("\nEnter candidate %d name: ", candidates[i].id); 
        scanf("%s", candidates[i].name); 

        candidates[i].votes = 0; 
    } 

    printf("\nEnter total number of voters: "); 
    scanf("%d", &total_voters); 

    for (i = 0; i < total_voters; i++) { 
        printf("\nEnter voter %d id: ", i + 1); 
        scanf("%d", &voter_id); 

        if (voter_id > 0 && voter_id <= total_voters) { 
            valid_voters_count++; 

            printf("\n----- Voting for candidate -----"); 
            for (j = 0; j < total_candidates; j++) { 
                printf("\n%d: %s", candidates[j].id, candidates[j].name); 
            } 

            printf("\nEnter candidate id to vote for: "); 
            scanf("%d", &candidate_id); 

            if (candidate_id > 0 && candidate_id <= total_candidates) { 
                candidates[candidate_id - 1].votes++; 
                vote++; 
            } else { 
                printf("\nInvalid Candidate selection!"); 
                invalid_votes++; 
            } 
        } else { 
            printf("\nInvalid Voter ID!"); 
        } 
    } 

    printf("\n\n========== Voting Summary ==========\n\n"); 
    printf("Total voters: %d\n", total_voters); 
    printf("Valid voters: %d\n", valid_voters_count); 
    printf("Invalid votes: %d\n\n", invalid_votes); 

    printf("========== Candidate Votes ==========\n\n"); 
    for (i = 0; i < total_candidates; i++) { 
        printf("%d. %s: %d\n", candidates[i].id, candidates[i].name, candidates[i].votes); 
    } 

    printf("\nWinner of the election: "); 

    int max_votes = 0, winner_id = 0; 

    for (i = 0; i < total_candidates; i++) { 
        if (max_votes < candidates[i].votes) { 
            max_votes = candidates[i].votes; 
            winner_id = i; 
        } 
    } 

    printf("%s\n", candidates[winner_id].name); 

    printf("\nTotal votes: %d\n", vote); 

    return 0; 
}