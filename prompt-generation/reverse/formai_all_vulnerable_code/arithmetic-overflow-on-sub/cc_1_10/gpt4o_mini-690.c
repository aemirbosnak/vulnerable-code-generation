//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAPE_SIZE 100
#define MAX_RULES 50
#define MAX_STATE_NAME 10

typedef struct {
    char state[MAX_STATE_NAME];
    char symbol;
    char new_state[MAX_STATE_NAME];
    char new_symbol;
    char direction; // L for left, R for right
} Rule;

void initialize_tape(char tape[], int tape_size) {
    for (int i = 0; i < tape_size; i++) {
        tape[i] = ' ';
    }
}

void print_tape(char tape[], int tape_size, int head_position) {
    for (int i = 0; i < tape_size; i++) {
        if (i == head_position) {
            printf("[%c]", tape[i]);
        } else {
            printf(" %c ", tape[i]);
        }
    }
    printf("\n");
}

void execute_turing_machine(char tape[], int tape_size, Rule rules[], int rule_count, 
                            char initial_state[], int initial_position) {
    char current_state[MAX_STATE_NAME];
    strcpy(current_state, initial_state);
    int head_position = initial_position;

    while (1) {
        char current_symbol = tape[head_position];
        int rule_found = 0;

        for (int i = 0; i < rule_count; i++) {
            if (strcmp(current_state, rules[i].state) == 0 && current_symbol == rules[i].symbol) {
                tape[head_position] = rules[i].new_symbol;
                strcpy(current_state, rules[i].new_state);
                head_position += (rules[i].direction == 'R' ? 1 : -1);
                
                // Ensure head does not move out of bounds
                if (head_position < 0 || head_position >= tape_size) {
                    printf("Head moved out of bounds! Stopping execution.\n");
                    return;
                }
                rule_found = 1;
                break;
            }
        }

        if (!rule_found) {
            printf("No applicable rule found! Halting machine.\n");
            break;
        }

        print_tape(tape, tape_size, head_position);
    }
}

int main() {
    char tape[MAX_TAPE_SIZE];
    Rule rules[MAX_RULES];
    int rule_count = 0;
    int tape_size;
    char initial_state[MAX_STATE_NAME];
    int initial_position;

    printf("Enter the size of the tape (max %d): ", MAX_TAPE_SIZE);
    scanf("%d", &tape_size);
    if (tape_size > MAX_TAPE_SIZE) {
        printf("Tape size exceeds maximum limit.\n");
        return 1;
    }

    initialize_tape(tape, tape_size);
    
    printf("Enter the initial state of the machine: ");
    scanf("%s", initial_state);
    
    printf("Enter the initial head position (0 to %d): ", tape_size - 1);
    scanf("%d", &initial_position);
    if (initial_position < 0 || initial_position >= tape_size) {
        printf("Initial head position is out of bounds.\n");
        return 1;
    }

    printf("Define the rules of the Turing Machine (state symbol new_state new_symbol direction):\n");
    printf("Type 'END' as state to finish entering rules.\n");
    
    while (1) {
        Rule r;
        scanf("%s", r.state);
        if (strcmp(r.state, "END") == 0) {
            break;
        }
        getchar(); // Consume space before the next input
        r.symbol = getchar();
        getchar(); // Consume space
        scanf("%s", r.new_state);
        getchar(); // Consume space
        r.new_symbol = getchar();
        getchar(); // Consume space
        scanf(" %c", &r.direction);

        rules[rule_count++] = r;
        if (rule_count >= MAX_RULES) {
            printf("Maximum number of rules reached.\n");
            break;
        }
    }

    execute_turing_machine(tape, tape_size, rules, rule_count, initial_state, initial_position);
    
    return 0;
}