//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define ABS(x) ((x < 0) ? -(x) : x)
#define SQR(x) ((x) * (x))

typedef struct {
    double fahrenheit;
    double celsius;
} temperature;

void convertFtoC(temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32) * 5.0 / 9.0;
}

void convertCtoF(temperature *temp) {
    temp->fahrenheit = temp->celsius * 9.0 / 5.0 + 32;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    temperature temp1, temp2;

    if (argc != 3) {
        printf("Usage: %s <temperature in Fahrenheit> <convert to Celsius or Fahrenheit (C/F)>");
        return 1;
    }

    temp1.fahrenheit = atof(argv[1]);

    if (argv[2][0] == 'F' || argv[2][0] == 'f') {
        convertFtoC(&temp1);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", temp1.fahrenheit, temp1.celsius);
    } else if (argv[2][0] == 'C' || argv[2][0] == 'c') {
        temp1.celsius = atof(argv[1]);
        convertCtoF(&temp1);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", temp1.celsius, temp1.fahrenheit);
    } else {
        printf("Invalid argument: %s\n", argv[2]);
        return 1;
    }

    temp2.fahrenheit = rand() % 100 + 32;
    convertCtoF(&temp2);
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", temp2.celsius, temp2.fahrenheit);

    return 0;
}