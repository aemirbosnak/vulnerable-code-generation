//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: genius
// A C program for data mining

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 1000
#define MAX_FEATURES 10

// Structure to store data
typedef struct {
    char name[50];
    int age;
    char gender;
    float height;
    float weight;
    int income;
} Person;

// Function to print data
void print_data(Person data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %c, %f, %f, %d\n", data[i].name, data[i].age, data[i].gender, data[i].height, data[i].weight, data[i].income);
    }
}

// Function to calculate average
float calculate_average(int arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to find the most common value in an array
int find_most_common(int arr[], int n) {
    int count[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int max = count[0];
    int most_common = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > max) {
            max = count[i];
            most_common = i;
        }
    }
    return most_common;
}

// Main function
int main() {
    // Initialize data
    Person data[MAX_DATA];
    int n = 0;

    // Read data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(fp, "%s %d %c %f %f %d", data[n].name, &data[n].age, &data[n].gender, &data[n].height, &data[n].weight, &data[n].income) != EOF) {
        n++;
    }
    fclose(fp);

    // Print data
    print_data(data, n);

    // Calculate average
    int ages[n];
    for (int i = 0; i < n; i++) {
        ages[i] = data[i].age;
    }
    float average = calculate_average(ages, n);
    printf("Average age: %f\n", average);

    // Find most common gender
    int genders[n];
    for (int i = 0; i < n; i++) {
        genders[i] = data[i].gender;
    }
    int most_common_gender = find_most_common(genders, n);
    printf("Most common gender: %c\n", most_common_gender);

    // Find most common income
    int incomes[n];
    for (int i = 0; i < n; i++) {
        incomes[i] = data[i].income;
    }
    int most_common_income = find_most_common(incomes, n);
    printf("Most common income: %d\n", most_common_income);

    return 0;
}