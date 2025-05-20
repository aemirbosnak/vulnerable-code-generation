//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *input;
    int length;
} Input;

void print_hint(char *hint) {
    printf("Hint: %s\n", hint);
}

int main() {
    char *hints[] = {
        "Start with a number between 1 and 9.",
        "Continue with any number, but don't repeat the previous one.",
        "End with a number that is not a prime.",
    };
    int hint_index = 0;

    Input input;
    input.input = malloc(100);
    input.length = 0;

    while (1) {
        printf("Enter a sequence of numbers (separated by spaces): ");
        scanf("%s", input.input);

        int valid = 1;
        int number = -1;
        int last_number = -1;
        int prime = 1;
        for (int i = 0; i < input.length; i++) {
            if (input.input[i] < '1' || input.input[i] > '9') {
                valid = 0;
                break;
            }
            number = input.input[i] - '0';
            if (number <= 0 || number > 9) {
                valid = 0;
                break;
            }
            if (number == last_number) {
                valid = 0;
                break;
            }
            if (number == 2) {
                prime = 0;
                break;
            }
            for (int j = 2; j < number; j++) {
                if (number % j == 0) {
                    prime = 0;
                    break;
                }
            }
            last_number = number;
        }
        if (!valid) {
            print_hint(hints[hint_index]);
            hint_index++;
            continue;
        }
        if (prime) {
            print_hint(hints[hint_index]);
            hint_index++;
            continue;
        }
        break;
    }

    printf("Valid input: %s\n", input.input);
    free(input.input);
    return 0;
}