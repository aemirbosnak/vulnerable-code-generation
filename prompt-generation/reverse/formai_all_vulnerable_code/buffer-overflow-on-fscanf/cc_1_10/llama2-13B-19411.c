//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to store data for a single person
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person_t;

// Function to read data from a file and store it in an array
person_t *read_data(const char *filename) {
    person_t *data = NULL;
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    while (i < MAX_NAME_LENGTH && fscanf(file, "%s %d", data[i].name, &data[i].age) == 2) {
        i++;
    }

    fclose(file);

    return data;
}

// Function to print the data in a nice format
void print_data(person_t *data, int num_people) {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("%s is %d years old\n", data[i].name, data[i].age);
    }
}

// Function to find the average age of the data
double find_average_age(person_t *data, int num_people) {
    double sum = 0;
    int i;

    for (i = 0; i < num_people; i++) {
        sum += data[i].age;
    }

    return sum / num_people;
}

int main() {
    person_t *data = read_data("people.dat");
    int num_people = sizeof(data) / sizeof(data[0]);

    print_data(data, num_people);
    double average_age = find_average_age(data, num_people);
    printf("The average age is: %f\n", average_age);

    return 0;
}