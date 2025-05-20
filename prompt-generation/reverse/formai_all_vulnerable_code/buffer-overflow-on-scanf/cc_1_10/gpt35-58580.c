//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    char input_file[100];
    char *word_list[10000] = {NULL};
    int word_count[10000] = {0};
    int total_words = 0;

    // Ask user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    FILE *fp = fopen(input_file, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    // Read words from file and count them
    char temp_word[100];
    while(fscanf(fp, "%s", temp_word) == 1) {
        // Convert word to lowercase
        for(int i=0; temp_word[i]!=0; i++) {
            temp_word[i] = tolower(temp_word[i]);
        }

        int found = 0;
        for(int i=0; i<total_words; i++) {
            if(word_list[i] != NULL && strcmp(temp_word, word_list[i]) == 0) {
                // Word already in word_list, increment count
                word_count[i]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            // Word not found in word_list, add to end
            word_list[total_words] = strdup(temp_word);
            word_count[total_words] = 1;
            total_words++;
        }
    }

    // Print word counts
    for(int i=0; i<total_words; i++) {
        printf("%s: %d\n", word_list[i], word_count[i]);
        free(word_list[i]);
    }

    fclose(fp);

    return 0;
}