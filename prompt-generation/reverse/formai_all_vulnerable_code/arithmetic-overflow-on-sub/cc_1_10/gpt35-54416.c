//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TESTS 10

// Function to calculate the typing speed of the user
int calculateTypingSpeed(char *text, double timeInSeconds);

int main()
{
    // Array to hold the different test texts
    char tests[NUM_TESTS][100] = {"The quick brown fox jumps over the lazy dog.",
                                "Pack my box with five dozen liquor jugs.",
                                "Sphinx of black quartz, judge my vow.",
                                "How vexingly quick daft zebras jump!",
                                "The jay, pig, fox, zebra and my wolves quack!",
                                "Jackdaws love my big sphinx of quartz.",
                                "The five boxing wizards jump quickly.",
                                "We promptly judged antique ivory buckles for the next prize.",
                                "Crazy Fredrick bought many very exquisite opal jewels.",
                                "A quick brown fox jumps over the lazy dog."};
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Select a random text from the array
    int randomIndex = rand() % NUM_TESTS;
    char *text = tests[randomIndex];

    printf("Type the following text as quickly as possible: \n%s\n", text);

    // Record the start time
    clock_t startTime = clock();

    // Get user input
    char userInput[100] = "";
    fgets(userInput, 100, stdin);

    // Calculate the total time
    clock_t endTime = clock();
    double totalTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int speed = calculateTypingSpeed(text, totalTime);

    // Print the result
    printf("Your typing speed is: %d WPM\n", speed);

}

int calculateTypingSpeed(char *text, double timeInSeconds)
{
    // First, count the number of words in the text
    int numWords = 1;
    for (int i=0; i<strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            numWords++;
        }
    }

    // Convert time to minutes
    double timeInMinutes = timeInSeconds / 60;

    // Calculate words per minute
    int speed = (int) ((double) numWords / timeInMinutes);

    return speed;
}