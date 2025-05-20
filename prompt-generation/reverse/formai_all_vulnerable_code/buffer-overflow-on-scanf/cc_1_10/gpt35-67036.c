//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LEN 100

// Define the maximum length of the compressed string
#define MAX_COMP_LEN 50

// Function to compress a string using run length encoding algorithm
char* RLE_compress(char input[]) {

    int len = strlen(input), count = 1, j = 0;
    char* compressed = (char*) malloc(MAX_COMP_LEN * sizeof(char));

    // Iterate over the string to compress
    for(int i = 0; i < len; i++) {

        // If two consecutive characters are the same, increment the count
        if(input[i] == input[i+1])
            count++;

        /*
         * If two consecutive characters are different or if the end of the string is reached,
         * store the character and the count in the compressed string
         */
        else {
            if(count > 1)
                j += sprintf(&compressed[j], "%d%c", count, input[i]);
            else
                j += sprintf(&compressed[j], "%c", input[i]);

            // Reset count to 1
            count = 1;
        }

        // If the compressed string exceeds MAX_COMP_LEN, stop compressing and return NULL
        if(j >= MAX_COMP_LEN) {
            free(compressed);
            return NULL;
        }
    }

    // Terminate the compressed string with a null character
    compressed[j] = '\0';

    // If the compressed string is shorter than the input string, return the compressed string
    if(strlen(compressed) < len)
        return compressed;

    // If the compressed string is not shorter than the input string, free the memory allocated and return NULL
    else {
        free(compressed);
        return NULL;
    }
}

int main() {

    // Allocate memory for the input string and the compressed string
    char* input = (char*) malloc(MAX_LEN * sizeof(char));
    char* compressed = (char*) malloc(MAX_COMP_LEN * sizeof(char));
    
    // Prompt the user to input a string
    printf("Enter a string to compress: ");
    scanf("%s", input);

    // Compress the input string using the run length encoding algorithm
    compressed = RLE_compress(input);

    // If the compressed string is not NULL, print the compressed string
    if(compressed != NULL)
        printf("Compressed string: %s\n", compressed);

    // If the compressed string is NULL, inform the user that the compression failed
    else
        printf("Compression failed! The compressed string exceeds the maximum length.\n");

    // Free the memory allocated for the input string and the compressed string
    free(input);
    free(compressed);

    return 0;
}