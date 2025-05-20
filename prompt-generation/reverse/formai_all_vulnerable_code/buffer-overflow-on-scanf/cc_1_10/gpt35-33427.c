//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
//Here is a unique C Periodic Table Quiz Example Program:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the struct for each element in the periodic table
struct element {
    char symbol[3];
    char name[20];
    float atomic_weight;
};

//declaration of functions
void load_elements();
int quiz();
void print_element(struct element el);

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Press any key to start the quiz or 'q' to quit.\n");
    char input;
    scanf("%c", &input);
    if (input == 'q' || input == 'Q') {
        printf("Goodbye!\n");
        exit(0);
    }
    load_elements();
    int score = quiz();
    printf("You scored %d out of 118.\n", score);
    printf("Thank you for playing!\n");
    return 0;
}

void load_elements() {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);
    }
    struct element el;
    while (fread(&el, sizeof(struct element), 1, fp)) {
        print_element(el);
    }
    fclose(fp);
}

void print_element(struct element el) {
    printf("Element: %s\n", el.symbol);
    printf("Name: %s\n", el.name);
    printf("Atomic Weight: %.2f\n", el.atomic_weight);
}

int quiz() {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);
    }
    printf("Welcome to the quiz!\n");
    int score = 0;
    for (int i = 1; i < 119; i++) {
        struct element el;
        fread(&el, sizeof(struct element), 1, fp);
        printf("Question %d:\n", i);
        printf("What is the name of the element with symbol %s?\n", el.symbol);
        char input[20];
        scanf("%s", input);
        if (!strcmp(input, el.name)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", el.name);
        }
        printf("Your current score is %d out of %d.\n", score, i);
    }
    fclose(fp);
    return score;
}