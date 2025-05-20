//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: detailed
// Text Summarizer Example Program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_WORD_LEN 100

// Function to tokenize the text
char** tokenize(char* text, int* count) {
    char** tokens = malloc(MAX_SENTENCES * sizeof(char*));
    char* token = strtok(text, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    *count = i;
    return tokens;
}

// Function to remove punctuation
char* remove_punctuation(char* word) {
    char* punctuation = "!@#$%^&*()_+-=[]{}|;':\"<>,./?";
    int i;
    for (i = 0; i < strlen(punctuation); i++) {
        word = strchr(word, punctuation[i]);
        if (word != NULL) {
            word[0] = '\0';
        }
    }
    return word;
}

// Function to remove stop words
char* remove_stop_words(char* word) {
    char* stop_words[] = {"the", "and", "a", "to", "in", "for", "with", "of"};
    int i;
    for (i = 0; i < sizeof(stop_words) / sizeof(stop_words[0]); i++) {
        if (strcmp(word, stop_words[i]) == 0) {
            word[0] = '\0';
        }
    }
    return word;
}

// Function to stem the word
char* stem_word(char* word) {
    char* suffixes[] = {"ing", "ly", "s", "ed", "er"};
    int i;
    for (i = 0; i < sizeof(suffixes) / sizeof(suffixes[0]); i++) {
        int len = strlen(word);
        if (len > strlen(suffixes[i]) && strcmp(word + len - strlen(suffixes[i]), suffixes[i]) == 0) {
            word[len - strlen(suffixes[i])] = '\0';
        }
    }
    return word;
}

// Function to compute the TF-IDF score
float tfidf(char* word, int count) {
    // Compute the TF score
    float tf = (float)count / (float)MAX_WORD_LEN;

    // Compute the IDF score
    float idf = log((float)MAX_SENTENCES / (float)count);

    // Compute the TF-IDF score
    float tfidf = tf * idf;

    return tfidf;
}

// Function to sort the words by TF-IDF score
void sort_words(char** words, int count) {
    int i, j;
    char* temp;
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (tfidf(words[j], count) < tfidf(words[j + 1], count)) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

// Function to extract the most important words
char** extract_words(char* text, int count) {
    char** words = malloc(MAX_SENTENCES * sizeof(char*));
    int i;
    for (i = 0; i < count; i++) {
        words[i] = malloc(MAX_WORD_LEN * sizeof(char));
        strcpy(words[i], text[i]);
    }
    return words;
}

// Main function
int main() {
    // Read the text from the user
    char text[MAX_SENTENCES][MAX_WORD_LEN];
    int count = 0;
    while (1) {
        char sentence[MAX_WORD_LEN];
        scanf("%s", sentence);
        if (strcmp(sentence, ".") == 0) {
            break;
        }
        strcpy(text[count++], sentence);
    }

    // Tokenize the text
    char** tokens = tokenize(text, &count);

    // Remove punctuation
    for (int i = 0; i < count; i++) {
        tokens[i] = remove_punctuation(tokens[i]);
    }

    // Remove stop words
    for (int i = 0; i < count; i++) {
        tokens[i] = remove_stop_words(tokens[i]);
    }

    // Stem the words
    for (int i = 0; i < count; i++) {
        tokens[i] = stem_word(tokens[i]);
    }

    // Compute the TF-IDF score
    for (int i = 0; i < count; i++) {
        tfidf(tokens[i], count);
    }

    // Sort the words by TF-IDF score
    sort_words(tokens, count);

    // Extract the most important words
    char** important_words = extract_words(tokens, count);

    // Print the most important words
    for (int i = 0; i < count; i++) {
        printf("%s\n", important_words[i]);
    }

    // Free the memory
    free(tokens);
    free(important_words);

    return 0;
}