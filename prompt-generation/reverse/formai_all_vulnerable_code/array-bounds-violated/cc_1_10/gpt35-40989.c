//FormAI DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LEN 1000
#define MAX_SENTENCES 100

int main(){
    char text[MAX_TEXT_LEN], sentence[MAX_SENTENCES][MAX_TEXT_LEN];
    int i, j, k, n, len, sentenceCount = 0;

    printf("Enter the text to be summarized:\n");
    fgets(text, MAX_TEXT_LEN, stdin);

    //split text into sentences
    for(i = 0; i < strlen(text)-1; i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            sentenceCount++;
            n = 0;
        }
        else{
            sentence[sentenceCount][n] = text[i];
            n++;
        }
    }

    //calculate length of each sentence
    int sentenceLength[sentenceCount];
    for(i = 0; i < sentenceCount; i++){
        len = strlen(sentence[i]);
        sentenceLength[i] = len;
    }

    //sort sentences based on length
    for(i = 0; i < sentenceCount-1; i++){
        for(j = i+1; j < sentenceCount; j++){
            if(sentenceLength[i] > sentenceLength[j]){
                //swap the sentence
                char temp[MAX_TEXT_LEN];
                strcpy(temp, sentence[i]);
                strcpy(sentence[i], sentence[j]);
                strcpy(sentence[j], temp);

                //swap the sentence length
                int tempLen = sentenceLength[i];
                sentenceLength[i] = sentenceLength[j];
                sentenceLength[j] = tempLen;
            }
        }
    }

    //print the summary
    printf("Summary:\n");
    for(i = 0; i < sentenceCount/2; i++){
        printf("%s", sentence[i]);
    }

    return 0;
}