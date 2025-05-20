//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

struct wordCount{
    char word[MAX_LEN];
    int count;
};

int main(int argc, char *argv[]){
    // Get the input text
    char text[MAX_WORDS][MAX_LEN];
    int wordCount = 0;
    printf("Enter the text: ");
    fgets(text[wordCount],MAX_LEN,stdin);
    while(strcmp(text[wordCount],"\n")!=0){
        wordCount++;
        fgets(text[wordCount],MAX_LEN,stdin);
    }

    // Find the frequency of each word
    struct wordCount frequency[MAX_WORDS];
    int frequencyCount = 0;
    for(int i=0;i<wordCount;i++){
        char temp[MAX_LEN];
        strcpy(temp,text[i]);
        int len = strlen(temp);
        if(temp[len-1] == '\n')
            temp[len-1] = '\0';

        int flag = 0;
        for(int j=0;j<frequencyCount;j++){
            if(strcmp(frequency[j].word,temp) == 0){
                frequency[j].count++;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            strcpy(frequency[frequencyCount].word,temp);
            frequency[frequencyCount].count = 1;
            frequencyCount++;
        }
    }

    // Find total number of words and positive words
    int totalWords = 0, positiveWords = 0;
    for(int i=0;i<frequencyCount;i++){
        if(isalpha(frequency[i].word[0])){
            totalWords += frequency[i].count;

            FILE* fp = fopen("positive.txt","r");
            char word[MAX_LEN];
            while(fscanf(fp,"%s",word) == 1){
                if(strcmp(word,frequency[i].word) == 0){
                    positiveWords += frequency[i].count;
                    break;
                }
            }
            fclose(fp);
        }
    }

    // Calculate positivity score
    float positivityScore = ((float)positiveWords/totalWords)*100;

    printf("Positivity score: %.2f %%\n",positivityScore);

    return 0;
}