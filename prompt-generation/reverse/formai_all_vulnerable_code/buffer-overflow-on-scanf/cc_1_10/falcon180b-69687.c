//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int age;
    int voter_id;
};

void generate_random_id(int id) {
    srand(time(0));
    id = rand() % 100000;
}

void print_candidates(struct candidate candidates[], int num_candidates) {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int num_voters = 0;
    struct voter voters[MAX_VOTERS];

    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter the age of voter %d: ", i + 1);
        scanf("%d", &voters[i].age);
        generate_random_id(voters[i].voter_id);
    }

    int choice;
    printf("\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, please enter your choice:\n", i + 1);
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }
        scanf("%d", &choice);
        candidates[choice - 1].votes++;
    }

    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}