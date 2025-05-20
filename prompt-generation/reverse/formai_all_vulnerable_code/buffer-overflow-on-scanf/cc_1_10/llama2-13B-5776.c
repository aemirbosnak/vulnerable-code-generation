//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Define a structure to hold name and age
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person;

// Function to read name and age from user
void get_info(person *p) {
    printf("Hello there! Please enter your name: ");
    fgets(p->name, MAX_NAME_LENGTH, stdin);
    printf("Now, please enter your age: ");
    scanf("%d", &p->age);
}

// Function to display name and age
void display_info(person p) {
    printf("Hello, %s! You are %d years old.\n", p.name, p.age);
}

int main() {
    person p;

    // Ask user for name and age
    get_info(&p);

    // Display name and age
    display_info(p);

    // Ask user if they want to play a game
    printf("Do you want to play a game? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    // If user wants to play, play a game
    if (choice == 'y') {
        printf("Great! Let's play a game of guess my age. I'll think of a number between 1 and 100, and you try to guess it.\n");
        int guess;
        printf("Go ahead and make your first guess: ");
        scanf("%d", &guess);

        // Keep playing until user guesses correctly
        while (guess != p.age) {
            printf("Too high! The correct answer is %d. Keep trying...\n", p.age);
            guess = -1;
            scanf(" %d", &guess);
        }
        printf("Wow, you guessed it! You're a genius! The correct answer was %d.\n", p.age);
    }

    return 0;
}