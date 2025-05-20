//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void printWelcomeMessage() {
    printf("****************************************\n");
    printf("*         Welcome to Checksum          *\n");
    printf("*   A magical number calculator!       *\n");
    printf("****************************************\n");
}

void printGoodbyeMessage() {
    printf("****************************************\n");
    printf("*          Thank you for using         *\n");
    printf("*          our Checksum Calculator!    *\n");
    printf("****************************************\n");
}

int calculateChecksum(int *numbers, int count) {
    int checksum = 0;
    for (int i = 0; i < count; i++) {
        checksum += numbers[i];
    }
    return checksum;
}

int main() {
    printWelcomeMessage();

    int numCount;
    printf("How many integers do you want to enter? ");
    scanf("%d", &numCount);

    if (numCount <= 0) {
        printf("Invalid number. Please enter a positive integer quantity.\n");
        return 1;
    }

    int *numbers = (int *)malloc(numCount * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 2;
    }

    printf("Great! Please enter %d integers:\n", numCount);
    for (int i = 0; i < numCount; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int checksum = calculateChecksum(numbers, numCount);
    
    printf("\n****************************************\n");
    printf("Your entered integers were:\n");
    for (int i = 0; i < numCount; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("The checksum of the entered integers is: %d\n", checksum);
    printf("****************************************\n");

    free(numbers);
    printGoodbyeMessage();

    return 0;
}