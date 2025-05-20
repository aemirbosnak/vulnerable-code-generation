//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to get the current time in seconds since the epoch
double getCurrentTime() {
    time_t current_time;
    time(&current_time);
    return (double)current_time;
}

// Function to display a message with the current time
void displayTime(double time) {
    printf("Current time: %f seconds\n", time);
}

// Function to calculate the typing speed in words per minute
double calculateTypingSpeed(int wordsTyped, int wordsPerMinute) {
    return (wordsTyped * 60) / wordsPerMinute;
}

int main() {
    // Get the current time
    double start_time = getCurrentTime();
    
    // Display the start time
    displayTime(start_time);
    
    // Read the number of words to type
    int wordsToType;
    printf("Enter the number of words to type: ");
    scanf("%d", &wordsToType);
    
    // Display the words to type
    printf("You have to type %d words.\n", wordsToType);
    
    // Start the timer
    double start_time_words = getCurrentTime();
    
    // Loop to get the number of words typed
    int wordsTyped = 0;
    while (wordsTyped < wordsToType) {
        char word[100];
        printf("Type a word: ");
        scanf("%s", word);
        wordsTyped++;
    }
    
    // End the timer
    double end_time_words = getCurrentTime();
    
    // Calculate the typing speed
    double wordsPerMinute = wordsTyped / (end_time_words - start_time_words);
    double typingSpeed = calculateTypingSpeed(wordsTyped, wordsPerMinute);
    
    // Display the typing speed
    printf("Your typing speed is %.2f words per minute.\n", typingSpeed);
    
    // Get the end time
    double end_time = getCurrentTime();
    
    // Display the end time
    displayTime(end_time);
    
    // Print the total time taken
    printf("Total time taken: %f seconds\n", end_time - start_time);
    
    return 0;
}