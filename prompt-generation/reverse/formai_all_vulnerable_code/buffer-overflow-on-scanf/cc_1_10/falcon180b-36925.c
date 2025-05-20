//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n;
    char ch;
    char name[20];
    char symbol[3];
    int atomic_number;
    int correct_answers = 0;
    int total_questions = 0;
    int score = 0;
    int choice;

    srand(time(NULL));

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &n);

    printf("\n");

    while (total_questions < n) {
        atomic_number = rand() % 118; // There are 118 elements in the periodic table

        if (atomic_number == 0) {
            atomic_number = 1;
        }

        sprintf(name, "Element %d", atomic_number);
        sprintf(symbol, "%c%c", 'A' + (atomic_number / 100) - 1, 'A' + (atomic_number % 100) - 1);

        printf("Question %d:\n", ++total_questions);
        printf("What is the name of the element with atomic number %d? ", atomic_number);

        fflush(stdin);
        scanf("%c", &ch);

        if (ch == '\n') {
            printf("Please enter your answer.\n");
        } else {
            ungetc(ch, stdin);
        }

        scanf("%s", name);

        if (strcmp(name, "Element 1") == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is Element %d.\n", atomic_number);
        }

        score += correct_answers;
    }

    printf("\n");
    printf("You got %d out of %d correct.\n", correct_answers, n);
    printf("Your score is %d.\n", score);

    return 0;
}