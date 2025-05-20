//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_periodic_table();
void quiz();

int main() {
    srand(time(NULL));
    int choice;

    do {
        system("clear");
        printf("Welcome to the C Periodic Table Quiz!\n\n");
        printf("What would you like to do?\n");
        printf("1. View the periodic table\n");
        printf("2. Take the quiz\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_periodic_table();
                break;
            case 2:
                quiz();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}

void print_periodic_table() {
    printf("\n");
    printf("    1  2  3  4  5  6  7  8  9 10\n");
    printf("-------------------------------------\n");
    printf("H  |  H  He Li Be B  C  N  O  F  Ne\n");
    printf("-------------------------------------\n");
    printf("2  |  Mg Ca Sr Ba Ra Ac Th Pa U  Np\n");
    printf("-------------------------------------\n");
    printf("3  |  Sc Y  La Ce Pr Nd Pm Sm Eu Gd\n");
    printf("-------------------------------------\n");
    printf("4  |  Dy Ho Er Tm Yb Lu\n");
    printf("-------------------------------------\n");
    printf("\n");
}

void quiz() {
    int score = 0;
    int num_questions = rand() % 10 + 1;

    for (int i = 0; i < num_questions; i++) {
        int element_num = rand() % 118 + 1;
        char element_symbol[3];
        sprintf(element_symbol, "%2d", element_num);

        printf("\nQuestion %d: What is the symbol for element %s?\n", i + 1, element_symbol);
        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, element_symbol) == 0) {
            score++;
        }
    }

    printf("\nYou got %d out of %d questions correct!\n", score, num_questions);
}