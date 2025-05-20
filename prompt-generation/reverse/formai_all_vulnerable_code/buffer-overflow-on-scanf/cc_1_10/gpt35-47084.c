//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Function to generate random characters
char getRandomChar() {
    char c;
    int r = rand() % 52;
    if (r < 26) {
        c = 'a' + r;
    } else {
        c = 'A' + (r - 26);
    }
    return c;
}

int main() {
    //User input for number of seconds for typing test
    int numSeconds;
    printf("Enter the number of seconds for the test: ");
    scanf("%d", &numSeconds);

    //Set the timer
    time_t startTime = time(NULL);
    time_t endTime = startTime + numSeconds;
    
    //Initial variables for typing test
    int correctCount = 0;
    int incorrectCount = 0;
    int totalCount = 0;
    char input;
    char randomChar = getRandomChar();

    //Loop until time runs out
    while (time(NULL) < endTime) {
        //Generate new random character if previous one was correctly typed or if it has been more than 3 seconds
        if (input == randomChar || (time(NULL) - startTime) % 3 == 0) {
            randomChar = getRandomChar();
        }
       
        printf("Type the character: %c\n", randomChar);
        input = getchar();
        fflush(stdin);

        //Check if input is correct or incorrect and increment counters accordingly
        if (tolower(input) == tolower(randomChar)) {
            printf("Correct!\n");
            correctCount++;
        } else {
            printf("Incorrect.\n");
            incorrectCount++;
        }

        //Increment total count and calculate accuracy
        totalCount = correctCount + incorrectCount;
        float accuracy = ((float) correctCount / (float) totalCount) * 100;

        //Print current statistics for the typing test
        printf("Correct: %d\n", correctCount);
        printf("Incorrect: %d\n", incorrectCount);
        printf("Total: %d\n", totalCount);
        printf("Accuracy: %.2f%%\n", accuracy);
    }

    //Print final statistics for the typing test
    printf("\n\nTime's up!\n");
    totalCount = correctCount + incorrectCount;
    float accuracy = ((float) correctCount / (float) totalCount) * 100;
    printf("Correct: %d\n", correctCount);
    printf("Incorrect: %d\n", incorrectCount);
    printf("Total: %d\n", totalCount);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}