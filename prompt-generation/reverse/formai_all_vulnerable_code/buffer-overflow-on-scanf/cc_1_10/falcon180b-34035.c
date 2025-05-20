//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOTE_SIZE 4

// function prototypes
void print_header(void);
void print_menu(void);
int get_vote(int *vote_count);
void print_results(int *vote_count);

int main() {
    int i;
    int vote_count[VOTE_SIZE];
    srand(time(0));

    // Initialize vote count to zero
    for (i = 0; i < VOTE_SIZE; i++) {
        vote_count[i] = 0;
    }

    // Main loop
    while (1) {
        print_header();
        print_menu();

        int choice = get_vote(vote_count);

        if (choice == 4) {
            break;
        }
    }

    print_results(vote_count);

    return 0;
}

// Print the header
void print_header() {
    printf("Electronic Voting System\n");
    printf("------------------------\n");
}

// Print the menu
void print_menu() {
    printf("1. Vote for Juliet\n");
    printf("2. Vote for Romeo\n");
    printf("3. View Results\n");
    printf("4. Exit\n");
}

// Get the vote and update the vote count
int get_vote(int *vote_count) {
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 2) {
        vote_count[choice - 1]++;
    } else if (choice == 3) {
        print_results(vote_count);
    } else if (choice == 4) {
        return 4;
    } else {
        printf("Invalid choice!\n");
    }

    return choice;
}

// Print the results
void print_results(int *vote_count) {
    printf("------------------------\n");
    printf("Results:\n");
    printf("Juliet: %d votes\n", vote_count[0]);
    printf("Romeo: %d votes\n", vote_count[1]);
    printf("------------------------\n");
}