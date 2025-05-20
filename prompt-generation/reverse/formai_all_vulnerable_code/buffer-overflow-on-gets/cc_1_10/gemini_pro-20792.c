//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the length of a string
int str_len(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Function to reverse a string
void str_rev(char *str) {
    int len = str_len(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert a string to lowercase
void str_lower(char *str) {
    int len = str_len(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

// Function to remove all spaces from a string
void str_rem_spaces(char *str) {
    int len = str_len(str);
    int new_len = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[new_len++] = str[i];
        }
    }
    str[new_len] = '\0';
}

// Function to remove all punctuation from a string
void str_rem_punc(char *str) {
    int len = str_len(str);
    int new_len = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[new_len++] = str[i];
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[new_len++] = str[i];
        } else if (str[i] >= '0' && str[i] <= '9') {
            str[new_len++] = str[i];
        }
    }
    str[new_len] = '\0';
}

// Function to remove all stop words from a string
void str_rem_stop_words(char *str) {
    char *stop_words[] = {"a", "an", "the", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "will", "would", "should", "could", "may", "might", "must", "can", "cannot", "could", "couldnt", "should", "shouldnt", "will", "wont", "would", "wouldnt", "of", "to", "from", "in", "on", "at", "by", "for", "with", "about", "as", "at", "before", "behind", "below", "beside", "between", "by", "despite", "during", "except", "for", "from", "in", "inside", "into", "like", "near", "of", "off", "on", "onto", "opposite", "outside", "over", "past", "since", "through", "throughout", "till", "to", "toward", "towards", "under", "underneath", "unlike", "until", "up", "upon", "versus", "via", "with", "within", "without"};
    int num_stop_words = sizeof(stop_words) / sizeof(char *);
    int len = str_len(str);
    int new_len = 0;
    char *new_str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        int is_stop_word = 0;
        for (int j = 0; j < num_stop_words; j++) {
            if (strcmp(str + i, stop_words[j]) == 0) {
                is_stop_word = 1;
                break;
            }
        }
        if (!is_stop_word) {
            new_str[new_len++] = str[i];
        }
    }
    new_str[new_len] = '\0';
    strcpy(str, new_str);
    free(new_str);
}

// Function to summarize a text
char *summarize_text(char *text) {
    // Convert the text to lowercase
    str_lower(text);

    // Remove all spaces from the text
    str_rem_spaces(text);

    // Remove all punctuation from the text
    str_rem_punc(text);

    // Remove all stop words from the text
    str_rem_stop_words(text);

    // Tokenize the text into words
    char *words[1000];
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the frequency of each word
    int word_freq[1000];
    for (int i = 0; i < num_words; i++) {
        word_freq[i] = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_freq[i]++;
            }
        }
    }

    // Sort the words by frequency in descending order
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_freq[i] < word_freq[j]) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
                int temp_freq = word_freq[i];
                word_freq[i] = word_freq[j];
                word_freq[j] = temp_freq;
            }
        }
    }

    // Generate the summary
    char *summary = malloc(1000);
    int summary_len = 0;
    for (int i = 0; i < num_words && i < 10; i++) {
        summary[summary_len++] = words[i];
        summary[summary_len++] = ' ';
    }
    summary[summary_len] = '\0';

    return summary;
}

int main() {
    // Get the text from the user
    char *text = malloc(1000);
    printf("Enter the text to summarize: ");
    gets(text);

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(text);
    free(summary);

    return 0;
}