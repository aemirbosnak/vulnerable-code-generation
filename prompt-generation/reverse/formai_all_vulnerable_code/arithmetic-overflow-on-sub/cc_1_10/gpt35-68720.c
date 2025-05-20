//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function to set traffic lights to green
void setGreenLights(int road1, int road2, int road3, int road4) {
    printf("\nGreen Lights Activated: \n");
    printf("Road 1: %d\nRoad 2: %d\nRoad 3: %d\nRoad 4: %d\n", road1, road2, road3, road4);
}

// function to set traffic lights to yellow
void setYellowLights(int road1, int road2, int road3, int road4) {
    printf("\nYellow Lights Activated: \n");
    printf("Road 1: %d\nRoad 2: %d\nRoad 3: %d\nRoad 4: %d\n", road1, road2, road3, road4);
}

// function to set traffic lights to red
void setRedLights(int road1, int road2, int road3, int road4) {
    printf("\nRed Lights Activated: \n");
    printf("Road 1: %d\nRoad 2: %d\nRoad 3: %d\nRoad 4: %d\n", road1, road2, road3, road4);
}

// main function
int main() {
    // variable initialization
    int road1, road2, road3, road4, timer;
    
    printf("Enter initial traffic on Road 1: ");
    scanf("%d", &road1);
    printf("Enter initial traffic on Road 2: ");
    scanf("%d", &road2);
    printf("Enter initial traffic on Road 3: ");
    scanf("%d", &road3);
    printf("Enter initial traffic on Road 4: ");
    scanf("%d", &road4);
    
    while (1) {
        // check traffic conditions
        if (road1 > road2 && road1 > road3 && road1 > road4) {
            setGreenLights(road1, road2, road3, road4);
            timer = 10;
        } else if (road2 > road1 && road2 > road3 && road2 > road4) {
            setGreenLights(road2, road1, road3, road4);
            timer = 10;
        } else if (road3 > road1 && road3 > road2 && road3 > road4) {
            setGreenLights(road3, road1, road2, road4);
            timer = 10;
        } else if (road4 > road1 && road4 > road2 && road4 > road3) {
            setGreenLights(road4, road1, road2, road3);
            timer = 10;
        } else {
            setYellowLights(road1, road2, road3, road4);
            timer = 5;
        }
        
        // decrease traffic on roads
        road1 -= rand() % 10;
        road2 -= rand() % 10;
        road3 -= rand() % 10;
        road4 -= rand() % 10;
        
        // check if traffic is over
        if (road1 <= 0 && road2 <= 0 && road3 <= 0 && road4 <= 0) {
            printf("\nTraffic on all roads is over!\n");
            break;
        }
        
        // set red lights before changing traffic
        setRedLights(road1, road2, road3, road4);
        
        // wait for timer before checking traffic conditions again
        printf("\nWaiting %d seconds before checking traffic conditions again...\n", timer);
        for (int i = timer; i >= 1; i--) {
            printf("%d ", i);
            sleep(1);
        }
        printf("\n");
    }
    
    return 0;
}