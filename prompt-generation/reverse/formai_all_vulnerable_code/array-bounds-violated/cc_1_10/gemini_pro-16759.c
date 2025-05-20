//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_SPAM_WORDS 100

// Spam detection system using regular expressions
int main() {
    // Define the regular expressions for spam words
    regex_t spam_words[MAX_SPAM_WORDS];
    char *spam_word_list[] = {
        "free", "money", "offer", "click", "win", "prize", "lose", "weight", "miracle", "guarantee"
    };

    // Compile the regular expressions
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (regcomp(&spam_words[i], spam_word_list[i], REG_ICASE) != 0) {
            fprintf(stderr, "Error compiling regular expression %s\n", spam_word_list[i]);
            return EXIT_FAILURE;
        }
    }

    // Get the input text from the user
    char *input_text = malloc(1024);
    printf("Enter the text to check for spam: ");
    fgets(input_text, 1024, stdin);

    // Check the text for spam words
    int spam_count = 0;
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (regexec(&spam_words[i], input_text, 0, NULL, 0) == 0) {
            spam_count++;
        }
    }

    // Print the results
    if (spam_count > 0) {
        printf("The text contains %d spam words.\n", spam_count);
    } else {
        printf("The text does not contain any spam words.\n");
    }

    // Free the allocated memory
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        regfree(&spam_words[i]);
    }
    free(input_text);

    return EXIT_SUCCESS;
}