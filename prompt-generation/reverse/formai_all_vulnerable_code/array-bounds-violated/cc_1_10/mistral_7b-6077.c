//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int data[SIZE];
    int len;
} ShapeShifter;

void shiftLeft(ShapeShifter *shifter) {
    int i, j, temp;
    if (shifter->len > 0) {
        for (i = 0; i < shifter->len - 1; i++) {
            shifter->data[i] = shifter->data[i + 1];
        }
        temp = shifter->data[shifter->len - 1];
        shifter->len--;
        shifter->data[shifter->len] = temp;
    }
}

void shiftRight(ShapeShifter *shifter) {
    int i, j, temp;
    if (shifter->len > 0) {
        temp = shifter->data[shifter->len - 1];
        shifter->data[shifter->len - 1] = shifter->data[shifter->len - 2];
        for (i = shifter->len - 2; i >= 0; i--) {
            shifter->data[i + 1] = shifter->data[i];
        }
        shifter->data[0] = temp;
        shifter->len++;
    }
}

int main() {
    ShapeShifter shifter = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 };
    int choice, i;

    srand(time(NULL));

    printf("Shape Shifter:\n");

    do {
        printf("\n1. Shift left\n2. Shift right\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shiftLeft(&shifter);
                break;
            case 2:
                shiftRight(&shifter);
                break;
            case 3:
                printf("\nData in Shape Shifter:\n");
                for (i = 0; i < shifter.len; i++) {
                    printf("%d ", shifter.data[i]);
                }
                printf("\n");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }

        // Generate a random number and add it to the ShapeShifter
        if (choice != 3 && rand() % 2 == 0) {
            shifter.data[shifter.len] = rand() % 11 + 1;
            shifter.len++;
        }

    } while (1);

    return 0;
}