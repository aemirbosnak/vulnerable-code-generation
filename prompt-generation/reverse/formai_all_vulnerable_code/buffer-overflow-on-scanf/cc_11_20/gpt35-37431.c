//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4

int main() {
    char elements[MAX_QUESTIONS][3] = {"Na", "K", "Au", "Fe", "Ne"};
    char symbols[MAX_QUESTIONS][10] = {"Sodium", "Potassium", "Gold", "Iron", "Neon"};
    int atomic_nums[MAX_QUESTIONS] = {11, 19, 79, 26, 10};
    char options[MAX_QUESTIONS][MAX_OPTIONS][10] = {
        {"Nitrogen", "Neon", "Sodium", "Nickel"},
        {"Calcium", "Beryllium", "Potassium", "Lithium"},
        {"Silver", "Copper", "Gold", "Iron"},
        {"Zinc", "Iron", "Gold", "Titanium"},
        {"Fluorine", "Neon", "Krypton", "Argon"}
    };
    int answers[MAX_QUESTIONS] = {2, 3, 3, 1, 2};
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");

    srand(time(0));

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int q_num = i + 1;
        int rand_option_index[MAX_OPTIONS] = {-1, -1, -1, -1};
        rand_option_index[rand() % MAX_OPTIONS] = i;
        for (int j = 0; j < MAX_OPTIONS; j++) {
            if (rand_option_index[j] == -1) {
                int rand_index = rand() % MAX_QUESTIONS;
                while (rand_index == i || rand_index == rand_option_index[0] || 
                    rand_index == rand_option_index[1] || rand_index == rand_option_index[2]) {
                    rand_index = rand() % MAX_QUESTIONS;
                }
                rand_option_index[j] = rand_index;
            }
        }

        printf("\nQuestion %d:\n", q_num);
        printf("What is the symbol for the element with atomic number %d?\n", atomic_nums[i]);
        printf("A) %s\n", symbols[rand_option_index[0]]);
        printf("B) %s\n", symbols[rand_option_index[1]]);
        printf("C) %s\n", symbols[rand_option_index[2]]);
        printf("D) %s\n", symbols[rand_option_index[3]]);

        char answer;
        int valid_answer = 0;
        while (!valid_answer) {
            printf("Enter your answer (A/B/C/D): ");
            scanf(" %c", &answer);
            switch (answer) {
                case 'A':
                    if (rand_option_index[0] == i) {
                        score++;
                        printf("Correct!\n");
                    } else {
                        printf("Incorrect! The correct answer is %s.\n", elements[i]);
                    }
                    valid_answer = 1;
                    break;
                case 'B':
                    if (rand_option_index[1] == i) {
                        score++;
                        printf("Correct!\n");
                    } else {
                        printf("Incorrect! The correct answer is %s.\n", elements[i]);
                    }
                    valid_answer = 1;
                    break;
                case 'C':
                    if (rand_option_index[2] == i) {
                        score++;
                        printf("Correct!\n");
                    } else {
                        printf("Incorrect! The correct answer is %s.\n", elements[i]);
                    }
                    valid_answer = 1;
                    break;
                case 'D':
                    if (rand_option_index[3] == i) {
                        score++;
                        printf("Correct!\n");
                    } else {
                        printf("Incorrect! The correct answer is %s.\n", elements[i]);
                    }
                    valid_answer = 1;
                    break;
                default:
                    printf("Invalid input. Try again.\n");
            }
        }
    }

    printf("\nCongratulations! You completed the quiz with a score of %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}