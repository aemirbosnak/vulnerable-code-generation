//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_table();
void ask_question(char* element);
int get_answer();
void score_update(int correct, int total);

int main() {
    srand(time(NULL));
    int score = 0;
    int total_questions = 0;

    print_table();

    while(1) {
        ask_question("What is the symbol for Hydrogen?");
        if(get_answer() == 1) {
            score_update(1, ++total_questions);
        }
        else {
            printf("Incorrect, the correct answer is H.\n");
        }
    }

    return 0;
}

void print_table() {
    printf("\n");
    printf("+----+---------------------+\n");
    printf("| No | Element             |\n");
    printf("+----+---------------------+\n");
    printf("| 1  | Hydrogen (H)       |\n");
    printf("| 2  | Helium (He)        |\n");
    printf("| 3  | Lithium (Li)       |\n");
    printf("| 4  | Beryllium (Be)     |\n");
    printf("| 5  | Boron (B)          |\n");
    printf("| 6  | Carbon (C)         |\n");
    printf("| 7  | Nitrogen (N)       |\n");
    printf("| 8  | Oxygen (O)         |\n");
    printf("| 9  | Fluorine (F)       |\n");
    printf("| 10 | Neon (Ne)          |\n");
    printf("+----+---------------------+\n");
}

void ask_question(char* element) {
    printf("\n");
    printf("What is the symbol for %s?\n", element);
    printf("Enter your answer (A-Z): ");
}

int get_answer() {
    char input[2];
    scanf("%s", input);

    if(input[0] == '\n') {
        return -1;
    }

    if(input[0] >= 'A' && input[0] <= 'Z') {
        return input[0] - 'A' + 1;
    }

    return -1;
}

void score_update(int correct, int total) {
    printf("\n");
    if(correct == 1) {
        printf("Correct!\n");
    }
    else {
        printf("Incorrect.\n");
    }

    printf("Your current score is: %d/%d\n", correct, total);
}