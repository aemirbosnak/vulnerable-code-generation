//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int trafficLight[3] = {0, 0, 0};
    int direction = 0;
    int red = 1, yellow = 2, green = 3;

    while (1) {
        printf("Enter direction: ");
        scanf("%d", &direction);

        switch (direction) {
            case 1:
                if (trafficLight[red]) {
                    trafficLight[red] = 0;
                    trafficLight[yellow] = 1;
                    trafficLight[green] = 0;
                } else {
                    trafficLight[green] = 1;
                    trafficLight[red] = 0;
                    trafficLight[yellow] = 0;
                }
                break;
            case 2:
                if (trafficLight[yellow]) {
                    trafficLight[yellow] = 0;
                    trafficLight[red] = 1;
                    trafficLight[green] = 0;
                } else {
                    trafficLight[green] = 1;
                    trafficLight[yellow] = 0;
                    trafficLight[red] = 0;
                }
                break;
            case 3:
                if (trafficLight[green]) {
                    trafficLight[green] = 0;
                    trafficLight[yellow] = 1;
                    trafficLight[red] = 0;
                } else {
                    trafficLight[red] = 1;
                    trafficLight[green] = 0;
                    trafficLight[yellow] = 0;
                }
                break;
            default:
                printf("Invalid direction!\n");
        }

        printf("Traffic light: %d %d %d\n", trafficLight[red], trafficLight[yellow], trafficLight[green]);
    }

    return 0;
}