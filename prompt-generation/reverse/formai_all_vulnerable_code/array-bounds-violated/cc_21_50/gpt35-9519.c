//FormAI DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SENTENCES 100
#define MAX_WORD_LEN 50

int main(){

    char input[MAX_INPUT_SIZE], sentences[MAX_SENTENCES][MAX_INPUT_SIZE], words[MAX_WORD_LEN][MAX_WORD_LEN];
    int i, j, k, sentence_count, word_count, word_length[MAX_WORD_LEN], count[MAX_WORD_LEN], max_index, max_count, max_length, paranoid_count;

    printf("Enter text to be summarized:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Break the input text into sentences
    i = 0;
    sentence_count = 0;
    while(input[i] != '\0'){
        if(input[i] == '.' || input[i] == '?' || input[i] == '!'){
            sentences[sentence_count][i] = input[i];
            sentences[sentence_count][i+1] = '\0';
            sentence_count++;
            i++;
        }
        else{
            sentences[sentence_count][i] = input[i];
            i++;
        }
    }

    // Break each sentence into words
    for(i = 0; i < sentence_count; i++){
        j = 0;
        word_count = 0;
        while(sentences[i][j] != '\0'){
            if(sentences[i][j] == ' ' || sentences[i][j] == '\n'){
                words[word_count][k] = '\0';
                word_count++;
                j++;
                k = 0;
            }
            else{
                words[word_count][k] = sentences[i][j];
                k++;
                j++;
            }
        }
        words[word_count][k] = '\0';
        word_count++;
        word_length[i] = word_count;
    }

    // Find the most repeated word in each sentence
    for(i = 0; i < sentence_count; i++){
        memset(count, 0, sizeof(count)); // Initialize the count array with 0s
        for(j = 0; j < word_length[i]; j++){
            for(k = 0; k < word_length[i]; k++){
                if(strcmp(words[j], words[k]) == 0){
                    count[j]++;
                }
            }
        }
        max_count = 0;
        max_index = 0;
        for(j = 0; j < word_length[i]; j++){
            if(count[j] > max_count){
                max_count = count[j];
                max_index = j;
            }
        }
        paranoid_count += max_count;
        max_length = strlen(words[max_index]);
        strncpy(words[max_index], "", MAX_WORD_LEN); // Remove the most repeated word from the array
    }

    // Calculate the threshold value
    float threshold = paranoid_count * 0.1;

    // Print the summarized text
    paranoid_count = 0;
    for(i = 0; i < sentence_count; i++){
        memset(count, 0, sizeof(count)); // Initialize the count array with 0s
        for(j = 0; j < word_length[i]; j++){
            for(k = 0; k < word_length[i]; k++){
                if(strcmp(words[j], words[k]) == 0){
                    count[j]++;
                }
            }
        }
        max_count = 0;
        max_index = 0;
        for(j = 0; j < word_length[i]; j++){
            if(count[j] > max_count){
                max_count = count[j];
                max_index = j;
            }
        }
        paranoid_count += max_count;
        if(paranoid_count >= threshold){
            printf("%s", sentences[i]);
            paranoid_count = 0;
        }
    }

    return 0;
}