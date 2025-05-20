//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_table() {
    printf("+----+------------------+------------------+\n");
    printf("| %3s | %20s | %20s |\n", "Elem", "Name", "Symbol");
    printf("+----+------------------+------------------+\n");
}

void print_row(char *name, char *symbol) {
    printf("| %3s | %20s | %20s |\n", "Elem", name, symbol);
}

int main() {
    srand(time(NULL));
    int num_elements = rand() % 120 + 1; // Randomly choose a number of elements between 1 and 120
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many elements do you want to quiz on? ");
    scanf("%d", &num_elements);
    
    int score = 0;
    int i;
    for (i = 1; i <= num_elements; i++) {
        int element_num = rand() % 118 + 1; // Randomly choose an element number between 1 and 118
        char element_name[50];
        char element_symbol[10];
        switch (element_num) {
            case 1:
                strcpy(element_name, "Hydrogen");
                strcpy(element_symbol, "H");
                break;
            case 2:
                strcpy(element_name, "Helium");
                strcpy(element_symbol, "He");
                break;
            // Add more cases for each element here
        }
        print_row(element_name, element_symbol);
        int user_answer;
        printf("What is the name of element %d? ", element_num);
        scanf("%d", &user_answer);
        if (user_answer == element_num) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", element_num);
        }
    }
    
    printf("You scored %d out of %d!\n", score, num_elements);
    
    return 0;
}