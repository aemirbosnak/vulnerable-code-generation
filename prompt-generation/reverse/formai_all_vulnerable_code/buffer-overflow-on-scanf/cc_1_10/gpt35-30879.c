//FormAI DATASET v1.0 Category: Random ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    printf("Welcome to the random number generator!\n");

    int choice;
    int min, max;
    printf("Would you like to generate a single number (enter 1) or a range of numbers (enter 2)? ");
    scanf("%d", &choice);

    if (choice == 1) {
        int number = rand();
        printf("Your random number is: %d\n", number);
    } else if (choice == 2) {
        printf("Please enter the minimum value: ");
        scanf("%d", &min);
        printf("Please enter the maximum value: ");
        scanf("%d", &max);
        
        if (min > max) {
            printf("Invalid input. Minimum value cannot be greater than maximum value.\n");
            return 1;
        }

        int numNumbers = max - min + 1;
        int numbers[numNumbers];

        int i;
        for (i = 0; i < numNumbers; i++) {
            numbers[i] = min + i;
        }

        printf("How many numbers would you like to generate? ");
        int numToGenerate;
        scanf("%d", &numToGenerate);

        if (numToGenerate > numNumbers) {
            printf("Invalid input. You cannot generate more numbers than the range you specified.\n");
            return 1;
        }

        int selected[numToGenerate];
        for (i = 0; i < numToGenerate; i++) {
            int index = rand() % numNumbers;
            selected[i] = numbers[index];
            numbers[index] = numbers[numNumbers-1];
            numNumbers--;
        }

        printf("Your random numbers are: ");
        for (i = 0; i < numToGenerate; i++) {
            printf("%d ", selected[i]);
        }
        printf("\n");
    } else {
        printf("Invalid input. Please enter 1 or 2.\n");
        return 1;
    }

    return 0;
}