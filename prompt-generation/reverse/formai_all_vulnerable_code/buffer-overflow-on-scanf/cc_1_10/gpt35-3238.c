//FormAI DATASET v1.0 Category: Spam Detection System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input string contains the word "spam"
int check_for_spam(char* input_string) {
    char* spam_string = "spam";
    int len_input = strlen(input_string);
    int len_spam = strlen(spam_string);

    for (int i = 0; i < len_input; i++) {
        if (input_string[i] == spam_string[0]) {
            int flag = 1;
            for (int j = 1; j < len_spam; j++) {
                if (input_string[i+j] != spam_string[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                return 1;
            }
        }
    }
    return 0;
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Spam Detection System!\n");

    // Infinite loop for user input
    while (1) {
        // Get user input
        printf("\nEnter a string (or type 'exit' to quit): ");
        char input_string[100];
        scanf("%[^\n]", input_string);
        getchar();

        // Check if user wants to exit
        if (strcmp(input_string, "exit") == 0) {
            printf("Thank you for using the Spam Detection System!\n");
            exit(0);
        }

        // Check for spam
        int spam = check_for_spam(input_string);

        // Print appropriate message
        if (spam == 1) {
            printf("WARNING! This message contains SPAM!\n");
        } else {
            printf("This message is spam-free.\n");
        }
    }

    return 0;
}