//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_DIGITS 10

int main() {
    int numbers[MAX_NUMBERS];
    int i, j, n, m, temp;
    char str[MAX_DIGITS];
    char *token;
    FILE *fp;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate random numbers
    for (i = 0; i < MAX_NUMBERS; i++) {
        n = rand() % MAX_DIGITS + 1; // Number of digits
        m = rand() % MAX_DIGITS + 1; // Maximum digit
        sprintf(str, "%d", m);
        str[n] = '\0'; // Add null terminator
        numbers[i] = atoi(str); // Convert string to integer
    }

    // Sort the numbers in descending order
    for (i = 0; i < MAX_NUMBERS - 1; i++) {
        for (j = i + 1; j < MAX_NUMBERS; j++) {
            if (numbers[i] < numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Print the sorted numbers
    printf("Sorted numbers:\n");
    for (i = 0; i < MAX_NUMBERS; i++) {
        printf("%d\n", numbers[i]);
    }

    // Save the numbers to a file
    fp = fopen("numbers.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    for (i = 0; i < MAX_NUMBERS; i++) {
        fprintf(fp, "%d\n", numbers[i]);
    }
    fclose(fp);

    // Read the numbers from the file
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    while ((token = fgets(str, MAX_DIGITS, fp))!= NULL) {
        printf("%s", token);
    }
    fclose(fp);

    return 0;
}