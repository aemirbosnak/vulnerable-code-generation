//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char typed_text[MAX_LENGTH];
    char generated_text[MAX_LENGTH];
    float time_taken;
    int correct_characters_typed = 0;
    int total_characters_typed = 0;
    int i;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can and press enter:\n");

    // Generate random sentence to be typed
    srand(time(0));
    for (i = 0; i < MAX_LENGTH-1; i++) {
        generated_text[i] = 'a' + (rand() % 26);
    }
    generated_text[MAX_LENGTH-1] = '\0';
    printf("%s\n", generated_text);

    // Start the timer
    clock_t start = clock();

    // Get the typed text from user
    fgets(typed_text, MAX_LENGTH, stdin);

    // Calculate the total characters typed
    total_characters_typed = strlen(typed_text);

    // Check if each character in typed text matches the generated text
    for (i = 0; i < total_characters_typed-1; i++) {
        if (typed_text[i] == generated_text[i]) {
            correct_characters_typed++;
        }
    }

    // Calculate the time taken to type
    time_taken = (float)(clock() - start) / CLOCKS_PER_SEC;

    // Calculate and display the typing speed
    float typing_speed = (float)correct_characters_typed / time_taken * 60;
    printf("\n\nYour typing speed is %.2f characters per minute\n", typing_speed);

    return 0;
}