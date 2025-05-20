//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_VOCAB_SIZE 10000

// Function to count the number of occurrences of a word in a given email
int count_word_occurrences(char* email, char* word) {
    int count = 0;
    int i = 0;
    while (email[i]!= '\0') {
        if (strstr(email + i, word)!= NULL) {
            count++;
        }
        i++;
    }
    return count;
}

// Function to calculate the log probability of a word in an email
float log_probability(char* email, char* word) {
    float count = (float)count_word_occurrences(email, word);
    float total_word_count = 0;
    char* word_list[MAX_VOCAB_SIZE];
    int num_words = 0;

    FILE* fp = fopen("word_list.txt", "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s", word_list[num_words])!= EOF) {
            total_word_count++;
            num_words++;
        }
        fclose(fp);
    } else {
        printf("Failed to open word_list.txt file\n");
        return -1;
    }

    float log_prob = 0;
    if (count > 0) {
        log_prob = (float)log10(count) + log10(total_word_count);
    }
    return log_prob;
}

// Function to calculate the probability of an email being spam based on word counts
float calculate_spam_probability(char* email) {
    float total_spam_count = 0;
    float total_word_count = 0;
    char* word_list[MAX_VOCAB_SIZE];
    int num_words = 0;

    FILE* fp = fopen("word_list.txt", "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s", word_list[num_words])!= EOF) {
            total_word_count++;
            num_words++;
        }
        fclose(fp);
    } else {
        printf("Failed to open word_list.txt file\n");
        return -1;
    }

    float spam_count = 0;
    for (int i = 0; i < MAX_EMAIL_LENGTH; i++) {
        char* word = email + i;
        if (strstr(word, "spam")!= NULL || strstr(word, "spammer")!= NULL) {
            spam_count++;
        }
    }

    float log_prob = 0;
    for (int i = 0; i < MAX_VOCAB_SIZE; i++) {
        char* word = word_list[i];
        float log_prob_word = log_probability(email, word);
        if (log_prob_word >= 0) {
            log_prob += log_prob_word;
        }
    }

    float spam_probability = spam_count / total_word_count;
    return spam_probability + log_prob / (float)num_words;
}

int main() {
    char* email = "This is a spam email.";
    float spam_probability = calculate_spam_probability(email);
    printf("The spam probability of the email is: %.2f\n", spam_probability);

    return 0;
}