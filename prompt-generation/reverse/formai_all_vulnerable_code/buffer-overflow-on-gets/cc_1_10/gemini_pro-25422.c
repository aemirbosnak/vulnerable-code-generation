//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // Let's get your fingers ready for a typing race!
    char sentence[100];
    printf("Type a sentence: ");
    gets(sentence);
    
    // Calculating your typing speed...
    int len = strlen(sentence);
    int words = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            words++;
        }
    }
    words++;  // One more word for the last part of the sentence

    int speed = (words * 60) / 5;  // 5 seconds is a common test duration
    
    // Time to show off your typing prowess!
    printf("\nYour typing speed is: %d words per minute\n", speed);
    
    // Now, let's check your accuracy...
    
    printf("\nType the same sentence again, but this time, try to be as accurate as possible: ");
    char sentence2[100];
    gets(sentence2);
    
    // Comparing your two attempts...
    int errors = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] != sentence2[i]) {
            errors++;
        }
    }
    
    // Let's make it official: your typing accuracy is...
    int accuracy = (100 * (len - errors)) / len;
    printf("\nYour typing accuracy is: %d%%\n", accuracy);
    
    // And of course, we can't forget your total score!
    int score = (speed + accuracy) / 2;
    printf("\nYour typing score is: %d\n", score);
    
    // pat yourself on the back, typist!
    
    return 0;
}