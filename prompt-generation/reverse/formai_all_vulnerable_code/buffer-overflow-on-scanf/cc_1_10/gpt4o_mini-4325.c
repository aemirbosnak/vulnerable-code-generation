//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printMenu();
void playGame();
int generateRandomNumber();
void swapNumbers(int *a, int *b);
void findLargestAndSmallest(int arr[], int size);
void calculateAverage(int arr[], int size);

int main() {
    int choice;

    // Seed for random number generation
    srand(time(0));

    do {
        printMenu();
        printf("Enter your choice (1-3 or 0 to exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You chose to play the number guessing game!\n");
                playGame();
                break;
            case 2:
                printf("You chose to find largest and smallest numbers from an array!\n");
                int arr1[10];
                for(int i = 0; i < 10; i++) {
                    arr1[i] = rand() % 100; // Random numbers between 0 and 99
                }
                findLargestAndSmallest(arr1, 10);
                break;
            case 3:
                printf("You chose to calculate the average from an array!\n");
                int arr2[5];
                for(int i = 0; i < 5; i++) {
                    arr2[i] = rand() % 50 + 1; // Random numbers between 1 and 50
                }
                calculateAverage(arr2, 5);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
        
    } while(choice != 0);

    return 0;
}

void printMenu() {
    printf("\n********** Welcome to the Educational Program **********\n");
    printf("1. Play Number Guessing Game\n");
    printf("2. Find Largest and Smallest Number in Array\n");
    printf("3. Calculate Average of Array Elements\n");
    printf("0. Exit\n");
}

void playGame() {
    int guess;
    int numberToGuess = generateRandomNumber();
    int attempts = 0;
    
    printf("I have selected a number between 1 and 100. Can you guess it?\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < numberToGuess) {
            printf("Too low! Try again.\n");
        } else if (guess > numberToGuess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", numberToGuess, attempts);
        }
    } while (guess != numberToGuess);
}

int generateRandomNumber() {
    return rand() % 100 + 1; // Random number between 1 and 100
}

void findLargestAndSmallest(int arr[], int size) {
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("Largest number is: %d\n", largest);
    printf("Smallest number is: %d\n", smallest);
}

void calculateAverage(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    float average = (float)sum / size;
    printf("The average of the array elements is: %.2f\n", average);
}