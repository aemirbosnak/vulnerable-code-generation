//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){
    int wordcount = 0, correctcount = 0, incorrectcount = 0;
    char userinput[100];
    
    time_t start, end;
    double timetaken;

    srand(time(NULL)); // seeding the random function with current time
    
    char *words[] = {"computer", "keyboard", "programming", "interface", "algorithm",
                       "variable", "function", "software", "hardware", "language", 
                       "developer", "analysis", "design", "debugging", "integration"}; // array of words to choose from
    
    printf("Welcome to the Typing Speed Test. Type the words as fast and accurately as possible.\n"); 
    printf("Press Enter to START the test!");
    getchar(); // getting a character without buffering
    
    start = time(NULL); // starting clock
    
    for(int i=0; i<10; i++){ // loop for 10 words
        char *currentword = words[rand()%15]; // getting a random word from array
        printf("Word %d: %s\n", i+1, currentword);
        scanf("%s", userinput); // getting user input
        
        if(strcmp(currentword, userinput)==0){ // if input matches the word
            printf("Correct!\n");
            correctcount++;
        }
        else{ // if input does not match the word
            printf("Wrong! The correct word is %s.\n", currentword);
            incorrectcount++;
        }
        
        wordcount++; // incrementing total word count
    }
    
    end = time(NULL); // stopping clock
    timetaken = difftime(end, start); // getting time taken
    
    printf("Test has finished.\n");
    
    printf("Total words: %d\n", wordcount);
    printf("Correct words: %d\n", correctcount);
    printf("Incorrect words: %d\n", incorrectcount);
    
    printf("Time taken: %.2lf seconds\n", timetaken);
    printf("Typing speed: %.2lf WPM\n", (wordcount/5)/(timetaken/60)); // words per minute calculation
    
    return 0;
}