//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print game instructions
void print_instructions() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the Lost City of Gold.\n");
    printf("Use the arrow keys to move around and explore the world.\n");
    printf("Press 'q' to quit the game.\n");
}

//Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

//Function to print the game map
void print_map(int player_x, int player_y) {
    int i, j;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            if(i == player_x && j == player_y) {
                printf("@");
            } else if(i == 4 && j == 4) {
                printf("L");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//Function to move the player
void move_player(int *player_x, int *player_y, char direction) {
    switch(direction) {
        case 'w':
            (*player_y)--;
            break;
        case's':
            (*player_y)++;
            break;
        case 'a':
            (*player_x)--;
            break;
        case 'd':
            (*player_x)++;
            break;
        default:
            break;
    }
}

//Function to check if the player has reached the Lost City of Gold
int check_win(int player_x, int player_y) {
    if(player_x == 4 && player_y == 4) {
        printf("Congratulations! You have found the Lost City of Gold!\n");
        return 1;
    }
    return 0;
}

int main() {
    int player_x = 0, player_y = 0;
    int win = 0;
    srand(time(NULL));
    print_instructions();
    while(!win) {
        system("clear");
        print_map(player_x, player_y);
        char direction;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &direction);
        move_player(&player_x, &player_y, direction);
        if(check_win(player_x, player_y)) {
            win = 1;
        }
    }
    return 0;
}