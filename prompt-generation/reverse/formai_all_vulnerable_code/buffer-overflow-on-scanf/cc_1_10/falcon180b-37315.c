//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
#define RED 1
#define GREEN 2
#define YELLOW 3

int light = GREEN;
int count = 0;
int road[MAX];

void init() {
    for(int i = 0; i < MAX; i++) {
        road[i] = 0;
    }
}

void carArrives(int pos) {
    if(pos >= 0 && pos < MAX) {
        road[pos] = 1;
        printf("Car arrives at position %d\n", pos);
        count++;
    }
}

void carLeaves(int pos) {
    if(pos >= 0 && pos < MAX) {
        road[pos] = 0;
        printf("Car leaves from position %d\n", pos);
        count--;
    }
}

void changeLight() {
    if(light == GREEN) {
        light = YELLOW;
        printf("Light turns yellow\n");
    }
    else if(light == YELLOW) {
        light = RED;
        printf("Light turns red\n");
    }
    else if(light == RED) {
        light = GREEN;
        printf("Light turns green\n");
    }
}

int main() {
    init();
    int choice, pos;
    while(1) {
        printf("1. Car arrives\n2. Car leaves\n3. Change light\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                carArrives(pos);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                carLeaves(pos);
                break;
            case 3:
                changeLight();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        if(light == GREEN && count > 0) {
            printf("Cars are waiting...\n");
        }
        else if(light == RED && count == 0) {
            printf("No cars, light turns green\n");
            light = GREEN;
        }
        sleep(1);
    }
    return 0;
}