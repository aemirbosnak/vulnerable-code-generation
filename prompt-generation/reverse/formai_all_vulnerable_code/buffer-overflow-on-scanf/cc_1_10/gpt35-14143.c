//FormAI DATASET v1.0 Category: Memory Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

volatile int game_over = 0; //global variable to signal end of game

// function to handle control+C signal and end the game
void end_game(int sig) {
    printf("\nTime's Up! Game Over.\n");
    game_over = 1;
}

// function to shuffle the array
void shuffle(int *arr, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// function to print the game board
void print_board(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// function to prompt user for input
int take_input() {
    int input;
    printf("Enter the index of the number you wish to flip: ");
    scanf("%d", &input);
    return input;
}

// main function
int main() {
    srand(time(NULL));
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // initialize array with numbers
    shuffle(arr, 10); // shuffle the array
    int flipped[10] = {0}; // initialize another array to keep track of flipped numbers
    int time_left = 10; // set initial time
    signal(SIGINT, end_game); // register signal handler for control+C
    printf("Welcome to the Memory Game!\n");
    printf("You have 10 seconds to memorize the numbers before they disappear!\n");
    sleep(2);
    print_board(arr, 10); // print the board for 2 seconds
    sleep(2);
    system("clear"); // clear the screen before starting the game loop
    while (!game_over && time_left > 0) { // main game loop
        printf("Time Left: %ds\n", time_left);
        print_board(flipped, 10); // print the current state of the board
        int input = take_input();
        if (input >= 0 && input < 10) { // check if input is within bounds
            if (flipped[input] == 0) { // check if number at index has been flipped before
                flipped[input] = arr[input]; // flip the number
            } else {
                printf("You have already flipped that number!\n");
            }
        } else {
            printf("Invalid input. Please enter a number between 0 and 9.\n");
        }
        int count = 0; // count the number of flipped numbers
        for (int i = 0; i < 10; i++) {
            if (flipped[i] != 0) {
                count++;
            }
        }
        if (count == 10) { // check if all numbers have been flipped
            printf("Congratulations! You have won the game.\n");
            break;
        }
        time_left--;
        sleep(1); // wait 1 second before continuing to next iteration
        system("clear"); // clear the screen for next iteration
    }
    printf("Game Over.\n");
    return 0;
}