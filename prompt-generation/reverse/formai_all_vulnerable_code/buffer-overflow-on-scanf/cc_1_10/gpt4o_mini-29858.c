//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6

// Function prototypes
void rollDice(int rolls, int results[]);
void printResults(int rolls, int results[]);
double calculateMean(int rolls, int results[]);
double calculateMedian(int rolls, int results[]);
int calculateMode(int rolls, int results[]);

int main() {
    int rolls;
    int results[SIDES + 1] = {0}; // Stores the count for each side (1-6)

    // Seed the random number generator
    srand(time(0));

    printf("Welcome to the C Dice Roller!\n");
    printf("How many times would you like to roll the die? ");
    scanf("%d", &rolls);

    // Validate input
    if (rolls <= 0) {
        printf("Please enter a positive number of rolls.\n");
        return 1;
    }

    // Roll the dice
    rollDice(rolls, results);
    
    // Print the results
    printResults(rolls, results);

    // Calculate and print statistics
    double mean = calculateMean(rolls, results);
    double median = calculateMedian(rolls, results);
    int mode = calculateMode(rolls, results);

    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);

    return 0;
}

// Function to simulate rolling the dice
void rollDice(int rolls, int results[]) {
    for (int i = 0; i < rolls; i++) {
        int roll = (rand() % SIDES) + 1; // Generate a number between 1 and 6
        results[roll]++; // Increment the count of the corresponding side
    }
}

// Function to print roll results
void printResults(int rolls, int results[]) {
    printf("Results of rolling the die %d times:\n", rolls);
    for (int i = 1; i <= SIDES; i++) {
        printf("Side %d: %d times (%.2f%%)\n", i, results[i], (results[i] / (double)rolls) * 100);
    }
}

// Function to calculate mean
double calculateMean(int rolls, int results[]) {
    int totalScore = 0;
    for (int i = 1; i <= SIDES; i++) {
        totalScore += i * results[i]; // Multiply number by its frequency
    }
    return (double)totalScore / rolls; // Mean = Total / Number of rolls
}

// Function to calculate median
double calculateMedian(int rolls, int results[]) {
    int cumulative = 0;
    for (int i = 1; i <= SIDES; i++) {
        cumulative += results[i];
    }

    int mid1 = cumulative / 2; // First midpoint
    int mid2 = (cumulative - 1) / 2; // Second midpoint
    int count = 0;
    
    for (int i = 1; i <= SIDES; i++) {
        count += results[i];
        if (count >= mid1) {
            if (cumulative % 2 == 0 && count == mid1) { // If even number of rolls
                // Find the next number to average with
                for (int j = i+1; j <= SIDES; j++) {
                    if (results[j] > 0) {
                        return (i + j) / 2.0;
                    }
                }
            }
            return (double)i; // Odd total, return the number
        }
    }
    return 0; // Default return, should not reach here
}

// Function to calculate mode
int calculateMode(int rolls, int results[]) {
    int mode = 1;
    int maxCount = results[1];
    
    for (int i = 2; i <= SIDES; i++) {
        if (results[i] > maxCount) {
            maxCount = results[i];
            mode = i;
        }
    }
    return mode;
}