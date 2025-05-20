//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red = 0, green = 0, yellow = 0;
    int i = 0, seconds, state = 0;

    printf("Enter the duration of each state in seconds:\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Yellow: ");
    scanf("%d", &yellow);
    printf("Green: ");
    scanf("%d", &green);

    while (1) {
        switch (state) {
            case 0: // red
                printf("RED light is ON\n");
                for (i = red; i > 0; i--) {
                    printf("Time left: %d seconds\n", i);
                    sleep(1);
                }
                state = 1;
                break;

            case 1: // yellow
                printf("YELLOW light is ON\n");
                for (i = yellow; i > 0; i--) {
                    printf("Time left: %d seconds\n", i);
                    sleep(1);
                }
                state = 2;
                break;

            case 2: // green
                printf("GREEN light is ON\n");
                for (i = green; i > 0; i--) {
                    printf("Time left: %d seconds\n", i);
                    sleep(1);
                }
                state = 0;
                break;
        }
    }

    return 0;
}