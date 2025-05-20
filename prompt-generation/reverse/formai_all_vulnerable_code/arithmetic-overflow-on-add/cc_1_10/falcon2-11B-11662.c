//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS_IN_SENTENCE 50
#define MAX_NUM_WORDS 500
#define MAX_CLASS_VALUES 5

typedef struct word_info {
    char word[MAX_SENTENCE_LENGTH];
    int count;
    int class_count[MAX_CLASS_VALUES];
} WordInfo;

WordInfo word_info[MAX_NUM_WORDS];

int main() {
    int num_words = 0;
    int num_classes = 0;
    int num_spam = 0;
    int num_ham = 0;
    int num_total = 0;

    // Initialize the word info array
    memset(word_info, 0, sizeof(WordInfo) * MAX_NUM_WORDS);

    // Read the training data from the file
    FILE *fp = fopen("training_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening the training data file\n");
        return 1;
    }

    // Read the number of words, classes and total number of examples
    fscanf(fp, "%d %d %d", &num_words, &num_classes, &num_total);

    // Read the training data
    for (int i = 0; i < num_total; i++) {
        WordInfo *word_info_ptr = &word_info[num_words];
        char sentence[MAX_SENTENCE_LENGTH];
        fscanf(fp, "%s", sentence);
        fscanf(fp, "%d", &word_info_ptr->count);
        fscanf(fp, "%d %d %d %d %d", &word_info_ptr->class_count[0], &word_info_ptr->class_count[1], &word_info_ptr->class_count[2], &word_info_ptr->class_count[3], &word_info_ptr->class_count[4]);
        num_words++;
    }

    fclose(fp);

    // Train the Naive Bayes classifier
    for (int i = 0; i < num_classes; i++) {
        int num_spam_examples = 0;
        int num_ham_examples = 0;
        for (int j = 0; j < num_total; j++) {
            if (word_info[j].class_count[i] == 1) {
                if (word_info[j].count > 0) {
                    num_spam_examples++;
                } else {
                    num_ham_examples++;
                }
            } else {
                if (word_info[j].count > 0) {
                    num_ham_examples++;
                } else {
                    num_spam_examples++;
                }
            }
        }
        float spam_prob = (float)num_spam_examples / num_total;
        float ham_prob = (float)num_ham_examples / num_total;
        float total_prob = spam_prob + ham_prob;
        float spam_class_prob = spam_prob / total_prob;
        float ham_class_prob = ham_prob / total_prob;
        printf("Class %d: Spam probability = %.2f, Ham probability = %.2f\n", i+1, spam_class_prob, ham_class_prob);
    }

    // Test the Naive Bayes classifier
    int num_test_examples = 0;
    fscanf(fp, "%d", &num_test_examples);
    WordInfo *word_info_ptr = &word_info[num_words];
    for (int i = 0; i < num_test_examples; i++) {
        WordInfo *word_info_ptr = &word_info[num_words];
        char sentence[MAX_SENTENCE_LENGTH];
        fscanf(fp, "%s", sentence);
        fscanf(fp, "%d", &word_info_ptr->count);
        fscanf(fp, "%d %d %d %d %d", &word_info_ptr->class_count[0], &word_info_ptr->class_count[1], &word_info_ptr->class_count[2], &word_info_ptr->class_count[3], &word_info_ptr->class_count[4]);
        num_words++;
    }

    fclose(fp);

    return 0;
}