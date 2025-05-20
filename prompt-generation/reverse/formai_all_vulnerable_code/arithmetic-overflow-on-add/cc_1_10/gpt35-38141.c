//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds) { //function to create a delay for dramatic effect
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void print_character(char c, int number_of_times) { //function to print a character multiple times
    for (int i = 0; i < number_of_times; i++) {
        printf("%c", c);
        delay(50);
    }
}

int main() {
    srand(time(0)); //initialize the random seed
    
    printf("\n\n\n\t\t*******************************************\n");
    printf("\t\t**                                       **\n");
    printf("\t\t**        WELCOME TO RETRO CODE!          **\n");
    printf("\t\t**                                       **\n");
    printf("\t\t*******************************************\n\n\n");

    delay(2000);
    
    printf("In this program, we will create a retro animation of a bouncing ball.\n");
    delay(2000);
    printf("Get ready to travel back in time to the golden era of computing!\n");
    delay(2000);

    printf("\n\n\n\t\t*******************************************\n");
    printf("\t\t**                                       **\n");
    printf("\t\t**                READY?                 **\n");
    printf("\t\t**                                       **\n");
    printf("\t\t*******************************************\n\n\n");

    delay(1000);

    int x = 0, y = 0; //initialize the ball position at (0,0)
    int dx = 1, dy = 1; //set the ball speed to 1 in both x and y directions

    while (1) { //infinite loop that animates the ball
        system("clear");

        //print the top border
        print_character('#', 30);
        printf("\n");

        //print the left border and the ball position
        printf("#");
        print_character(' ', x);
        printf("*");
        print_character(' ', 28 - x);
        printf("#\n");

        //print the middle border
        printf("#");
        print_character(' ', 29);
        printf("#\n");

        //print the right border and the ball position
        printf("#");
        print_character(' ', x);
        printf("*");
        print_character(' ', 28 - x);
        printf("#\n");

        //print the bottom border
        print_character('#', 30);
        printf("\n");

        delay(50); //create a delay for smooth animation

        x += dx; //update the ball position
        y += dy;

        //reverse the direction of the ball if it hits a border
        if (x == 28 || x == 0) {
            dx = -dx;
        }
        if (y == 4 || y == 0) {
            dy = -dy;
        }
    }

    return 0;
}