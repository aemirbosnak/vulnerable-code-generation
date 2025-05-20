//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions
#define NUM_QUESTIONS 10

// Define the elements and their properties
struct Element {
    char symbol[3];
    char name;
    int atomicNumber;
    int group;
    int period;
};

// Define the questions and their answers
struct Question {
    char question[80];
    int answer;
};

// Define the main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define the elements
    struct Element elements[] = {{"H", "Hydrogen", 1, 1, 1},
                                 {"He", "Helium", 2, 18, 1},
                                 {"Li", "Lithium", 3, 1, 2},
                                 {"Be", "Beryllium", 4, 2, 2},
                                 {"B", "Boron", 5, 13, 2},
                                 {"C", "Carbon", 6, 14, 2},
                                 {"N", "Nitrogen", 7, 15, 2},
                                 {"O", "Oxygen", 8, 16, 2},
                                 {"F", "Fluorine", 9, 17, 2},
                                 {"Ne", "Neon", 10, 18, 2}};

    // Define the questions
    struct Question questions[] = {{"What element has the symbol H?", 1},
                                   {"What element has the symbol He?", 2},
                                   {"What element has the symbol Li?", 3},
                                   {"What element has the symbol Be?", 4},
                                   {"What element has the symbol B?", 5},
                                   {"What element has the symbol C?", 6},
                                   {"What element has the symbol N?", 7},
                                   {"What element has the symbol O?", 8},
                                   {"What element has the symbol F?", 9},
                                   {"What element has the symbol Ne?", 10}};

    // Loop through the questions
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Print the question
        printf("%s\n", questions[i].question);

        // Get the user's answer
        int userAnswer;
        scanf("%d", &userAnswer);

        // Check if the user's answer is correct
        if (userAnswer == questions[i].answer) {
            score++;
        }
    }

    // Print the user's score
    printf("You scored %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}