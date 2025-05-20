//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num;
    int count = 0;

    srand(time(NULL)); // Seed the random generator with current time

    printf("Welcome to the Unique Number Generator\n\n");
    printf("How many unique numbers would you like to generate? ");
    scanf("%d", &num);
    
    if(num <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        exit(0);
    }
    
    int *array = (int*)malloc(num * sizeof(int)); // Dynamically allocate memory for array
    
    printf("\nGenerating random unique numbers...\n");

    while(count < num) {
        int flag = 1;
        int rand_num = rand() % 100 + 1; // Generate a random number between 1 to 100

        for(i=0; i<count; i++) {
            if(rand_num == array[i]) {
                flag = 0;
                break;
            }
        }

        if(flag == 1) {
            array[count] = rand_num;
            count++;
        }
    }

    printf("\n");

    for(i=0; i<num; i++) {
        printf("%d ", array[i]);
    }

    free(array); // Free the dynamically allocated memory

    printf("\n\nThank you for using the Unique Number Generator!\n");

    return 0;
}