//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random text
char* generate_text(int length) {
    char* text = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        text[i] = 'a' + (rand() % 26);
    }
    text[length] = '\0';
    return text;
}

// Function to calculate typing speed
float calculate_typing_speed(int length, int time) {
    return (float)length / time * 60;
}

// Main function
int main() {
    // Set random seed
    srand(time(NULL));

    // Get user input
    int length;
    printf("Enter the length of the text: ");
    scanf("%d", &length);

    // Generate random text
    char* text = generate_text(length);

    // Display the text
    printf("Type the following text:\n%s\n", text);

    // Start timer
    clock_t start = clock();

    // Wait for user to finish typing
    char input[length + 1];
    scanf("%s", input);

    // Stop timer
    clock_t end = clock();

    // Calculate typing speed
    float speed = calculate_typing_speed(length, end - start);

    // Display results
    printf("Your typing speed is: %.2f words per minute\n", speed);

    // Free allocated memory
    free(text);

    return 0;
}