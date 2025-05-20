//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_WORD_LENGTH 20

// Helper function to strip punctuation and convert to lowercase
char *strip_punct_and_lower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (ispunct(str[i])) { // if character is punctuation, remove it
            memmove(&str[i], &str[i + 1], len - i);
            len--;
            i--;
        }
        else if (isupper(str[i])) { // if character is uppercase, convert to lowercase
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

int main() {
    char sentences[MAX_SENTENCES][MAX_WORD_LENGTH];

    // Collect user input
    for (int i = 0; i < MAX_SENTENCES; i++) {

        printf("Enter sentence %d (max %d characters):\n", (i+1), MAX_WORD_LENGTH);
        fgets(sentences[i], MAX_WORD_LENGTH, stdin);

        // Replace newline character with null terminator
        int len = strlen(sentences[i]);
        if (sentences[i][len - 1] == '\n') {
            sentences[i][len - 1] = '\0';
        }

        // End input if user enters empty sentence
        if (strlen(sentences[i]) == 0) {
            break;
        }
    }

    // Analyze sentiment scores for each sentence
    int pos_count = 0;
    int neg_count = 0;
    int neu_count = 0;
    for (int i = 0; i < MAX_SENTENCES; i++) {
        if (strlen(sentences[i]) == 0) { // exit loop if we've reached end of user input
            break;
        }

        char *words[MAX_WORD_LENGTH];
        int num_words = 0;

        // Split sentence into words
        char *tok = strtok(sentences[i], " ");
        while (tok != NULL && num_words < MAX_WORD_LENGTH) {
            words[num_words] = strip_punct_and_lower(tok);
            tok = strtok(NULL, " ");
            num_words++;
        }

        // Calculate sentiment score for sentence based on word list
        int score = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j], "good") == 0) {
                score += 1;
            }
            else if (strcmp(words[j], "bad") == 0) {
                score -= 1;
            }
        }

        // Determine sentiment category based on score
        if (score > 0) {
            printf("Positive sentiment\n");
            pos_count++;
        }
        else if (score < 0) {
            printf("Negative sentiment\n");
            neg_count++;
        }
        else {
            printf("Neutral sentiment\n");
            neu_count++;
        }
    }

    // Print overall sentiment distribution
    printf("\nSentiment distribution:\n");
    printf("Positive: %d\n", pos_count);
    printf("Negative: %d\n", neg_count);
    printf("Neutral: %d\n", neu_count);

    return 0;
}