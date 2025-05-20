//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 5
#define RED '0'
#define GREEN '1'

char trafficLight[N][M] = {{RED}, {RED}, {RED}, {RED}, {RED}, {RED}, {RED}, {RED}, {RED}, {RED}};
int currentLight = 0;
int currentRow = 0;
int currentCol = 0;

void drawTrafficLight(int row, int col) {
    printf("\033[0;31m");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("  ");
        }
        printf("|%c|\n", trafficLight[currentLight][currentRow * 3 + i]);
    }
    printf("\033[0m");
}

void changeLight() {
    currentLight++;
    if (currentLight == N) {
        currentLight = 0;
    }
}

void moveCar() {
    if (currentRow == 9) {
        printf("\nCar reached destination.\n");
        exit(0);
    } else if (trafficLight[currentLight][currentRow * 3 + currentCol] == RED) {
        printf("\nCar stopped at red light.\n");
    } else if (trafficLight[currentLight][currentRow * 3 + currentCol] == GREEN) {
        currentRow++;
        currentCol = (currentCol + 1) % 3;
        drawTrafficLight(currentRow, currentCol);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            trafficLight[i][j] = (char) (rand() % 2 + '0');
        }
    }

    printf("\nTraffic Flow Simulation\n");
    drawTrafficLight(currentRow, currentCol);

    while (1) {
        moveCar();
        changeLight();
        usleep(100000); // Change this value to control the speed of the simulation
    }

    return 0;
}