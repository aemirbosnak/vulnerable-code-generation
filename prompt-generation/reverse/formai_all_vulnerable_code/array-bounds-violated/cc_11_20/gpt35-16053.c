//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_LEN 1000


int main() {

    char input[MAX_LEN]; //User input 
    char output[MAX_LEN]; //Summarized output 
    char sentences[MAX_SENTENCES][MAX_LEN]; //Array to store sentences from input 
    int freq[MAX_SENTENCES] = {0}; //Frequency of each sentence 
    int sentenceCount = 0; //Number of sentences in input 
    
    printf("Hello there! I am your happy text summarizer!\n");
    printf("Give me some text and I will summarize it for you!\n");

    //Read user input 
    printf("\nEnter your text here (max %d characters):\n", MAX_LEN);
    fgets(input, MAX_LEN, stdin);

    //Tokenize input into sentences 
    char* sentence = strtok(input, ".!?");
    while (sentence != NULL && sentenceCount < MAX_SENTENCES) {
        strcpy(sentences[sentenceCount], sentence);
        sentenceCount++;
        sentence = strtok(NULL, ".!?");
    }
    
    //Calculate frequency of each sentence 
    for (int i = 0; i < sentenceCount; i++) {
        for (int j = 0; j < sentenceCount; j++) {
            if (strstr(sentences[i], sentences[j]) != NULL) {
                freq[i]++;
            }
        }
    }

    //Select the top 3 sentences with highest frequency 
    int selected[MAX_SENTENCES] = {0};
    int selectedCount = 0;
    while (selectedCount < 3) {
        int maxFreq = -1;
        int maxIndex = -1;
        for (int i = 0; i < sentenceCount; i++) {
            if (freq[i] > maxFreq && selected[i] == 0) {
                maxFreq = freq[i];
                maxIndex = i;
            }
        }
        selected[maxIndex] = 1;
        selectedCount++;
    }

    //Concatenate the selected sentences into output 
    strcpy(output, "Here is your happy summary: ");
    for (int i = 0; i < sentenceCount; i++) {
        if (selected[i] == 1) {
            strcat(output, sentences[i]);
            strcat(output, ". ");
        }
    }

    printf("\n%s\n", output);
    printf("\nThank you for using my summary service!\nHave a happy day!\n");

    return 0;
}