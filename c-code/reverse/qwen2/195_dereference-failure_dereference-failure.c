#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 100

int main() {
    int votes[MAX_VOTERS];
    int num_voters = 0;
    int choice;

    printf("Welcome to the Electronic Voting System\n");

    while (num_voters < MAX_VOTERS) {
        printf("Enter your vote (1-5): ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        votes[num_voters++] = choice;
    }

    printf("\nThank you for using the Electronic Voting System!\n");

    return 0;
}
