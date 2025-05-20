//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_DIGITS 10

// Function to convert a string to uppercase
void toUpper(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to remove duplicates from a string
void removeDups(char *str) {
    int i, j;
    char temp[MAX_LENGTH];
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            temp[j] = str[i];
            j++;
        }
    }
    str[0] = '\0';
    for (i = 0; i < j; i++) {
        str[i] = temp[i];
    }
}

// Function to extract the most frequent word from a string
char *getMostFrequentWord(char *str) {
    int i, j, count[MAX_LENGTH];
    char mostFrequentWord[MAX_LENGTH];
    for (i = 0; str[i] != '\0'; i++) {
        count[0] = 1;
        for (j = 1; j < MAX_LENGTH; j++) {
            if (str[i] == str[j]) {
                count[j]++;
            }
        }
        mostFrequentWord[0] = str[i];
        mostFrequentWord[1] = count[0];
        for (j = 1; j < MAX_LENGTH; j++) {
            if (count[j] > mostFrequentWord[1]) {
                mostFrequentWord[1] = count[j];
                mostFrequentWord[2] = str[j];
            }
        }
    }
    return mostFrequentWord;
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter a text: ");
    fgets(text, MAX_LENGTH, stdin);
    toUpper(text);
    removeDups(text);
    char *mostFrequentWord = getMostFrequentWord(text);
    printf("The most frequent word in the text is: %s\n", mostFrequentWord);
    return 0;
}