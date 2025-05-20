//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, l, n, m, c, v;
    int count_car = 0;
    srand(time(NULL));

    printf("Enter the number of lanes in the road: ");
    scanf("%d",&n);
    printf("Enter the number of car in the road: ");
    scanf("%d",&m);

    int lane[n][m];

    for (j = 0; j < m; j++) {
        for (i = 0; i < n; i++) {
            lane[i][j] = 0;
        }
    }

    //Assign random values to the array
    for (j = 0; j < m; j++) {
        v = rand() % 10;
        for (i = 0; i < n; i++) {
            lane[i][j] = v;

        }
        count_car++;
    }

    //Print the initial values of the array
    printf("\nInitial conditions of Traffic Flow Simulation:\n");
    for (j = 0; j < m; j++) {
        printf("Car %d:\t", j + 1);
        for (i = 0; i < n; i++) {
            printf("%d\t", lane[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Update the position of each car after every iteration
    for (l = 0; l < 10; l++) {
        for (j = 0; j < m; j++) {
            for (i = 0; i < n; i++) {
                //Check if the current position of the car is not the last element of the lane array
                if (i < n - 1) {
                    //Check if there is no car in front
                    if (lane[i + 1][j] == 0) {
                        lane[i + 1][j] = lane[i][j];
                        lane[i][j] = 0;
                    }
                    //Check if there is a car in front
                    else if (lane[i + 1][j] != 0 && lane[i][j] != 0) {
                        c = lane[i][j];
                        lane[i][j] = 0;
                        lane[i + 1][j] = c;
                    }
                }
                //Check if the current position of the car is the last element of the lane array
                else if (i == n - 1 && lane[0][j] == 0) {
                    lane[0][j] = lane[i][j];
                    lane[i][j] = 0;
                }
                //Check if the current position of the car is the last element of the lane array and there is a car in front
                else if (i == n - 1 && lane[0][j] != 0 && lane[i][j] != 0) {
                    c = lane[i][j];
                    lane[i][j] = 0;
                    lane[0][j] = c;
                }
            }
        }

        //Print the updated values of the array after each iteration
        printf("Iteration %d:\n", l + 1);
        for (j = 0; j < m; j++) {
            printf("Car %d:\t", j + 1);
            for (i = 0; i < n; i++) {
                printf("%d\t", lane[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Total number of cars: %d\n", count_car);
    return 0;
}