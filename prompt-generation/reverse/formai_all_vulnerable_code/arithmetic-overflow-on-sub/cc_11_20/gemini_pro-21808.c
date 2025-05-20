//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: medieval
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define NORTH_RED   0x01
#define NORTH_YELLOW 0x02
#define NORTH_GREEN  0x04

#define EAST_RED   0x08
#define EAST_YELLOW 0x10
#define EAST_GREEN  0x20

#define SOUTH_RED   0x40
#define SOUTH_YELLOW 0x80
#define SOUTH_GREEN  0x100

#define WEST_RED   0x200
#define WEST_YELLOW 0x400
#define WEST_GREEN  0x800

#define ALL_RED (NORTH_RED | EAST_RED | SOUTH_RED | WEST_RED)
#define ALL_GREEN (NORTH_GREEN | EAST_GREEN | SOUTH_GREEN | WEST_GREEN)
#define ALL_YELLOW (NORTH_YELLOW | EAST_YELLOW | SOUTH_YELLOW | WEST_YELLOW)

void delay(unsigned int ms) {
    clock_t start = clock();
    while (clock() - start < ms);
}

int main(void) {
    // Initialize the traffic lights
    unsigned int state = ALL_RED;

    // Main loop
    while (1) {
        // Display the traffic light state
        printf("\n");
        printf("    N    E    S    W\n");
        printf("---------------------\n");
        printf(" %c  %c  %c  %c \n", (state & NORTH_RED) ? 'R' : ' ', (state & EAST_RED) ? 'R' : ' ', (state & SOUTH_RED) ? 'R' : ' ', (state & WEST_RED) ? 'R' : ' ');
        printf(" %c  %c  %c  %c \n", (state & NORTH_YELLOW) ? 'Y' : ' ', (state & EAST_YELLOW) ? 'Y' : ' ', (state & SOUTH_YELLOW) ? 'Y' : ' ', (state & WEST_YELLOW) ? 'Y' : ' ');
        printf(" %c  %c  %c  %c \n", (state & NORTH_GREEN) ? 'G' : ' ', (state & EAST_GREEN) ? 'G' : ' ', (state & SOUTH_GREEN) ? 'G' : ' ', (state & WEST_GREEN) ? 'G' : ' ');

        // Update the traffic light state
        switch (state) {
            case ALL_RED:
                state = NORTH_GREEN | EAST_YELLOW | SOUTH_YELLOW | WEST_YELLOW;
                delay(5000);
                break;
            case NORTH_GREEN | EAST_YELLOW | SOUTH_YELLOW | WEST_YELLOW:
                state = NORTH_YELLOW | EAST_RED | SOUTH_RED | WEST_RED;
                delay(2000);
                break;
            case NORTH_YELLOW | EAST_RED | SOUTH_RED | WEST_RED:
                state = EAST_GREEN | NORTH_YELLOW | SOUTH_YELLOW | WEST_YELLOW;
                delay(5000);
                break;
            case EAST_GREEN | NORTH_YELLOW | SOUTH_YELLOW | WEST_YELLOW:
                state = EAST_YELLOW | NORTH_RED | SOUTH_RED | WEST_RED;
                delay(2000);
                break;
            case EAST_YELLOW | NORTH_RED | SOUTH_RED | WEST_RED:
                state = SOUTH_GREEN | EAST_YELLOW | NORTH_YELLOW | WEST_YELLOW;
                delay(5000);
                break;
            case SOUTH_GREEN | EAST_YELLOW | NORTH_YELLOW | WEST_YELLOW:
                state = SOUTH_YELLOW | EAST_RED | NORTH_RED | WEST_RED;
                delay(2000);
                break;
            case SOUTH_YELLOW | EAST_RED | NORTH_RED | WEST_RED:
                state = WEST_GREEN | EAST_YELLOW | SOUTH_YELLOW | NORTH_YELLOW;
                delay(5000);
                break;
            case WEST_GREEN | EAST_YELLOW | SOUTH_YELLOW | NORTH_YELLOW:
                state = WEST_YELLOW | EAST_RED | SOUTH_RED | NORTH_RED;
                delay(2000);
                break;
            default:
                state = ALL_RED;
                break;
        }
    }

    return 0;
}