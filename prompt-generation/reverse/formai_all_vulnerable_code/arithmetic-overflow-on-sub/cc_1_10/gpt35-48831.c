//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h> //for rand() and srand()
#include <time.h> //for time()

//function to clear the screen
void clear_screen() {
    printf("\033[H\033[J");
}

//function to pause for a specified number of milliseconds
void delay(int milliseconds) {
    long pause;
    clock_t now, then;
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause) {
        now = clock();
    }
}

//function to draw the game board
void draw_board(int player_pos, int dragon_pos) {
    clear_screen();
    printf("+-------------------------------------------------------+\n");
    for (int i = 0; i < 10; i++) {
        printf("|                                                       |\n");
    }
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                         +---+                           |\n");
    printf("|                         | P |                           |\n");
    printf("|                         +---+                           |\n");
    for (int i = 0; i < 5; i++) {
        printf("|                                                       |\n");
    }
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                         +---+                           |\n");
    printf("|                         | D |                           |\n");
    printf("|                         +---+                           |\n");
    printf("|                                                       |\n");
    for (int i = 0; i < 10; i++) {
        printf("|                                                       |\n");
    }
    printf("+-------------------------------------------------------+\n");
}

//function to move the player
void move_player(int* player_pos) {
    char key_pressed;
    scanf("%c", &key_pressed);
    if (key_pressed == 'w' && *player_pos > 13) {
        *player_pos -= 14;
    } else if (key_pressed == 'a' && *player_pos % 14 != 0) {
        (*player_pos)--;
    } else if (key_pressed == 's' && *player_pos < 133) {
        *player_pos += 14;
    } else if (key_pressed == 'd' && (*player_pos + 1) % 14 != 0) {
        (*player_pos)++;
    }
}

//function to move the dragon
void move_dragon(int* dragon_pos) {
    int random_move = rand() % 4;
    if (random_move == 0 && *dragon_pos > 13) {
        *dragon_pos -= 14;
    } else if (random_move == 1 && *dragon_pos % 14 != 0) {
        (*dragon_pos)--;
    } else if (random_move == 2 && *dragon_pos < 133) {
        *dragon_pos += 14;
    } else if (random_move == 3 && (*dragon_pos + 1) % 14 != 0) {
        (*dragon_pos)++;
    }
}

//function to check for collisions
int check_collision(int player_pos, int dragon_pos) {
    if (player_pos == dragon_pos) {
        return 1;
    } else {
        return 0;
    }
}

//main function
int main() {
    srand(time(NULL)); //seed rand with current time
    int player_pos = 84; //starting position for player
    int dragon_pos = 19; //starting position for dragon
    int score = 0;
    
    while(1) { //infinite loop
        draw_board(player_pos, dragon_pos);
        printf("Score: %d\n", score);
        move_player(&player_pos);
        move_dragon(&dragon_pos);
        if (check_collision(player_pos, dragon_pos)) {
            printf("Game over!\n");
            delay(2000);
            break;
        } else {
            score++;
        }
    }
    
    return 0;
}