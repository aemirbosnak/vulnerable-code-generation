//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions;
    int score = 0;
    int i;
    int correct_answers[118] = {0};

    srand(time(NULL));
    num_questions = rand() % 50 + 10;

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("This quiz will test your knowledge of the elements in the periodic table.\n");
    printf("There will be %d questions.\n", num_questions);

    for (i = 0; i < num_questions; i++) {
        int element = rand() % 118;
        int question = rand() % 4;
        int answer = -1;

        switch (question) {
            case 0:
                printf("What is the symbol for element %d?\n", element);
                printf("A. H\n");
                printf("B. He\n");
                printf("C. Li\n");
                printf("D. Be\n");
                break;
            case 1:
                printf("What is the atomic number of element %d?\n", element);
                printf("A. 1\n");
                printf("B. 2\n");
                printf("C. 3\n");
                printf("D. 4\n");
                break;
            case 2:
                printf("What is the atomic weight of element %d?\n", element);
                printf("A. 1.008\n");
                printf("B. 4.003\n");
                printf("C. 6.941\n");
                printf("D. 9.012\n");
                break;
            case 3:
                printf("What is the name of element %d?\n", element);
                printf("A. Hydrogen\n");
                printf("B. Helium\n");
                printf("C. Lithium\n");
                printf("D. Beryllium\n");
                break;
        }

        scanf("%d", &answer);

        if (answer == correct_answers[element]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }

        correct_answers[element] = answer;
    }

    printf("\nYou got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}