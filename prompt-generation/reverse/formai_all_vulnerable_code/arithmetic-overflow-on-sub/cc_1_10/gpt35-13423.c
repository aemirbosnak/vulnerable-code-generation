//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int string_length = 50;
    char user_input[string_length];
    int i, j, correct_count = 0;
    double time_taken;

    // Set seed for randomization
    srand(time(0));

    // Generate random string of characters from alphabet
    char random_string[string_length + 1];
    for (i = 0; i < string_length; i++) {
        j = rand() % 26;
        random_string[i] = alphabet[j];
    }
    random_string[string_length] = '\0';

    // Start timer
    clock_t start_time = clock();

    // Prompt user to type generated string
    printf("Type this string as quickly as possible: %s\n", random_string);
    fgets(user_input, string_length + 1, stdin);

    // Stop timer
    clock_t end_time = clock();
    time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Compare user input to generated string
    for (i = 0; i < string_length; i++) {
        if (random_string[i] == user_input[i])
            correct_count++;
    }

    // Calculate typing speed and accuracy
    int typing_speed = (int) (string_length / time_taken) * 60;
    double accuracy = (double) (correct_count * 100) / string_length;

    // Display results
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %d words per minute\n", typing_speed);
    printf("Accuracy: %.2lf%%\n", accuracy);

    return 0;
}