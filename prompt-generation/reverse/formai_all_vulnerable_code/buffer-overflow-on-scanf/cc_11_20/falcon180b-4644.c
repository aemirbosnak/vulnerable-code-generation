//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double input, output;
    char choice;
    int flag = 0;
    printf("Welcome to the Unit Converter!\n");
    printf("Enter a number to convert: ");
    scanf("%lf", &input);
    printf("Enter the units you want to convert from (e.g. meters, feet, inches): ");
    scanf(" %c", &choice);
    switch (choice) {
        case'm':
            printf("Enter the units you want to convert to (e.g. feet, inches): ");
            scanf(" %c", &choice);
            switch (choice) {
                case 'f':
                    output = input * 3.28084;
                    printf("%lf meters is %lf feet.\n", input, output);
                    flag = 1;
                    break;
                case 'i':
                    output = input * 39.3701;
                    printf("%lf meters is %lf inches.\n", input, output);
                    flag = 1;
                    break;
                default:
                    printf("Invalid units.\n");
            }
            break;
        case 'f':
            printf("Enter the units you want to convert to (e.g. meters, inches): ");
            scanf(" %c", &choice);
            switch (choice) {
                case'm':
                    output = input / 3.28084;
                    printf("%lf feet is %lf meters.\n", input, output);
                    flag = 1;
                    break;
                case 'i':
                    output = input * 12;
                    printf("%lf feet is %lf inches.\n", input, output);
                    flag = 1;
                    break;
                default:
                    printf("Invalid units.\n");
            }
            break;
        case 'i':
            printf("Enter the units you want to convert to (e.g. meters, feet): ");
            scanf(" %c", &choice);
            switch (choice) {
                case'm':
                    output = input / 39.3701;
                    printf("%lf inches is %lf meters.\n", input, output);
                    flag = 1;
                    break;
                case 'f':
                    output = input / 12;
                    printf("%lf inches is %lf feet.\n", input, output);
                    flag = 1;
                    break;
                default:
                    printf("Invalid units.\n");
            }
            break;
        default:
            printf("Invalid units.\n");
    }
    if (flag == 0) {
        printf("No conversion was made.\n");
    }
    return 0;
}