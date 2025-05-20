//Falcon-180B DATASET v1.0 Category: Text processing ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000

struct word_count {
    char word[50];
    int count;
};

int main() {
    FILE *file;
    char line[100];
    int i, j;
    struct word_count *words = (struct word_count *)malloc(MAX_WORDS*sizeof(struct word_count));
    int num_words = 0;

    // Open file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Convert to lowercase
        for (i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize line into words
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            // Check if word is already in array
            for (j = 0; j < num_words; j++) {
                if (strcmp(token, words[j].word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            // Add new word to array
            if (j == num_words) {
                strcpy(words[num_words].word, token);
                words[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    // Close file
    fclose(file);

    // Sort array by word count
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[i].count < words[j].count) {
                struct word_count temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print top 10 words
    printf("Top 10 most frequent words:\n");
    for (i = 0; i < 10 && i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free memory
    free(words);

    return 0;
}