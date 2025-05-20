//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
//Donald Knuth Style Typing Speed Test

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define LENGTH 10              //Number of words in the test
#define WORDSIZE 6             //Max size of a single word
#define MINWAIT 3              //Minimum wait time between words (in seconds)
#define MAXWAIT 5              //Maximum wait time between words (in seconds)

typedef struct word {
    char w[WORDSIZE];
    int len;
} word;

int main() {
    word words[LENGTH] = {
        {"apple", 5},
        {"banana", 6},
        {"cherry", 6},
        {"grapes", 6},
        {"kiwi", 4},
        {"melon", 5},
        {"orange", 6},
        {"peach", 5},
        {"pear", 4},
        {"pineapple", 9}
    };                          //List of words to use in the test
    int correct = 0;            //Number of correctly typed words
    int mistakes = 0;           //Number of mistakes made
    time_t start, end;          //Variables to calculate typing speed
    int wait = 0;               //Wait time between words
    int i, j;                   //Variables for looping
    char c;                     //Variable to store user input
    
    printf("Welcome to the Donald Knuth Style Typing Speed Test!\n\n");
    printf("You will be presented with %d words to type. Ready?\n\n", LENGTH);
    printf("Press enter to begin...");
    getchar();                  //Waits for user to press enter
    
    srand(time(NULL));          //Seed the random number generator
    
    for (i = 0; i < LENGTH; i++) {
        printf("%s ", words[i].w);
        fflush(stdout);         //Flush output so user can see the word
        time(&start);           //Start timing
        
        //Wait for random amount of time between words
        wait = rand() % (MAXWAIT - MINWAIT + 1) + MINWAIT;
        sleep(wait);
        
        //Get user input for the current word
        for (j = 0; j < words[i].len; j++) {
            c = getchar();
            if (islower(c)) {               //Make user input lowercase
                c = toupper(c);
            }
            if (c == words[i].w[j]) {
                correct++;
            } else {
                mistakes++;
            }
        }
        while ((c = getchar()) != '\n');    //Flush remaining input
        
        time(&end);                      //Stop timing
        printf("\n");
        
        //Calculate typing speed for the current word
        double seconds = difftime(end, start);
        double wpm = (double)correct / (seconds / 60.0);
        printf("You typed \"%s\" in %.2lf seconds (%.2lf WPM)\n", words[i].w, seconds, wpm);
        correct = 0;                      //Reset correct count for next word
    }
    printf("\nTyping Speed Test Complete!\n");
    printf("You made %d mistakes in total.", mistakes);
    
    return 0;
}