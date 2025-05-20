//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_TIME 60

int main() {

    char str[MAX_STRING_LENGTH];
    int correct = 0;
    int mistakes = 0;
    int count = 0;
    double time_spent = 0.0;
    clock_t begin, end;
 
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast and accurately as you can within 60 seconds: \n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    fgets(str, MAX_STRING_LENGTH, stdin); // get user input
    str[strcspn(str, "\n")] = 0; // remove newline character added by fgets

    begin = clock();

    while (time_spent < MAX_TIME) {
        
        if (count == 0) {
            printf("Type the same sentence again: \n");
        }

        fgets(str, MAX_STRING_LENGTH, stdin);
        str[strcspn(str, "\n")] = 0;

        if (strcmp(str,"The quick brown fox jumps over the lazy dog.") == 0) {
            printf("Congratulations! You typed the sentence correctly.\n");
            correct++;
        } else {
            printf("Sorry, you made a mistake. Please try again.\n");
            mistakes++;
        }
    
        count++;
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    }
    
    printf("Time's up! You typed %d sentences correctly and made %d mistakes.\n", correct, mistakes);
    printf("Your typing speed is %.2f characters per minute.\n", (double)(correct * strlen("The quick brown fox jumps over the lazy dog.")) / (time_spent / 60));

    return 0;
}