//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold the data
struct data {
    int age;
    char name[50];
    int score;
};

// Function to read data from user
void read_data(struct data *data, int num_data) {
    for (int i = 0; i < num_data; i++) {
        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &data[i].age);
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", data[i].name);
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &data[i].score);
    }
}

// Function to print data
void print_data(struct data *data, int num_data) {
    for (int i = 0; i < num_data; i++) {
        printf("Student %d: Age = %d, Name = %s, Score = %d\n", i + 1, data[i].age, data[i].name, data[i].score);
    }
}

// Main function
int main() {
    int num_data;
    printf("Enter number of data: ");
    scanf("%d", &num_data);

    // Allocate memory for data
    struct data *data = (struct data*)malloc(num_data * sizeof(struct data));

    // Read data from user
    read_data(data, num_data);

    // Print data
    print_data(data, num_data);

    // Free memory
    free(data);

    return 0;
}