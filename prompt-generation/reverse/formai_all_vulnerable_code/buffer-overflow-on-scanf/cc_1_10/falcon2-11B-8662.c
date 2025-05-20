//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* name;
    int id;
    char* gender;
    char* party;
} Candidate;

void print_candidates(Candidate candidates[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Candidate %d: %s (%s)\n", i+1, candidates[i].name, candidates[i].gender);
    }
}

void register_candidate(Candidate candidates[], int n) {
    printf("Enter candidate name: ");
    fflush(stdin);
    fgets(candidates[n].name, sizeof(candidates[n].name), stdin);
    candidates[n].name[strcspn(candidates[n].name, "\n")] = '\0';

    printf("Enter candidate ID: ");
    scanf("%d", &candidates[n].id);

    printf("Enter candidate gender (M/F): ");
    fflush(stdin);
    fgets(candidates[n].gender, sizeof(candidates[n].gender), stdin);
    candidates[n].gender[strcspn(candidates[n].gender, "\n")] = '\0';

    printf("Enter candidate party (M/F): ");
    fflush(stdin);
    fgets(candidates[n].party, sizeof(candidates[n].party), stdin);
    candidates[n].party[strcspn(candidates[n].party, "\n")] = '\0';

    candidates[n].gender[strlen(candidates[n].gender)] = '\0';
    candidates[n].party[strlen(candidates[n].party)] = '\0';

    n++;
}

int main() {
    srand(time(NULL));

    Candidate candidates[10];
    int n = 0;

    while (n < 10) {
        register_candidate(candidates, n);
        n++;
    }

    print_candidates(candidates, n);

    return 0;
}