#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void input_candidate(char name[10]) {
    printf("Enter candidate name: ");
    scanf("%s", name);
    getchar(); // Consume newline left by scanf
}

void display_results() {
    printf("\nResults:\n");
    printf("Candidate A: Votes\n");
    printf("Candidate B: Votes\n");
    printf("Candidate C: Votes\n");
}

int main() {
    char candidate[10];
    int votes[3] = {0, 0, 0};
    int choice;

    while (1) {
        display_results();
        input_candidate(candidate);

        if (strcmp(candidate, "Candidate A") == 0) {
            votes[0]++;
            break;
        } else if (strcmp(candidate, "Candidate B") == 0) {
            votes[1]++;
            break;
        } else if (strcmp(candidate, "Candidate C") == 0) {
            votes[2]++;
            break;
        } else {
            printf("Invalid candidate.\n");
        }
    }

    printf("Thank you for voting!\n");
    return 0;
}
