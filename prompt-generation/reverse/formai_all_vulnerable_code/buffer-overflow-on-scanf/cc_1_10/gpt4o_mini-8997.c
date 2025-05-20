//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FORWARD 'W'
#define BACKWARD 'S'
#define LEFT 'A'
#define RIGHT 'D'
#define QUIT 'Q'

void display_instructions() {
    printf("===== Noble Paladin Robot Movement =====\n");
    printf("W - Move Forward\n");
    printf("S - Move Backward\n");
    printf("A - Turn Left\n");
    printf("D - Turn Right\n");
    printf("Q - Flee in Fear (Quit)\n");
    printf("========================================\n");
}

void move_robot(char direction) {
    switch (direction) {
        case FORWARD:
            printf("The noble paladin strides gallantly forth!\n");
            break;
        case BACKWARD:
            printf("The noble paladin retreats to a safe position!\n");
            break;
        case LEFT:
            printf("The noble paladin turns left, ready for an ambush!\n");
            break;
        case RIGHT:
            printf("The noble paladin pivots right, seeking new foes!\n");
            break;
        case QUIT:
            printf("The noble paladin flees the battlefield! A wise choice.\n");
            break;
        default:
            printf("Alas! The noble paladin does not comprehend such commands!\n");
    }
}

int main() {
    char command = ' ';
    
    display_instructions();
    
    while (command != QUIT) {
        printf("Enter your command: ");
        scanf(" %c", &command);
        
        if (command != QUIT) {
            move_robot(command);
        }
        
        sleep(1);  // Pause to simulate thinking
    }
    
    printf("The quest is over, the noble paladin rests until the next adventure!\n");
    
    return 0;
}