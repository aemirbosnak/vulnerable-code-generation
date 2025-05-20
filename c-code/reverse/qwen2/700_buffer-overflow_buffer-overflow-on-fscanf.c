#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char train_filename[10];
    char test_filename[10];

    printf("Enter training data filename: ");
    fscanf(stdin, "%s", train_filename);

    printf("Enter test data filename: ");
    fscanf(stdin, "%s", test_filename);

    // Simulate loading and processing data
    FILE *train_file = fopen(train_filename, "r");
    if (train_file == NULL) {
        perror("Error opening training file");
        return 1;
    }
    fclose(train_file);

    FILE *test_file = fopen(test_filename, "r");
    if (test_file == NULL) {
        perror("Error opening test file");
        return 1;
    }
    fclose(test_file);

    printf("Training and testing completed.\n");

    return 0;
}
