//LLAMA2-13B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024
#define MAX_STR_LEN 50

// Define a struct to hold the input parameters
typedef struct {
    char *name;
    int age;
    float height;
    float weight;
} person_t;

// Function to read input parameters from the user
void get_input(person_t *person) {
    printf("Enter your name: ");
    fgets(person->name, MAX_STR_LEN, stdin);
    printf("Enter your age: ");
    scanf("%d", &person->age);
    printf("Enter your height: ");
    scanf("%.2f", &person->height);
    printf("Enter your weight: ");
    scanf("%.2f", &person->weight);
}

// Function to calculate the BMI of a person
float calculate_bmi(person_t *person) {
    return person->weight / (person->height * person->height);
}

// Function to print the BMI and a message
void print_bmi(person_t *person) {
    printf("Your BMI is: %.2f\n", calculate_bmi(person));
    if (calculate_bmi(person) < 18.5) {
        printf("You are underweight\n");
    } else if (calculate_bmi(person) < 25) {
        printf("You are normal weight\n");
    } else if (calculate_bmi(person) < 30) {
        printf("You are overweight\n");
    } else {
        printf("You are obese\n");
    }
}

int main() {
    // Create a person struct to hold the input parameters
    person_t person = {0};

    // Read the input parameters from the user
    get_input(&person);

    // Calculate the BMI of the person
    float bmi = calculate_bmi(&person);

    // Print the BMI and a message
    print_bmi(&person);

    return 0;
}