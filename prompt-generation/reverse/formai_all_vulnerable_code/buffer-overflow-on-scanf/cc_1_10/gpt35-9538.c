//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <string.h>

// function to display periodic table
void display_periodic_table(char periodic_table[][20], int rows, int columns) {
    printf("\n\n----------------------------------------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%-20s", periodic_table[i][j]); // formatting
        }
        printf("\n");
    }
    printf("----------------------------------------------\n\n");
}

// function to check answer
void check_answer(char element[20], char answer[20], int *score) {
    if (strcmp(element, answer) == 0) {
        printf("Correct! +10 points\n");
        *score += 10;
    } else {
        printf("Wrong! The answer is %s\n", element);
    }
}

int main() {
    char periodic_table[10][20] = {
            {"H"}, {"He"}, {"Li"}, {"Be"}, {"B"}, {"C"}, {"N"}, {"O"}, {"F"}, {"Ne"}
    };
    int rows = 10;
    int columns = 1;
    int score = 0; // starting score

    printf("Welcome to the Periodic Table Quiz!\n\n");

    // instructions
    printf("You will be given the name of an element, and you have to enter the correct symbol of the element.\n");
    printf("For each correct answer, you will get 10 points.\n\n");

    // display periodic table
    display_periodic_table(periodic_table, rows, columns);

    // quiz loop
    for (int i = 0; i < rows; i++) {
        char element[20];
        strcpy(element, periodic_table[i][0]);

        printf("What is the symbol of %s? ", element);

        char answer[20];
        scanf("%s", answer);

        check_answer(element, answer, &score);
    }

    printf("\nYour final score is %d out of 100\n", score);

    return 0;
}