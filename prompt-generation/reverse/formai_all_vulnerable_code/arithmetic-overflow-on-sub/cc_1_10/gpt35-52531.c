//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING 100 // Maximum length of input string

char* generate_sentence(); // Function to generate a random sentence
int calculate_typing_speed(int seconds, int characters); // Function to calculate typing speed

int main() {
    char input_string[MAX_STRING]; // Store user input
    int start_time, end_time; // Variables to track start and end time
    int seconds, characters; // Variables to calculate typing speed
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the sentence below as quickly as you can:\n");
    
    char* sentence = generate_sentence(); // Generate random sentence
    printf("%s\n", sentence);
    
    time(&start_time); // Record start time
    
    fgets(input_string, MAX_STRING, stdin); // Get user input
    
    time(&end_time); // Record end time
    
    // Calculate time taken and number of characters typed
    seconds = (int)(end_time - start_time);
    characters = 0;
    char* ptr = input_string;
    while (*ptr != '\n') {
        characters++;
        ptr++;
    }
    
    int typing_speed = calculate_typing_speed(seconds, characters);
    printf("You typed at a speed of %d characters per minute!\n", typing_speed);
    
    return 0;
}

char* generate_sentence() {
    char* sentences[] = {"The quick brown fox jumps over the lazy dog.",
                         "She sells seashells by the seashore.",
                         "Peter Piper picked a peck of pickled peppers.",
                         "How much wood would a woodchuck chuck if a woodchuck could chuck wood?"};
    int num_sentences = 4; // Number of sentences in the array
    
    srand(time(NULL)); // Seed random number generator
    int index = rand() % num_sentences; // Pick a random number between 0 and 3
    
    return sentences[index];
}

int calculate_typing_speed(int seconds, int characters) {
    int minutes = seconds / 60;
    int speed = (int)((double)characters / minutes);
    
    return speed;
}