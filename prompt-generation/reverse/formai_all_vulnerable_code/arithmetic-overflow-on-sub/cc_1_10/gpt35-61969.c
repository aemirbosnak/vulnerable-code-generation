//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    char sampleText[] = "The quick brown fox jumps over the lazy dog";
    int textLength = sizeof(sampleText) - 1;
    int words = 0, characters = 0, correct = 0, errors = 0, wpm = 0;
    clock_t start, end;
    double time_used;

    printf("\n***Welcome to the Typing Speed Test!***\n");
    printf("You will be given a sentence to type.\n");
    printf("Type the given sentence correctly as fast as possible.\n");
    printf("Press enter to start the test.\n");

    getchar();

    //Start the test
    start = clock();

    //Print the sentence to type
    printf("\n%s\n", sampleText);

    //Take input from user
    char userInput[100];
    fgets(userInput, 100, stdin);

    //Stop the time after the input is taken
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //Calculate words and characters in the sentence
    for(int i = 0; i < textLength; i++){
        if(sampleText[i] != ' '){
            characters++;
        }
        else{
            words++;
        }
    }
    words++;

    //Check if the input is correct or not
    for(int i = 0; i < textLength; i++){
        if(userInput[i] != sampleText[i]){
            errors++;
        }
        else{
            correct++;
        }
    }

    //Calculate WPM
    wpm = (correct/(time_used/60))/5;

    //Print the results
    printf("\n\nYou typed %d correct characters out of %d characters.\n", correct, textLength);
    printf("You typed %d words in %f seconds.\n", words, time_used);
    printf("Your typing speed is %d words per minute.\n", wpm);

    if(errors > 0){
        printf("You made %d typing mistake(s).\n", errors);
    }
    else{
        printf("Congratulations! You made no typing mistakes.\n");
    }

    return 0;
}