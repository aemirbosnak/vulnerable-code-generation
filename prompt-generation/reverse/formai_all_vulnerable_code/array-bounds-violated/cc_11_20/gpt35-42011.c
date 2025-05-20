//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000  // Maximum length of input string
#define ALPHA_NUM 26  // Number of alphabets in English

int main() {
    char input[MAX_STRING_LENGTH];
    char watermark[MAX_STRING_LENGTH];
    char output[MAX_STRING_LENGTH];
    int input_len, watermark_len, i, j;
    int freq[ALPHA_NUM], max_freq_index;
    float prob[ALPHA_NUM];

    // Read input string from user
    printf("Enter the input string: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input_len = strlen(input) - 1;
    input[input_len] = '\0';  // Remove newline character from input

    // Generate watermark string
    srand(time(NULL));  // Seed for random number generation
    watermark_len = rand() % input_len + 1;  // Random length between 1 and input length
    for (i = 0; i < watermark_len; i++) {
        watermark[i] = rand() % ALPHA_NUM + 'a';  // Random alphabetic character
    }
    watermark[watermark_len] = '\0';

    // Calculate probability of each alphabet in input string
    for (i = 0; i < ALPHA_NUM; i++) {
        freq[i] = 0;
    }
    for (i = 0; i < input_len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            freq[input[i] - 'a']++;
        }
    }
    for (i = 0; i < ALPHA_NUM; i++) {
        prob[i] = (float)freq[i] / input_len;
    }

    // Find alphabet with maximum probability and replace it with watermark in output string
    max_freq_index = 0;
    for (i = 1; i < ALPHA_NUM; i++) {
        if (prob[i] > prob[max_freq_index]) {
            max_freq_index = i;
        }
    }
    strcpy(output, input);
    for (i = 0, j = 0; i < input_len && j < watermark_len; i++) {
        if (output[i] == max_freq_index + 'a') {
            output[i] = watermark[j];
            j++;
        }
    }

    // Print results
    printf("Input string:\n%s\n\n", input);
    printf("Watermark string:\n%s\n\n", watermark);
    printf("Output string:\n%s\n", output);

    return 0;
}