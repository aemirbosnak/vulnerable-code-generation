//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SPEED 1000     // maximum internet speed in Mbps 
#define MIN_SPEED 1        // minimum internet speed in Mbps 
#define MAX_SCORE 5        // maximum score for accuracy
#define MIN_SCORE 0        // minimum score for accuracy
#define NUM_TESTS 5        // number of speed tests to perform 
#define BUFFER_SIZE 256    // buffer size for reading user input

// function to perform internet speed test 
double speedTest() {
    double speed = (double)(rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED);      // simulate internet speed 
    return speed;
}

// function to calculate accuracy score 
int getAccuracyScore(double estimatedSpeed, double trueSpeed) {
    double accuracy = 1 - (double)abs(estimatedSpeed - trueSpeed) / trueSpeed;      // calculate accuracy as a percentage 
    int score = (int)((accuracy * MAX_SCORE) + 0.5);                                // convert accuracy to a score 
    return score;
}

// main program 
int main() {
    srand(time(NULL));                              // seed random number generator 
    char buffer[BUFFER_SIZE];                        // buffer for reading user input 
    double trueSpeed, estimatedSpeed, totalScore = 0; // variables for speed test results 
    int i, score;                                     // variables for accuracy score 
    
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please enter your true internet speed in Mbps: ");
    fgets(buffer, BUFFER_SIZE, stdin);               // read user input 
    trueSpeed = atof(buffer);                        // convert input to double 
    
    printf("\n");
    
    for (i = 1; i <= NUM_TESTS; i++) {
        printf("Test %d: ", i);
        estimatedSpeed = speedTest();                 // perform speed test 
        
        printf("Your estimated speed is %.2f Mbps\n", estimatedSpeed);
        
        score = getAccuracyScore(estimatedSpeed, trueSpeed);  // calculate accuracy score 
        totalScore += score;                          // add score to total 
        
        printf("Accuracy score: %d\n", score);
        printf("===================================\n");
    }
    
    double averageScore = totalScore / NUM_TESTS;    // calculate average score 
    
    printf("\n");
    printf("Average accuracy score: %.2f\n", averageScore);
    printf("Thank you for using the Internet Speed Test Application!\n");
    
    return 0;
}