//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[30];
    int atomic_number;
    char symbol[3];
} Element;

Element elements[118];

void load_elements() {
    FILE *fp = fopen("periodic_table.txt", "r");
    char line[100];
    int i = 0;

    if (fp == NULL) {
        printf("Error: Unable to open periodic_table.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d %s", elements[i].name, &elements[i].atomic_number, elements[i].symbol);
        elements[i].name[strlen(elements[i].name) - 1] = '\0'; // Remove newline character
        i++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));
    int score = 0;
    int num_questions = 10;

    load_elements();

    printf("\n** Welcome to the Periodic Table Quiz! **\n");
    printf("Let's test your knowledge and have some fun!\n");

    for (int i = 0; i < num_questions; i++) {
        int random_index = rand() % 118;
        printf("\nQuestion %d:\n", i + 1);
        printf("%s (%s) is the element with atomic number:\n", elements[random_index].name, elements[random_index].symbol);

        int answer;
        scanf("%d", &answer);

        if (answer == elements[random_index].atomic_number) {
            printf("Correct! You're a genius!\n");
            score++;
        } else {
            printf("Sorry, that's incorrect. The correct answer is %d.\n", elements[random_index].atomic_number);
        }

        printf("\n");
    }

    printf("\n** Quiz Results **\n");
    printf("You answered %d questions correctly out of %d.\n", score, num_questions);
    printf("Keep learning and improving! Have a great day!\n");

    return 0;
}