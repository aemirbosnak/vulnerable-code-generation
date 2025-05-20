//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_float(char input[]){ // function to determine if input is a valid float
    float f;
    return sscanf(input, "%f", &f) == 1;
}

bool is_int(char input[]){ // function to determine if input is a valid int
    int i;
    return sscanf(input, "%d", &i) == 1;
}

bool is_alpha(char input[]){ // function to determine if input is a valid string
    int i;
    for(i = 0; input[i] != '\0'; i++){
        if(!isalpha(input[i])){
            return false; // if a non-alphabetic character is found, return false
        }
    }
    return true;
}

int main(){
    char input[100];
    int age;
    float salary;

    printf("Please enter your age: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character from input

    while(!is_int(input)){ // If input is not a valid int, loop until valid input is received
        printf("Invalid input. Please enter your age as a number: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
    }

    age = atoi(input); // Convert input to an int

    printf("Please enter your salary: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    while(!is_float(input)){ // If input is not a valid float, loop until valid input is received
        printf("Invalid input. Please enter your salary as a number: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
    }

    salary = atof(input); // Convert input to a float

    printf("Please enter your name: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    while(!is_alpha(input)){ // If input is not a valid string, loop until valid input is received
        printf("Invalid input. Please enter your name: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
    }

    printf("Name: %s\nAge: %d\nSalary: %.2f", input, age, salary);

    return 0;
}