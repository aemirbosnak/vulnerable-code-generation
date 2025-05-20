//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 100

//function to remove punctuations from the input string
void removePunctuation(char *input){
    int i, j = 0;
    for(i = 0; input[i] != '\0'; i++){
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == ' '){
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

//function to convert all characters to lowercase
void convertToLowercase(char *input){
    int i;
    for(i = 0; input[i] != '\0'; i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = input[i] + 32;
        }
    }
}

//function to remove all duplicate words from the input string
void removeDuplicates(char *input){
    int i, j, k;
    for(i = 0; input[i] != '\0'; i++){
        for(j = i + 1; input[j] != '\0'; j++){
            if(input[i] == input[j]){
                for(k = j; input[k] != '\0'; k++){
                    input[k] = input[k + 1];
                }
                input[k] = '\0';
                j--;
            }
        }
    }
}

//function to count the number of occurrences of each word in the input string
void countWords(char *input, char words[][MAX_INPUT_SIZE], int frequency[]){
    int i, j, wordCount = 0;
    char temp[MAX_INPUT_SIZE];
    for(i = 0; input[i] != '\0'; i++){
        if(input[i] == ' '){
            temp[wordCount] = '\0';
            strcpy(words[wordCount], temp);
            wordCount++;
            j = 0;
        }
        else{
            temp[j] = input[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(words[wordCount], temp);
    wordCount++;

    int count;
    for(i = 0; i < wordCount; i++){
        count = 1;
        for(j = i + 1; j < wordCount; j++){
            if(strcmp(words[i], words[j]) == 0){
                count++;
                frequency[j] = -1;
            }
        }
        if(frequency[i] != -1){
            frequency[i] = count;
        }
    }
}

//function to get the most frequent words in the input string
void getMostFrequentWords(char *input, char result[][MAX_OUTPUT_SIZE], int count){
    int i, j, k, l, wordCount = 0;
    char words[MAX_INPUT_SIZE][MAX_INPUT_SIZE];
    int frequency[MAX_INPUT_SIZE] = {0};

    removePunctuation(input);
    convertToLowercase(input);
    removeDuplicates(input);

    countWords(input, words, frequency);
    for(i = 0; i < count; i++){
        int max = -1;
        char maxWord[MAX_INPUT_SIZE];
        for(j = 0; j < strlen(input); j++){
            if(frequency[j] > max){
                max = frequency[j];
                strcpy(maxWord, words[j]);
            }
        }
        int flag = 0;
        for(k = 0; k < wordCount; k++){
            if(strcmp(result[k], maxWord) == 0){
                flag = 1;
            }
        }
        if(flag == 0){
            strcpy(result[wordCount], maxWord);
            wordCount++;
        }
        frequency[strlen(input)] = -1; 
    }
}

int main(){
    char input[MAX_INPUT_SIZE];
    char result[MAX_OUTPUT_SIZE][MAX_OUTPUT_SIZE];
    int i;
    printf("Enter the text to be summarized: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    printf("\n");

    getMostFrequentWords(input, result, 5);

    printf("Summary:\n");
    for(i = 0; i < 5; i++){
        printf("%d. %s\n", i + 1, result[i]);
    }

    return 0;
}