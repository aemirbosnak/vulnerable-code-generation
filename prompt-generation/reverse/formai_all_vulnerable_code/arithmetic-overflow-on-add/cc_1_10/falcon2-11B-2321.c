//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void delay(int milliseconds) {
    clock_t start, end;
    start = clock();
    while (clock() < start + milliseconds) {
        ; // do nothing
    }
}

int main() {
    srand(time(0));
    
    int color1 = rand() % 3;
    int color2 = rand() % 3;
    int color3 = rand() % 3;
    
    int green_duration = rand() % (10 + 1);
    int yellow_duration = rand() % (5 + 1);
    int red_duration = rand() % (5 + 1);
    
    printf("Color 1: %d\n", color1);
    printf("Color 2: %d\n", color2);
    printf("Color 3: %d\n", color3);
    printf("Green Duration: %d\n", green_duration);
    printf("Yellow Duration: %d\n", yellow_duration);
    printf("Red Duration: %d\n", red_duration);
    
    while (1) {
        switch (color1) {
            case 0:
                printf("Green\n");
                delay(green_duration);
                break;
            case 1:
                printf("Yellow\n");
                delay(yellow_duration);
                break;
            case 2:
                printf("Red\n");
                delay(red_duration);
                break;
        }
        
        switch (color2) {
            case 0:
                printf("Green\n");
                delay(green_duration);
                break;
            case 1:
                printf("Yellow\n");
                delay(yellow_duration);
                break;
            case 2:
                printf("Red\n");
                delay(red_duration);
                break;
        }
        
        switch (color3) {
            case 0:
                printf("Green\n");
                delay(green_duration);
                break;
            case 1:
                printf("Yellow\n");
                delay(yellow_duration);
                break;
            case 2:
                printf("Red\n");
                delay(red_duration);
                break;
        }
    }
    
    return 0;
}