//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 10000
#define MIN_SUPPORT 10

// Structure to hold the data
struct data {
    char *name;
    int age;
};

// Function to read the data from a file
void readData(struct data *data, int size) {
    FILE *file = fopen("data.txt", "r");
    int i = 0;

    while (i < size) {
        fscanf(file, "%s %d", data[i].name, &data[i].age);
        i++;
    }

    fclose(file);
}

// Function to calculate the support for each item
int calculateSupport(struct data *data, int size) {
    int i, j, support = 0;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (strcmp(data[i].name, data[j].name) == 0) {
                support++;
            }
        }
    }

    return support;
}

// Function to print the frequent items
void printFrequentItems(struct data *data, int size) {
    int i, j, support;

    for (i = 0; i < size; i++) {
        support = calculateSupport(data, i);

        if (support >= MIN_SUPPORT) {
            printf("%s (age %d) is frequent with support %d\n", data[i].name, data[i].age, support);
        }
    }
}

int main() {
    struct data data[DATABASE_SIZE];
    int size = sizeof(data) / sizeof(data[0]);

    // Read the data from a file
    readData(data, size);

    // Calculate the support for each item
    int support = calculateSupport(data, size);

    // Print the frequent items
    printFrequentItems(data, size);

    return 0;
}