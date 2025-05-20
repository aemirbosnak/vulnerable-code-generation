//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>

/* Define custom error codes */
#define INPUT_ERROR 1
#define FILE_ERROR 2
#define DIVIDE_BY_ZERO_ERROR 3

/* Custom error handling function */
void error_handler(int error_code) {
    switch(error_code) {
        case INPUT_ERROR:
            printf("Error: Invalid input.\n");
            break;
        case FILE_ERROR:
            printf("Error: Unable to open file.\n");
            break;
        case DIVIDE_BY_ZERO_ERROR:
            printf("Error: Attempted to divide by zero.\n");
            break;
        default:
            printf("Error: Unknown error code.\n");
    }
}

int main() {
    int a, b;
    double result;
    FILE* fp;

    /* Get user input */
    printf("Enter two integers: ");
    if(scanf("%d%d", &a, &b) != 2) {
        error_handler(INPUT_ERROR);
        return 1;
    }

    /* Check for divide-by-zero error */
    if(b == 0) {
        error_handler(DIVIDE_BY_ZERO_ERROR);
        return 1;
    }

    /* Calculate result */
    result = (double)a / (double)b;

    /* Open output file */
    fp = fopen("output.txt", "w");
    if(fp == NULL) {
        error_handler(FILE_ERROR);
        return 1;
    }

    /* Write result to file */
    fprintf(fp, "Result: %lf", result);

    /* Close file */
    fclose(fp);

    return 0;
}