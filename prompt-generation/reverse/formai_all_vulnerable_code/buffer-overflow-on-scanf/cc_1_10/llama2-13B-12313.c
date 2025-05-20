//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and variables
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MIN_AGE 18
#define MAX_GPA 4.0
#define MIN_GPA 0.0
#define MAX_BOOK_LENGTH 500
#define MIN_BOOK_LENGTH 100

// Function to read a name from the user
void get_name(char *name) {
    printf("Hello there! Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
}

// Function to read an age from the user
void get_age(int *age) {
    printf("Oh my, how old are you? ");
    scanf("%d", age);
}

// Function to read a GPA from the user
void get_gpa(double *gpa) {
    printf("Wow, what's your GPA? ");
    scanf("%lf", gpa);
}

// Function to read a book length from the user
void get_book_length(int *length) {
    printf("Hey there, how long is your book? ");
    scanf("%d", length);
}

// Main function
int main() {
    // Declare some variables
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
    int book_length;

    // Call the functions to read the user input
    get_name(name);
    get_age(&age);
    get_gpa(&gpa);
    get_book_length(&book_length);

    // Print the user input
    printf("Hello %s! You are %d years old and have a GPA of %lf. Your book is %d pages long.\n", name, age, gpa, book_length);

    // Add some randomness to the program
    srand(time(NULL));
    if (age > MIN_AGE && age < MAX_AGE) {
        printf("You are exactly %d years old! Nice!\n", age);
    } else if (age == MIN_AGE || age == MAX_AGE) {
        printf("Happy birthday! Today is your %dth birthday!\n", age);
    } else {
        printf("Oops, you are not old enough... yet! Try again later.\n");
    }

    // Print a message based on the GPA
    if (gpa > MAX_GPA) {
        printf("Congratulations, you have an amazing GPA of %lf! You must be a genius!\n", gpa);
    } else if (gpa < MIN_GPA) {
        printf("Don't worry, you can still improve your GPA. Keep trying!\n");
    } else {
        printf("Your GPA is just right, keep up the good work!\n");
    }

    // Print a message based on the book length
    if (book_length > MAX_BOOK_LENGTH) {
        printf("Wow, your book is so long! It must be a bestseller!\n");
    } else if (book_length < MIN_BOOK_LENGTH) {
        printf("That's a pretty short book. Maybe you should add more chapters?\n");
    } else {
        printf("Your book is just the right length. Good job!\n");
    }

    return 0;
}