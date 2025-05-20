//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

typedef struct {
    int disk_num;
    int source;
    int target;
} move;

void print_towers(int disks, char towers[3][MAX_DISKS]);
void move_disk(int disks, char towers[3][MAX_DISKS], int source, int target);
void robot(int disks, char towers[3][MAX_DISKS]);

int main() {
    char towers[3][MAX_DISKS];
    int disks;

    printf("Welcome to the Tower of Hanoi problem solver!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    if (disks > MAX_DISKS) {
        printf("Error: too many disks!\n");
        return 1;
    }

    memset(towers, 0, sizeof(towers));
    for (int i = disks; i > 0; i--) {
        towers[0][disks - i] = 'D' + i;
    }

    printf("Initial configuration:\n");
    print_towers(disks, towers);

    printf("\nRobot is moving the disks now...\n");
    robot(disks, towers);

    printf("\nFinal configuration:\n");
    print_towers(disks, towers);

    return 0;
}

void print_towers(int disks, char towers[3][MAX_DISKS]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < disks; j++) {
            if (towers[i][j] != 0)
                printf("%c ", towers[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void move_disk(int disks, char towers[3][MAX_DISKS], int source, int target) {
    if (disks <= 0)
        return;

    int temp = towers[source][0];
    towers[source][0] = towers[target][disks - 1];
    towers[target][disks - 1] = temp;
}

void robot(int disks, char towers[3][MAX_DISKS]) {
    move moves[disks * 3];

    int index = 0;
    for (int i = disks; i > 0; i--) {
        moves[index++] = (move){i, 0, 2};
        moves[index++] = (move){i, 2, 1};
    }

    for (int i = 0; i < disks * 3; i++) {
        int source = moves[i].source;
        int target = moves[i].target;
        move_disk(disks, towers, source, target);
        usleep(100000); // add a short delay for the robot animation effect
    }
}