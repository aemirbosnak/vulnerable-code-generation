//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
void welcome_message();
void menu();
void explore();
void solve_equation();
void find_clue();
int evaluate_expression(char* expression);
void get_input(char* input);

int main() {
    welcome_message();
    menu();

    return 0;
}

void welcome_message() {
    printf("Welcome to the Mathematical Adventure!\n");
    printf("In this adventure, your skills in mathematics will be challenged.\n");
    printf("Solve problems, find clues, and uncover the secrets of the mysterious town.\n");
}

void menu() {
    int choice;
    printf("\nChoose an action:\n");
    printf("1. Explore the town\n");
    printf("2. Solve an equation\n");
    printf("3. Find a clue\n");
    printf("4. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            explore();
            break;
        case 2:
            solve_equation();
            break;
        case 3:
            find_clue();
            break;
        case 4:
            printf("Thank you for playing the Mathematical Adventure!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please choose again.\n");
            menu();
    }
}

void explore() {
    char input[MAX_LENGTH];

    printf("\nYou are wandering through the town. You see a fountain with a puzzling inscription.\n");
    printf("Would you like to:\n");
    printf("1. Solve the inscription\n");
    printf("2. Go back to the menu\n");
    printf("Your choice: ");
    
    get_input(input);

    if (strcmp(input, "1") == 0) {
        printf("The inscription reads: 'What is the result of 5 + 3 * 2?'\n");
        int answer = evaluate_expression("5 + 3 * 2");
        printf("The answer is %d\n", answer);
    } else {
        menu();
    }
}

void solve_equation() {
    char equation[MAX_LENGTH];
    
    printf("\nEnter an equation to solve (e.g., 2 * x + 5 = 11): ");
    getchar(); // To consume the newline character
    fgets(equation, sizeof(equation), stdin);
    
    printf("You entered: %s", equation);
    // Here, you can implement a simple parser to extract values from the equation and solve it.
    // For demonstration, we'll just print it.
    printf("Solving the equation is under development...\n");
    
    menu();
}

void find_clue() {
    printf("\nYou found a clue hidden under a rock!\n");
    printf("It says: 'The first prime number is...'\n");
    
    // Wait for user input to proceed
    char input[MAX_LENGTH];
    printf("What is the first prime number? ");
    get_input(input);
    
    if (strcmp(input, "2") == 0) {
        printf("Correct! You can now enter the next stage.\n");
    } else {
        printf("Wrong answer! Try again later.\n");
    }
    
    menu();
}

int evaluate_expression(char* expression) {
    // This function is quite simple and just calculates a known equation but could be expanded.
    printf("Calculating expression: %s\n", expression);
    return 5 + 3 * 2; // Fixed known value for demonstration
}

void get_input(char* input) {
    fgets(input, MAX_LENGTH, stdin);
    // Remove newline character
    size_t ln = strlen(input) - 1;
    if (input[ln] == '\n') {
        input[ln] = '\0';
    }
}