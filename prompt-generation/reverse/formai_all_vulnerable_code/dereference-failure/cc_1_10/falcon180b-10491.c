//Falcon-180B DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for each data point
typedef struct {
    char name[20];
    int age;
    int income;
    char gender[10];
} data_point;

// Define the function to read data from a CSV file
void read_data(data_point* data, FILE* file) {
    char line[100];
    int i = 0;
    while(fgets(line, 100, file)!= NULL) {
        char* token = strtok(line, ",");
        strcpy(data[i].name, token);
        token = strtok(NULL, ",");
        data[i].age = atoi(token);
        token = strtok(NULL, ",");
        data[i].income = atoi(token);
        token = strtok(NULL, ",");
        strcpy(data[i].gender, token);
        i++;
    }
}

// Define the function to sort data based on age
void sort_data(data_point* data, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(data[i].age > data[j].age) {
                data_point temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// Define the function to calculate the average income
double calculate_average(data_point* data, int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += data[i].income;
    }
    return sum/n;
}

// Define the main function
int main() {
    // Define the data points
    data_point data[100];

    // Read data from a CSV file
    FILE* file = fopen("data.csv", "r");
    if(file == NULL) {
        printf("Error: unable to open file.\n");
        return 1;
    }
    read_data(data, file);
    fclose(file);

    // Sort data based on age
    sort_data(data, 100);

    // Calculate the average income
    double average_income = calculate_average(data, 100);

    // Print the results
    printf("The average income is: $%.2f\n", average_income);
    return 0;
}