//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

// Define the pattern configuration structure
typedef struct {
    int num_spaces;   // Number of spaces in the pattern
    int num_dots;    // Number of dots in the pattern
    int num_lines;   // Number of lines in the pattern
} pattern_config_t;

// Function to print the pattern
void print_pattern(pattern_config_t config) {
    int i, j;

    // Print the configured number of spaces
    for (i = 0; i < config.num_spaces; i++) {
        printf(" ");
    }

    // Print the configured number of dots
    for (j = 0; j < config.num_dots; j++) {
        printf(".");
    }

    // Print a newline character
    printf("\n");

    // Print the configured number of lines
    for (i = 0; i < config.num_lines; i++) {
        print_pattern(config);
    }
}

int main() {
    // Prompt the user for the pattern configuration
    printf("Enter the number of spaces in the pattern: ");
    int num_spaces;
    scanf("%d", &num_spaces);

    printf("Enter the number of dots in the pattern: ");
    int num_dots;
    scanf("%d", &num_dots);

    printf("Enter the number of lines in the pattern: ");
    int num_lines;
    scanf("%d", &num_lines);

    // Create a pattern configuration structure
    pattern_config_t config = {num_spaces, num_dots, num_lines};

    // Print the pattern
    print_pattern(config);

    return 0;
}