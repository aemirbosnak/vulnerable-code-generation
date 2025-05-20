#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT 2147483647

int feet_to_miles(int feet) {
    return feet * 0.000254 / 1760.0;
}

int main() {
    int feet;
    printf("Enter feet: ");
    scanf("%d", &feet);

    if (feet > MAX_INPUT) {
        printf("Error: Integer overflow detected.\n");
        return 1;
    }

    double miles = feet_to_miles(feet);
    printf("%d feet is approximately %f miles.\n", feet, miles);
    return 0;
}
