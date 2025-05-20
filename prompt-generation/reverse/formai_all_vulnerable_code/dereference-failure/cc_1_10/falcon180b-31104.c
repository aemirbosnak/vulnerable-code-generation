//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Function to split a string into words
void split_string(char* str, char** words) {
    int num_words = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }
}

// Function to classify a message as spam or not spam
int classify_message(char** words, int num_words) {
    int spam_count = 0;
    for (int i = 0; i < num_words; i++) {
        if (isupper(words[i][0])) {
            spam_count++;
        }
        if (strstr(words[i], "free")!= NULL) {
            spam_count++;
        }
        if (strstr(words[i], "earn")!= NULL) {
            spam_count++;
        }
        if (strstr(words[i], "money")!= NULL) {
            spam_count++;
        }
        if (strstr(words[i], "buy")!= NULL) {
            spam_count++;
        }
        if (strstr(words[i], "discount")!= NULL) {
            spam_count++;
        }
        if (strstr(words[i], "cheap")!= NULL) {
            spam_count++;
        }
    }
    if (spam_count >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input_buffer[1000];
    char** words = malloc(MAX_WORDS * sizeof(char*));
    int num_words = 0;

    // Prompt the user to enter a message
    printf("Enter a message: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    // Remove the newline character from the input
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    // Split the input into words
    split_string(input_buffer, words);
    num_words = strlen(words);

    // Classify the message as spam or not spam
    int is_spam = classify_message(words, num_words);

    // Print the result
    if (is_spam) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}