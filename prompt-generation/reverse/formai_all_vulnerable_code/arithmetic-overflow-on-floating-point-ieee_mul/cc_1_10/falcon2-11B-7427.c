//Falcon2-11B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

float Fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float Celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

void convert(float celsius) {
    printf("%.2f degrees Fahrenheit = %.2f degrees Celsius\n", Celsius(Fahrenheit(celsius)), celsius);
}

void convertFahrenheit(float fahrenheit) {
    printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", Celsius(fahrenheit), fahrenheit);
}

int main(void) {
    char in;
    float celsius = 0.0, fahrenheit = 0.0;
    int n = 1;

    printf("Temperature Converter\n\n");
    puts("Enter a temperature in degrees Celsius or Fahrenheit, or type 'exit' to quit:");

    while ((in = getchar())!= 'x') {
        if (in == '\n') {
            in = getchar();
        }

        if (isdigit(in)) {
            celsius = atof(in);
            convert(celsius);
        }
        else if (in == 'F') {
            fahrenheit = atof(in);
            convertFahrenheit(fahrenheit);
        }
        else if (in == 'C') {
            celsius = atof(in);
            convert(celsius);
        }
        else {
            puts("Invalid input. Try again.");
            continue;
        }

        puts("Enter a temperature in degrees Celsius or Fahrenheit, or type 'exit' to quit:");
        n = 1;
    }

    printf("Thanks for using the Temperature Converter!\n");
    system("PAUSE");
    return 0;
}