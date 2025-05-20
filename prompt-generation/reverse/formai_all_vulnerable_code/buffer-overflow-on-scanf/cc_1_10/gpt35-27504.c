//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 25

struct Word {
    char text[MAX_WORD_LEN];
    int frequency;
};

void sortWords(struct Word words[], int numWords);
int binarySearch(struct Word words[], char word[], int numWords);

int main() {
    struct Word words[MAX_WORDS];
    int numWords = 0;

    // Read input
    char input[MAX_WORD_LEN];
    while (scanf("%s", input) != EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words\n");
            return 1;
        }

        int index = binarySearch(words, input, numWords);
        if (index < 0) {
            // Word not found, add to array
            struct Word newWord = {
                .frequency = 1
            };
            strcpy(newWord.text, input);
            words[numWords++] = newWord;
        } else {
            // Word found, increment frequency
            words[index].frequency++;
        }
    }

    // Sort words by frequency
    sortWords(words, numWords);

    // Print output
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].text, words[i].frequency);
    }

    return 0;
}

void sortWords(struct Word words[], int numWords) {
    // Insertion sort
    for (int i = 1; i < numWords; i++) {
        struct Word keyWord = words[i];
        int j = i - 1;
        while (j >= 0 && words[j].frequency < keyWord.frequency) {
            words[j+1] = words[j];
            j--;
        }
        words[j+1] = keyWord;
    }
}

int binarySearch(struct Word words[], char word[], int numWords) {
    // Binary search
    int left = 0;
    int right = numWords - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(words[mid].text, word);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}