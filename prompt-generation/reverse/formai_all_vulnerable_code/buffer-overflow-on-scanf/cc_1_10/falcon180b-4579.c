//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_DATA_SIZE 1000
#define MAX_FILE_SIZE 1000000
#define FILENAME "data.txt"

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float income;
} Data;

void generateData(Data* data, int num) {
    for (int i = 0; i < num; i++) {
        srand(time(NULL) + i);
        data[i].age = rand() % 100;
        data[i].income = rand() % 10000;
        sprintf(data[i].name, "Name %d", i + 1);
    }
}

void writeToFile(Data* data, int num) {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        fprintf(file, "%s %d %.2f\n", data[i].name, data[i].age, data[i].income);
    }

    fclose(file);
}

void readFromFile(Data* data, int num) {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        fscanf(file, "%s %d %.2f", data[i].name, &data[i].age, &data[i].income);
    }

    fclose(file);
}

void analyzeData(Data* data, int num) {
    float avgAge = 0;
    float avgIncome = 0;

    for (int i = 0; i < num; i++) {
        avgAge += data[i].age;
        avgIncome += data[i].income;
    }

    avgAge /= num;
    avgIncome /= num;

    printf("Average age: %.2f\n", avgAge);
    printf("Average income: $%.2f\n", avgIncome);
}

int main() {
    Data data[MAX_DATA_SIZE];
    int num = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &num);

    if (num > MAX_DATA_SIZE) {
        printf("Error: Number of data points exceeds the maximum limit.\n");
        exit(1);
    }

    generateData(data, num);
    writeToFile(data, num);
    readFromFile(data, num);
    analyzeData(data, num);

    return 0;
}