//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random sentence
char *generate_sentence(int length) {
    char *sentence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sentence[i] = (rand() % 26) + 'a';
    }
    sentence[length] = '\0';
    return sentence;
}

// Function to test the user's typing speed
int test_typing_speed(char *sentence) {
    printf("Type the following sentence: %s\n", sentence);
    char input[100];
    clock_t start = clock();
    scanf("%s", input);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    int correct = strcmp(input, sentence) == 0;
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Correct: %s\n", correct ? "Yes" : "No");
    return correct;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the desired sentence length from the user
    int length;
    printf("Enter the desired sentence length: ");
    scanf("%d", &length);

    // Generate a random sentence
    char *sentence = generate_sentence(length);

    // Test the user's typing speed
    int correct = test_typing_speed(sentence);

    // Calculate the accuracy
    double accuracy = (double)correct / length * 100;
    printf("Accuracy: %.2f%%\n", accuracy);

    // Free the allocated memory
    free(sentence);

    return 0;
}