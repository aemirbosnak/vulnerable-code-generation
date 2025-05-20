//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define F_MIN -459.67
#define F_MAX 373.15
#define C_MIN -273.15
#define C_MAX 55.0

struct Temperature {
    char unit;
    double value;
};

void print_help() {
    printf("\nUsage: temp_conv [F|C] value\n");
    printf("Example:\n");
    printf("temp_conv F 100\n");
    printf("temp_conv C -20\n");
}

void error_invalid_input(char input) {
    printf("\nInvalid input '%c'. Use F for Fahrenheit and C for Celsius.\n", input);
    print_help();
    exit(1);
}

double fahrenheit_to_celsius(double f) {
    double c;
    c = (f - 32) * 5.0 / 9.0;
    return c;
}

double celsius_to_fahrenheit(double c) {
    double f;
    f = c * 9.0 / 5.0 + 32;
    return f;
}

int main(int argc, char* argv[]) {
    struct Temperature temp;

    if (argc != 3) {
        print_help();
        exit(1);
    }

    if (argv[1][0] != 'F' && argv[1][0] != 'C') {
        error_invalid_input(argv[1][0]);
    }

    temp.unit = argv[1][0];
    temp.value = atof(argv[2]);

    if (temp.unit == 'F') {
        printf("%.2lf degrees Celsius is: ", temp.value);
        printf("%.2lf degrees Celsius\n", fahrenheit_to_celsius(temp.value));
    } else {
        printf("%.2lf degrees Fahrenheit is: ", temp.value);
        printf("%.2lf degrees Fahrenheit\n", celsius_to_fahrenheit(temp.value));
    }

    return 0;
}