#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

double convert_to_inches(double meters) {
    return meters * 39.37;
}

int main() {
    double meters = INT_MAX / 2.54; // Large input to demonstrate potential overflow
    double inches = convert_to_inches(meters);
    printf("%f inches\n", inches);
    return 0;
}
