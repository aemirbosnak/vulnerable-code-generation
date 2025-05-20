//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int vehiclePosition[2] = {0, 0};

void printBoard(char board[ROW][COL]) {
    for (int i=0; i<ROW; i++) {
      for (int j=0; j<COL; j++) {
          if (i == vehiclePosition[0] && j == vehiclePosition[1]) {
              printf("V ");
          }
          else {
              printf("%c ", board[i][j]);
          }
      }
      printf("\n");
    }
}

void moveNorth() {
    if (vehiclePosition[0] > 0) {
        vehiclePosition[0] -= 1;
        printf("Vehicle moved North.\n");
    }
    else {
        printf("Vehicle cannot move further North.\n");
    }
}

void moveSouth() {
    if (vehiclePosition[0] < ROW-1) {
        vehiclePosition[0] += 1;
        printf("Vehicle moved South.\n");
    }
    else {
        printf("Vehicle cannot move further South.\n");
    }
}

void moveWest() {
    if (vehiclePosition[1] > 0) {
        vehiclePosition[1] -= 1;
        printf("Vehicle moved West.\n");
    }
    else {
        printf("Vehicle cannot move further West.\n");
    }
}

void moveEast() {
    if (vehiclePosition[1] < COL-1) {
        vehiclePosition[1] += 1;
        printf("Vehicle moved East.\n");
    }
    else {
        printf("Vehicle cannot move further East.\n");
    }
}

int main() {
    char board[ROW][COL];
    srand(time(NULL));

    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            board[i][j] = '-';
        }
    }

    vehiclePosition[0] = rand() % 10;
    vehiclePosition[1] = rand() % 10;

    board[vehiclePosition[0]][vehiclePosition[1]] = 'V';

    printBoard(board);

    char choice;
    do {
        printf("Enter the direction in which you want to move the vehicle (N/S/W/E): ");
        scanf(" %c", &choice);

        switch(choice) {
            case 'N':
              moveNorth();
              break;

            case 'S':
              moveSouth();
              break;

            case 'W':
              moveWest();
              break;

            case 'E':
              moveEast();
              break;

            default:
              printf("Invalid direction.\n");
        }

        board[vehiclePosition[0]][vehiclePosition[1]] = 'V';

        system("clear");
        printBoard(board);

    } while (choice != 'Q');

    printf("Thank you for using the Remote Control Vehicle Simulation!\n");

    return 0;
}