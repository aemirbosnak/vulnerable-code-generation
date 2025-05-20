//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
/* This is a C program that demonstrates error handling in a unique way. 
 * Using Claude Shannon's principles of information theory, the program 
 * creates a custom error message based on the amount of information 
 * contained in the error. The more information, the less severe the error.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INFO 5
#define MIN_SEVERITY 1
#define MAX_SEVERITY 10

int main(void) {
    int info = 0;
    int severity = 0;

    printf("Enter the amount of information in the error (0-5): ");
    scanf("%d", &info);

    if (info < 0 || info > MAX_INFO) {
        printf("Error: Invalid input. Please enter a number from 0 to 5.\n");
        return 1;
    }

    printf("Enter the severity of the error (1-10): ");
    scanf("%d", &severity);

    if (severity < MIN_SEVERITY || severity > MAX_SEVERITY) {
        printf("Error: Invalid input. Please enter a number from 1 to 10.\n");
        return 1;
    }

    char* error = (char*) malloc(sizeof(char) * (info * severity + 1));
    if (error == NULL) {
        printf("Error: Out of memory.\n");
        return 1;
    }

    // Generate the error message based on the amount of information and severity
    printf("Generating error message...\n");
    for (int i = 0; i < info * severity; i++) {
        if (i % info == 0) {
            error[i] = 'E';
        } else if (i % severity == 0) {
            error[i] = 'R';
        } else {
            error[i] = 'R';
        }
    }
    error[info * severity] = '\0';

    printf("Error message: %s\n", error);

    free(error);
    return 0;
}