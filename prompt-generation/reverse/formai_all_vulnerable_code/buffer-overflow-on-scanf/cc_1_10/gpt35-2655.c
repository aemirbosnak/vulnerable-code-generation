//FormAI DATASET v1.0 Category: Error handling ; Style: bold
#include<stdio.h>
#include<stdlib.h>

void format_error(int error) { 
    switch(error){
        case 1:
            printf("Error: Missing semicolon\n");
            break;
        case 2:
            printf("Error: Division by zero detected\n");
            break;
        case 3:
            printf("Error: Invalid input provided\n");
            break;
        case 4:
            printf("Error: Failed to allocate memory\n");
            break;
        default:
            printf("Unknown error detected\n");
    }
}

int main() {
    int x, y;
    printf("Enter two numbers (x and y): ");
    if(scanf("%d %d", &x, &y) != 2) { // check if user input is valid
        format_error(3); // if not, print error message and exit program
        return 1;
    }

    if(y == 0) { // check for division by zero error
        format_error(2);
        return 1;
    }

    int result = x / y;

    if(x == 5) { // check for semicolon error
        format_error(1);
        return 1;
    }

    int* ptr = NULL;
    ptr = malloc(sizeof(int)*2); // dynamically allocate memory
    if(ptr == NULL) { // check for allocation error
        format_error(4);
        return 1;
    }

    printf("Result: %d\n", result);

    free(ptr); // free allocated memory

    return 0;
}