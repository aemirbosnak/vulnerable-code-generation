//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of tokens in a string
int countTokens(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to print the frequency of each token in a string
void printFrequency(char* str) {
    int freq[256] = {0};
    char* token = strtok(str, " ");
    while (token!= NULL) {
        freq[(int)token[0]]++;
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

// Function to print the most common token in a string
void printMostCommon(char* str) {
    int maxFreq = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        int freq = countTokens(token);
        if (freq > maxFreq) {
            maxFreq = freq;
        }
        token = strtok(NULL, " ");
    }
    printf("Most common token: %s\n", strtok(str, " "));
    printf("Frequency: %d\n", maxFreq);
}

// Function to print the least common token in a string
void printLeastCommon(char* str) {
    int minFreq = 1000000;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        int freq = countTokens(token);
        if (freq < minFreq) {
            minFreq = freq;
        }
        token = strtok(NULL, " ");
    }
    printf("Least common token: %s\n", strtok(str, " "));
    printf("Frequency: %d\n", minFreq);
}

// Main function
int main() {
    char* str = "The quick brown fox jumps over the lazy dog";
    printf("String: %s\n", str);
    printFrequency(str);
    printMostCommon(str);
    printLeastCommon(str);
    return 0;
}