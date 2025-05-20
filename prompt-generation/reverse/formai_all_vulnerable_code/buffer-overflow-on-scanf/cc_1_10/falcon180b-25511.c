//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct Candidate {
    char name[50];
    int votes;
};

void shuffle(char* arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i, j, k, choice, count = 0;
    char candidates[100][50];
    struct Candidate c[100];
    char vote[100];
    char valid_input = 0;
    srand(time(NULL));

    printf("Enter number of candidates (max 100): ");
    scanf("%d", &n);

    printf("\nEnter the names of the candidates:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", candidates[i]);
        strcpy(c[i].name, candidates[i]);
        c[i].votes = 0;
    }

    shuffle(candidates, n);

    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }

    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%s", vote);

        for (i = 0; i < n; i++) {
            if (strcmp(vote, candidates[i]) == 0) {
                c[i].votes++;
                valid_input = 1;
                break;
            }
        }

        if (valid_input == 0) {
            printf("Invalid choice. Please try again.\n");
        } else {
            valid_input = 0;
            count++;
        }

        if (count == n) {
            break;
        }
    }

    printf("\n\nResults:\n");
    for (i = 0; i < n; i++) {
        printf("%s: %d votes\n", c[i].name, c[i].votes);
    }

    return 0;
}