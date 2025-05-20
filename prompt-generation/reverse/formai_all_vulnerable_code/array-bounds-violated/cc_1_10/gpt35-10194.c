//FormAI DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define the maximum length of the compressed string
#define COMP_LENGTH 50

// Define the maximum number of characters to compress at once
#define MAX_COMPRESS 10

// Define the struct for each compressed block
typedef struct Block {
    char data[MAX_COMPRESS];
    int count;
} Block;

// Define the main function
int main(void) {
    // Initialize variables
    char input[MAX_LENGTH];
    Block blocks[COMP_LENGTH];
    int block_count = 0;
    int input_length, i, j, k;
    
    // Get the input string from the user
    printf("Enter a string to compress (max length %d): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    input_length = strlen(input);
    if (input[input_length-1] == '\n') {
        input[input_length-1] = '\0';
        input_length--;
    }
    
    // Loop through the input string and compress blocks of characters
    for (i = 0; i < input_length; i += MAX_COMPRESS) {
        // Initialize the current block
        Block current;
        current.count = 1;
        for (j = 0; j < MAX_COMPRESS; j++) {
            current.data[j] = input[i+j];
            if (input[i+j] == '\0') {
                // If we reach the end of the string, break the loop
                break;
            }
        }
        
        // Loop through the remaining input string to find matching blocks
        for (k = i + MAX_COMPRESS; k < input_length; k += MAX_COMPRESS) {
            // Initialize the next block
            Block next;
            next.count = 1;
            for (j = 0; j < MAX_COMPRESS; j++) {
                next.data[j] = input[k+j];
                if (input[k+j] == '\0') {
                    // If we reach the end of the string, break the loop
                    break;
                }
            }
            
            // Compare the current and next blocks, and increment the count if they match
            if (strcmp(current.data, next.data) == 0) {
                current.count++;
                i = k;
            }
            else {
                break;
            }
        }
        
        // Add the current block to the array of blocks
        blocks[block_count] = current;
        block_count++;
    }
    
    // Print out the compressed string
    printf("Compressed string: ");
    for (i = 0; i < block_count; i++) {
        printf("%d%s", blocks[i].count, blocks[i].data);
    }
    printf("\n");
    
    return 0;
}