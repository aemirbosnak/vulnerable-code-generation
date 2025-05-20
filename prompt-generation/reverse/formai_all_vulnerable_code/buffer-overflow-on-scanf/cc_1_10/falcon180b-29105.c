//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int candidate_id;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

void read_candidates() {
    int i = 0;
    FILE *fp;
    fp = fopen("candidates.txt", "r");
    if (fp == NULL) {
        printf("Error opening candidates file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s %d", candidates[i].name, &candidates[i].votes)!= EOF) {
        i++;
    }
    fclose(fp);
}

void read_voters() {
    int i = 0;
    FILE *fp;
    fp = fopen("voters.txt", "r");
    if (fp == NULL) {
        printf("Error opening voters file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s %d", voters[i].name, &voters[i].candidate_id)!= EOF) {
        i++;
    }
    fclose(fp);
}

void count_votes() {
    int i, j;
    for (i = 0; i < MAX_VOTERS; i++) {
        for (j = 0; j < MAX_CANDIDATES; j++) {
            if (strcmp(candidates[j].name, voters[i].name) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }
}

void print_results() {
    int i;
    printf("\nResults:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i;
    char input[100];
    printf("Enter the number of candidates (max 10): ");
    scanf("%d", &i);
    if (i > MAX_CANDIDATES) {
        printf("Error: number of candidates exceeds limit.\n");
        exit(1);
    }
    printf("Enter the candidates:\n");
    read_candidates();
    printf("Enter the number of voters (max 100): ");
    scanf("%d", &i);
    if (i > MAX_VOTERS) {
        printf("Error: number of voters exceeds limit.\n");
        exit(1);
    }
    printf("Enter the voters:\n");
    read_voters();
    count_votes();
    print_results();
    return 0;
}