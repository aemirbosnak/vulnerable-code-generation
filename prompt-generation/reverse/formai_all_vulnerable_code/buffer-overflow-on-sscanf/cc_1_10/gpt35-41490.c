//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <ctype.h>

// Function to validate integer input
int validate_int() {
    int num;
    char input[20];
    while (1) {
        printf("Enter an integer: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &num) == 1) {
            return num;
        }
        else {
            printf("Input is not a valid integer. Please try again.\n");
        }
    }
}

// Function to validate float input
float validate_float() {
    float num;
    char input[20];
    while (1) {
        printf("Enter a float: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &num) == 1) {
            return num;
        }
        else {
            printf("Input is not a valid float. Please try again.\n");
        }
    }
}

// Function to validate string input
void validate_string(char* result) {
    char input[100];
    while (1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%s", result) == 1) {
            // Check if string contains only alphabetic characters
            int i;
            for (i = 0; result[i] != '\0'; i++) {
                if (!isalpha(result[i])) {
                    break;
                }
            }
            if (result[i] == '\0') {
                return;
            }
            else {
                printf("Input is not a valid string. Please try again.\n");
            }
        }
        else {
            printf("Input is not a valid string. Please try again.\n");
        }
    }
}

int main() {
    int a = validate_int();
    printf("You entered: %d\n", a);
    
    float b = validate_float();
    printf("You entered: %f\n", b);
    
    char str[100];
    validate_string(str);
    printf("You entered: %s\n", str);
    
    return 0;
}