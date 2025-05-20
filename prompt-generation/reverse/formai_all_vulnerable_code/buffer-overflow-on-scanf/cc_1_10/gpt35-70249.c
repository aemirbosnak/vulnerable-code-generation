//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random color codes for each pixel
char* getRandomColorCode() {
    static const char* colorCodes[] = {"#FF5733", "#FFC300", "#00C851", "#3F51B5", "#9C27B0", "#E91E63"};
    int randomIndex = rand() % 6;
    return colorCodes[randomIndex];
}

int main() {
    srand(time(NULL)); //Initialize random seed

    //Get user input for the dimensions of the pixel art
    int numRows, numCols;
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    //Initialize a 2D array to store the color codes for each pixel
    char* pixelGrid[numRows][numCols];

    //Generate random color codes for each pixel
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            pixelGrid[row][col] = getRandomColorCode();
        }
    }

    //Shape-shifting animation
    for (int i = 0; i < 10; i++) {
        //Clear the console screen
        system("clear");

        //Shuffle the color codes randomly
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                pixelGrid[row][col] = getRandomColorCode();
            }
        }

        //Print the pixel art grid
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                printf("\033[48;2;%sm  ", pixelGrid[row][col]);
            }
            printf("\033[0m\n"); //Reset background color
        }

        //Wait for some time before the next animation frame
        struct timespec delay = {0, 400000000};
        if (nanosleep(&delay, &delay) < 0) {
            printf("Error: sleep call failed\n");
            return 1;
        }
    }

    return 0;
}