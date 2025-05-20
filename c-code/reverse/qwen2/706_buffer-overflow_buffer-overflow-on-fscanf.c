#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void trainModel(const char* filename) {
    // Dummy function to simulate model training
    printf("Training model with data from: %s\n", filename);
}

void testModel(const char* filename) {
    // Dummy function to simulate model testing
    printf("Testing model with data from: %s\n", filename);
}

int main() {
    char trainFilename[MAX_FILENAME_LENGTH];
    char testFilename[MAX_FILENAME_LENGTH];

    printf("Enter the filename for training data: ");
    scanf("%255s", trainFilename); // Vulnerable to buffer overflow

    printf("Enter the filename for testing data: ");
    scanf("%255s", testFilename); // Vulnerable to buffer overflow

    trainModel(trainFilename);
    testModel(testFilename);

    return 0;
}
