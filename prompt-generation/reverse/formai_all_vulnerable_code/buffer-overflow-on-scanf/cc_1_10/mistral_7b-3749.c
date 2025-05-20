//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct {
    int num;
    int flag;
} number;

number numbers[MAX];

void read_numbers(number *numbers) {
    for (int i = 0; i < MAX; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i].num);
        numbers[i].flag = 0;
    }
}

void print_numbers(number *numbers) {
    for (int i = 0; i < MAX; i++) {
        printf("\nNumber %d: %d", i + 1, numbers[i].num);
        printf("\nBitwise AND with 5: %d", numbers[i].num & 5);
        printf("\nBitwise OR with 6: %d", numbers[i].num | 6);
        printf("\nBitwise XOR with 3: %d", numbers[i].num ^ 3);
        printf("\nBitwise NOT: %d\n", ~numbers[i].num);
    }
}

void randomize_numbers(number *numbers) {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        numbers[i].num = rand() % 20;
        numbers[i].flag = 1;
    }
}

int main() {
    int choice;

    read_numbers(numbers);

    while (1) {
        printf("\n1. Print numbers and their bitwise operations\n");
        printf("2. Randomize numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_numbers(numbers);
                break;
            case 2:
                randomize_numbers(numbers);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}