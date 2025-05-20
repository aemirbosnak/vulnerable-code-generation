//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LENGTH 1024

void display_intro() {
    printf("************************************\n");
    printf("*      A Typing Test:              *\n");
    printf("*        Romeo and Juliet          *\n");
    printf("************************************\n\n");
    
    printf("In fair Verona, where we set our scene,\n");
    printf("Two households, both alike in dignity,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n\n");
    
    printf("Test your typing speed, noble friend.\n");
    printf("Type the lines that follow with great care,\n");
    printf("In but a minute, you shall compare,\n");
    printf("How swift your fingers can descend!\n\n");
}

void type_test(const char *sample_text, int *duration, int *letters_typed) {
    char user_input[MAX_LENGTH];
    time_t start_time, end_time;
    
    printf("Type the following text:\n\n");
    printf("\"%s\"\n\n", sample_text);
    printf("Press Enter when you are ready...\n");
    getchar();
    
    start_time = time(NULL);
    
    fgets(user_input, MAX_LENGTH, stdin);
    
    end_time = time(NULL);
    
    *duration = difftime(end_time, start_time);
    *letters_typed = strlen(user_input) - 1; // Ignore the newline character
}

void calculate_and_display_results(int duration, int letters_typed) {
    double wpm = (letters_typed / 5.0) / (duration / 60.0);
    
    printf("\n----- Results -----\n");
    printf("Time taken: %d seconds\n", duration);
    printf("Letters typed: %d\n", letters_typed);
    
    if (duration > 0) {
        printf("Words per minute (WPM): %.2f\n", wpm);
    } else {
        printf("Error: Duration is zero!\n");
    }
    
    printf("-------------------\n");
}

int main() {
    char sample_text[] = "But, soft! What light through yonder window breaks? "
                         "It is the east, and Juliet is the sun.";
    
    int duration = 0;
    int letters_typed = 0;
    
    display_intro();
    type_test(sample_text, &duration, &letters_typed);
    calculate_and_display_results(duration, letters_typed);
    
    return 0;
}