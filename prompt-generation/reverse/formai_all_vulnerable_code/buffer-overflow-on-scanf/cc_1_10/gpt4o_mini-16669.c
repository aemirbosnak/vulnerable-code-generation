//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

const char *sentences[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Pack my box with five dozen liquor jugs.",
    "How razorback-jumping frogs can level six piqued gymnasts!",
    "The five boxing wizards jump quickly.",
    "Jinxed wizards pluck ivy from the big quilt."
};

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a sentence to type.\n");
    printf("Try to type it as quickly and accurately as possible.\n");
    printf("Press Enter to start...\n");
    getchar();
}

char* get_sentence() {
    srand(time(NULL));
    return (char *)sentences[rand() % MAX_SENTENCES];
}

double calculate_typing_speed(double time_taken, int length) {
    return (length / time_taken) * 60.0; // Speed in words per minute
}

void run_typing_test() {
    char typed[MAX_LENGTH];
    char *sentence = get_sentence();
    int length = strlen(sentence);
  
    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", sentence);
    
    clock_t start = clock();
    fgets(typed, MAX_LENGTH, stdin);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = calculate_typing_speed(time_taken, length);
    
    if (strncmp(typed, sentence, length) == 0) {
        printf("Correct! You typed the sentence correctly.\n");
    } else {
        printf("Oops! There was an error in your typing.\n");
    }
    
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f words per minute\n", speed);
}

int main() {
    print_instructions();
    
    char choice;
    do {
        run_typing_test();
        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar();  // Clear newline character from buffer
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for participating in the typing speed test! Goodbye!\n");
    return 0;
}