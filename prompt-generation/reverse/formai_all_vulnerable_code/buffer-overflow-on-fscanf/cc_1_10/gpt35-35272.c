//FormAI DATASET v1.0 Category: Data mining ; Style: random
/* Unique C Data Mining Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold data
typedef struct {
    char name[50];
    int age;
    char gender;
    float height;
    float weight;
} person;

// Constants for array sizes
const int MAX_PEOPLE = 1000;
const int MAX_NAME_LEN = 50;

// Function to read input file and populate array
int read_data(char* file_name, person people[]) {
    FILE* input_file = fopen(file_name, "r");
    int i = 0;

    if (input_file == NULL) {
        printf("File not found!\n");
        return 0;
    }

    while (!feof(input_file) && i < MAX_PEOPLE) {
        fscanf(input_file, "%s %d %c %f %f", people[i].name, &people[i].age, &people[i].gender, &people[i].height, &people[i].weight);
        i++;
    }

    fclose(input_file);
    return i;
}

// Function to find average height of a certain gender
float find_average_height(person people[], int num_people, char gender) {
    int i, count = 0;
    float total_height = 0;

    for (i = 0; i < num_people; i++) {
        if (people[i].gender == gender) {
            total_height += people[i].height;
            count++;
        }
    }

    return total_height / count;
}

// Function to calculate BMI
float calc_bmi(float height, float weight) {
    return weight / (height * height);
}

// Main function
int main() {
    person people[MAX_PEOPLE];
    int num_people = read_data("input.txt", people);
    int i;
    float avg_height_m, avg_height_f, bmi;

    if (num_people == 0) {
        return 0;
    }

    avg_height_m = find_average_height(people, num_people, 'M');
    avg_height_f = find_average_height(people, num_people, 'F');

    printf("Average height of males: %.2f\n", avg_height_m);
    printf("Average height of females: %.2f\n", avg_height_f);

    // Calculate BMI for each person
    for (i = 0; i < num_people; i++) {
        bmi = calc_bmi(people[i].height, people[i].weight);

        if (bmi > 30) {
            printf("%s is obese with a BMI of %.2f\n", people[i].name, bmi);
        }
    }

    return 0;
}