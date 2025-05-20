//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

// Array of C cat language words to be translated
char c_cats[][20] = {"meow", "purr", "hiss", "scratch", "claw", 
                      "sleep", "eat", "drink", "play", "hunt"};

// Array of English words for C cat language translation
char english[][20] = {"Hello", "How are you?", "I am hungry", "Can you pet me?", 
                      "What is this?", "I want to play", "I am tired", "Goodbye"};

// Function to perform C cat language translation
char* c_cat_translate(char input[]) {
    static char output[MAX_INPUT_SIZE]; // initialize output array
    char* token = strtok(input, " "); // split input string into tokens
 
    while (token != NULL) {
        int found = 0; // flag to check token presence in C cat language words array
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, c_cats[i]) == 0) { // token found in C cat language words array
                strcat(output, english[i]); // append English translation to output array
                strcat(output, " "); // add space separator
                found = 1; // set flag to 1
                break; // move to the next token
            }
        }
        if (found == 0) { // token not found in C cat language words array
            strcat(output, token); // copy token as it is to output array
            strcat(output, " "); // add space separator
        }
        token = strtok(NULL, " "); // move to next token
    }
    return output; //return the final output
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter C cat language message:\n");
    fgets(input, MAX_INPUT_SIZE, stdin); // accept input from user
    
    // remove newline character from input string
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    char* output = c_cat_translate(input); // translate input string
    printf("Translated message: %s\n", output); // print the translated message
    
    return 0;
}