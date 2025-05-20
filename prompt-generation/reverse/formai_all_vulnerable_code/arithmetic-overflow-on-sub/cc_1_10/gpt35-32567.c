//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX 1000 //maximum length of the string

int main(){
    char userInput[MAX];
    char sentence[MAX] = "The quick brown fox jumps over the lazy dog";
    int sentenceLen = strlen(sentence);
    int userInputLen, index, mistakes=0, cps=0, accuracy=0;
    clock_t start, end;
    double timeUsed;

    //get user input
    printf("Please type the following sentence:\n%s\n", sentence);
    fgets(userInput, sizeof(userInput), stdin);
    //strip newline character from fgets to avoid bugs
    userInput[strcspn(userInput,"\n")] = '\0';

    //calculate user typing speed
    start = clock();

    userInputLen = strlen(userInput);
    if(userInputLen != sentenceLen){
        printf("Typing speed test failed. Sentence length is %d, you have typed %d characters only.\n", sentenceLen, userInputLen);
        return 1;
    }

    for(index=0; index<sentenceLen; index++){
        if(userInput[index] != sentence[index]){
            mistakes++;
        }
    }

    end = clock();

    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    //calculate characters per second and accuracy
    cps = (int) (sentenceLen/timeUsed);
    accuracy = ((sentenceLen-mistakes)*100)/sentenceLen;

    //print summary of typing speed test
    printf("Typing speed test complete! \n\n");
    printf("You have typed the following sentence: %s\n", userInput);
    printf("You have made %d mistake(s).\n", mistakes);
    printf("Typing speed: %d characters per second.\n", cps);
    printf("Accuracy: %d%%.\n", accuracy);

    return 0;
}