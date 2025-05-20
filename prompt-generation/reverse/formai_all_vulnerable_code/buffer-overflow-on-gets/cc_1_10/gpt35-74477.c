//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <string.h>

//function declarations
int countWords(char sentence[]);
int calculateSentiment(char sentence[], int numWords);

int main() {
    char sentence[1000];
    int numWords, sentiment;
    
    printf("Enter a sentence: ");
    gets(sentence);
    
    numWords = countWords(sentence);
    
    if (numWords == 0) {
        printf("Invalid input.\n");
        return 0;
    }
    
    sentiment = calculateSentiment(sentence, numWords);
    
    printf("Sentiment of the sentence \"%s\" is: %d\n", sentence, sentiment);
    
    return 0;
}

int countWords(char sentence[]) {
    int numWords = 0;
    char *word = strtok(sentence, " ");
    
    while (word != NULL) {
        numWords++;
        word = strtok(NULL, " ");
    }
    
    return numWords;
}

int calculateSentiment(char sentence[], int numWords) {
    int sentiment = 0;
    char *word = strtok(sentence, " ");
    
    while (word != NULL) {
        if (strcmp(word, "happy") == 0 || strcmp(word, "excited") == 0 || strcmp(word, "joyful") == 0) {
            sentiment += 2;
        } else if (strcmp(word, "good") == 0 || strcmp(word, "nice") == 0 || strcmp(word, "awesome") == 0) {
            sentiment++;
        } else if (strcmp(word, "sad") == 0 || strcmp(word, "unhappy") == 0 || strcmp(word, "depressed") == 0) {
            sentiment -= 2;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
            sentiment--;
        }
        
        word = strtok(NULL, " ");
    }
    
    if (sentiment >= numWords / 2) {
        return 1;
    } else if (sentiment <= -numWords / 2) {
        return -1;
    } else {
        return 0;
    }
}