//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 100
#define MAX_OPTIONS 5

// Function to check if an array slot is empty
bool is_empty(int *array, int index) {
    return array[index] == 0;
}

// Function to validate a voter ID
bool validate_id(char *id) {
    int len = strlen(id);
    return len >= 10 && len <= 12 && (isdigit(id[0]) || (id[0] == 'V' && isdigit(id[1])));
}

// Function to get a valid voter ID from the user
void get_id(char *id) {
    char input[20];
    int attempt = 0;
    bool valid = false;

    while (!valid) {
        printf("Enter your voter ID: ");
        scanf("%s", input);
        valid = validate_id(input);
        if (!valid) {
            printf("Invalid ID. Please try again.\n");
            attempt++;
            if (attempt >= 3) {
                printf("Too many invalid attempts. Exiting...\n");
                exit(1);
            }
        }
        strcpy(id, input);
    }
}

// Function to get a valid option number from the user
void get_option(int *option) {
    int choice;
    bool valid = false;

    while (!valid) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        valid = (choice >= 1 && choice <= 5);
        if (!valid) {
            printf("Invalid choice. Please try again.\n");
        }
        *option = choice;
    }
}

// Function to cast a vote
void cast_vote(int *votes, int voter_id, int option) {
    int index = voter_id % MAX_VOTERS;
    if (is_empty(votes, index)) {
        votes[index] = option;
        printf("Your vote has been recorded.\n");
    } else {
        printf("Error: You have already voted.\n");
    }
}

int main() {
    int votes[MAX_VOTERS];
    char id[20];
    int option;

    memset(votes, 0, sizeof(votes));

    while (true) {
        get_id(id);
        cast_vote(votes, atoi(id), 0); // Option number can be changed here

        printf("Do you want to exit? (y/n): ");
        char exit_choice;
        scanf(" %c", &exit_choice);
        if (exit_choice == 'y') {
            break;
        }
    }

    printf("\nVoting results:\n");
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (!is_empty(votes, i)) {
            printf("Voter %d voted for option %d.\n", i + 1, votes[i]);
        }
    }

    return 0;
}