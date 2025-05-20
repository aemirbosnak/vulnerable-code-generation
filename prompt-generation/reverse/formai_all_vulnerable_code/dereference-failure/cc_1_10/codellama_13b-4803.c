//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
// Sentiment Analysis Tool in Paranoid Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to store the sentiment of a word
struct Sentiment {
    char word[20];
    int sentiment;
};

// Define an array of structs to store all the words and their sentiments
struct Sentiment words[100];

// Define a function to read in the words and their sentiments from a file
void read_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *word = strtok(line, " ");
        if (word == NULL) {
            break;
        }
        strcpy(words[i].word, word);
        words[i].sentiment = atoi(strtok(NULL, " "));
        i++;
    }

    fclose(fp);
}

// Define a function to analyze the sentiment of a string
int analyze_sentiment(char *str) {
    int sentiment = 0;
    char *word = strtok(str, " ");
    while (word != NULL) {
        int i = 0;
        while (words[i].word[0] != '\0') {
            if (strcmp(words[i].word, word) == 0) {
                sentiment += words[i].sentiment;
                break;
            }
            i++;
        }
        word = strtok(NULL, " ");
    }
    return sentiment;
}

int main(int argc, char *argv[]) {
    // Check if the input file is provided
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    // Read in the words and their sentiments from the file
    read_words(argv[1]);

    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    // Analyze the sentiment of the string
    int sentiment = analyze_sentiment(str);
    printf("The sentiment of the string is %d\n", sentiment);

    return 0;
}