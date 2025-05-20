//LLAMA2-13B DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info_t;

// Function to read user information from the console
void read_user_info(user_info_t* user) {
    printf("What's your name? ");
    fgets(user->name, MAX_NAME_LENGTH, stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove newline character

    printf("How old are you? ");
    scanf("%d", &user->age);
}

// Function to print a random joke
void print_joke(void) {
    // Generate a random joke
    char joke[100];
    sprintf(joke, "Why did the %s cross the road? To get to the other side... of the joke!",
             rand() % 2 ? "chicken" : "eggplant");

    // Print the joke
    printf("%s\n", joke);
}

int main(void) {
    user_info_t user;

    // Read user information from the console
    read_user_info(&user);

    // Check if the user is old enough for the joke
    if (user.age >= 18) {
        // Print the joke
        print_joke();
    } else {
        printf("Sorry, you're too young for this joke!\n");
    }

    return 0;
}