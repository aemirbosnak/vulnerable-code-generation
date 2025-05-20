//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_VALUE 1000

typedef struct {
    int value;
    int index;
} Number;

void generateRandomNumbers(Number numbers[], int numNumbers) {
    srand(time(NULL));
    for (int i = 0; i < numNumbers; i++) {
        numbers[i].value = rand() % MAX_VALUE;
        numbers[i].index = i;
    }
}

void bubbleSort(Number numbers[], int numNumbers) {
    for (int i = 0; i < numNumbers - 1; i++) {
        for (int j = 0; j < numNumbers - 1 - i; j++) {
            if (numbers[j].value > numbers[j + 1].value) {
                Number temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void printNumbers(Number numbers[], int numNumbers) {
    for (int i = 0; i < numNumbers; i++) {
        printf("%d ", numbers[i].value);
    }
    printf("\n");
}

int main() {
    Number numbers[MAX_NUMBERS];
    int numNumbers;

    printf("Enter the number of random numbers to generate (<= %d): ", MAX_NUMBERS);
    scanf("%d", &numNumbers);

    if (numNumbers > 0 && numNumbers <= MAX_NUMBERS) {
        generateRandomNumbers(numbers, numNumbers);
        bubbleSort(numbers, numNumbers);
        printNumbers(numbers, numNumbers);
    } else {
        printf("Invalid number of random numbers.\n");
    }

    return 0;
}