//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Prototypes
void display_instructions();
void start_typing_test(const char *text);
double calculate_speed(double seconds, int characters);
void print_result(double speed);

int main() {
    const char *passage = "But, soft! What light through yonder window breaks?\n"
                          "It is the east, and Juliet is the sun.\n"
                          "Arise, fair sun, and kill the envious moon,\n"
                          "Who is already sick and pale with grief.\n";

    display_instructions();
    start_typing_test(passage);
    
    return 0;
}

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You shall type the following passage as quickly as you can:\n\n");
}

void start_typing_test(const char *text) {
    printf("%s\n", text);
    printf("Press ENTER when you are ready to start...\n");
    getchar();  // wait for user to start

    clock_t start_time = clock();
    
    char user_input[500];
    printf("\nType here: \n");
    fgets(user_input, sizeof(user_input), stdin);  // getting user input
    
    clock_t end_time = clock();
    
    // Remove the newline character at the end (if it's there)
    user_input[strcspn(user_input, "\n")] = 0;

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int typed_chars = strlen(user_input);
    
    printf("\nYou typed %d characters in %.2f seconds.\n", typed_chars, time_taken);
    double speed = calculate_speed(time_taken, typed_chars);
    print_result(speed);
}

double calculate_speed(double seconds, int characters) {
    if (seconds == 0) return 0.0;  // Prevent division by zero
    return (characters / seconds) * 60.0;  // Speed in characters per minute
}

void print_result(double speed) {
    printf("Your typing speed is: %.2f characters per minute.\n", speed);
    if (speed < 20.0) {
        printf("Alas! Thy speed is but slow, a turtle doth outpace thee!\n");
    } else if (speed < 40.0) {
        printf("Thou art improving, but still needeth more practice!\n");
    } else if (speed < 60.0) {
        printf("Fair! Thy speed art respectable, yet more could be achieved!\n");
    } else {
        printf("Bravo! Thou art swift as the wind, like Romeo on his quest!\n");
    }
}