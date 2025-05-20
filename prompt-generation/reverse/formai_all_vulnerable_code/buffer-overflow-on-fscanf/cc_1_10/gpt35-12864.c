//FormAI DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>

// Define struct for data
typedef struct Data {
    int id;
    char name[20];
    float score;
} Data;

// Function to read data from file and store in array of structs
void readData(FILE* fp, Data* dataArr, int* size) {
    *size = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d,%[^,],%f\n", &(dataArr[*size].id), dataArr[*size].name, &(dataArr[*size].score));
        (*size)++;
    }
}

// Function to calculate average score
float getAverageScore(Data* dataArr, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += dataArr[i].score;
    }
    return sum / size;
}

// Function to print data array
void printData(Data* dataArr, int size) {
    printf("Data:\n");
    for (int i = 0; i < size; i++) {
        printf("%d,%s,%.2f\n", dataArr[i].id, dataArr[i].name, dataArr[i].score);
    }
}

int main() {
    // Open data file
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read data into array of structs
    Data dataArr[50];
    int size;
    readData(fp, dataArr, &size);

    // Print data
    printData(dataArr, size);

    // Calculate average score
    float avgScore = getAverageScore(dataArr, size);
    printf("Average score: %.2f\n", avgScore);

    // Close file
    fclose(fp);

    return 0;
}