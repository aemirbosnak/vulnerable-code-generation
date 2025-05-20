//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 118

typedef struct {
    char name[50];
    int atomic_number;
    char symbol[3];
    int group_number;
    int periodic_number;
} element;

void print_element(element e) {
    printf("%-10s %2d %-2s %-2d %s\n", e.name, e.atomic_number, e.symbol, e.group_number, e.periodic_number > 7 ? "Lanthanide" : "Non-lanthanide");
}

void print_table_header() {
    printf("| %-10s | %2s | %-2s | %-2s | %-10s |\n", "Name", "Atomic Number", "Symbol", "Group Number", "Periodic Number");
    printf("|-----------------------------------------------------|");
}

void print_table_footer() {
    printf("|-----------------------------------------------------|");
    printf("\n");
}

element elements[NUM_ELEMENTS];

void load_elements() {
    FILE *fp;
    char filename[50] = "elements.txt";
    int i = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s %d %s %d %d", elements[i].name, &elements[i].atomic_number, elements[i].symbol, &elements[i].group_number, &elements[i].periodic_number) != EOF) {
        i++;
    }

    fclose(fp);
}

int main() {
    int i, j, score = 0, correct_answers = 0;
    char user_answer[50];
    element question;

    srand(time(NULL));

    load_elements();

    print_table_header();

    for (i = 0; i < NUM_ELEMENTS; i++) {
        if (i % 10 == 0) {
            if (i != 0) {
                print_table_footer();
            }
            printf("\nNew row:\n");
            print_table_header();
        }

        question = elements[rand() % NUM_ELEMENTS];

        printf("| %-10s | %2d | %-2s | %-2d | %-10s |", question.name, question.atomic_number, question.symbol, question.group_number, question.periodic_number > 7 ? "Lanthanide" : "Non-lanthanide");

        printf("\nWhat is the name of this element? ");
        scanf("%s", user_answer);

        if (strcmp(question.name, user_answer) == 0) {
            score++;
            correct_answers++;
            printf("Correct answer! Your current score is: %d\n", score);
        } else {
            printf("Sorry, the correct answer is: %s\n", question.name);
        }

        printf("\n");
    }

    print_table_footer();

    printf("\nGame over! You got %d out of %d questions correct.", correct_answers, NUM_ELEMENTS);

    return 0;
}