//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compare the frequency count of two words
int compare(const void *a, const void *b) {
    int *count1 = (int *) a;
    int *count2 = (int *) b;
    return (*count2 - *count1);
}

int main() {
    char words[50][50]; // Array to store 50 words of maximum 50 length

    int freq[50]; // Array to store the frequency count

    int i, j, k, count, n;

    printf("Enter the number of words (max 50): ");
    scanf("%d", &n);

    // Reading n words from user and counting their frequency
    for (i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);

        // Converting word to lower case
        for (j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }

        freq[i] = 1; // Initializing the frequency count to 1

        // Counting the frequency of each word
        for (k = i + 1; k < n; k++) {
            if (strcmp(words[i], words[k]) == 0) {
                freq[i]++;
            }
        }
    }

    // Sorting the words based on their frequency count
    qsort(freq, n, sizeof(int), compare);

    // Displaying the words in multiplayer style with their frequency count
    printf("\nFrequency Counter:\n");
    printf("|%16s|%16s|\n", "Words", "Frequency");

    for (i = 0; i < n; i += 2) {
        printf("|%16s|%16d|", words[i], freq[i]);
        // If there is an odd number of words, display the last word separately
        if (i == n - 1 && n % 2 == 1) {
            printf("\n|%16s|%16d|", words[i], freq[i]);
        } else {
            printf("%16s|%16d|\n", words[i+1], freq[i+1]);
        }
    }

    return 0;
}