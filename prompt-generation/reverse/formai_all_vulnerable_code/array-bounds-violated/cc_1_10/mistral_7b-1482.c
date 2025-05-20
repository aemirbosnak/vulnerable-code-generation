//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

typedef struct {
    char shape;
    int size;
} Shape;

Shape shapes[] = {
    {'O', 1}, {'X', 2}, {'S', 3}, {'I', 4}, {'Z', 5}, {'L', 6}, {'T', 7}, {'U', 8}, {'V', 9}, {'W', 10}
};

void sanitize_input(char *input) {
    int i, j;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] < ' ' || input[i] > '~') {
            input[i] = '\0';
            for (j = i; input[j] != '\0'; j++) {
                input[j] = input[j + 1];
            }
            i--;
        }
    }
}

void print_shape(Shape shape) {
    int i, j;
    for (i = 0; i < shape.size; i++) {
        for (j = 0; j < shape.size; j++) {
            putchar(shape.shape);
        }
        putchar('\n');
    }
}

void print_message(char *input) {
    int i, j;
    for (i = 0; input[i] != '\0'; i++) {
        for (j = 0; j < shapes[input[i] - 'A'].size; j++) {
            putchar(shapes[input[i] - 'A'].shape);
        }
        putchar(' ');
    }
    putchar('\n');
}

int main() {
    char input[MAX_INPUT_SIZE];
    int random_number;
    Shape current_shape;

    srand(time(NULL));
    random_number = rand() % 11;
    current_shape = shapes[random_number];

    printf("Welcome to the shape-shifting input sanitizer!\n");
    print_shape(current_shape);

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitize_input(input);

    printf("Sanitized input: ");
    print_message(input);

    return 0;
}