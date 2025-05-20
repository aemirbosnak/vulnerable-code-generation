//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char element[3];
    char name[20];
    int atomic_num;
    float atomic_mass;
} Element;

// Function to initialize an Element struct
Element init_element(char element[3], char name[20], int atomic_num, float atomic_mass) {
    Element e;
    strcpy(e.element, element);
    strcpy(e.name, name);
    e.atomic_num = atomic_num;
    e.atomic_mass = atomic_mass;
    return e;
}

int main() {
    printf("Welcome to the C Periodic Table Quiz!\n");

    // Create an array of 10 Element structs
    Element table[10];
    table[0] = init_element("H", "Hydrogen", 1, 1.008);
    table[1] = init_element("He", "Helium", 2, 4.003);
    table[2] = init_element("Li", "Lithium", 3, 6.941);
    table[3] = init_element("Be", "Beryllium", 4, 9.012);
    table[4] = init_element("B", "Boron", 5, 10.81);
    table[5] = init_element("C", "Carbon", 6, 12.01);
    table[6] = init_element("N", "Nitrogen", 7, 14.01);
    table[7] = init_element("O", "Oxygen", 8, 16.00);
    table[8] = init_element("F", "Fluorine", 9, 19.00);
    table[9] = init_element("Ne", "Neon", 10, 20.18);

    // Quiz the user on the periodic table
    int score = 0;
    for (int i = 0; i < 10; i++) {
        printf("What is the element with atomic number %d?\n", table[i].atomic_num);
        char answer[3];
        scanf("%s", answer);  // Read the user's answer
        if (strcmp(answer, table[i].element) == 0) {
            printf("Correct! %s is the element with atomic number %d.\n", table[i].name, table[i].atomic_num);
            score++;
        } else {
            printf("Incorrect. %s is the element with atomic number %d.\n", table[i].name, table[i].atomic_num);
        }
    }

    // Display the user's score
    printf("You scored %d out of 10.\n", score);

    return 0;
}