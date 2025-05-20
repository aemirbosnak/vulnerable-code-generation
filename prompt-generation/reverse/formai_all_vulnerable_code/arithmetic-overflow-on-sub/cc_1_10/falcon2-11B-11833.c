//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int height;
} Tower;

Tower* createTower(int num, int height) {
    Tower* tower = (Tower*) malloc(sizeof(Tower));
    tower->num = num;
    tower->height = height;
    return tower;
}

void destroyTower(Tower* tower) {
    free(tower);
}

void printTower(Tower* tower) {
    printf("Tower: %d, Height: %d\n", tower->num, tower->height);
}

void moveDisk(Tower* from, Tower* to, Tower* temp, int num) {
    Tower* top = from->num - 1;
    if (top < 0) {
        return;
    }
    Tower* bottom = from->num + num - 1;
    if (bottom >= from->height) {
        bottom = from->height - 1;
    }
    if (top == bottom) {
        Tower* disk = from->num - 2;
        while (disk > 0) {
            temp->num = disk;
            disk--;
            if (disk == top) {
                temp->num = bottom;
                break;
            }
            temp->num = disk;
        }
    } else {
        moveDisk(from, temp, from, top);
        moveDisk(from, temp, to, bottom);
        moveDisk(from, temp, from, top);
    }
}

void towerOfHanoi(Tower* tower, int num, Tower* source, Tower* destination) {
    if (num == 0) {
        return;
    }
    towerOfHanoi(tower, num - 1, source, destination);
    moveDisk(tower, destination, tower, num);
    towerOfHanoi(tower, num - 1, source, destination);
}

int main() {
    int num, source, destination;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    printf("Enter the source tower number: ");
    scanf("%d", &source);
    printf("Enter the destination tower number: ");
    scanf("%d", &destination);
    Tower* sourceTower = createTower(source, num);
    Tower* destinationTower = createTower(destination, num);
    Tower* tempTower = createTower(0, num);
    towerOfHanoi(sourceTower, num, sourceTower, destinationTower);
    printTower(sourceTower);
    printTower(destinationTower);
    destroyTower(sourceTower);
    destroyTower(destinationTower);
    destroyTower(tempTower);
    return 0;
}