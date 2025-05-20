//FormAI DATASET v1.0 Category: Data validation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Function to validate integer data
int validate_int(char input[]) {
    int i = 0;

    //Check if string contains non-digit characters
    for(i = 0; i < strlen(input); i++) {
        if(!isdigit(input[i])) {
            printf("Invalid Input! Please enter only integer values.\n");
            return 0;
        }
    }
    return 1;
}

//Function to validate float data
int validate_float(char input[]) {
    int i = 0;
    int pointCount = 0;

    //Check if string contains non-digit and non-decimal characters
    for(i = 0; i < strlen(input); i++) {
        if(!isdigit(input[i]) && input[i] != '.') {
            printf("Invalid Input! Please enter proper floating point values.\n");
            return 0;
        }
        if(input[i] == '.') {
            pointCount++;
        }
        //Multiple decimal points are not allowed in floating point values
        if(pointCount > 1) {
            printf("Invalid Input! Please enter only one decimal point in floating point values.\n");
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[50];
    int valid = 0;

    //Validate integer input
    do {
        printf("Enter an integer value: ");
        scanf("%s", input);
        valid = validate_int(input);
    } while(!valid);

    //Validate floating point input
    do {
        printf("Enter a floating point value: ");
        scanf("%s", input);
        valid = validate_float(input);
    } while(!valid);

    printf("Data validation successful! You have entered an integer value: %d, and a floating point value: %f\n", atoi(input), atof(input));
    return 0;
}