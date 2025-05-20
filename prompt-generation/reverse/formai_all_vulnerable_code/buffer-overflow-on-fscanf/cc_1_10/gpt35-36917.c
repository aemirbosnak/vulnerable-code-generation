//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LEN 15
#define MIN_WORD_LEN 3
#define MAX_WORDS 100
#define TIME_LIMIT 60

int compare_char(const void *a, const void *b)
{
  return *(const char *)a - *(const char *)b;
}

void sort_string(char *str)
{
  qsort(str, strlen(str), sizeof(char), compare_char);
}

int main() 
{
    char wordlist[MAX_WORDS][MAX_WORD_LEN];
    int wordsread = 0;
    FILE *wordfile;

    // Read in the list of words
    if (!(wordfile = fopen("wordlist.txt", "r"))) {
        printf("Could not find wordlist.txt");
        return 1;
    }

    while (wordsread < MAX_WORDS && fscanf(wordfile, "%s", wordlist[wordsread]) == 1) {
        wordsread++;
    }
    fclose(wordfile);

    if (wordsread < MAX_WORDS) {
        printf("Not enough words in wordlist\n");
        return 1;
    }

    // Initialize variables
    int score = 0;
    time_t start_time = time(NULL);

    // Loop until time is up or all words are typed
    while (time(NULL) - start_time < TIME_LIMIT) {
        int index = rand() % MAX_WORDS;
        char word[MAX_WORD_LEN];
        strcpy(word, wordlist[index]);

        sort_string(word);

        // Print the scrambled word
        for (int i = 0; i < strlen(word); i++) {
            printf("%c", word[i]);
        }
        printf(" ");

        // Read user input and check if it matches the word
        char user_input[MAX_WORD_LEN];
        scanf("%s", user_input);

        if (strcmp(user_input, wordlist[index]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct word is \"%s\"\n", wordlist[index]);
        }
    }

    // Print final score
    printf("Time is up! Your final score is %d\n", score);

    return 0;
}