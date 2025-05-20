//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>

/* A simple function to check if a character is a punctuation mark */
int is_punctuation(char c) {
    return c == '.' || c == ',' || c == '?' || c == '!';
}

/* A simple function to check if a character is a whitespace */
int is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

/* A simple function to count the number of words in a string */
int count_words(char *str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (!is_punctuation(*str) && !is_whitespace(*str)) {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }

        str++;
    }

    return count;
}

/* A simple function to count the number of positive words in a string */
int count_positive_words(char *str) {
    int count = 0;
    char *positive_words[] = {"good", "great", "excellent", "nice", "awesome", "amazing", "fantastic"};

    while (*str) {
        /* Skip whitespace and punctuation */
        while (*str && (is_punctuation(*str) || is_whitespace(*str))) {
            str++;
        }

        /* Check if the current word is a positive word */
        int found_positive_word = 0;
        for (int i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++) {
            int positive_word_length = strlen(positive_words[i]);
            if (strncmp(str, positive_words[i], positive_word_length) == 0 && 
                is_whitespace(*(str + positive_word_length))) {
                found_positive_word = 1;
                break;
            }
        }

        /* Increment the count if a positive word was found */
        if (found_positive_word) {
            count++;
        }

        /* Skip to the next word */
        while (*str && !is_punctuation(*str) && !is_whitespace(*str)) {
            str++;
        }
    }

    return count;
}

/* A simple function to count the number of negative words in a string */
int count_negative_words(char *str) {
    int count = 0;
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "poor", "dreadful", "disgusting"};

    while (*str) {
        /* Skip whitespace and punctuation */
        while (*str && (is_punctuation(*str) || is_whitespace(*str))) {
            str++;
        }

        /* Check if the current word is a negative word */
        int found_negative_word = 0;
        for (int i = 0; i < sizeof(negative_words) / sizeof(negative_words[0]); i++) {
            int negative_word_length = strlen(negative_words[i]);
            if (strncmp(str, negative_words[i], negative_word_length) == 0 && 
                is_whitespace(*(str + negative_word_length))) {
                found_negative_word = 1;
                break;
            }
        }

        /* Increment the count if a negative word was found */
        if (found_negative_word) {
            count++;
        }

        /* Skip to the next word */
        while (*str && !is_punctuation(*str) && !is_whitespace(*str)) {
            str++;
        }
    }

    return count;
}

/* The main function of the program */
int main() {
    char input[100];
    int positive_words;
    int negative_words;
    int word_count;

    printf("Enter some text: ");
    fgets(input, 100, stdin);
    
    /* Remove the newline character from the input */
    input[strlen(input) - 1] = '\0';

    positive_words = count_positive_words(input);
    negative_words = count_negative_words(input);
    word_count = count_words(input);

    printf("Positive words: %d\n", positive_words);
    printf("Negative words: %d\n", negative_words);
    printf("Total words: %d\n", word_count);

    return 0;
}