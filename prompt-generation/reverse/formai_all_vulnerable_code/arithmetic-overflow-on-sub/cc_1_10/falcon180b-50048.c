//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length;
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int wpm = 0;
    char input[100];
    char answer[100];
    char *sentence;
    char *punctuations = "!@#$%^&*()_+-=[]{}|;:,.<>/?\\";
    clock_t start_time = clock();

    // Ask the user for the length of the test
    printf("Enter the length of the test (in characters): ");
    scanf("%d", &length);

    // Generate a random sentence
    sentence = (char *)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        sentence[i] = punctuations[rand() % strlen(punctuations)];
    }
    sentence[length - 1] = '\0';

    // Display the sentence to the user
    printf("Type the following sentence:\n%s\n", sentence);

    // Get the user's input
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Compare the user's input with the correct answer
    if (strcmp(input, sentence) == 0)
    {
        correct++;
    }
    else
    {
        incorrect++;
    }
    total++;

    // Calculate the user's words per minute
    if (total > 0)
    {
        wpm = (int)((double)correct / (double)(total / length) * 60);
    }

    // Display the results to the user
    printf("You typed %d characters.\n", strlen(input));
    printf("You typed %d words per minute.\n", wpm);
    printf("You made %d correct and %d incorrect characters.\n", correct, incorrect);

    free(sentence);

    return 0;
}