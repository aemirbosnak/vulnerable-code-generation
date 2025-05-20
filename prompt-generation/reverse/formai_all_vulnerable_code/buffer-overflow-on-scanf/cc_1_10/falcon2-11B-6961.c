//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quiz_periodic_table(int n) {
    char answer[3][3] = {
        { 'F', 'O', 'H' },
        { 'B', 'C', 'N' },
        { 'M', 'P', 'S' },
    };
    char question[3][3] = {
        { 'F', 'O', 'H' },
        { 'B', 'C', 'N' },
        { 'M', 'P', 'S' },
    };
    int score = 0;

    for (int i = 0; i < n; i++) {
        srand(time(NULL));
        int index1 = rand() % 3;
        int index2 = rand() % 3;
        int index3 = rand() % 3;
        int index4 = rand() % 3;

        printf("Question %d:\n", i+1);
        printf("Which element is represented by the following letters?\n");
        printf("%s%s%s%s\n", question[index1][0], question[index2][0], question[index3][0], question[index4][0]);
        printf("A) %c%c%c%c\n", answer[index1][0], answer[index2][0], answer[index3][0], answer[index4][0]);
        printf("B) %c%c%c%c\n", answer[index1][1], answer[index2][1], answer[index3][1], answer[index4][1]);
        printf("C) %c%c%c%c\n", answer[index1][2], answer[index2][2], answer[index3][2], answer[index4][2]);
        printf("D) %c%c%c%c\n", answer[index1][3], answer[index2][3], answer[index3][3], answer[index4][3]);

        char choice;
        printf("Enter your choice (A, B, C, or D): ");
        scanf("%c", &choice);

        if (choice == answer[index1][0]) {
            score++;
            printf("Correct!\n");
        } else if (choice == answer[index2][0]) {
            score++;
            printf("Correct!\n");
        } else if (choice == answer[index3][0]) {
            score++;
            printf("Correct!\n");
        } else if (choice == answer[index4][0]) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }

    printf("\nFinal Score: %d\n", score);
}

int main() {
    int n = 10;
    quiz_periodic_table(n);
    return 0;
}