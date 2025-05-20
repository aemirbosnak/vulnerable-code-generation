//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define ALIEN_VOWELS "aeiou"
#define ALIEN_CONSONANTS "bcdfghjklmnpqrstvwxyz"

char translate_alien_word(char* alien_word);
char* remove_punctuation(char* sentence);

int main() {
    char sentence[1000], translated_sentence[1000];
    int i, j = 0;
  
    printf("Enter a sentence in the alien language: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strlen(sentence)-1] = '\0'; // Removing trailing newline
  
    char* sentence_without_punctuation = remove_punctuation(sentence);
    char words[20][MAX_WORD_LENGTH];
  
    // Splitting sentence into words
    char* token = strtok(sentence_without_punctuation, " ");
    while(token != NULL) {
        strcpy(words[j], token);
        j++;
        token = strtok(NULL, " ");
    }
  
    // Translating each word in the sentence
    for(i = 0; i < j; i++)
        translated_sentence[i] = translate_alien_word(words[i]);
    translated_sentence[i] = '\0';
  
    printf("The translated sentence is:\n");
    printf("%s\n", translated_sentence);
  
    return 0;
}

char translate_alien_word(char* alien_word) {
    char translated_word[MAX_WORD_LENGTH];
    int i, vowel_found = 0, consonant_found = 0, j = 0;
  
    for(i = 0; alien_word[i] != '\0'; i++) {
        if(strchr(ALIEN_VOWELS, tolower(alien_word[i])) != NULL) {
            translated_word[j] = 'a';
            vowel_found = 1;
        }
        else if(strchr(ALIEN_CONSONANTS, tolower(alien_word[i])) != NULL) {
            translated_word[j] = 'b';
            consonant_found = 1;
        }
        else
            translated_word[j] = alien_word[i];
        j++;
    }
  
    // If no vowels or consonants are found
    if(!vowel_found && !consonant_found)
        return '\0'; 
  
    translated_word[j] = '\0';
    return translated_word[0];
}

char* remove_punctuation(char* sentence) {
    int i, j;
    char* sentence_copy = strdup(sentence);
  
    for(i = 0, j = 0; sentence_copy[i]; i++) {
        if(isalpha((unsigned char)sentence_copy[i]) || isspace((unsigned char)sentence_copy[i])) {
            sentence_copy[j++] = sentence_copy[i];
        }
    }
    sentence_copy[j] = '\0';
  
    return sentence_copy;
}