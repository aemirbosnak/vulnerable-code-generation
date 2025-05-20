//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_FUNCTIONS 10

typedef struct {
    char name[20];
    double (*func)(double);
} Function;

double sin_func(double x) {
    return sin(x);
}

double cos_func(double x) {
    return cos(x);
}

double tan_func(double x) {
    return tan(x);
}

double sqrt_func(double x) {
    return sqrt(x);
}

double pow_func(double x, double y) {
    return pow(x, y);
}

double log_func(double x) {
    return log(x);
}

double abs_func(double x) {
    return fabs(x);
}

double floor_func(double x) {
    return floor(x);
}

double ceil_func(double x) {
    return ceil(x);
}

double round_func(double x) {
    return round(x);
}

int main() {
    Function functions[MAX_FUNCTIONS] = {{"sin", sin_func}, {"cos", cos_func}, {"tan", tan_func}, {"sqrt", sqrt_func}, {"pow", pow_func}, {"log", log_func}, {"abs", abs_func}, {"floor", floor_func}, {"ceil", ceil_func}, {"round", round_func}};
    char input[50];
    double x, y, result;

    printf("Welcome to the Math Exercise Program!\n");
    printf("Enter a function and its parameters (e.g. sin 1.23): ");
    scanf("%s %lf", input, &x);

    for (int i = 0; i < MAX_FUNCTIONS; i++) {
        if (strcmp(input, functions[i].name) == 0) {
            result = functions[i].func(x);
            printf("Result: %lf\n", result);
            break;
        }
    }

    return 0;
}