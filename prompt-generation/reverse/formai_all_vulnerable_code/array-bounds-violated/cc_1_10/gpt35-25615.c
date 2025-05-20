//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

/**
* This program takes a C language code as input string and parses it to identify variable names, 
* data types, and function names.
* It then prints out the identified items along with their positions in the input string.
*/

// Function to check if a given string is a valid C language data type
int isDataType(char *str) {
    char *dataTypes[] = {"int", "float", "double", "char", "void"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(str, dataTypes[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[1000];
    printf("Enter your C code:\n");
    fgets(str, 1000, stdin);

    int len = strlen(str);
    int flag = 0;
    int i = 0;

    // Loop through the input string character by character
    while (i < len) {
        // If we encounter a letter, it may be a variable name or function name
        if (isalpha(str[i])) {
            flag = 1;
            int j = i + 1;
            // Keep advancing the pointer j until we reach a non-alphanumeric character
            while (isalnum(str[j])) {
                j++;
            }
            char *subStr = (char*) calloc(j - i + 1, sizeof(char));
            strncpy(subStr, &str[i], j - i);

            // If the substring is a valid data type, we know it's not a variable or function name
            if (isDataType(subStr)) {
                printf("Data type found at position %d: %s\n", i, subStr);
            } else {
                // If the character immediately following the substring is a '(', we have identified a function name
                if (str[j] == '(') {
                    printf("Function name found at position %d: %s\n", i, subStr);

                    // Loop through until we find the closing ')' to identify the function's parameters
                    int k = j + 1;
                    while (str[k] != ')') {
                        if (!isspace(str[k])) {
                            int l = k + 1;
                            while (!isspace(str[l]) && str[l] != ',' && str[l] != ')') {
                                l++;
                            }
                            char *param = (char*) calloc(l - k + 1, sizeof(char));
                            strncpy(param, &str[k], l - k);
                            printf("Parameter found: %s\n", param);
                            free(param);
                            k = l + 1;
                        } else {
                            k++;
                        }
                    }
                } else {
                    // If not a function name, it must be a variable name
                    printf("Variable name found at position %d: %s\n", i, subStr);
                }
            }
            i = j;
            free(subStr);
        } else {
            // Handle punctuation marks, which may be part of a function declaration or initialization
            if (str[i] == '(') {
                int j = i - 1;
                while (isspace(str[j])) {
                    j--;
                }
                char *subStr = (char*) calloc(50, sizeof(char));
                int k = 0;
                while (isalnum(str[j]) || str[j] == '_') {
                    subStr[k++] = str[j--];
                }
                printf("Function declaration or initialization found at position %d: %s\n", j + 1, subStr);
                free(subStr);
            }
            i++;
        }
    }
    return 0;
}