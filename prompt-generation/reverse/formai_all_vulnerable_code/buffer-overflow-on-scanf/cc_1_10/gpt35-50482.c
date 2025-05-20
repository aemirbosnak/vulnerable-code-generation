//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int age = rand() % 100; // generate random age between 0 to 99
    char* gender;

    if (rand() % 2 == 0) {
        gender = "male";
    } else {
        gender = "female";
    }

    printf("Welcome to the genetic sequencer!\n");
    printf("Please enter your name:\n");

    char name[50];
    scanf("%s", name);

    printf("Hello %s, you are a %s and you are %d years old.\n", name, gender, age);
    printf("Now let's analyze your DNA...\n");

    char dna[100];
    printf("Please enter your DNA sequence:\n");
    scanf("%s", dna);

    int count_A = 0, count_T = 0, count_C = 0, count_G = 0;

    for (int i = 0; i < 100; i++) {
        switch (dna[i]) {
            case 'A':
                count_A++;
                break;
            case 'T':
                count_T++;
                break;
            case 'C':
                count_C++;
                break;
            case 'G':
                count_G++;
                break;
            default:
                break;
        }
    }

    printf("Analyzing...\n\n");
    printf("A: %d\n", count_A);
    printf("T: %d\n", count_T);
    printf("C: %d\n", count_C);
    printf("G: %d\n", count_G);

    printf("\nCongratulations, %s, you have the DNA of a perfect human. Unfortunately, that means the rest of humanity is genetically inferior to you.", name);

    return 0;
}