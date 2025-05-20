//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function tokenizes the input text into words
char** tokenize(char* text) {
    char** tokens = malloc(sizeof(char*) * 100);
    int numTokens = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        tokens[numTokens++] = token;
        token = strtok(NULL, " ");
    }
    return tokens;
}

// This function removes stop words from the list of tokens
char** removeStopWords(char** tokens, int numTokens) {
    char** newTokens = malloc(sizeof(char*) * numTokens);
    int numNewTokens = 0;
    for (int i = 0; i < numTokens; i++) {
        if (strcmp(tokens[i], "the") != 0 && strcmp(tokens[i], "a") != 0 && strcmp(tokens[i], "an") != 0 && strcmp(tokens[i], "and") != 0 && strcmp(tokens[i], "of") != 0) {
            newTokens[numNewTokens++] = tokens[i];
        }
    }
    return newTokens;
}

// This function stems the tokens
char** stem(char** tokens, int numTokens) {
    char** newTokens = malloc(sizeof(char*) * numTokens);
    int numNewTokens = 0;
    for (int i = 0; i < numTokens; i++) {
        // Here we would call a stemming algorithm to stem the token, but for simplicity we just copy it to the new array
        newTokens[numNewTokens++] = tokens[i];
    }
    return newTokens;
}

// This function counts the frequency of each word in the list of tokens
int* countWords(char** tokens, int numTokens) {
    int* counts = malloc(sizeof(int) * numTokens);
    for (int i = 0; i < numTokens; i++) {
        counts[i] = 0;
    }
    for (int i = 0; i < numTokens; i++) {
        for (int j = i + 1; j < numTokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                counts[i]++;
            }
        }
    }
    return counts;
}

// This function finds the top 10 most frequent words in the list of tokens
char** findTop10Words(char** tokens, int numTokens, int* counts) {
    char** top10Words = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++) {
        int maxCount = -1;
        int maxIndex = -1;
        for (int j = 0; j < numTokens; j++) {
            if (counts[j] > maxCount && strcmp(tokens[j], "") != 0) {
                maxCount = counts[j];
                maxIndex = j;
            }
        }
        if (maxIndex == -1) {
            break;
        }
        top10Words[i] = tokens[maxIndex];
        counts[maxIndex] = -1;
    }
    return top10Words;
}

// This function prints the top 10 most frequent words in the list of tokens
void printTop10Words(char** top10Words) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(top10Words[i], "") != 0) {
            printf("%s\n", top10Words[i]);
        }
    }
}

int main() {
    // Get the input text from the user
    char text[1000];
    printf("Enter the text you want to summarize: ");
    scanf("%[^\n]", text);

    // Tokenize the input text into words
    char** tokens = tokenize(text);

    // Remove stop words from the list of tokens
    tokens = removeStopWords(tokens, 100);

    // Stem the tokens
    tokens = stem(tokens, 100);

    // Count the frequency of each word in the list of tokens
    int* counts = countWords(tokens, 100);

    // Find the top 10 most frequent words in the list of tokens
    char** top10Words = findTop10Words(tokens, 100, counts);

    // Print the top 10 most frequent words in the list of tokens
    printTop10Words(top10Words);

    return 0;
}