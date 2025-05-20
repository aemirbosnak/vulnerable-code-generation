//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random floating-point number between min and max (inclusive)
double randDouble(double min, double max) {
    return rand() / (double)RAND_MAX * (max - min) + min;
}

int main() {
    int i, j, n, sum = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random integer between 1 and 100 (inclusive)
    int randomNum = randInt(1, 100);
    printf("Random number between 1 and 100: %d\n", randomNum);

    // Generate a random floating-point number between 0.0 and 1.0 (inclusive)
    double randomDouble = randDouble(0.0, 1.0);
    printf("Random floating-point number between 0.0 and 1.0: %.2f\n", randomDouble);

    // Generate a random array of integers between 1 and 100 (inclusive)
    int arr[10];
    for (i = 0; i < 10; i++) {
        arr[i] = randInt(1, 100);
    }
    printf("Random array of integers between 1 and 100:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate the sum of the elements in the array
    for (i = 0; i < 10; i++) {
        sum += arr[i];
    }
    printf("Sum of the elements in the array: %d\n", sum);

    // Generate a random string of uppercase letters
    char str[10];
    for (i = 0; i < 10; i++) {
        str[i] = 'A' + randInt(0, 25);
    }
    str[10] = '\0'; // Add null terminator to end of string
    printf("Random string of uppercase letters: %s\n", str);

    return 0;
}