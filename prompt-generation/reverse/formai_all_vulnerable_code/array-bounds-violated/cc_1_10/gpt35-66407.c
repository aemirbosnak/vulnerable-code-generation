//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

int main() {
    char sentence[MAX_WORDS * MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int num_words = 0;
    int i, j, k;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove new line character
    if(sentence[strlen(sentence) - 1] == '\n')
        sentence[strlen(sentence) - 1] = '\0';

    // Split sentence into words
    for(i = 0, j = 0; i <= strlen(sentence); i++){
        if(sentence[i] == ' ' || sentence[i] == '\0'){
            // End of word
            word[j] = '\0';
            
            // Check if word is already counted
            for(k = 0; k < num_words; k++){
                if(strcmp(word, &sentence[counts[k]]) == 0){
                    // Match found
                    counts[k]++;
                    break;
                }
            }

            // New word found
            if(k == num_words){
                counts[k] = 1;
                num_words++;
                strcpy(&sentence[num_words * MAX_WORD_LENGTH], word);
            }

            j = 0;
        } else {
            // Add to word
            word[j++] = sentence[i];
        }
    }

    // Print word count
    printf("\nWord Count:\n");
    for(i = 0; i < num_words; i++){
        printf("%s: %d\n", &sentence[counts[i]], counts[i]);
    }

    return 0;
}