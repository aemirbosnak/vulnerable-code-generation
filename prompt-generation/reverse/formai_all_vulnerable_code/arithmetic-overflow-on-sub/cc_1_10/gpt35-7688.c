//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main() {
    char *sentences[] = {"The quick brown fox jumps over the lazy dog", "I am a typing speed demon!", "Hakuna Matata, what a wonderful phrase", "Sphinx of black quartz, judge my vow", "Pack my box with five dozen liquor jugs", "How vexingly quick daft zebras jump", "The five boxing wizards jump quickly", "My mnemonic is a dyslexic's nightmare"};
    // Array of sentences to be typed
    
    int total_time = 0; // Total time taken to type all sentences
    
    srand(time(NULL)); // Initialize random seed
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type and you must type it as quickly as possible.\n");
    printf("There will be a new sentence each time you finish typing one.\n");
    printf("Press ENTER to start.\n");
    getchar(); // Wait for user to press enter
    
    for (int i = 0; i < sizeof(sentences)/sizeof(sentences[0]); i++) { // Loop through all sentences in array
        char *sentence = sentences[rand()%sizeof(sentences)/sizeof(sentences[0])]; // Choose a random sentence
        printf("Type this sentence as quickly and accurately as possible:\n%s\n", sentence);
        clock_t start_time = clock(); // Get starting time
        char input[200]; // String to store user input
        fgets(input, 200, stdin); // Get user input
        
        // Remove newline character from input
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        
        // Calculate time taken
        clock_t end_time = clock();
        int time_taken = (end_time-start_time)/CLOCKS_PER_SEC;
        total_time += time_taken;
        
        // Calculate accuracy and words per minute
        int errors = 0;
        int words_typed = 1;
        for (int j = 0; j < strlen(input); j++) {
            if (sentence[j] != input[j]) {
                errors++;
            }
            if (isspace(sentence[j])) {
                words_typed++;
            }
        }
        int accuracy = ((strlen(sentence)-errors)*100)/strlen(sentence);
        int wpm = words_typed*(60/time_taken);
        
        // Print results
        printf("\nTime taken: %d seconds\n", time_taken);
        printf("Accuracy: %d%%\n", accuracy);
        printf("Words per minute: %d\n\n", wpm);
    }
    
    // Calculate and print overall results
    int average_time = total_time/sizeof(sentences)/sizeof(sentences[0]);
    int overall_wpm = (sizeof(sentences)/sizeof(sentences[0]))*(60/average_time);
    printf("Congratulations! You have completed the Typing Speed Test.\n");
    printf("Your overall wpm: %d\n", overall_wpm);
    
    return 0;
}