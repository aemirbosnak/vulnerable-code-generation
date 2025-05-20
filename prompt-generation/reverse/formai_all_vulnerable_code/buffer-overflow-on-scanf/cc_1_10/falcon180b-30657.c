//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 10
#define MAX_CODE_WORDS 100

// Function prototypes
void generate_morse_code(char *code);
void print_morse_code(char *code);
void add_morse_code(char *code);

int main() {
    char input_code[MAX_CODE_LENGTH];
    int num_codes;

    printf("Enter number of codes to generate: ");
    scanf("%d", &num_codes);

    for (int i = 0; i < num_codes; i++) {
        printf("Enter code %d: ", i + 1);
        scanf("%s", input_code);
        generate_morse_code(input_code);
        print_morse_code(input_code);
        add_morse_code(input_code);
    }

    return 0;
}

// Function to generate Morse code from input string
void generate_morse_code(char *code) {
    char *morse_code = malloc(MAX_CODE_LENGTH * sizeof(char));
    int code_length = strlen(code);

    for (int i = 0; i < code_length; i++) {
        switch (code[i]) {
            case 'A':
                strcat(morse_code, ".-");
                break;
            case 'B':
                strcat(morse_code, "-...");
                break;
            case 'C':
                strcat(morse_code, "-.-.");
                break;
            // Add more cases for other letters and numbers
        }
    }

    // Add the generated Morse code to a list
    add_morse_code(morse_code);
}

// Function to print Morse code
void print_morse_code(char *code) {
    printf("%s\n", code);
}

// Function to add Morse code to a list
void add_morse_code(char *code) {
    int num_codes = 0;
    char **morse_codes = malloc(MAX_CODE_WORDS * sizeof(char *));

    // Check if the list is full
    if (num_codes >= MAX_CODE_WORDS) {
        printf("List is full.\n");
        return;
    }

    // Add the Morse code to the list
    morse_codes[num_codes] = code;
    num_codes++;
}