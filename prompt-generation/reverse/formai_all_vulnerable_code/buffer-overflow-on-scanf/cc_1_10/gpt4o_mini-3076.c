//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
} Element;

void initialize_elements(Element *elements) {
    // Initialize the periodic table elements
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomic_number = 1;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomic_number = 2;

    strcpy(elements[2].name, "Lithium");
    strcpy(elements[2].symbol, "Li");
    elements[2].atomic_number = 3;

    // Add more elements as necessary
    strcpy(elements[3].name, "Beryllium");
    strcpy(elements[3].symbol, "Be");
    elements[3].atomic_number = 4;

    strcpy(elements[4].name, "Boron");
    strcpy(elements[4].symbol, "B");
    elements[4].atomic_number = 5;

    // ... (Add remaining elements up to a desired count, e.g., 10)

    printf("Periodic Table Quiz Initialized! You can now test your knowledge.\n\n");
}

void quiz(Element *elements, int total_elements) {
    int score = 0;
    int question_count = 5; // Number of questions for the quiz
    int asked[question_count];
    
    for (int i = 0; i < question_count; i++)
        asked[i] = -1;

    printf("Welcome to the Periodic Table Quiz!\n");
    
    for (int i = 0; i < question_count; i++) {
        int random_index;
        int already_asked;
        
        // Generate a unique random index for the quiz
        do {
            already_asked = 0;
            random_index = rand() % total_elements;
            for (int j = 0; j < i; j++) {
                if (asked[j] == random_index) {
                    already_asked = 1;
                    break;
                }
            }
        } while (already_asked);
        
        asked[i] = random_index;

        // Present the question
        printf("Question %d: What is the symbol for the element with atomic number %d?\n", i + 1, elements[random_index].atomic_number);
        char answer[3];
        printf("Your answer: ");
        scanf("%s", answer);

        // Check the answer
        if (strcasecmp(answer, elements[random_index].symbol) == 0) {
            printf("Correct! Well done.\n\n");
            score++;
        } else {
            printf("Oops! The correct answer is %s.\n\n", elements[random_index].symbol);
        }
    }

    // Display final score
    printf("You've completed the quiz!\nYour final score: %d out of %d\n", score, question_count);
}

int main() {
    int total_elements = 5; // Update this for total initialized elements
    Element elements[10]; // Array for storing elements
    srand(time(NULL)); // Seed for random number generation

    initialize_elements(elements);
    quiz(elements, total_elements);
    
    printf("Thank you for playing the Periodic Table Quiz! Keep learning and exploring!\n");
    return 0;
}