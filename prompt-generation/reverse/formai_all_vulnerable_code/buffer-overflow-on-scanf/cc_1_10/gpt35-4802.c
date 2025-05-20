//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare function prototypes
void runTests();
void runSingleTest();

// Main function
int main() {
    printf("Welcome to The Internet Speed Test, version 2.1 (beta).\n");
    printf("This program measures your internet speed to determine how fast your connection is.\n");
    
    // Prompt user to run tests
    char input[10];
    printf("\nWould you like to run a single test or multiple tests?\n");
    printf("Type 'S' for a single test or 'M' for multiple tests: ");
    scanf("%s", input);
    
    // Validate user input
    while (strcmp(input, "S") != 0 && strcmp(input, "M") != 0) {
        printf("\nInvalid input. Please type 'S' or 'M': ");
        scanf("%s", input);
    }
    
    // Run tests based on user input
    if (strcmp(input, "S") == 0) {
        runSingleTest();
    } else {
        runTests();
    }
    
    return 0;
}

// Function to run multiple tests
void runTests() {
    printf("\nStarting multiple tests. This may take a few minutes.\n\n");
    
    // Initialize counters
    int numTests = 0;
    int numSuccess = 0;
    
    // Run 5 tests
    for (int i = 1; i <= 5; i++) {
        printf("Running test %d...\n", i);
        runSingleTest();
        numTests++;
        
        // Simulate random test success or failure
        srand(time(0));
        int randomNum = rand() % 10;
        if (randomNum < 8) {
            printf("Test %d successful.\n", i);
            numSuccess++;
        } else {
            printf("Test %d failed.\n", i);
        }
    }
    
    // Calculate success rate
    double successRate = ((double)numSuccess / numTests) * 100;
    
    // Print results
    printf("\nTest results:\n");
    printf("Number of tests: %d\n", numTests);
    printf("Number successful: %d\n", numSuccess);
    printf("Success rate: %.2f%%\n", successRate);
}

// Function to run a single test
void runSingleTest() {
    printf("Starting test...\n");
    
    // Simulate download and upload times
    srand(time(0));
    int downloadTime = rand() % 5 + 1;
    int uploadTime = rand() % 5 + 1;
    
    // Simulate test completion time
    int totalTime = downloadTime + uploadTime;
    
    // Print results
    printf("Download time: %d seconds\n", downloadTime);
    printf("Upload time: %d seconds\n", uploadTime);
    printf("Total time: %d seconds\n", totalTime);
    
    // Determine internet speed
    if (totalTime < 3) {
        printf("Your internet speed is very fast!\n");
    } else if (totalTime < 6) {
        printf("Your internet speed is fast.\n");
    } else if (totalTime < 10) {
        printf("Your internet speed is average.\n");
    } else {
        printf("Your internet speed is slow.\n");
    }
}