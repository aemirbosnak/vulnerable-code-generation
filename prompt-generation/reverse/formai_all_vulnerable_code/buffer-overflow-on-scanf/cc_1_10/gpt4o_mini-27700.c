//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void print_intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Do you dare to explore? Enter your choice to proceed...\n");
}

void print_map(char house[SIZE][SIZE], int player_x, int player_y) {
    printf("\nCurrent House Map:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player_x && j == player_y) {
                printf(" P "); // Player's position
            } else {
                printf(" %c ", house[i][j]);
            }
        }
        printf("\n");
    }
}

void encounter() {
    int event = rand() % 3;
    switch (event) {
        case 0:
            printf("You hear a ghostly whisper...\n");
            break;
        case 1:
            printf("A bat flies past you, screeching!\n");
            break;
        case 2:
            printf("You find an old, dusty book...\n");
            break;
        default:
            break;
    }
}

void move_player(int *player_x, int *player_y, char direction) {
    switch (direction) {
        case 'w': // Up
            if (*player_x > 0) (*player_x)--;
            break;
        case 's': // Down
            if (*player_x < SIZE - 1) (*player_x)++;
            break;
        case 'a': // Left
            if (*player_y > 0) (*player_y)--;
            break;
        case 'd': // Right
            if (*player_y < SIZE - 1) (*player_y)++;
            break;
        default:
            printf("Invalid move! Use 'w', 'a', 's', 'd'!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    char house[SIZE][SIZE] = {
        {'E', 'W', 'W', 'W', 'E'},
        {'W', 'W', 'W', 'W', 'W'},
        {'E', 'W', 'E', 'W', 'E'},
        {'W', 'W', 'W', 'W', 'W'},
        {'E', 'W', 'E', 'W', 'E'}
    };

    int player_x = 0, player_y = 0;
    char choice;
    
    print_intro();
    
    while (1) {
        print_map(house, player_x, player_y);
        printf("Move (w/a/s/d) or quit (q): ");
        scanf(" %c", &choice);
        
        if (choice == 'q') {
            printf("You have exited the haunted house! Brave adventurer!\n");
            break;
        }

        move_player(&player_x, &player_y, choice);
        encounter();
        
        if (house[player_x][player_y] == 'E') {
            printf("You found an exit! Congratulations on escaping the haunted house!\n");
            break;
        }
    }

    return 0;
}