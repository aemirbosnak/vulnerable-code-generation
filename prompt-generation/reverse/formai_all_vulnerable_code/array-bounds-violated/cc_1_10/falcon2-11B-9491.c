//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_WORD_LENGTH 4

int main() {
    char text[MAX_LENGTH];
    char word[MAX_LENGTH];
    int word_length;

    // Read the text
    printf("Enter the text to be checked: ");
    scanf("%s", text);

    // Split the text into words
    int word_count = 0;
    char *word_array[MAX_LENGTH];
    int i = 0;
    while (text[i]!= '\0') {
        if (isalpha(text[i])) {
            word[word_length] = text[i];
            word_length++;
        } else if (word[word_length - 1]!= '\0') {
            word[word_length] = '\0';
            word_array[word_count] = strdup(word);
            word_length = 0;
            word_count++;
        }
        i++;
    }
    word_array[word_count] = NULL;

    // Check for spelling errors
    int error_count = 0;
    for (int j = 0; word_array[j]!= NULL; j++) {
        if (strlen(word_array[j]) < MIN_WORD_LENGTH) {
            printf("The word '%s' is too short to be a valid word.\n", word_array[j]);
            error_count++;
        } else {
            int dictionary_index = 0;
            char dictionary[MAX_LENGTH];
            while (isalpha(dictionary[dictionary_index])) {
                dictionary_index++;
                if (dictionary_index >= MAX_LENGTH) {
                    break;
                }
            }
            if (strcasecmp(word_array[j], dictionary)!= 0) {
                printf("The word '%s' is not in the dictionary.\n", word_array[j]);
                error_count++;
            }
        }
    }

    // Output the results
    printf("Total words: %d\n", word_count);
    printf("Total errors: %d\n", error_count);
    return 0;
}