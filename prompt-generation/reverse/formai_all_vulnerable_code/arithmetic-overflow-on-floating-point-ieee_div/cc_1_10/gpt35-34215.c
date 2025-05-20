//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char text[100];
    int typingSpeed, seconds;
    time_t start, end;
    double timeTaken;
    int characterCount=0, incorrectCount=0;
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as fast as you can:\n");

    // Generate a random text for the test
    srand(time(NULL));
    int randomNumber = rand() % 5;
    switch(randomNumber){
        case 0:
            strcpy(text, "The quick brown fox jumps over the lazy dog.");
            break;
        case 1:
            strcpy(text, "She sells seashells by the seashore.");
            break;
        case 2:
            strcpy(text, "Peter Piper picked a peck of pickled peppers.");
            break;
        case 3:
            strcpy(text, "How much wood would a woodchuck chuck if a woodchuck could chuck wood?");
            break;
        case 4:
            strcpy(text, "The rain in Spain falls mainly on the plain.");
            break;
        default:
            break;
    }

    printf("%s\n", text);
    time(&start); // start the timer

    // Get the user input
    char input[100];
    fgets(input, 100, stdin);

    time(&end); // end the timer

    timeTaken = difftime(end, start);
    characterCount = strlen(text); // Get the number of characters in the text

    // Calculate the number of incorrect characters
    for(int i=0; i<characterCount; i++){
        if(text[i] != input[i]){
            incorrectCount++;
        }
    }

    // Calculate the typing speed in words per minute (wpm)
    typingSpeed = ((characterCount - incorrectCount) / 5) / (timeTaken / 60);

    // Display the results
    printf("\n");
    printf("Time taken: %.2lf seconds\n", timeTaken);
    printf("Number of characters: %d\n", characterCount);
    printf("Number of incorrect characters: %d\n", incorrectCount);
    printf("Typing speed: %d wpm\n", typingSpeed);

    return 0;
}