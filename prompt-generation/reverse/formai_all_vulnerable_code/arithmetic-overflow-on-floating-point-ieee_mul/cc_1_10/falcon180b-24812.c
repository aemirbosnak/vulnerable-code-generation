//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 10
#define MIN_TEMP -273.15
#define MAX_TEMP 1000.0

struct temperature {
    char unit[MAX_LENGTH];
    double value;
};

int main() {
    struct temperature temp1, temp2, result;
    char choice, input[MAX_LENGTH];
    int i, j;

    printf("Welcome to Temperature Converter!\n");
    printf("Enter the first temperature (e.g. 25C): ");
    scanf("%s", input);
    strcpy(temp1.unit, input);
    temp1.value = strtod(input, NULL);

    printf("Enter the second temperature (e.g. 32F): ");
    scanf("%s", input);
    strcpy(temp2.unit, input);
    temp2.value = strtod(input, NULL);

    printf("Enter the conversion choice (e.g. C to F): ");
    scanf(" %c", &choice);

    switch(choice) {
        case 'C':
            result.unit[0] = 'F';
            result.value = (temp1.value * 9/5) + 32;
            break;
        case 'F':
            result.unit[0] = 'C';
            result.value = (temp1.value - 32) * 5/9;
            break;
        default:
            printf("Invalid conversion choice!\n");
            return 1;
    }

    printf("The result is %s%c %.2f\n", result.unit, choice, result.value);

    return 0;
}