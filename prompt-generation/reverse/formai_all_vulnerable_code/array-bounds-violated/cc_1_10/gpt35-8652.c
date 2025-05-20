//FormAI DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_punct_char(char c) {
    return ispunct(c) && c != '\'' && c != '-';
}

int main() {
    char* dictionary[] = {"hi", "hello", "goodbye", "farewell", "love", "hate", "death", "life", "night", "day"};
    int dict_size = sizeof(dictionary) / sizeof(dictionary[0]);

    printf("Please enter a sentence to spell check:\n");
    char sentence[100];
    fgets(sentence, 100, stdin);

    int sentence_length = strlen(sentence);
    if(sentence[sentence_length-1] == '\n') {
        sentence[sentence_length-1] = '\0';
        sentence_length--;
    }

    char* sentence_words[20];
    int num_words = 0;
    char* token = strtok(sentence, " ");
    while(token != NULL) {
        sentence_words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }

    int i;
    for(i = 0; i < num_words; i++) {
        int j;
        int is_word_in_dict = 0;
        for(j = 0; j < dict_size; j++) {
            if(strcmp(sentence_words[i], dictionary[j]) == 0) {
                is_word_in_dict = 1;
            }
        }
        if(!is_word_in_dict) {
            printf("\nRomeo: Oh, pardon me, thou misguided swain,\nThat hath not learned of word's proper rein.\nFor, '%s' is not a word in fair dictionary's rule,\nAnd thusly conveys a meaning quite the fool.\n", sentence_words[i]);

            int k;
            printf("Juliet: Nay, methinks thou art in error,\nFor '%s' didst come from my heart's amour.\n", sentence_words[i]);
            printf("Romeo: Good Juliet, thine heart is true,\nBut 'tis not enough to spell the word anew.\n");

            int word_length = strlen(sentence_words[i]);
            char corrected_word[word_length];
            int num_letters_different = 0;
            for(k = 0; k < word_length; k++) {
                corrected_word[k] = tolower(sentence_words[i][k]);
            }
            for(k = 0; k < dict_size; k++) {
                char* dict_word = dictionary[k];
                int dict_word_length = strlen(dict_word);
                if(dict_word_length == word_length) {
                    int num_letters_match = 0;
                    int l;
                    for(l = 0; l < dict_word_length; l++) {
                        if(tolower(dict_word[l]) == corrected_word[l]) {
                            num_letters_match++;
                        }
                    }
                    if(num_letters_match == word_length) {
                        is_word_in_dict = 1;
                        printf("Juliet: O, I shall remember now,\nT'was '%s' that graced my heart's vow.\n", dict_word);
                        strcpy(sentence_words[i], dict_word);
                        break;
                    }
                    else if(num_letters_match == word_length - 1) {
                        num_letters_different++;
                        if(num_letters_different == 1) {
                            printf("Romeo: Hark, what light through yonder window breaks,\nIt is the semblance of '%s', which thy word remakes.\n", dict_word);
                        }
                        else {
                            printf("Romeo: Nay, '%s' art not the desired word,\nFor there are letters missing, as absurd.\n", dict_word);
                        }
                    }
                }
            }
            if(!is_word_in_dict) {
                printf("Juliet: Alas, I know not the word thy heart did mean,\nHow could our love's bond ever reconvene?\n");
            }
        }
    }

    printf("\nThou hath spake like a true scholar,\nAnd shackled tight the chains of grammar's dollar.\n");
    printf("With love's true words to guide us on,\nOur story shall last until the morning dawn.\n");

    return 0;
}