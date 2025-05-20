//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct element {
    char name[3];
    char symbol[3];
    int atomic_number;
    int atomic_mass;
    char category[20];
};

void generate_table() {
    struct element table[118];
    int count = 0;
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open elements.txt\n");
        exit(1);
    }
    while (fscanf(fp, "%s %s %d %d %s", table[count].name, table[count].symbol, &table[count].atomic_number, &table[count].atomic_mass, table[count].category)!= EOF) {
        count++;
    }
    fclose(fp);
    int choice;
    srand(time(NULL));
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &choice);
    int score = 0;
    for (int i = 0; i < choice; i++) {
        int index = rand() % 118;
        printf("What is the symbol for element %s? ", table[index].name);
        char answer[4];
        scanf("%s", answer);
        if (strcmp(answer, table[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", table[index].symbol);
        }
    }
    printf("Your final score is %d out of %d.\n", score, choice);
}

int main() {
    generate_table();
    return 0;
}