//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
// Periodic Table Quiz Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10

// Structure to represent an element
struct Element {
    char symbol[5];
    char name[20];
    int atomic_number;
};

// Structure to represent a question
struct Question {
    char question[50];
    char answer[50];
};

// Function to print a question and get the user's answer
void print_question(struct Question *question) {
    printf("%s\n", question->question);
    char answer[50];
    scanf("%s", answer);
    if (strcmp(answer, question->answer) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The answer is %s.\n", question->answer);
    }
}

// Function to generate a random question
struct Question generate_question(struct Element *elements, int num_elements) {
    // Generate random element and question
    int element_index = rand() % num_elements;
    struct Element *element = &elements[element_index];
    int question_type = rand() % 2;

    // Create question and answer
    struct Question question;
    if (question_type == 0) {
        // Symbol
        sprintf(question.question, "What is the symbol of the %s element?", element->name);
        sprintf(question.answer, "%s", element->symbol);
    } else {
        // Atomic number
        sprintf(question.question, "What is the atomic number of the %s element?", element->name);
        sprintf(question.answer, "%d", element->atomic_number);
    }

    return question;
}

int main() {
    // Create array of elements
    struct Element elements[MAX_ELEMENTS] = {
        // Hydrogen
        {
            .symbol = "H",
            .name = "Hydrogen",
            .atomic_number = 1
        },
        // Helium
        {
            .symbol = "He",
            .name = "Helium",
            .atomic_number = 2
        },
        // Lithium
        {
            .symbol = "Li",
            .name = "Lithium",
            .atomic_number = 3
        },
        // Beryllium
        {
            .symbol = "Be",
            .name = "Beryllium",
            .atomic_number = 4
        },
        // Boron
        {
            .symbol = "B",
            .name = "Boron",
            .atomic_number = 5
        },
        // ...
    };

    // Create array of questions
    struct Question questions[MAX_QUESTIONS];

    // Generate questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i] = generate_question(elements, MAX_ELEMENTS);
    }

    // Print questions and get user's answers
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        print_question(&questions[i]);
    }

    return 0;
}