//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_TIME 10
#define YELLOW_TIME 3
#define RED_TIME 15

void traffic_light(int num) {
    switch(num) {
        case 1:
            printf("Green light is on\n");
            break;
        case 2:
            printf("Yellow light is on\n");
            break;
        case 3:
            printf("Red light is on\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

int main() {
    int num = 1;
    int count = 0;
    int total_time = GREEN_TIME + YELLOW_TIME + RED_TIME;

    while(1) {
        traffic_light(num);
        printf("Press enter to switch lights\n");
        scanf("%d", &num);

        if(num == 1) {
            count = 0;
        } else if(num == 2) {
            count = GREEN_TIME;
        } else {
            count = 0;
        }

        while(count < total_time) {
            printf("Light is on\n");
            count++;
            sleep(1);
        }
    }

    return 0;
}