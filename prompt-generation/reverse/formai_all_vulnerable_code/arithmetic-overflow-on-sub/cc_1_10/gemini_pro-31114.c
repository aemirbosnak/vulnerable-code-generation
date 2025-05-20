//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct candidate{
    char name[50];
    int vote;
};

int main()
{
    int num_candidates, i, j, choice;
    struct candidate *candidates;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidates = malloc(num_candidates * sizeof(struct candidate));

    for(i = 0; i < num_candidates; i++){
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].vote = 0;
    }

    while(1){
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);

        if(choice == 0){
            break;
        }else if(choice > num_candidates){
            printf("Invalid choice. Please try again.\n");
        }else{
            candidates[choice - 1].vote++;
        }
    }

    for(i = 0; i < num_candidates; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote);
    }

    int max_votes = 0;
    int winner_index = -1;

    for(i = 0; i < num_candidates; i++){
        if(candidates[i].vote > max_votes){
            max_votes = candidates[i].vote;
            winner_index = i;
        }
    }

    printf("The winner is %s with %d votes.\n", candidates[winner_index].name, max_votes);

    free(candidates);

    return 0;
}