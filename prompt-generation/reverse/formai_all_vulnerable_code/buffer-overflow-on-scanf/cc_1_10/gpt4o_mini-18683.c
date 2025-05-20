//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define NAME_LENGTH 30

typedef struct {
    int atomic_number;
    char name[NAME_LENGTH];
    char symbol[3];
    double atomic_weight;
} Element;

void initialize_elements(Element elements[]);
void print_quiz(Element elements[], int num_questions);
int ask_question(Element elements[]);
void print_element_info(Element element);

int main() {
    Element elements[MAX_ELEMENTS];
    initialize_elements(elements);
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will get 5 random questions about elements.\n");
    
    int num_questions = 5;
    print_quiz(elements, num_questions);
    
    printf("Thank you for participating!\n");
    return 0;
}

void initialize_elements(Element elements[]) {
    // Populate the periodic table with some elements
    elements[0] = (Element){1, "Hydrogen", "H", 1.008};
    elements[1] = (Element){2, "Helium", "He", 4.0026};
    elements[2] = (Element){3, "Lithium", "Li", 6.94};
    elements[3] = (Element){4, "Beryllium", "Be", 9.0122};
    elements[4] = (Element){5, "Boron", "B", 10.81};
    elements[5] = (Element){6, "Carbon", "C", 12.011};
    elements[6] = (Element){7, "Nitrogen", "N", 14.007};
    elements[7] = (Element){8, "Oxygen", "O", 15.999};
    elements[8] = (Element){9, "Fluorine", "F", 18.998};
    elements[9] = (Element){10, "Neon", "Ne", 20.180};
    // Add more elements as needed...
}

void print_quiz(Element elements[], int num_questions) {
    int score = 0;
    
    for (int i = 0; i < num_questions; i++) {
        int correct = ask_question(elements);
        if (correct) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Wrong answer. Better luck next time!\n\n");
        }
    }
    
    printf("Your final score: %d out of %d\n", score, num_questions);
}

int ask_question(Element elements[]) {
    // Randomly select an element
    int index = rand() % 10; // change to 118 for all elements
    Element selected = elements[index];
    
    // Ask the question
    printf("What is the symbol of %s (Atomic Number: %d)? ", selected.name, selected.atomic_number);
    
    char user_input[3];
    scanf("%s", user_input);
    
    // Check if the input matches the element's symbol
    if (strcmp(user_input, selected.symbol) == 0) {
        print_element_info(selected);
        return 1; // correct answer
    }
    
    return 0; // wrong answer
}

void print_element_info(Element element) {
    printf("Element Info:\n");
    printf("Name: %s\n", element.name);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Weight: %.3f\n", element.atomic_weight);
}