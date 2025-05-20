//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define an example structure for holding data */
struct ExampleData {
    int number;
    char string[50];
};

/* Define a function for validating input data */
bool validateInput(struct ExampleData data) {
    bool valid = true;
    
    /* Check that the integer is between 1 and 1000 */
    if(data.number < 1 || data.number > 1000) {
        printf("Error: integer must be between 1 and 1000.\n");
        valid = false;
    }
    
    /* Check that the string is not empty */
    if(strlen(data.string) == 0) {
        printf("Error: string cannot be empty.\n");
        valid = false;
    }
    
    return valid;
}

int main() {
    struct ExampleData data;
    bool valid;
    
    /* Prompt the user for input */
    printf("Enter a number between 1 and 1000: ");
    scanf("%d", &data.number);
    printf("Enter a string (max 50 characters): ");
    scanf("%s", data.string);
    
    /* Validate the input data */
    valid = validateInput(data);
    if(valid) {
        printf("Input data is valid!\n");
    } else {
        printf("There were errors validating the input data.\n");
    }
    
    return 0;
}