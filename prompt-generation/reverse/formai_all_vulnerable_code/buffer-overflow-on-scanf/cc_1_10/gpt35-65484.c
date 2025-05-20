//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>
#include <string.h>

// Structure for Periodic Table Element
struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
};

// Function to initialize Periodic Table elements
void initialize_elements(struct Element elements[]) {
    // Hydrogen
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;
    
    // Carbon
    strcpy(elements[1].symbol, "C");
    strcpy(elements[1].name, "Carbon");
    elements[1].atomic_number = 6;
    
    // Oxygen
    strcpy(elements[2].symbol, "O");
    strcpy(elements[2].name, "Oxygen");
    elements[2].atomic_number = 8;
    
    // Nitrogen
    strcpy(elements[3].symbol, "N");
    strcpy(elements[3].name, "Nitrogen");
    elements[3].atomic_number = 7;
    
    // Sodium
    strcpy(elements[4].symbol, "Na");
    strcpy(elements[4].name, "Sodium");
    elements[4].atomic_number = 11;
    
    // Chlorine
    strcpy(elements[5].symbol, "Cl");
    strcpy(elements[5].name, "Chlorine");
    elements[5].atomic_number = 17;
    
    // Iron
    strcpy(elements[6].symbol, "Fe");
    strcpy(elements[6].name, "Iron");
    elements[6].atomic_number = 26;
    
    // Helium
    strcpy(elements[7].symbol, "He");
    strcpy(elements[7].name, "Helium");
    elements[7].atomic_number = 2;
    
    // Neon
    strcpy(elements[8].symbol, "Ne");
    strcpy(elements[8].name, "Neon");
    elements[8].atomic_number = 10;
    
    // Sodium
    strcpy(elements[9].symbol, "K");
    strcpy(elements[9].name, "Potassium");
    elements[9].atomic_number = 19;
    
    // Gold
    strcpy(elements[10].symbol, "Au");
    strcpy(elements[10].name, "Gold");
    elements[10].atomic_number = 79;
}

// Function to display periodic table quiz menu
void display_menu() {
    printf("---- Periodic Table Quiz ----\n\n");
    printf("1. Guess the symbol\n");
    printf("2. Guess the name\n");
    printf("3. Guess the atomic number\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to generate random number between 0 and max
int generate_random_number(int max) {
    return rand() % max;
}

// Function to get user's answer
int get_answer() {
    int answer;
    printf("Your answer: ");
    scanf("%d", &answer);
    return answer;
}

// Function to validate user's answer
int validate_answer(int answer, int correct_answer, int question_number) {
    if (answer == correct_answer) {
        printf("Correct answer!\n");
        return 1;
    } else {
        printf("Wrong answer! The correct answer for question %d is %d.\n", question_number, correct_answer);
        return 0;
    }
}

// Function to run periodic table quiz
void run_quiz(struct Element elements[]) {
    int choice, question_number = 1, correct_answer, user_answer, score = 0;
    printf("---- Welcome to Periodic Table Quiz ----\n\n");
    printf("Are you ready to test your knowledge?\n\n");
    printf("Press any key to start...");
    getchar(); // To capture the extra newline character
    
    do {
        display_menu();
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                // Guess the symbol
                printf("Question %d: What is the symbol for %s?\n", question_number, elements[generate_random_number(11)].name);
                correct_answer = elements[question_number - 1].symbol[0]; // Only check first character
                user_answer = get_answer();
                score += validate_answer(user_answer, correct_answer, question_number);
                break;
            case 2:
                // Guess the name
                printf("Question %d: What is the name for %s?\n", question_number, elements[generate_random_number(11)].symbol);
                correct_answer = strcmp(elements[question_number - 1].name, ""); // Compare with an empty string to get non-zero value
                user_answer = get_answer();
                score += validate_answer(user_answer, correct_answer, question_number);
                break;
            case 3:
                // Guess the atomic number
                printf("Question %d: What is the atomic number for %s?\n", question_number, elements[generate_random_number(11)].name);
                correct_answer = elements[question_number - 1].atomic_number;
                user_answer = get_answer();
                score += validate_answer(user_answer, correct_answer, question_number);
                break;
            case 4:
                // Exit
                printf("Thanks for playing!\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice! Please choose again.\n");
                break;
        }
        
        printf("\n");
        question_number++;
    } while (choice != 4);
    
    printf("Your final score is: %d out of %d\n", score, question_number - 2); // Minus 2 as we have 2 extra attempts for exit option
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Initialize Periodic Table elements
    struct Element elements[11];
    initialize_elements(elements);
    
    // Run periodic table quiz
    run_quiz(elements);
    
    return 0;
}