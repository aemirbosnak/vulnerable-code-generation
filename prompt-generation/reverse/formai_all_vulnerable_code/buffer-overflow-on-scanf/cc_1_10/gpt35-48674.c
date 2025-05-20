//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <string.h>

// define the maximum number of elements in the quiz
#define MAX_Q 10

// define the structure for each question
typedef struct {
    char question[200];
    char options[4][50];
    int answer;
} Question;

// define the structure for the periodic table elements
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// define an array of elements with their symbols, names, and atomic numbers
Element elements[118] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10},
    {"Na", "Sodium", 11},
    {"Mg", "Magnesium", 12},
    {"Al", "Aluminium", 13},
    {"Si", "Silicon", 14},
    {"P", "Phosphorus", 15},
    {"S", "Sulfur", 16},
    {"Cl", "Chlorine", 17},
    {"Ar", "Argon", 18},
    {"K", "Potassium", 19},
    {"Ca", "Calcium", 20},
    // add more elements here
};

// define an array of questions
Question questions[MAX_Q] = {
    {"What is the symbol for Carbon?",
     {"A. Cr", "B. Cu", "C. Ca", "D. C"},
     3
    },
    {"What is the atomic number of Sodium?",
     {"A. 10", "B. 11", "C. 12", "D. 13"},
     2
    },
    {"What is the symbol for Oxygen?",
     {"A. O", "B. Ox", "C. Oygen", "D. Ol"},
     1
    },
    // add more questions here
};

// function to shuffle an array of integers
void shuffle(int arr[], int n) {
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    printf("Hello! Welcome to the periodic table quiz.\n");

    int n_correct = 0; // number of correct answers
    int n_questions = sizeof(questions) / sizeof(Question);

    // generate a random order for the questions
    int question_order[n_questions];
    for (int i = 0; i < n_questions; i++) {
        question_order[i] = i;
    }
    shuffle(question_order, n_questions);

    // loop through the questions in random order
    for (int i = 0; i < n_questions; i++) {
        Question q = questions[question_order[i]];
        
        printf("\n%s\n\n", q.question); // print the question
        
        int option_order[4] = {0, 1, 2, 3};
        shuffle(option_order, 4); // generate a random order for the options
        
        // print the options in random order
        for (int j = 0; j < 4; j++) {
            printf("%s\n", q.options[option_order[j]]);
        }
        
        int answer;
        printf("Enter your answer (A, B, C, or D): ");
        scanf("%c", &answer);
        getchar(); // consume the newline character
        
        // check if the answer is correct
        if (answer == q.answer + 'A' - 1) {
            printf("Correct!\n");
            n_correct++;
        } else {
            printf("Incorrect! The correct answer is %c. %s\n", q.answer + 'A' - 1, q.options[q.answer]);
        }
    }
    
    printf("\nCongratulations! You have completed the quiz.\n");
    printf("You got %d out of %d correct.\n", n_correct, n_questions);

    return 0;
}