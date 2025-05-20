//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LENGTH 300
#define NUMBER_OF_TESTS 5

void display_instructions() {
    printf("**************************************\n");
    printf("*     The Royal Typing Speed Test    *\n");
    printf("**************************************\n");
    printf("Greetings, noble scribe! Prove thy typing prowess.\n\n");
    printf("Instructions:\n");
    printf("1. You shall be presented with a line of text.\n");
    printf("2. When prompted, type the text as swiftly as thou can.\n");
    printf("3. Your time shall be measured, and your speed calculated.\n");
    printf("4. May fortune favor your fingers!\n\n");
}

void generate_text(char *text) {
    const char *sample_texts[NUMBER_OF_TESTS] = {
        "In the kingdom of code, all are equal.",
        "Swiftly the knights rode into the sunset.",
        "A brave scribe conquers the blank page.",
        "Magic exists in the lines of a well-crafted script.",
        "With quill in hand, he penned the legends of yore."
    };
    
    // Choose a random text from the samples
    srand(time(NULL));
    int random_index = rand() % NUMBER_OF_TESTS;
    strcpy(text, sample_texts[random_index]);
}

double calculate_typing_speed(int typed_length, double time_seconds) {
    // Speed is calculated in words per minute (WPM)
    return (typed_length / 5.0) / (time_seconds / 60.0);
}

void perform_typing_test() {
    char text[MAX_TEXT_LENGTH];
    char user_input[MAX_TEXT_LENGTH];
    
    generate_text(text);
    
    printf("Text to type:\n\"%s\"\n\n", text);
    printf("Are you ready? Press ENTER to begin...\n");
    getchar();
    
    clock_t start_time = clock();
    
    printf("Begin typing now:\n");
    fgets(user_input, sizeof(user_input), stdin);
    
    clock_t end_time = clock();
    
    // Strip newline character
    user_input[strcspn(user_input, "\n")] = 0;
    
    double time_seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double speed = calculate_typing_speed(strlen(user_input), time_seconds);
    
    if(strcmp(user_input, text) == 0) {
        printf("Huzzah! Thou hast typed correctly!\n");
        printf("Your typing speed: %.2f WPM\n", speed);
    } else {
        printf("Alas! Thy typing was not correct. Better luck next time!\n");
    }
}

int main() {
    display_instructions();
    
    char continue_test = 'y';
    while (continue_test == 'y') {
        perform_typing_test();
        printf("Wouldst thou like to try again? (y/n): ");
        scanf(" %c", &continue_test);
        getchar(); // Clear the newline character from input buffer
    }

    printf("Fare thee well, brave scribe! Until we meet again!\n");
    return 0;
}