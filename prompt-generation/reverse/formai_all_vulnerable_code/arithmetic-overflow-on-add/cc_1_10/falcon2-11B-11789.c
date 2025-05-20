//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 1000

int main() {
    char data[MAX_LEN];
    int i, j;

    printf("Enter data: ");
    fgets(data, MAX_LEN, stdin);

    // Remove trailing newline character
    data[strcspn(data, "\n")] = '\0';

    // Split data into individual words
    char *words[100];
    for (i = 0; i < strlen(data); i++) {
        char *word = strtok(data + i, " ");
        words[i] = word;
    }

    // Count occurrences of each word
    int word_count[100];
    for (i = 0; i < strlen(data); i++) {
        word_count[strtol(words[i], NULL, 10)]++;
    }

    // Sort words by frequency
    for (i = 0; i < strlen(data); i++) {
        for (j = i + 1; j < strlen(data); j++) {
            if (word_count[strtol(words[i], NULL, 10)] < word_count[strtol(words[j], NULL, 10)]) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
                int temp_count = word_count[strtol(words[i], NULL, 10)];
                word_count[strtol(words[i], NULL, 10)] = word_count[strtol(words[j], NULL, 10)];
                word_count[strtol(words[j], NULL, 10)] = temp_count;
            }
        }
    }

    // Print sorted words
    printf("Sorted words by frequency:\n");
    for (i = 0; i < strlen(data); i++) {
        printf("%s - %d\n", words[i], word_count[strtol(words[i], NULL, 10)]);
    }

    return 0;
}