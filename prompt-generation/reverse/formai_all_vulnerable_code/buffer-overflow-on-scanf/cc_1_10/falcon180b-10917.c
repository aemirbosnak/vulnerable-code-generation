//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 100
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20

// Function to count the frequency of each word in the email
void count_words(char *email, int *word_counts) {
    char *word = strtok(email, " \t\n\r\f\v,.!?;:");
    while (word!= NULL) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        word_counts[(int)log10(strlen(word))]++;
        word = strtok(NULL, " \t\n\r\f\v,.!?;:");
    }
}

// Function to calculate the spam score of the email
float calculate_spam_score(int *word_counts) {
    float score = 0.0;
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i] > 0) {
            score += pow(log10(word_counts[i]), 2);
        }
    }
    return score;
}

int main() {
    char email[1000];
    int word_counts[MAX_WORDS] = {0};
    float spam_score;

    // Prompt user for input email
    printf("Enter an email: ");
    scanf("%s", email);

    // Count the frequency of each word in the email
    count_words(email, word_counts);

    // Calculate the spam score of the email
    spam_score = calculate_spam_score(word_counts);

    // Print the spam score of the email
    if (spam_score > 1.0) {
        printf("The email is spam with a score of %.2f\n", spam_score);
    } else {
        printf("The email is not spam with a score of %.2f\n", spam_score);
    }

    return 0;
}