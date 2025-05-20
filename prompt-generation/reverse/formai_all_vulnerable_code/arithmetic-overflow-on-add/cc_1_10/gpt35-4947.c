//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int compress(char *input_str, char *output_str) {
    int i, j, k;
    int freq[MAX_LEN] = {0};

    for (i = 0; input_str[i] != '\0'; ++i) {
        ++freq[input_str[i] - 'a'];
    }

    int max_freq = 0, max_freq_char;
    for (i = 0; i < MAX_LEN; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_freq_char = i;
        }
    }

    if (max_freq == 1) {
        strcpy(output_str, input_str);
        return 0;
    }

    int input_len = strlen(input_str);
    int output_len = (input_len / 2) + 1;
    char compressed_str[output_len];
    memset(compressed_str, 0, output_len);

    k = 0;
    for (i = 0; i < input_len; ++i) {
        if (input_str[i] == max_freq_char + 'a') {
            ++k;
            if (i == input_len - 1) {
                compressed_str[(k - 1) * 2 + 1] = '\0';
            }
        } else {
            if (k > 1) {
                compressed_str[(k - 1) * 2] = max_freq_char + 'a';
                compressed_str[(k - 1) * 2 + 1] = '0' + k;
            } else {
                compressed_str[(k - 1) * 2] = input_str[i];
            }
            k = 1;
            if (i == input_len - 1) {
                compressed_str[(k - 1) * 2] = input_str[i];
                compressed_str[(k - 1) * 2 + 1] = '\0';
            }
        }
    }

    strcpy(output_str, compressed_str);
    return 0;
}

int main() {
    char input_str[MAX_LEN], output_str[MAX_LEN];

    printf("Enter input string: ");
    fgets(input_str, MAX_LEN, stdin);
    input_str[strcspn(input_str, "\n")] = '\0';

    compress(input_str, output_str);

    printf("Compressed string: %s\n", output_str);

    return 0;
}