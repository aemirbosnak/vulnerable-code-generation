//LLAMA2-13B DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_STATEMENTS 10

// Define the possible states of the Turing machine
typedef enum {
    QUIT,
    RUN,
    LEFT,
    RIGHT,
    OUTPUT,
    ACCEPT,
    REJECT
} state_t;

// Define the tape alphabet and the blank symbol
typedef char tape_t[10];
#define BLANK ' '

// Define the Turing machine's current state and tape
state_t state = QUIT;
tape_t tape = "";

// Define the input string and the current position on the tape
char input[MAX_INPUT];
int pos = 0;

// Define the function to move the tape left or right
void move(state_t dir) {
    if (dir == LEFT) {
        tape[pos] = BLANK;
        pos--;
    } else {
        tape[pos] = BLANK;
        pos++;
    }
}

// Define the function to output a symbol
void output(char sym) {
    printf("%c", sym);
}

// Define the function to advance the tape and change the state
void advance() {
    if (state == ACCEPT) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    state = QUIT;
}

int main() {
    // Read the input string from the user
    printf("Enter a string: ");
    fgets(input, MAX_INPUT, stdin);
    pos = strlen(input) - 1;

    // Initialize the tape with the input string
    for (int i = 0; i < pos; i++) {
        tape[i] = input[i];
    }
    tape[pos] = BLANK;

    // Start the Turing machine in the QUIT state
    state = QUIT;

    // Loop until the Turing machine reaches the ACCEPT state
    while (state != ACCEPT) {
        // Determine the next state based on the current state and the symbol on the tape
        if (state == RUN) {
            if (tape[pos] == BLANK) {
                move(LEFT);
            } else {
                move(RIGHT);
            }
        } else if (state == LEFT) {
            move(LEFT);
        } else if (state == RIGHT) {
            move(RIGHT);
        } else if (state == OUTPUT) {
            output(tape[pos]);
            move(QUIT);
        } else if (state == ACCEPT) {
            advance();
        }

        // Check if the tape is empty
        if (pos == 0) {
            state = QUIT;
        }
    }

    return 0;
}