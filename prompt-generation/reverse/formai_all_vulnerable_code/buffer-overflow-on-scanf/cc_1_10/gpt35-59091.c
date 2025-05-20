//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 20

typedef struct Element {
    int atomic_number;
    char name[MAX_NAME_LEN];
    char symbol[3];
    double atomic_mass;
} Element;

Element periodic_table[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.003},
    {3, "Lithium", "Li", 6.941},
    {4, "Beryllium", "Be", 9.012},
    /* More elements up to 118 */
};

int main() {
    int input;
    char ans[MAX_NAME_LEN];
    double ans_mass;
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to put your knowledge to the test?\n");
    printf("Enter 1 to start the quiz or any other number to quit: ");
    scanf("%d", &input);
    
    if (input != 1) {
        printf("Goodbye!\n");
        return 0;
    }
    printf("\n");
    
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        /* Question 1 */
        printf("Question 1:\n");
        printf("What is the symbol for %s?\n", periodic_table[i].name);
        scanf("%s", ans);
        if (strcmp(ans, periodic_table[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %s.\n", periodic_table[i].symbol);
        }
        printf("\n");
        
        /* Question 2 */
        printf("Question 2:\n");
        printf("What is the atomic number for %s?\n", periodic_table[i].name);
        scanf("%d", &input);
        if (input == periodic_table[i].atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %d.\n", periodic_table[i].atomic_number);
        }
        printf("\n");
        
        /* Question 3 */
        printf("Question 3:\n");
        printf("What is the atomic mass for %s (in g/mol)?\n", periodic_table[i].name);
        scanf("%lf", &ans_mass);
        if (ans_mass == periodic_table[i].atomic_mass) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %.3lf.\n", periodic_table[i].atomic_mass);
        }
        printf("\n");
    }
    
    /* Display results */
    printf("Congratulations, you have completed the quiz!\n");
    printf("Your score is: %d / %d\n", score, MAX_ELEMENTS * 3);
    
    return 0;
}