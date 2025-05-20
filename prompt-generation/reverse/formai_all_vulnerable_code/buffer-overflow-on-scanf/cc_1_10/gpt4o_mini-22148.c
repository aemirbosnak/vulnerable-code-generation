//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CLUES 5
#define MAX_NEIGHBORS 5

typedef struct {
    char clue[50];
    int collected;
} Clue;

typedef struct {
    char name[20];
    int alertness; // 0 = not alert, 1 = alert
} Neighbor;

Clue clues[MAX_CLUES] = {
    {"Found a secret note!", 0},
    {"Spotted suspicious activity!", 0},
    {"Heard odd noises at night!", 0},
    {"Saw a mysterious figure!", 0},
    {"Received a strange message!", 0}
};

Neighbor neighbors[MAX_NEIGHBORS] = {
    {"Mr. Johnson", 0},
    {"Ms. Smith", 0},
    {"Old Man Jenkins", 0},
    {"The Parkers", 0},
    {"Mrs. Wilson", 0}
};

int score = 0;
int game_over = 0;

void print_instructions() {
    printf("Welcome to Vigilant Shadows!\n");
    printf("You are trying to gather clues about a conspiracy.\n");
    printf("Each choice you make could alert your neighbors.\n");
    printf("Collect all the clues without getting caught!\n");
    printf("Good luck!\n\n");
}

void print_clues() {
    printf("Clues collected:\n");
    for (int i = 0; i < MAX_CLUES; i++) {
        if (clues[i].collected) {
            printf(" - %s\n", clues[i].clue);
        }
    }
    printf("\n");
}

void check_neighbors() {
    for (int i = 0; i < MAX_NEIGHBORS; i++) {
        if (neighbors[i].alertness) {
            printf("Watch out! %s is alert!\n", neighbors[i].name);
        }
    }
}

void random_event() {
    int rand_num = rand() % MAX_NEIGHBORS;
    neighbors[rand_num].alertness = 1;
    printf("%s has noticed you!\n", neighbors[rand_num].name);
}

void collect_clue(int clue_index) {
    if (clues[clue_index].collected == 0) {
        clues[clue_index].collected = 1;
        score++;
        printf("Clue collected: %s\n", clues[clue_index].clue);
    } else {
        printf("You already have this clue!\n");
    }
}

void play_game() {
    print_instructions();
    
    srand(time(NULL));
    while (!game_over) {
        printf("You can choose to (C)ollect a clue or (E)scape. (Type 'Q' to quit)\n");
        char choice;
        scanf(" %c", &choice);
        choice = tolower(choice);
        
        if (choice == 'c') {
            int clue_index = rand() % MAX_CLUES;
            collect_clue(clue_index);
            random_event();
        } else if (choice == 'e') {
            printf("You decided to escape for now.\n");
            game_over = 1; // End game but not from alert
        } else if (choice == 'q') {
            printf("Quitting the game.\n");
            game_over = 1;
        } else {
            printf("Invalid option. Please choose again.\n");
        }
        
        check_neighbors();
        print_clues();
        
        if (score == MAX_CLUES) {
            printf("Congratulations! You've collected all the clues!\n");
            game_over = 1;
        }
    }
}

int main() {
    play_game();
    printf("Game over! Your final score: %d\n", score);
    return 0;
}