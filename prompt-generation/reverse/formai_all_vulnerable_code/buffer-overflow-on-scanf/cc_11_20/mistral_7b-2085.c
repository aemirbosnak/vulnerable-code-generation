//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

int main() {
    int i, j, num1, num2, choice1, choice2, flag = 0;
    int arr[SIZE][SIZE];

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            arr[i][j] = rand() % 10 + 1;
        }
    }

    printf("Memory Game\n");
    printf("------------\n\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    num1 = rand() % SIZE;
    num2 = rand() % SIZE;

    while (num1 == num2) {
        num2 = rand() % SIZE;
    }

    arr[num1][num1] = 0;

    printf("Find the pair: \n");

    do {
        printf("Your choice: %d %d\n", choice1 / SIZE, choice1 % SIZE);
        scanf("%d", &choice1);

        if (choice1 / SIZE >= SIZE || choice1 % SIZE >= SIZE) {
            printf("Invalid choice. Try again!\n");
            continue;
        }

        if (arr[choice1 / SIZE][choice1 % SIZE] == 0) {
            printf("Invalid choice. Try again!\n");
            continue;
        }

        flag = 1;

        arr[num1][num1] = arr[choice1 / SIZE][choice1 % SIZE];
        arr[choice1 / SIZE][choice1 % SIZE] = 0;

    } while (choice1 != num1 * SIZE + num2 % SIZE || flag != 1);

    printf("Congratulations! You have found the pair.\n");

    return 0;
}