//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Dictionary { char words[100]; };

int main()
{
    FILE *fp;
    char dictionary_file[100], text_file[100], temp_word[20], temp_chr;
    int i, j, k, len, isMatched;

    struct Dictionary dict[10000];

    // Read dictionary file
    printf("Enter dictionary file name: ");
    scanf("%s", dictionary_file);

    fp = fopen(dictionary_file, "r");
    if(fp == NULL) {
        printf("Failed to open the file.\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while(fgets(dict[i].words, 100, fp)) {
        len = strlen(dict[i].words);
        dict[i].words[len - 1] = '\0';
        i++;
    }

    fclose(fp);

    // Read text file
    printf("\nEnter text file name: ");
    scanf("%s", text_file);

    fp = fopen(text_file, "r");
    if(fp == NULL) {
        printf("Failed to open the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("\n------Misspelled Words------\n");

    while(fscanf(fp, "%s", temp_word) == 1) {
        len = strlen(temp_word);
        isMatched = 0;

        // Remove punctuation marks
        for(i = 0; i < len; i++) {
            temp_chr = temp_word[i];
            if(ispunct(temp_chr)) {
                for(j = i; j < len; j++) {
                    temp_word[j] = temp_word[j+1];
                }
                len--;
                i--;
            }
        }

        // Convert to lower case
        for(i = 0; i < len; i++) {
            temp_word[i] = tolower(temp_word[i]);
        }

        // Check if the word is in the dictionary
        for(j = 0; j < i; j++) {
            if(strcmp(temp_word, dict[j].words) == 0) {
                isMatched = 1;
                break;
            }
        }

        if(!isMatched) {
            printf("%s\n", temp_word);
        }
    }

    fclose(fp);

    return 0;
}