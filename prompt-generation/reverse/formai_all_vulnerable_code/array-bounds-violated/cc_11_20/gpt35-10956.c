//FormAI DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 501
#define MAX_SUMMARY_SIZE 101

int main() {
    char input[MAX_INPUT_SIZE], summary[MAX_SUMMARY_SIZE];
    int length;
    printf("Enter the text to be summarized: ");
    // Reading input from user
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Calculating length of input
    length = strlen(input);
    if (input[length - 1] == '\n') input[length - 1] = '\0';
    
    // Checking if input is already within summary size limit
    if (length <= MAX_SUMMARY_SIZE) {
        strcpy(summary, input);
    } else {
        // Initializing variables needed to create summary
        int i, j, k = 0, count = 0, spaces = 0;
        for (i = 0; i < length; i++) {
            // Counting number of spaces
            if (input[i] == ' ' && i <= MAX_SUMMARY_SIZE) spaces++;
            // Creating summary up to MAX_SUMMARY_SIZE characters
            if (k <= MAX_SUMMARY_SIZE) {
                k++;
                summary[i] = input[i];
                if (input[i] == ' ') count++;
            }
        }
        // Handling case when last word is cut in middle
        if (count != spaces) {
            for (j = k - 1; j >= 0; j--) {
                if (summary[j] == ' ') {
                    summary[j] = '\0';
                    break;
                }
            }
        } else {
            summary[k-1] = '\0';
        }
    }
    
    // Printing summary
    printf("Summary: %s\n", summary);
    
    return 0;
}