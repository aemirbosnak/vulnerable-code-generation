//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_table() {
    printf("+----+------------------+\n");
    printf("| ELEMENT | SYMBOL         |\n");
    printf("+======+=================\n");
}

void generate_question() {
    int rand_index = rand() % 118;
    char element[50];
    char symbol[10];
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    while (fscanf(file, "%s %s", element, symbol)!= EOF) {
        if (rand_index == 0) {
            printf("What is the symbol for %s? ", element);
            char answer[10];
            scanf("%s", answer);
            if (strcmp(answer, symbol) == 0) {
                printf("Correct!\n");
            } else {
                printf("Incorrect. The correct answer is %s.\n", symbol);
            }
            break;
        }
        rand_index--;
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    int score = 0;
    int num_questions = 10;
    print_table();
    for (int i = 0; i < num_questions; i++) {
        generate_question();
    }
    printf("+----+------------------+\n");
    printf("| SCORE | OUT OF %d        |\n", num_questions);
    printf("+======+=================\n");
    printf("| %d   |                    |\n", score);
    printf("+======+=================\n");
    return 0;
}