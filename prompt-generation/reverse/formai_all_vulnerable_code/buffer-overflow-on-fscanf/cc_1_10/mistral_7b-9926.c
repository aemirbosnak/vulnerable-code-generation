//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
//***************************************************************************
//*                                                                         *
//*                       C TYPING SPEED TEST                               *
//*                                                                         *
//***************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

// Function to generate random words
void generate_words(char words[MAX_WORDS][WORD_LENGTH]) {
    int i;
    FILE *fp;

    fp = fopen("words.txt", "r");

    if (fp == NULL) {
        printf("Unable to open file words.txt\n");
        exit(1);
    }

    for (i = 0; i < MAX_WORDS; i++) {
        fscanf(fp, "%s", words[i]);
        fgetc(fp); // consume newline character
    }

    fclose(fp);
}

// Function to check if a given string is a palindrome
int is_palindrome(char str[WORD_LENGTH]) {
    int start = 0;
    int end = WORD_LENGTH - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main() {
    int i, j, k, time_taken;
    char words[MAX_WORDS][WORD_LENGTH];
    char input[WORD_LENGTH];

    // Generate random words
    generate_words(words);

    // Warm up
    clock_t start = clock();
    for (i = 0; i < 10; i++) {
        printf("%s ", words[i % MAX_WORDS]);
        fgets(input, WORD_LENGTH, stdin);
        strcpy(input, input + 1);
    }
    time_taken = clock() - start;

    // Test
    start = clock();

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < strlen(words[j % MAX_WORDS]); k++) {
                input[k] = getchar();
                if (input[k] != words[j % MAX_WORDS][k]) {
                    printf("Incorrect character for word %s. Try again.\n", words[j % MAX_WORDS]);
                    i--;
                    break;
                }
            }

            // Check if the word is a palindrome
            if (is_palindrome(input)) {
                printf("Palindrome! Well done.\n");
            } else {
                printf("Incorrect word. Try again.\n");
                i--;
                break;
            }

            memset(input, 0, WORD_LENGTH); // Clear input buffer
        }
    }

    time_taken = clock() - start;

    printf("Time taken to type and check %d palindrome words: %ld microseconds.\n", 10, time_taken * 1000 / CLOCKS_PER_SEC);

    return 0;
}