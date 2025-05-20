//FormAI DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 500

// Function to remove punctuation from the given string
void removePunctuations(char *str){
    int i, len;
    len = strlen(str);

    for(i=0;i<len;i++){
        if(str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':' || str[i] == '!' || str[i] == '?'){
            str[i] = '\0';
        }
    }
}

// Function to convert all characters to lowercase in the given string
void toLower(char *str){
    int i, len;
    len = strlen(str);

    for(i=0;i<len;i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

// Function to find the number of occurrences of a word in a given string
int findOccurrences(char *str, char *word){
    int i, j, count, len1, len2;
    count = 0;
    len1 = strlen(str);
    len2 = strlen(word);

    for(i=0;i<=len1-len2;i++){
        for(j=0;j<len2;j++){
            if(str[i+j] != word[j]){
                break;
            }
        }
        if(j == len2){
            count++;
        }
    }
    return count;
}

// Function to calculate the score of each sentence in the given text
void sentenceScore(char *text, char *word, float score[]){
    int i, j, k, len1, len2, count;
    char sentence[50][MAX_SIZE];
    float tempScore;

    len1 = strlen(text);
    len2 = strlen(word);

    i = j = 0;
    for(k=0;k<=len1;k++){
        if(text[k] == '.' || text[k] == '\0'){
            sentence[i][j] = '.';
            sentence[i][j+1] = '\0';
            i++;
            j=0;
        }
        else{
            sentence[i][j] = text[k];
            j++;
        }
    }

    for(i=0;i<=strlen(text);i++){
        score[i] = 0;
        removePunctuations(sentence[i]);
        toLower(sentence[i]);
        count = findOccurrences(sentence[i], word);

        // Calculate score of a sentence
        for(j=0;j<strlen(sentence[i]);j++){
            if(sentence[i][j] != ' '){
                score[i] = score[i] + (count*0.5);
                break;
            }
        }

        // Calculate score by comparing words in the sentence with the given word
        for(j=0;j<strlen(sentence[i]);j++){
            if(sentence[i][j] == ' '){
                tempScore = findOccurrences(&sentence[i][j+1], word);
                if(tempScore>0){
                    score[i] = score[i] + (tempScore*0.5);
                }
            }
        }
    }
}

// Function to print the summary of the given text
void printSummary(char *text, char *word, float threshold){
    float score[MAX_SIZE], maxScore;
    int i, j, len1;
    char sentence[50][MAX_SIZE];

    sentenceScore(text, word, score);

    len1 = strlen(text);

    j = 0;
    for(i=0;i<=len1;i++){
        if(text[i] == '.' || text[i] == '\0'){
            sentence[j][0] = text[i];
            sentence[j][1] = '\0';
            j++;
        }
        else{
            sentence[j][strnlen(sentence[j], MAX_SIZE)] = text[i];
        }
    }

    // Find maximum score
    maxScore = 0;
    for(i=0;i<j;i++){
        if(score[i] > maxScore){
            maxScore = score[i];
        }
    }

    // Print sentences with score greater than threshold
    for(i=0;i<j;i++){
        if(score[i] >= (threshold*maxScore)){
            printf("%s", sentence[i]);
        }
    }
}

// Main function
int main(){
    char text[MAX_SIZE], word[MAX_SIZE];
    float threshold;

    printf("Enter the text to summarize: ");
    fgets(text, MAX_SIZE, stdin);

    printf("Enter the word to summarize about: ");
    scanf("%s", word);

    printf("Enter the threshold score: ");
    scanf("%f", &threshold);

    printf("\nSummary:\n");
    printSummary(text, word, threshold);

    return 0;
}