//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOVERS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Lover;

void display_lovers(Lover lovers[], int count) {
    printf("\nCast your vote for your favorite lover:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, lovers[i].name);
    }
}

void cast_vote(Lover lovers[], int count) {
    int choice;
    printf("Enter the number of your chosen lover (1-%d): ", count);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > count) {
        printf("Invalid choice. Love is not meant to be forced!\n");
    } else {
        lovers[choice - 1].votes++;
        printf("Your love has been recorded for %s! Heartfelt thanks!\n", lovers[choice - 1].name);
    }
}

void display_results(Lover lovers[], int count) {
    printf("\nThe results are in! Let the love be known!\n");
    for (int i = 0; i < count; i++) {
        printf("%s received %d votes\n", lovers[i].name, lovers[i].votes);
    }
    
    int max_votes = -1;
    char winner[MAX_NAME_LENGTH];

    for (int i = 0; i < count; i++) {
        if (lovers[i].votes > max_votes) {
            max_votes = lovers[i].votes;
            strcpy(winner, lovers[i].name);
        }
    }

    printf("\nAnd the most loved one is: %s with %d votes! True love prevails!\n", winner, max_votes);
}

int main() {
    Lover lovers[MAX_LOVERS] = {
        {"Juliet", 0},
        {"Romeo", 0},
        {"Scarlett", 0},
        {"Heathcliff", 0},
        {"Elizabeth", 0},
        {"Darcy", 0},
        {"Catherine", 0},
        {"Gatsby", 0},
        {"Daisy", 0},
        {"Pride", 0}
    };

    int lover_count = 10;
    char continue_voting = 'y';

    printf("Welcome to the Electronic Voting System of Love!\n");
    
    while (continue_voting == 'y' || continue_voting == 'Y') {
        display_lovers(lovers, lover_count);
        cast_vote(lovers, lover_count);
        printf("Would you like to vote again? (y/n): ");
        scanf(" %c", &continue_voting);
    }
    
    display_results(lovers, lover_count);
    
    printf("Thank you for participating in this romantic affair!\n");
    return 0;
}