//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read data from a file
void read_file(char* filename, int* data, int size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int i = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        data[i++] = c - '0';
    }

    fclose(file);
}

// Function to calculate the frequency of each data point
void calculate_frequency(int* data, int size) {
    int frequency[10];
    memset(frequency, 0, sizeof(frequency));

    int i;
    for (i = 0; i < size; i++) {
        frequency[data[i]]++;
    }

    int max_frequency = 0;
    int max_index = 0;
    for (i = 1; i < 10; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
            max_index = i;
        }
    }

    printf("Most frequent data point: %d, with frequency of %d\n", max_index, max_frequency);
}

int main() {
    int data[100];
    int size;

    printf("Enter the size of the data: ");
    scanf("%d", &size);

    read_file("data.txt", data, size);
    calculate_frequency(data, size);

    return 0;
}