//FormAI DATASET v1.0 Category: Data validation ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to validate integer input
int validate_int() {
    int num;
    char input[50];
    
    while (1) {
        printf("Enter an integer: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input!\n");
            continue;
        }
        if (sscanf(input, "%d", &num) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            continue;
        }
        break;
    }
    return num;
}

// Function to validate floating point input
float validate_float() {
    float num;
    char input[50];
    
    while (1) {
        printf("Enter a floating point number: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input!\n");
            continue;
        }
        if (sscanf(input, "%f", &num) != 1) {
            printf("Invalid input! Please enter a floating point number.\n");
            continue;
        }
        break;
    }
    return num;
}

// Function to validate string input
void validate_string(char *str, int max_length) {
    char input[50];
    
    while (1) {
        printf("Enter a string (max %d characters): ", max_length);
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input!\n");
            continue;
        }
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;
        if (strlen(input) > max_length) {
            printf("String too long! Please enter a string with max %d characters.\n", max_length);
            continue;
        }
        // Check if string contains only alphabetic characters
        for (int i=0; input[i]!='\0'; i++) {
            if (!isalpha(input[i])) {
                printf("Invalid input! Please enter a string with only alphabetic characters.\n");
                goto continue_while;
            }
        }
        break;
        continue_while:;
    }
    strcpy(str, input);
}

int main() {
    int num;
    float fnum;
    char str[20];
    
    num = validate_int();
    printf("Valid integer entered: %d\n", num);
    
    fnum = validate_float();
    printf("Valid floating point number entered: %f\n", fnum);
    
    validate_string(str, 10);
    printf("Valid string entered: %s\n", str);
    
    return 0;
}