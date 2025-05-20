//FormAI DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// define the maximum number of nested blocks
#define MAX_BLOCKS 10

// define a struct for storing block information
typedef struct {
    char name[20];
    int start;
    int end;
} Block;

int main() {
    // initialize the array of block information
    Block blocks[MAX_BLOCKS];
    int num_blocks = 0;

    // initialize the variables for tracking current block and line number
    int current_block = -1;
    int line_number = 1;

    // read in a line of input from stdin
    char line[1000];
    while (fgets(line, 1000, stdin) != NULL) {
        // remove the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        // check if this is a new block
        if (strstr(line, "{") != NULL) {
            // add information about the new block to the array
            num_blocks++;
            if (num_blocks > MAX_BLOCKS) {
                printf("Error: too many nested blocks\n");
                return 1;
            }
            strcpy(blocks[num_blocks-1].name, line);
            blocks[num_blocks-1].start = line_number;
            current_block = num_blocks-1;
        }
        // check if this is the end of the current block
        else if (strstr(line, "}") != NULL) {
            // update the end line number for the current block
            blocks[current_block].end = line_number;
            current_block--;
        }
        // if this is not a block delimiter, just increment the line number
        else {
            line_number++;
        }
    }

    // print out the information about each block
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: %s\n", i+1, blocks[i].name);
        printf("Start line: %d\n", blocks[i].start);
        printf("End line: %d\n", blocks[i].end);
    }

    return 0;
}