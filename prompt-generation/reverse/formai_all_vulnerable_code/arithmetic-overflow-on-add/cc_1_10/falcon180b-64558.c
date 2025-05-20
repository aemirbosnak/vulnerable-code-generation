//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove non-alphabetic characters from a string
void removeNonAlpha(char* str) {
    int i = 0;
    while (*str) {
        if (isalpha(*str)) {
            str[i++] = tolower(*str);
        }
        str++;
    }
    str[i] = '\0';
}

// Function to calculate the frequency of words in a string
void calcWordFreq(char* str, int* freqTable) {
    char* word;
    int i = 0;
    while ((word = strtok(str, " "))!= NULL) {
        removeNonAlpha(word);
        freqTable[i++]++;
    }
}

// Function to compare the frequency of words in two strings
int compareWordFreq(int* freqTable1, int* freqTable2) {
    int i, j;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (freqTable1[i]!= freqTable2[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to classify a message as spam or not-spam
int classifyMessage(char* message) {
    int freqTable[26];
    calcWordFreq(message, freqTable);
    int i;
    for (i = 0; i < 26; i++) {
        if (freqTable[i] > 5) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[1000];
    printf("Enter a message:\n");
    fgets(message, sizeof(message), stdin);

    if (classifyMessage(message)) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}