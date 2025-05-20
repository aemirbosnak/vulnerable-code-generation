//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100

#define CAR_X 10
#define CAR_Y 10

#define DEST_X 50
#define DEST_Y 50

#define SPEED 5

// Function to calculate distance between two points
int distance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    return dx * dx + dy * dy;
}

int main()
{
    int current_x = CAR_X;
    int current_y = CAR_Y;
    int target_x = DEST_X;
    int target_y = DEST_Y;

    time_t start_time = time(NULL);

    while (distance(current_x, current_y, target_x, target_y) > SPEED)
    {
        int direction = rand() % 4;

        switch (direction)
        {
            case 0:
                current_x++;
                break;
            case 1:
                current_y++;
                break;
            case 2:
                current_x--;
                break;
            case 3:
                current_y--;
                break;
        }

        time_t end_time = time(NULL);
        int time_taken = end_time - start_time;
        printf("Time taken: %d seconds\n", time_taken);
    }

    printf("Reached destination!\n");

    return 0;
}