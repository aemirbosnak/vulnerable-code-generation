//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 

void clear_screen() {
    printf("\033[2J\033[1;1H");
}

void print_title() {
    printf("*************\n");
    printf(" ADVENTURE!! \n");
    printf("*************\n\n");
}

void print_directions() {
    printf("Move Commands: N, S, E, W\n");
    printf("Press Q at any time to quit.\n");
}

void print_location(int x, int y) {
    printf("\nYou are at location (%d,%d)\n\n", x, y);
}

void print_encounter() {
    int encounter = rand() % 3;
    if (encounter == 0) {
        printf("You encountered a monster! Prepare for battle.\n");
    } else if (encounter == 1) {
        printf("You found a treasure chest! Open it?\n");
    } else if (encounter == 2) {
        printf("You stumbled upon an old map.. should you follow it?\n");
    }
}

int main() {
    srand(time(NULL));
    clear_screen();
    print_title();
    print_directions();

    int x = 0;
    int y = 0;

    while (1) {
        print_location(x,y);
        print_encounter();
        char input;
        printf(">> ");
        scanf(" %c", &input);

        if (input == 'Q' || input == 'q') {
            printf("\nGoodbye!\n");
            break;
        } else if (input == 'N' || input == 'n') {
            y += 1;
        } else if (input == 'S' || input == 's') {
            y -= 1;
        } else if (input == 'E' || input == 'e') {
            x += 1;
        } else if (input == 'W' || input == 'w') {
            x -= 1;
        } else {
            printf("Invalid Input\n");
            delay(2);
            continue;
        }
    }
    return 0;
}