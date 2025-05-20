//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char candidate[50];
    int vote_count;
} candidate_t;

typedef struct {
    char name[50];
    bool voted;
    int candidate_choice;
} voter_t;

int num_candidates;
candidate_t candidates[MAX_CANDIDATES];
int num_voters;
voter_t voters[MAX_VOTERS];

void add_candidate() {
    char name[50];
    printf("Enter candidate name: ");
    scanf("%s", name);
    strcpy(candidates[num_candidates].candidate, name);
    candidates[num_candidates].vote_count = 0;
    num_candidates++;
}

void list_candidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, candidates[i].candidate, candidates[i].vote_count);
    }
}

int get_choice(char* prompt, int min_value, int max_value) {
    int choice;
    do {
        printf("%s", prompt);
        scanf("%d", &choice);
    } while (choice < min_value || choice > max_value);
    return choice;
}

void vote() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            if (voters[i].voted) {
                printf("You have already voted.\n");
                return;
            }
            voters[i].voted = true;
            int choice = get_choice("Select candidate (by number): ", 1, num_candidates);
            voters[i].candidate_choice = choice - 1;
            candidates[choice-1].vote_count++;
            printf("You have successfully voted for %s.\n", candidates[choice-1].candidate);
            return;
        }
    }
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted = true;
    int choice = get_choice("Select candidate (by number): ", 1, num_candidates);
    voters[num_voters].candidate_choice = choice - 1;
    candidates[choice-1].vote_count++;
    printf("You have successfully voted for %s.\n", candidates[choice-1].candidate);
    num_voters++;
}

void show_results() {
    list_candidates();
    if (num_voters == 0) {
        printf("No votes have been cast yet.\n");
        return;
    }
    printf("Voting Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes (%.1f%%)\n", candidates[i].candidate, candidates[i].vote_count, 100.0*candidates[i].vote_count/num_voters);
    }
}

int main() {
    num_candidates = 0;
    num_voters = 0;
    while (true) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. List Candidates\n");
        printf("3. Vote\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        int choice = get_choice("Enter choice (by number): ", 1, 5);
        printf("\n");
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                list_candidates();
                break;
            case 3:
                vote();
                break;
            case 4:
                show_results();
                break;
            case 5:
                return 0;
        }
    }
}