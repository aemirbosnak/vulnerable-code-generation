//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 50    // maximum length of each word
#define MAX_WORDS 10     // maximum number of words in the test
#define MAX_TIME 60      // maximum time allotted for the test in seconds

int main()
{
    int i, j;       // loop variables
    int words_correct = 0;   // number of correctly typed words
    int words_typed = 0;     // number of words typed
    int elapsed_time = 0;    // elapsed time in seconds
    time_t start_time, current_time;   // variables to keep track of time
  
    // list of words for the typing test
    char words[MAX_WORDS][MAX_LENGTH] = {"apple", "banana", "cherry", "orange",
                                         "grape", "kiwi", "lemon", "mango",
                                         "pear", "pineapple"};
  
    // print instructions for the user
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type as many words as you can in %d seconds.\n", MAX_TIME);
    printf("Press Enter to start the test.\n");

    // wait for the user to start the test
    getchar();
  
    // get the current time
    start_time = time(NULL);
  
    // loop until the maximum time is reached
    while (elapsed_time < MAX_TIME)
    {
        // generate a random word from the list of words
        int word_index = rand() % MAX_WORDS;
        char word[MAX_LENGTH];
        strcpy(word, words[word_index]);
      
        // print the word for the user to type
        printf("\n%s\n", word);
      
        // get the user's input
        char input[MAX_LENGTH];
        fgets(input, MAX_LENGTH, stdin);
      
        // remove the newline character from the input
        input[strlen(input)-1] = '\0';
      
        // check if the input matches the word
        if (strcmp(input, word) == 0)
        {
            printf("Correct!\n");
            words_correct++;
        }
        else
        {
            printf("Incorrect.\n");
        }
      
        // update the number of words typed
        words_typed++;
      
        // get the current time
        current_time = time(NULL);
      
        // update the elapsed time
        elapsed_time = (int) difftime(current_time, start_time);
    }
  
    // calculate the typing speed
    double speed = (double) words_correct / ((double) elapsed_time / 60.0);
  
    // print the results
    printf("\nTime: %d seconds\n", elapsed_time);
    printf("Words typed: %d\n", words_typed);
    printf("Words correct: %d\n", words_correct);
    printf("Typing speed: %.2f words per minute\n", speed);

    return 0;
}