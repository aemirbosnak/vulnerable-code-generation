//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

// structure for candidate
struct Candidate {
    char name[30];
    int votes;
};

// function to get vote
void vote(struct Candidate candidates[], int num_candidates, int candidate_id) {
    candidates[candidate_id].votes++;
    printf("You have successfully voted for %s!\n", candidates[candidate_id].name);
}

// function to display result
void display_result(struct Candidate candidates[], int num_candidates) {
    printf("Result\n");
    printf("========================================\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates, choice;
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    struct Candidate candidates[num_candidates];
    printf("Enter candidate names:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }

    bool voting = true;
    while(voting) {
        printf("====================================================\n");
        printf("Election Day! Please select your candidate from below:\n");
        for(int i=0; i<num_candidates; i++) {
            printf("%d. %s\n", i+1, candidates[i].name);
        }
        printf("%d. Display Result\n", num_candidates+1);
        printf("%d. Exit\n", num_candidates+2);
        printf("====================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == num_candidates+1) {
            display_result(candidates, num_candidates);
        } else if(choice == num_candidates+2) {
            printf("Thank you for voting!\n");
            voting = false;
        } else if(choice <= num_candidates) {
            vote(candidates, num_candidates, choice-1);
        } else {
            printf("Invalid choice! Please select from the given options.\n");
        }
    }
    return 0;
}