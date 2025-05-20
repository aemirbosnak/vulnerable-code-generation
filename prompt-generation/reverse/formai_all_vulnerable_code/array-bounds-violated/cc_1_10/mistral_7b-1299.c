//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VOTERS 100
#define MAX_OPTIONS 5
#define SHAPE_SHIFT 5

typedef struct {
    char name[50];
    int vote[MAX_OPTIONS];
} Voter;

typedef struct {
    char label[10];
    int value;
} Option;

Option options[MAX_OPTIONS] = {{"Option 1", 1}, {"Option 2", 2}, {"Option 3", 3}, {"Option 4", 4}, {"Option 5", 5}};
Voter voters[MAX_VOTERS];
int num_voters = 0;

void print_menu() {
    int i;
    printf("\n------------------------------\n");
    printf("| Electronic Voting System    |\n");
    printf("|------------------------------|\n");
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("| %s. %s          |", i+1, options[i].label);
    }
    printf("\n|------------------------------|\n");
    printf("| Enter your choice and vote:  |");
}

void vote(int voter_num) {
    int choice, i;
    printf("\nVoter %d, please enter your choice: ", voter_num+1);
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_OPTIONS) {
        printf("\nInvalid choice. Please try again.\n");
        vote(voter_num);
        return;
    }
    voters[voter_num].vote[choice-1]++;
    printf("\nThank you for voting.\n");
}

void shift_shape() {
    int i, j;
    for (i = 0; i < MAX_OPTIONS; i++) {
        for (j = 0; j < voters[i].vote[i]; j++) {
            printf("%c", isupper(options[i].label[0]) ? tolower(options[i].label[0]) : toupper(options[i].label[0]));
        }
        printf(" %d\n", voters[i].vote[i]);
        for (j = 0; j < MAX_OPTIONS-i-1; j++) {
            printf("  ");
        }
        printf("%s\n", options[i].label);
    }
    printf("\n------------------------------\n");
}

int main() {
    int voter_num;
    char c;

    while (1) {
        print_menu();
        scanf(" %c", &c);
        if (isdigit(c)) {
            voter_num = c - '1';
            if (num_voters >= MAX_VOTERS) {
                printf("\nMaximum number of voters reached. Please wait for others to finish voting.\n");
            } else {
                voters[num_voters].vote[voter_num-1] = 0;
                vote(num_voters);
                num_voters++;
            }
        } else if (c == 'S') {
            shift_shape();
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}