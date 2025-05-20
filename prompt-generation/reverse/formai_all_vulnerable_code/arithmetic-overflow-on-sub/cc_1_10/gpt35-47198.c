//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10
#define MAX_TYPING_TIME 60

// A function to generate random words for typing test
char* getRandomWord(){
    char* words[MAX_WORDS] = {"computer", "programming", "language", "algorithm", "data", "structure", "memory", "pointer", "function", "variable",
                              "integer", "floating", "conditional", "iteration", "assignment", "expression", "operator", "logic", "library", "header"
                             };
    int index = rand() % MAX_WORDS;
    char* randomWord = words[index];
    return randomWord;
}

int main(){
    int i, j;
    bool timeUp = false;
    int score = 0;
    
    // Set the seed for random function
    srand(time(0));
    
    printf("\nWelcome to Typing Speed Test\n");
    printf("You will get random words and you have to type them as fast as you can in 60 seconds\n");
    printf("Press enter to start the test\n");
    getchar();
    
    // Start the typing test
    time_t startTime = time(NULL);
    while(!timeUp){
        char* word = getRandomWord();
        printf("Type this word: %s\n", word);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strlen(input)-1] = '\0'; // Remove the newline character from input
        
        if(strcmp(word, input) == 0){
            score++;
        }
        
        // Check if 60 seconds are over
        time_t currentTime = time(NULL);
        if(currentTime - startTime > MAX_TYPING_TIME){
            timeUp = true;
        }
    }
    
    printf("\nTime up!\n");
    printf("Your typing score is %d\n", score);
    
    return 0;
}