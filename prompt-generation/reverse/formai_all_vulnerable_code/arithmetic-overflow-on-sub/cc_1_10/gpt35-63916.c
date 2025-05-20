//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX 100
#define MIN 1

int generateRandomNumber(int min, int max) {
    //function to generate random number between min and max
    return (rand() % (max - min + 1)) + min;
}

void fillSentence(char * words[MAX]) {
    //function to fill the words array with random sentences
    words[0]="The quick brown fox jumps over the lazy dog.";
    words[1]="The five boxing wizards jump quickly.";
    words[2]="How vexingly quick daft zebras jump!";
    words[3]="Pack my box with five dozen liquor jugs.";
    words[4]="The quick onyx goblin jumps over the lazy dwarf.";
    words[5]="Jaded zombies acted quaintly but kept driving their oxen forward.";
    words[6]="Waltz, bad nymph, for quick jigs vex.";
    words[7]="Quick zephyrs blow, vexing daft Jim.";
}

int main() {
    int i, n, wordsTyped=0, correctWordsTyped=0, wordsMissTyped=0;
    char * words[MAX];
    clock_t startTime, endTime;
    double elapsedTime;
    fillSentence(words);

    srand(time(NULL));
    n = generateRandomNumber(MIN, MAX-1);
    printf("Type the following sentence within 60 seconds:\n%s\n", words[n]);
    startTime = clock(); //start the clock 

    char line[1000]; 
    fgets(line, sizeof(line), stdin); //read user input line by line
    
    char * word;
    word = strtok(line, " ");
    while(word!=NULL) {
        wordsTyped++;
        if(strcmp(word,words[n])==0) {
            correctWordsTyped++;
        } else {
            wordsMissTyped++;
        }
        word = strtok(NULL, " ");
    }

    endTime = clock(); //stop the clock 
    elapsedTime = (double) (endTime - startTime) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2lf seconds\n", elapsedTime);
    printf("Words typed: %d\n", wordsTyped);
    printf("Correct words: %d\n", correctWordsTyped);
    printf("Incorrect words: %d\n", wordsMissTyped);
    printf("Typing speed: %.2lf WPM\n", (double)(correctWordsTyped*60)/(5*elapsedTime));
    
    return 0;
}