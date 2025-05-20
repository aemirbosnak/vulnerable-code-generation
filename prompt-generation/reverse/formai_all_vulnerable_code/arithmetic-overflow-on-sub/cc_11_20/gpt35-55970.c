//FormAI DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the shape shifting data mining program!\n");

    srand(time(NULL)); // Generate random seed

    int option;
    do {
        printf("\nChoose an option:\n");
        printf("1. Generate random integers\n");
        printf("2. Generate random floats\n");
        printf("3. Generate random strings\n");
        printf("4. Exit program\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nHow many integers do you want to generate?\n");
                int numInts;
                scanf("%d", &numInts);

                int *intArray = malloc(numInts * sizeof(int)); // Allocate memory for array

                printf("\nGenerating %d random integers...\n", numInts);
                for(int i=0; i<numInts; i++) {
                    intArray[i] = rand() % 100; // Generate random integer between 0 and 99
                    printf("%d ", intArray[i]);
                }
                printf("\n");

                free(intArray); // Free memory

                break;
            
            case 2:
                printf("\nHow many floats do you want to generate?\n");
                int numFloats;
                scanf("%d", &numFloats);

                float *floatArray = malloc(numFloats * sizeof(float)); // Allocate memory for array

                printf("\nGenerating %d random floats...\n", numFloats);
                for(int i=0; i<numFloats; i++) {
                    floatArray[i] = ((float) rand() / (float) RAND_MAX) * 10.0; // Generate random float between 0.0 and 10.0
                    printf("%.2f ", floatArray[i]);
                }
                printf("\n");

                free(floatArray); // Free memory

                break;

            case 3:
                printf("\nWhat is the maximum length of the strings you want to generate?\n");
                int maxLen;
                scanf("%d", &maxLen);

                int numStrings;
                printf("\nHow many strings do you want to generate?\n");
                scanf("%d", &numStrings);

                char **stringArray = malloc(numStrings * sizeof(char*)); // Allocate memory for array

                printf("\nGenerating %d random strings...\n", numStrings);
                for(int i=0; i<numStrings; i++) {
                    int len = rand() % maxLen + 1; // Generate random string length between 1 and maxLen
                    stringArray[i] = malloc(len * sizeof(char)); // Allocate memory for string

                    for(int j=0; j<len-1; j++) {
                        stringArray[i][j] = 'a' + (rand() % 26); // Generate random lowercase letter
                    }
                    stringArray[i][len-1] = '\0'; // Add null terminator

                    printf("%s ", stringArray[i]);
                }
                printf("\n");

                for(int i=0; i<numStrings; i++) {
                    free(stringArray[i]); // Free memory for each string
                }
                free(stringArray); // Free memory for array

                break;
            
            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while(option != 4);

    return 0;
}