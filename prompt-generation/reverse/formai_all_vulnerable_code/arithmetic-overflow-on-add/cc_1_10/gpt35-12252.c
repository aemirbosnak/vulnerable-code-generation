//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENTENCES 5
#define SENTENCE_LENGTH 50

int calculateTypingSpeed(int totalTimeInSeconds, int totalWords);
float calculateAccuracy(int totalTypedChars, int totalCorrectChars);

int main(){
    char sentences[SENTENCES][SENTENCE_LENGTH] = {
        "The quick brown fox jumps over the lazy dog.",
        "Jackdaws love my big sphinx of quartz.",
        "Pack my box with five dozen liquor jugs.",
        "How vexingly quick daft zebras jump!",
        "Sphinx of black quartz, judge my vow."
    };
    char userInput[SENTENCES][SENTENCE_LENGTH];
    int index, sentence, correctChars, totalTypedChars, totalCorrectChars, totalWords = 0, totalTimeInSeconds;
    clock_t startTime, endTime;
    
    printf("Welcome to the Typing Speed Test!\n\n");  
    
    for (sentence = 0; sentence < SENTENCES; sentence++){
        printf("Sentence %d: %s\n", sentence+1, sentences[sentence]);
        printf("Please type the sentence exactly as it is: ");
        fgets(userInput[sentence], SENTENCE_LENGTH, stdin);
        
        totalWords++; // increment total number of words
        
        for (index = 0; index < SENTENCE_LENGTH; index++){
            if (sentences[sentence][index] != userInput[sentence][index]){
                break; // assumes user will type sentence correctly, but breaks at first error
            }
            correctChars++;
        }
        totalCorrectChars += correctChars; // add to total correct characters
        
        printf("You typed %d out of %d characters correctly.\n\n", correctChars, SENTENCE_LENGTH - 1);
        
        correctChars = 0;
    }

    endTime = clock(); // get ending time
    totalTimeInSeconds = (endTime - startTime) / CLOCKS_PER_SEC; // calculate total time in seconds
    totalTypedChars = totalWords * SENTENCE_LENGTH; // calculate total typed characters
    
    printf("Congratulations! You have completed the Typing Test.\n\n");  
    printf("Your typing speed is: %d words per minute.\n", calculateTypingSpeed(totalTimeInSeconds, totalWords));
    printf("Your typing accuracy is: %0.2f%%.\n", calculateAccuracy(totalTypedChars, totalCorrectChars));
    
    return 0;
}

int calculateTypingSpeed(int totalTimeInSeconds, int totalWords){
    return (totalWords / totalTimeInSeconds) * 60; // number of words divided by time in seconds, then multiplied by 60 to get wpm
}

float calculateAccuracy(int totalTypedChars, int totalCorrectChars){
    return (totalCorrectChars / (float)totalTypedChars) * 100; // correct characters divided by total typed characters, then multiplied by 100
}