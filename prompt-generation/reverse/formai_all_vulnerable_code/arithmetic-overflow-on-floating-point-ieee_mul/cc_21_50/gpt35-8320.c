//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>

int main() {
    float inputVal;
    int inputUnit;
    int outputUnit;
    printf("Welcome to the futuristic Unit Converter!\n");
    printf("Enter the value you wish to convert: ");
    scanf("%f", &inputVal);
    printf("Select the input unit:\n");
    printf("[1] Meter\n");
    printf("[2] Kilometer\n");
    printf("[3] Mile\n");
    printf("[4] Yard\n");
    printf("[5] Foot\n");
    printf("[6] Inch\n");
    printf("Input unit: ");
    scanf("%d", &inputUnit);
    printf("\nSelect the output unit:\n");
    printf("[1] Meter\n");
    printf("[2] Kilometer\n");
    printf("[3] Mile\n");
    printf("[4] Yard\n");
    printf("[5] Foot\n");
    printf("[6] Inch\n");
    printf("Output unit: ");
    scanf("%d", &outputUnit);

    float meter = inputVal;
    switch (inputUnit) {
        case 2:
            meter = inputVal * 1000;
            break;
        case 3:
            meter = inputVal * 1609.34;
            break;
        case 4:
            meter = inputVal * 0.9144;
            break;
        case 5:
            meter = inputVal * 0.3048;
            break;
        case 6:
            meter = inputVal * 0.0254;
            break;
        default:
            break;
    }

    float result = meter;
    switch (outputUnit) {
        case 2:
            result = meter / 1000;
            break;
        case 3:
            result = meter / 1609.34;
            break;
        case 4:
            result = meter / 0.9144;
            break;
        case 5:
            result = meter / 0.3048;
            break;
        case 6:
            result = meter / 0.0254;
            break;
        default:
            break;
    }

    printf("\n%.2f ", inputVal);
    switch (inputUnit) {
        case 1:
            printf("meters");
            break;
        case 2:
            printf("kilometers");
            break;
        case 3:
            printf("miles");
            break;
        case 4:
            printf("yards");
            break;
        case 5:
            printf("feet");
            break;
        case 6:
            printf("inches");
            break;
        default:
            break;
    }
    printf(" is equal to %.2f ", result);

    switch (outputUnit) {
        case 1:
            printf("meters.\n");
            break;
        case 2:
            printf("kilometers.\n");
            break;
        case 3:
            printf("miles.\n");
            break;
        case 4:
            printf("yards.\n");
            break;
        case 5:
            printf("feet.\n");
            break;
        case 6:
            printf("inches.\n");
            break;
        default:
            break;
    }

    return 0;
}