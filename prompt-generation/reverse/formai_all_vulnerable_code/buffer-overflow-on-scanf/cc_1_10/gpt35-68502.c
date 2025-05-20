//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int wpm_goal = 70; // Words Per Minute goal
    int wpm_typist = 0; // Typist's average Words Per Minute
    int accuracy = 0; // Typist's accuracy percentage
    int word_count = 0; // Words typed by the typist
    int error_count = 0; // Errors made by the typist
    int time_taken = 0; // Time taken by the typist
    
    srand(time(NULL)); // Seed for random word generation
    
    char words[10][10] = {"sky", "grass", "fire", "water", "stone", "metal", "sand", "dust", "rust", "blood"}; // Array of words to be typed
    int total_words = sizeof(words) / sizeof(words[0]); // Total number of words in the array
    
    printf("Welcome to the Typing Speed Test in a post-apocalyptic world!\n\n");
    printf("Your goal is to reach a typing speed of %d WPM with at least %d%% accuracy.\n", wpm_goal, accuracy);
    printf("You will be given 10 random words to type. Ready? Press enter to start.\n");
    
    getchar(); // Waits for user to press enter
    
    time_t start_time = time(NULL); // Start time
    
    for (int i = 0; i < 10; i++) {
        int word_index = rand() % total_words; // Random index for selecting a word
        printf("%s ", words[word_index]);
        
        char typed_word[10]; // Array to store typed word
        scanf("%s", typed_word);
        
        if (strcmp(words[word_index], typed_word) == 0) { // If word is typed correctly
            wpm_typist += 1; // Increment WPM by 1
            word_count += 1; // Increment word count by 1
        } 
        else { // If word is typed incorrectly
            error_count += 1; // Increment error count by 1
        }
    }
    
    time_t end_time = time(NULL); // End time
    time_taken = (int) difftime(end_time, start_time); // Calculates time taken
    
    wpm_typist = (word_count / time_taken) * 60; // Calculates WPM
    
    accuracy = ((word_count - error_count) / word_count) * 100; // Calculates accuracy
    
    printf("\n\nCongratulations on completing the Typing Speed Test!\n");
    printf("You typed an average of %d WPM with %d%% accuracy in %d seconds.\n", wpm_typist, accuracy, time_taken);
    
    if (wpm_typist >= wpm_goal && accuracy >= 90) { // If Typist's WPM and accuracy meet the goal
        printf("You have passed the test! You are now a certified Typing Master in this post-apocalyptic world!\n");
    } 
    else { // If Typist's WPM and/or accuracy doesn't meet the goal
        printf("You have failed the test. You need to work harder to survive in this post-apocalyptic world!\n");
    }
    
    return 0;
}