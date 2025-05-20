//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10

void display_instructions() {
    printf("Type the word that shows up as fast as you can!\n");
    printf("Press enter after each word.\n");
    printf("Type 'exit' to quit.\n\n");
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char* get_random_word() {
    char* words[MAX_WORDS] = {"hello", "world", "computer", "program", "keyboard", "mouse", "monitor", "internet", "software", "hardware", "algorithm", "database", "network", "memory", "storage", "interface", "processor", "monitor", "peripheral", "graphics"};
    int random_index = get_random_number(0, MAX_WORDS - 1);
    return words[random_index];
}

int main() {
    srand(time(0)); // seed random number generator
    
    display_instructions();
    
    int num_words = 0;
    double total_time = 0;
    char input[MAX_WORD_LENGTH];
    
    while (1) {
        char* word = get_random_word();
        printf("%s\n", word);
        clock_t start_time = clock();
        fgets(input, MAX_WORD_LENGTH, stdin);
        clock_t end_time = clock();
        double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        
        // remove trailing \n from input
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        
        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, word) == 0) {
            printf("Correct!\n");
            num_words++;
            total_time += time_elapsed;
        } else {
            printf("Incorrect, try again.\n");
        }
    }
    
    if (num_words > 0) {
        double avg_time = total_time / (double)num_words;
        double wpm = (double)num_words / (total_time / 60.0);
        printf("You typed %d words with an average time of %.2f seconds per word.\n", num_words, avg_time);
        printf("Your typing speed is %.0f words per minute.\n", wpm);
    }
    
    return 0;
}