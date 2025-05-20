//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
    char *stop_words[] = {"a", "an", "the", "is", "are", "am", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "will", "would", "should", "could", "may", "might", "must", "can", "cannot", "in", "on", "at", "to", "from", "by", "with", "and", "or", "nor", "but", "yet", "so", "for", "as", "of", "out", "about", "above", "below", "up", "down", "over", "under", "near", "far", "here", "there", "when", "where", "why", "how", "who", "what", "whose", "whom", "all", "any", "some", "none", "each", "every", "no", "not", "only", "just", "quite", "rather", "very", "too", "so", "such", "same", "different", "other", "another", "much", "more", "most", "less", "least", "few", "fewer", "fewest", "little", "less", "least", "many", "more", "most"};
    int num_stop_words = sizeof(stop_words) / sizeof(char *);

    char *new_str = malloc(strlen(str) + 1);
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        int is_stop_word = 0;
        for (int k = 0; k < num_stop_words; k++) {
            if (strcmp(str + i, stop_words[k]) == 0) {
                is_stop_word = 1;
                break;
            }
        }
        if (!is_stop_word) {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';

    return new_str;
}

// Function to summarize a text
char *summarize_text(char *text) {
    // Remove stop words from the text
    char *new_text = remove_stop_words(text);

    // Convert the text to lowercase
    for (int i = 0; i < strlen(new_text); i++) {
        new_text[i] = tolower(new_text[i]);
    }

    // Split the text into sentences
    char **sentences = malloc(sizeof(char *) * 100);
    int num_sentences = 0;
    char *sentence = strtok(new_text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Calculate the frequency of each word in the text
    int **word_freq = malloc(sizeof(int *) * 100);
    for (int i = 0; i < 100; i++) {
        word_freq[i] = malloc(sizeof(int) * 100);
    }
    for (int i = 0; i < num_sentences; i++) {
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            int j = 0;
            while (strcmp(word, word_freq[j]) != 0 && j < 100) {
                j++;
            }
            if (j == 100) {
                strcpy(word_freq[j], word);
                word_freq[j][0] = 1;
            } else {
                word_freq[j][0]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Sort the words by frequency
    for (int i = 0; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (word_freq[i][0] < word_freq[j][0]) {
                int *temp = word_freq[i];
                word_freq[i] = word_freq[j];
                word_freq[j] = temp;
            }
        }
    }

    // Generate the summary
    char *summary = malloc(1000);
    int j = 0;
    for (int i = 0; i < 100; i++) {
        if (word_freq[i][0] > 0) {
            strcat(summary, word_freq[i]);
            strcat(summary, " ");
            j++;
            if (j == 10) {
                break;
            }
        }
    }

    return summary;
}

int main() {
    // Read the text from the user
    char *text = malloc(1000);
    printf("Enter the text to be summarized: ");
    gets(text);

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    return 0;
}