//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants and variables
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MIN_AGE 18
#define NUM_PEOPLE 10

// Structure to hold person information
struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

// Function to print a cheerful message
void print_message(char *message) {
    printf("🎉 %s\n", message);
}

// Function to get user input and store it in an array
void get_input(struct person *people, int num_people) {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("👋 What's your name? ");
        fgets(people[i].name, MAX_NAME_LENGTH, stdin);
        printf("🤔 How old are you? ");
        scanf("%d", &people[i].age);
    }
}

// Function to check if the input is valid
void check_input(struct person people[], int num_people) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (people[i].age < MIN_AGE || people[i].age > MAX_AGE) {
            printf("❓ Age must be between %d and %d\n", MIN_AGE, MAX_AGE);
            return;
        }
    }
}

// Function to print the information
void print_info(struct person people[], int num_people) {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("👋 Hi there, %s! You are %d years old.\n", people[i].name, people[i].age);
    }
}

int main() {
    // Declare an array of structs to hold the person information
    struct person people[NUM_PEOPLE];

    // Get the user input and store it in the array
    get_input(people, NUM_PEOPLE);

    // Check if the input is valid
    check_input(people, NUM_PEOPLE);

    // Print the information
    print_info(people, NUM_PEOPLE);

    return 0;
}