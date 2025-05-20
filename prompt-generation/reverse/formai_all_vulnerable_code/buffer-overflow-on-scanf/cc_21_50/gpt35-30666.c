//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100], output[100] = "", compressed_output[100] = "", temp[2], curr_char;
    int freq[26] = {0}, i, j, len, compressed_len = 0, current_count = 0;

    printf("Enter the string to be compressed: ");
    scanf("%[^\n]s", input);

    len = strlen(input);

    // Counting the frequency of each character
    for (i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            freq[input[i]-'a']++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            freq[input[i]-'A']++;
        }
    }

    // Creating the compressed output
    for (i = 0; i < len; i++) {
        curr_char = input[i];

        // Compress only if it's a letter
        if ((curr_char >= 'a' && curr_char <= 'z') || (curr_char >= 'A' && curr_char <= 'Z')) {
            current_count++;

            if (i == len-1) {
                // Last character of the input
                sprintf(temp, "%d%c", current_count, curr_char);
                strcat(compressed_output, temp);
                compressed_len += strlen(temp);
            }
        }
        else {
            // Non-letter character
            sprintf(temp, "%d", current_count);
            strcat(compressed_output, temp);
            compressed_len += strlen(temp);
            current_count = 0;

            sprintf(temp, "%c", curr_char);
            strcat(compressed_output, temp);
            compressed_len += strlen(temp);
        }
    }

    printf("Compressed Output: %s\n", compressed_output);

    // Finding the original output from the compressed output
    for (i = 0; i < compressed_len; i++) {
        if ((compressed_output[i] >= 'a' && compressed_output[i] <= 'z') || (compressed_output[i] >= 'A' && compressed_output[i] <= 'Z')) {
            // Letter
            current_count++;
            
            if (i == compressed_len-1) {
                // Last character of the compressed output
                for (j = 0; j < current_count; j++) {
                    strcat(output, &curr_char);
                }
            }
        }
        else if (compressed_output[i] >= '0' && compressed_output[i] <= '9') {
            // Digit
            current_count = (current_count*10) + (compressed_output[i] - '0');
        }
        else {
            // Non-digit character
            for (j = 0; j < current_count; j++) {
                strcat(output, &compressed_output[i]);
            }
            current_count = 0;
        }
    }

    printf("Original Output: %s\n", output);

    return 0;
}