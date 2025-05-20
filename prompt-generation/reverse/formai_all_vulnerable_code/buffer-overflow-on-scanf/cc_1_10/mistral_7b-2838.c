//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 256

// Function to calculate hash value for a given word
unsigned long long hash(char *word) {
    unsigned long long hash = 5381;
    int c;

    while ((c = *word++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 1000003;
}

// Function to count words in a given string
int countWords(char *str) {
    int count = 0;
    char word[WORD_SIZE];

    strcpy(word, str);
    unsigned long long currentHash = hash(word);

    while (*str != '\0') {
        char c = *str++;

        if (c == ' ' || c == '\n' || c == '\t') {
            str -= 1; // Go back to the previous character

            if (strlen(word) > 0) {
                count++;
                unsigned long long nextHash = hash(word);

                if (currentHash != nextHash) {
                    currentHash = nextHash;
                    strcpy(word, "");
                }
            }
        } else {
            strncat(word, &c, 1);
        }
    }

    if (strlen(word) > 0)
        count++;

    return count;
}

int main() {
    char *input;
    int size, count;

    printf("Enter the string to count words: ");
    scanf("%d", &size);

    input = (char *)malloc(size * sizeof(char));

    printf("Enter the string: ");
    fgets(input, size, stdin);

    count = countWords(input);
    printf("Number of words: %d\n", count);

    free(input);

    return 0;
}