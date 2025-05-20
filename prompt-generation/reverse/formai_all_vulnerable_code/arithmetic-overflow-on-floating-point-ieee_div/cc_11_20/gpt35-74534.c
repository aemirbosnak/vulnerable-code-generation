//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX 100 // Length of Test Blurb

int main()
{
    char sentence[MAX];
    int words = 0, wpm = 0, correct = 0, incorrect = 0;
    float time_taken;

    printf("\n\t\t\tWelcome to Typing Speed Test\n\n");
    printf("You will be presented with a short passage that you have to type as quickly as possible!\n");
    printf("We will keep track of your typing speed and accuracy.\n");
    printf("Let's see how fast and accurate you can type!\n\n");

    printf("Please type the following passage to begin:\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    fgets(sentence, MAX, stdin);
    
    // Removing newline character from fgets input
    sentence[strcspn(sentence, "\n")] = 0;

    time_t start_time, end_time;
    start_time = time(NULL);

    printf("Type the following passage and hit 'ENTER' to finish when you are done: \n%s\n", sentence);
    printf("\n");

    fgets(sentence, MAX, stdin);
    
    // Removing newline character from fgets input
    sentence[strcspn(sentence, "\n")] = 0;

    end_time = time(NULL);
    time_taken = difftime(end_time, start_time);

    // Calculating the number of words in the passage
    for(int i = 0; i < strlen(sentence); i++)
    {
        if(sentence[i] == ' ')
            words++;
    }
    words++; // Taking into account the last word which doesn't have a space after it

    // Counting number of correctly and incorrectly typed words
    char *token = strtok(sentence, " ");
    while(token != NULL)
    {
        if(strcmp(token, "The") == 0 || strcmp(token, "quick") == 0 || strcmp(token, "brown") == 0 || 
           strcmp(token, "fox") == 0 || strcmp(token, "jumps") == 0 || strcmp(token, "over") == 0 || 
           strcmp(token, "the") == 0 || strcmp(token, "lazy") == 0 || strcmp(token, "dog.") == 0 )
            correct++;
        else
            incorrect++;
        token = strtok(NULL, " ");
    }

    // Calculating WPM and Accuracy
    wpm = (int)((float)words/(time_taken/60));
    float accuracy = ((float)correct/(correct+incorrect))*100;

    // Printing Results
    printf("\n\n\t\t\tResults\n\n");
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Words Typed: %d\n", words);
    printf("Correctly Typed Words: %d\n", correct);
    printf("Incorrectly Typed Words: %d\n", incorrect);
    printf("Typing Speed : %d WPM\n", wpm);
    printf("Accuracy: %.2f %\n\n", accuracy);

    printf("\t\t\tThank You for taking the Typing Speed Test!\n\n");

    return 0;
}