//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5

int generate_question(int question_num, int correct_answer);
void print_periodic_table();
void clear_screen();

int main() {
    int correct_answers = 0;

    // seed random number generator
    srand(time(NULL));

    clear_screen();
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions. Good luck!\n\n", NUM_QUESTIONS);

    // ask 5 random questions
    for (int i = 1; i <= NUM_QUESTIONS; i++) {
        // randomly generate atomic number between 1 and 118
        int atomic_number = rand() % 118 + 1;

        // generate question and get correct answer
        int correct_answer = generate_question(i, atomic_number);

        // prompt user for answer
        int user_answer;
        printf("Enter the atomic number of the element: ");
        scanf("%d", &user_answer);

        // check if answer is correct
        if (user_answer == correct_answer) {
            printf("Correct!\n\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", correct_answer);
        }
    }

    // print final score
    printf("Quiz complete! You answered %d out of %d questions correctly.\n", correct_answers, NUM_QUESTIONS);

    return 0;
}

// generates a question based on atomic number
// returns the correct answer
int generate_question(int question_num, int atomic_number) {
    int correct_answer;

    printf("Question %d:\n", question_num);

    switch (atomic_number) {
        case 1:
            printf("What is the symbol for Hydrogen?\n");
            printf("A. H\nB. He\nC. Li\nD. Be\n");
            correct_answer = 1;
            break;
        case 6:
            printf("What is the atomic number of Carbon?\n");
            printf("A. 4\nB. 5\nC. 6\nD. 7\n");
            correct_answer = 3;
            break;
        case 11:
            printf("Which element has an atomic number of 11?\n");
            printf("A. Na\nB. Mg\nC. Al\nD. Si\n");
            correct_answer = 1;
            break;
        case 29:
            printf("What is the symbol for Copper?\n");
            printf("A. Co\nB. Cr\nC. Cu\nD. Cl\n");
            correct_answer = 3;
            break;
        case 47:
            printf("What is the atomic number of Silver?\n");
            printf("A. 45\nB. 46\nC. 47\nD. 48\n");
            correct_answer = 3;
            break;
        case 79:
            printf("Which element is commonly used in jewelry and has an atomic number of 79?\n");
            printf("A. Au\nB. Ag\nC. Pt\nD. Pd\n");
            correct_answer = 2;
            break;
        case 92:
            printf("What is the atomic number of Uranium?\n");
            printf("A. 91\nB. 92\nC. 93\nD. 94\n");
            correct_answer = 2;
            break;
        default:
            printf("Which element has an atomic number of %d?\n", atomic_number);
            printf("A. Sodium\nB. Chlorine\nC. Carbon\nD. Calcium\n");
            correct_answer = (atomic_number == 11) ? 1 :
                             (atomic_number == 17) ? 2 :
                             (atomic_number == 6)  ? 3 :
                                                    4;
            break;
    }

    return correct_answer;
}

// prints the periodic table
void print_periodic_table() {
    // TODO: implement periodic table printing
}

// clears the console screen
void clear_screen() {
    // TODO: implement console screen clearing
}