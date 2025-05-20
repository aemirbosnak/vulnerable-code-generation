//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000

typedef struct {
    char *name;
    double (*fn)(double);
} Function;

Function functions[] = {
    {"sin", sin},
    {"cos", cos},
    {"tan", tan},
    {"sqrt", sqrt},
    {"log", log},
    {"log10", log10},
    {"exp", exp},
    {"pow", pow},
    {"abs", fabs}
};

int num_functions() {
    return sizeof(functions) / sizeof(Function);
}

char *get_function_name(int i) {
    return functions[i].name;
}

double call_function(int i, double x) {
    return functions[i].fn(x);
}

int main() {
    char input[MAX_SIZE];
    double num1, num2, result;
    int choice;

    printf("Enter an expression in the format 'function(argument)':\n");
    fgets(input, MAX_SIZE, stdin);

    num1 = atof(strtok(input, "("));
    choice =atoi(strtok(NULL, ")"));

    switch (choice) {
        case 1:
            result = sin(num1);
            break;
        case 2:
            result = cos(num1);
            break;
        case 3:
            result = tan(num1);
            break;
        case 4:
            result = sqrt(num1);
            break;
        case 5:
            result = log(num1);
            break;
        case 6:
            result = log10(num1);
            break;
        case 7:
            result = exp(num1);
            break;
        case 8:
            result = pow(num1, 2);
            break;
        case 9:
            result = fabs(num1);
            break;
        default:
            printf("Invalid function choice.\n");
            return 1;
    }

    printf("Result: %.2f\n", result);

    return 0;
}