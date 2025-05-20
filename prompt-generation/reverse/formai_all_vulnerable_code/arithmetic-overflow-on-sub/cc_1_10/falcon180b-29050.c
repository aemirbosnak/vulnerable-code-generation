//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the given string
void print_string(char* str) {
    printf("%s", str);
}

// Function to display the typing speed
void display_speed(int characters, int time) {
    float speed = (float) characters / time;
    printf("Your typing speed is: %.2f characters per second\n", speed);
}

// Function to generate a random string
char* generate_string(int length) {
    char* str = (char*) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = (char) (rand() % 26 + 'a');
    }
    str[length] = '\0';
    return str;
}

int main() {
    srand(time(NULL));

    // Get the length of the string
    int length;
    printf("Enter the length of the string: ");
    scanf("%d", &length);

    // Generate a random string
    char* str = generate_string(length);

    // Get the time limit
    int time_limit;
    printf("Enter the time limit in seconds: ");
    scanf("%d", &time_limit);

    // Start the timer
    clock_t start_time = clock();

    // Start typing
    print_string(str);

    // Get the user input
    char input[100];
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    float time_taken = (float) (end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of characters typed
    int characters_typed = strlen(input);

    // Display the typing speed
    display_speed(characters_typed, time_taken);

    return 0;
}