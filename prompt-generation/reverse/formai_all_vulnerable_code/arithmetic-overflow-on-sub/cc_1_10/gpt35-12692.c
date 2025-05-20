//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random sentence to type out as quickly and accurately as possible.\n");

    // The sentences for the test
    char sentences[5][100] = {
        "The quick brown fox jumps over the lazy dog.",
        "She sells seashells by the seashore.",
        "How much wood would a woodchuck chuck, if a woodchuck could chuck wood?",
        "Peter Piper picked a peck of pickled peppers.",
        "Betty bought a bit of butter, but the butter was bitter, so Betty bought another bit of butter to make the bitter butter better."
    };

    // Set the seed for the random number generator
    srand(time(NULL));

    // Get a random number between 0 and 4 to select a sentence from the array
    int randIndex = rand() % 5;

    // Get the sentence from the array
    char *sentence = sentences[randIndex];

    // The user's input
    char input[100];

    // The start time of the test
    clock_t tStart = clock();

    // Prompt the user to start typing
    printf("Type the following sentence as quickly and accurately as possible:\n%s\n", sentence);

    // Get the user's input
    scanf("%[^\n]", input);

    // Calculate the elapsed time in seconds
    double elapsedSeconds = (double)(clock() - tStart) / CLOCKS_PER_SEC;

    // Calculate the user's accuracy
    int correctCount = 0;
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == sentence[i]){
            correctCount++;
        }
    }
    double accuracy = (double)correctCount / strlen(sentence) * 100;

    // Calculate the user's typing speed in words per minute
    double typingSpeed = (double)strlen(input) / elapsedSeconds * 12;

    // Print the results
    printf("You typed: %s\n", input);
    printf("Elapsed time: %.2f seconds\n", elapsedSeconds);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f words per minute\n", typingSpeed);

    return 0;
}