//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define MAX_PROMPT_LENGTH 512

void display_menu() {
    printf("==================================\n");
    printf("         Typing Speed Test        \n");
    printf("==================================\n");
    printf("Select an option:\n");
    printf("1. Start Test\n");
    printf("2. Exit\n");
    printf("==================================\n");
}

void get_test_string(char *prompt) {
    const char *texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "In the midst of chaos, there is also opportunity."
    };
    
    int random_index = rand() % (sizeof(texts) / sizeof(texts[0]));
    strcpy(prompt, texts[random_index]);
}

void calculate_speed(int typed_length, double time_taken) {
    double speed = (typed_length / 5.0) / (time_taken / 60.0); // WPM calculation
    printf("Your typing speed: %.2f WPM\n", speed);
}

void typing_test() {
    char prompt[MAX_PROMPT_LENGTH];
    char user_input[MAX_TEXT_LENGTH];
    
    get_test_string(prompt);
    
    printf("\nType the following text:\n");
    printf("%s\n\n", prompt);
    
    time_t start_time, end_time;
    time(&start_time);

    printf("Start typing now:\n");
    fgets(user_input, sizeof(user_input), stdin);
    
    time(&end_time);
    
    double time_taken = difftime(end_time, start_time);
    
    if (strcmp(user_input, prompt) == 0) {
        printf("Perfect! You typed it correctly.\n");
    } else {
        printf("You didn't type the text exactly as shown. Keep practicing!\n");
    }
    
    int typed_length = strlen(user_input);
    calculate_speed(typed_length, time_taken);
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after choice input

        switch (choice) {
            case 1:
                typing_test();
                break;
            case 2:
                printf("Exiting the Typing Speed Test. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}