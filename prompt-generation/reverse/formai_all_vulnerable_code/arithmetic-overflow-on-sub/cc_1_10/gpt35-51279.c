//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LEN 100
#define NUM_TESTS 5

int testTypingSpeed(char* testString) {
    clock_t start, end;
    double time_spent;
    int i, errors=0, num_chars=0, wpm, accuracy;
    char input[MAX_STRING_LEN];
    
    printf("\n\nType the following: %s\n", testString);
    start = clock();
    fgets(input, MAX_STRING_LEN, stdin);
    end = clock();
    
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    // Calculate typing speed
    num_chars = strlen(testString);
    for(i=0; i<num_chars; i++) {
        if(input[i] != testString[i])
            errors++;
    }
    wpm = (num_chars/5)/(time_spent/60);
    accuracy = (num_chars-errors)/num_chars * 100;
    
    printf("\nTyping speed: %d WPM", wpm);
    printf("\nAccuracy: %d%%", accuracy);
    
    return wpm;
}

int main() {
    char testStrings[NUM_TESTS][MAX_STRING_LEN] =
        {"The quick brown fox jumps over the lazy dog.",
         "Now is the time for all good men to come to the aid of their country.",
         "The five boxing wizards jump quickly.",
         "How vexingly quick daft zebras jump!",
         "Jaded zombies acted quaintly but kept driving their oxen forward."};
    int i, totalWpm=0, avgWpm;
    
    srand(time(NULL));
    
    printf("Welcome to the Typing Speed Test!\n\n");
    
    for(i=0; i<NUM_TESTS; i++) {
        printf("Test %d\n", i+1);
        totalWpm += testTypingSpeed(testStrings[rand() % NUM_TESTS]);
    }
    
    avgWpm = totalWpm / NUM_TESTS;
    printf("\n\nYour average typing speed: %d WPM", avgWpm);
    
    return 0;
}