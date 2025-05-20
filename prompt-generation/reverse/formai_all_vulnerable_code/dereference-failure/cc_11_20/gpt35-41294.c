//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a word structure to store the word */
typedef struct{
    char* word;
    int length;
} Word;

/* Function to compare two words for sorting purposes */
int compareWords(const void* a, const void* b){
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

int main(){
    char input[1000]; // Buffer to store user input
    int i, j, k, length, foundMistake; // Variables for looping and checking
    Word* words = NULL; // Array to store all the words
    int nWords = 0; // Number of words read

    /* Read input from user */
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    /* Split the input into words */
    i = 0;
    while(input[i] != '\0'){
        /* Ignore punctuation marks and spaces */
        while(input[i] == ' ' || input[i] == '.' || input[i] == ',' || input[i] == '!' || input[i] == '?'){
            i++;
        }
        /* Start reading the word */
        j = i;
        while(input[j] != ' ' && input[j] != '.' && input[j] != ',' && input[j] != '!' && input[j] != '?' && input[j] != '\0'){
            j++;
        }
        /* Allocate memory for the word */
        length = j - i;
        if(length > 0){
            words = (Word*)realloc(words, (nWords+1)*sizeof(Word));
            words[nWords].word = (char*)malloc((length+1)*sizeof(char));
            strncpy(words[nWords].word, input+i, length);
            words[nWords].word[length] = '\0';
            words[nWords].length = length;
            nWords++;
        }
        i = j;
    }

    /* Sort the words alphabetically */
    qsort(words, nWords, sizeof(Word), compareWords);

    /* Check each word for spelling mistakes */
    printf("Spelling mistakes:\n");
    for(i=0; i<nWords; i++){
        foundMistake = 0;
        /* Check each character in the word */
        for(j=0; j<words[i].length; j++){
            /* Convert to lowercase for easier comparison */
            if(words[i].word[j] >= 'A' && words[i].word[j] <= 'Z'){
                words[i].word[j] += 'a' - 'A';
            }
            /* Check if character is a letter */
            if(words[i].word[j] < 'a' || words[i].word[j] > 'z'){
                foundMistake = 1;
                break;
            }
        }
        /* If word contains a mistake, print it */
        if(foundMistake){
            printf("%s\n", words[i].word);
        }
    }

    /* Free memory */
    for(i=0; i<nWords; i++){
        free(words[i].word);
    }
    free(words);

    return 0;
}