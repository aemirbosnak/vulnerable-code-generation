//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>  // For multithreading

#define MAX_INPUT_LEN 50

int input_validated = 0;  // Will be used to communicate between threads

void *validate_input(void *input_ptr) {
    char *input = (char *)input_ptr;
    
    // Check if input contains only digits
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Error: Input contains non-digit characters.\n");
            return NULL;  // Exit thread
        }
    }
    
    if (atoi(input) > 100) {
        printf("Error: Input is greater than 100.\n");
        return NULL;  // Exit thread
    }
    
    // Validation complete
    printf("Input validated.\n");
    input_validated = 1;
    
    return NULL;
}

int main() {
    char input[MAX_INPUT_LEN];
    pthread_t validation_thread;
    
    printf("Enter a number (maximum 100): ");
    scanf("%s", input);
    
    // Start validation thread
    pthread_create(&validation_thread, NULL, validate_input, (void *)input);
    
    // Wait for validation thread to finish
    pthread_join(validation_thread, NULL);

    if (input_validated) {
        printf("Input is valid.\n");
    }
    
    return 0;
}