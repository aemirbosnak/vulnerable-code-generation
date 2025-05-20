//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int age;
    int choice;
} voter;

typedef struct {
    char name[50];
    int votes;
} candidate;

void shuffle(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_candidates(candidate cands[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d. %s - %d votes\n", i + 1, cands[i].name, cands[i].votes);
    }
}

int main() {
    int i, j, n, m, choice;
    char ch;
    voter voters[MAX_VOTERS];
    candidate cands[MAX_CANDIDATES];

    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    printf("Enter the names of candidates:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", cands[i].name);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &m);

    printf("Enter the names and ages of voters:\n");
    for (i = 0; i < m; i++) {
        scanf("%s %d", voters[i].name, &voters[i].age);
    }

    printf("Enter the choices of voters:\n");
    for (i = 0; i < m; i++) {
        printf("%s's choice: ", voters[i].name);
        scanf("%d", &voters[i].choice);
    }

    srand(time(NULL));
    shuffle(cands, n);

    printf("\nElection results:\n");
    print_candidates(cands, n);

    return 0;
}