//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000 // maximum length of input string

// function to remove punctuations from the input text
void removePunctuations(char *text){
    int len = strlen(text);
    int index = 0;
    for(int i = 0; i < len; i++){
        if(isalpha(text[i]) || isspace(text[i])){
            text[index++] = tolower(text[i]);
        }
    }
    text[index] = '\0';
    return;
}

// function to split the input text into sentences
char** splitTextIntoSentences(char *text, int *numberOfSentences){
    int len = strlen(text);
    int sentenceIndex = 0, currentIndex = 0, lastSpaceIndex = -1;
    char *currentSentence = (char*)malloc(sizeof(char)*MAX_LEN);
    char **sentences = NULL;

    sentences = (char**)malloc(sizeof(char*));

    for(int i = 0; i < len; i++){
        if(text[i] == '.'){
            if(i < len - 1 && text[i+1] == ' '){
                currentSentence[currentIndex++] = text[i];
                currentSentence[currentIndex++] = text[i+1];
                currentSentence[currentIndex] = '\0';
                sentences[sentenceIndex++] = currentSentence;
                currentIndex = 0;
                lastSpaceIndex = -1;
                sentences = (char**)realloc(sentences, (sentenceIndex+1)*sizeof(char*));
                currentSentence = (char*)malloc(sizeof(char)*MAX_LEN);
            }
            else{
                currentSentence[currentIndex++] = text[i];
            }
        }
        else if(text[i] == ' '){
            lastSpaceIndex = currentIndex;
            currentSentence[currentIndex++] = text[i];
        }
        else{
            currentSentence[currentIndex++] = text[i];
        }
    }
    if(currentIndex > 0){
        if(lastSpaceIndex == -1){
            currentSentence[currentIndex] = '\0';
        }
        else{
            currentSentence[lastSpaceIndex] = '\0';
        }
        sentences[sentenceIndex++] = currentSentence;
    }
    *numberOfSentences = sentenceIndex;
    sentences = (char**)realloc(sentences, sentenceIndex*sizeof(char*));
    return sentences;
}

// function to count the number of words in a sentence
int countWordsInSentence(char *sentence){
    int len = strlen(sentence);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(sentence[i] == ' ' && i < len - 1 && sentence[i+1] != ' '){
            count++;
        }
    }
    return count+1;
}

// function to calculate the frequency of each word in the input text
void calculateWordFrequencies(char *text, int numberOfSentences, char **sentences, int *frequencies){
    int len = strlen(text);
    int wordCount = 0;
    char **words = (char**)malloc(sizeof(char*));
    for(int i = 0; i < numberOfSentences; i++){
        int sentenceLength = strlen(sentences[i]);
        char *currentWord = (char*)malloc(sizeof(char)*MAX_LEN);
        int currentIndex = 0;
        for(int j = 0; j < sentenceLength; j++){
            if(sentences[i][j] == ' '){
                currentWord[currentIndex] = '\0';
                int found = 0;
                for(int k = 0; k < wordCount; k++){
                    if(strcmp(words[k], currentWord) == 0){
                        frequencies[k]++;
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    wordCount++;
                    words = (char**)realloc(words, wordCount*sizeof(char*));
                    words[wordCount-1] = (char*)malloc(sizeof(char)*MAX_LEN);
                    strcpy(words[wordCount-1], currentWord);
                    frequencies[wordCount-1] = 1;
                }
                currentIndex = 0;
            }
            else{
                currentWord[currentIndex++] = sentences[i][j];
            }
        }
        if(currentIndex > 0){
            currentWord[currentIndex] = '\0';
            int found = 0;
            for(int k = 0; k < wordCount; k++){
                if(strcmp(words[k], currentWord) == 0){
                    frequencies[k]++;
                    found = 1;
                    break;
                }
            }
            if(!found){
                wordCount++;
                words = (char**)realloc(words, wordCount*sizeof(char*));
                words[wordCount-1] = (char*)malloc(sizeof(char)*MAX_LEN);
                strcpy(words[wordCount-1], currentWord);
                frequencies[wordCount-1] = 1;
            }
        }
        free(currentWord);
    }
    for(int i = 0; i < wordCount; i++){
        frequencies[i] = frequencies[i]*100/numberOfSentences;
    }
    for(int i = 0; i < wordCount; i++){
        for(int j = i+1; j < wordCount; j++){
            if(strcmp(words[i], words[j]) > 0){
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
                int tempFreq = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = tempFreq;
            }
        }
    }
    return;
}

// function to calculate the sentence score
int calculateSentenceScore(char *sentence, int wordCount, char **words, int *frequencies){
    int score = 0;
    for(int i = 0; i < wordCount; i++){
        if(strstr(sentence, words[i]) != NULL){
            score += frequencies[i];
        }
    }
    return score;
}

// main function
int main(){
    char inputText[MAX_LEN];
    printf("Enter the text to be summarized:\n");
    fgets(inputText, MAX_LEN, stdin);
    inputText[strlen(inputText)-1] = '\0';

    removePunctuations(inputText);
    int numberOfSentences = 0;
    char **sentences = splitTextIntoSentences(inputText, &numberOfSentences);
    int *frequencies = (int*)malloc(sizeof(int));
    calculateWordFrequencies(inputText, numberOfSentences, sentences, frequencies);
    int wordCount = 0;
    char **words = (char**)malloc(sizeof(char*));
    for(int i = 0; i < numberOfSentences; i++){
        wordCount += countWordsInSentence(sentences[i]);
    }

    for(int i = 0; i < numberOfSentences; i++){
        int score = calculateSentenceScore(sentences[i], wordCount, words, frequencies);
        printf("Sentence %d: %s\nScore: %d\n\n", i+1, sentences[i], score);
    }

    for(int i = 0; i < numberOfSentences; i++){
        free(sentences[i]);
    }
    free(sentences);

    for(int i = 0; i < wordCount; i++){
        free(words[i]);
    }
    free(words);
    free(frequencies);

    return 0;
}