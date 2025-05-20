#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 60000
#define DIGIT_SIZE 784

int loadMNISTData(const char* filename, float data[MAX_DIGITS][DIGIT_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    int count = 0;
    while (count < MAX_DIGITS && fscanf(file, "%f", &data[count][0]) == 1) {
        for (int i = 1; i < DIGIT_SIZE; ++i) {
            if (fscanf(file, "%f", &data[count][i]) != 1) {
                fclose(file);
                return -1;
            }
        }
        ++count;
    }

    fclose(file);
    return count;
}

int main() {
    float mnistData[MAX_DIGITS][DIGIT_SIZE];
    int loadedCount = loadMNISTData("mnist_data.txt", mnistData);

    if (loadedCount > 0) {
        printf("Successfully loaded %d digits.\n", loadedCount);
    } else {
        printf("Failed to load data.\n");
    }

    return 0;
}
