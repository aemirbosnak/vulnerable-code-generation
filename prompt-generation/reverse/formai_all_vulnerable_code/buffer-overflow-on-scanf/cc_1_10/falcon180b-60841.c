//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 200
#define MAX_NUM_WORDS 1000

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, ",.?!;:");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }

    return count;
}

// Function to print the top n words in a string
void printTopWords(char* str, int n) {
    int i = 0;
    char* word = strtok(str, ",.?!;:");

    while (word!= NULL && i < n) {
        printf("%s ", word);
        i++;
        word = strtok(NULL, ",.?!;:");
    }
}

// Function to print the frequency of each word in a string
void printWordFrequency(char* str) {
    int freq[MAX_NUM_WORDS] = {0};
    char* word = strtok(str, ",.?!;:");

    while (word!= NULL) {
        int index = 0;
        while (index < MAX_NUM_WORDS && freq[index]!= 0) {
            index++;
        }

        if (index < MAX_NUM_WORDS) {
            freq[index] = 1;
        } else {
            printf("Error: Maximum number of words exceeded\n");
        }

        word = strtok(NULL, ",.?!;:");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        if (freq[i]!= 0) {
            printf("%s : %d\n", str, freq[i]);
        }
    }
}

int main() {
    char str[MAX_WORD_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    int numWords = countWords(str);
    printf("\nTotal number of words: %d\n", numWords);

    printf("Enter the number of top words to print: ");
    int n;
    scanf("%d", &n);

    printTopWords(str, n);

    printWordFrequency(str);

    return 0;
}