//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_EQUATIONS 3

typedef enum {
    ROOM_START,
    ROOM_1,
    ROOM_2,
    ROOM_3,
    ROOM_END
} Room;

typedef struct {
    int operand1;
    int operand2;
    char operator;
    double answer;
} Equation;

Equation generate_equation() {
    Equation eq;
    eq.operand1 = rand() % 10 + 1; // Random number between 1 and 10
    eq.operand2 = rand() % 10 + 1; // Random number between 1 and 10
    int op = rand() % 2; // 0 for '+' and 1 for '-'
    if (op == 0) {
        eq.operator = '+';
        eq.answer = eq.operand1 + eq.operand2;
    } else {
        eq.operator = '-';
        eq.answer = eq.operand1 - eq.operand2;
    }
    return eq;
}

void print_intro() {
    printf("Welcome to the Mathematical Maze Adventure!\n");
    printf("You must solve equations to progress through the maze.\n");
    printf("Solve the equations correctly to unlock the next room.\n");
}

void navigate_room(Room current_room) {
    Equation equation;
    double player_answer;
    
    switch (current_room) {
        case ROOM_START:
            printf("You are at the START room.\n");
            equation = generate_equation();
            printf("Solve the equation: %d %c %d = ?\n", equation.operand1, equation.operator, equation.operand2);
            break;
        case ROOM_1:
            printf("You are in ROOM 1.\n");
            equation = generate_equation();
            printf("Solve the equation: %d %c %d = ?\n", equation.operand1, equation.operator, equation.operand2);
            break;
        case ROOM_2:
            printf("You are in ROOM 2.\n");
            equation = generate_equation();
            printf("Solve the equation: %d %c %d = ?\n", equation.operand1, equation.operator, equation.operand2);
            break;
        case ROOM_3:
            printf("You are in ROOM 3.\n");
            equation = generate_equation();
            printf("Solve the equation: %d %c %d = ?\n", equation.operand1, equation.operator, equation.operand2);
            break;
        case ROOM_END:
            printf("Congratulations! You've arrived at the END room!\n");
            return;
    }

    printf("Your answer: ");
    scanf("%lf", &player_answer);

    if (player_answer == equation.answer) {
        printf("Correct! You may proceed to the next room.\n");
    } else {
        printf("Incorrect. Try solving the same equation again!\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    Room current_room = ROOM_START;
    print_intro();
    
    while (current_room != ROOM_END) {
        navigate_room(current_room);
        current_room++; // Move to the next room
    }

    return 0;
}