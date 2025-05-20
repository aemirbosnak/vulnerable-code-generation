//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include<stdio.h>

int main() {
    int choice1, choice2;
    float input, output;
    printf("Welcome to the Unit Converter!\n");
    printf("Please choose the input unit:\n1. Meter (m)\n2. Kilometer (km)\n3. Centimeter (cm)\n");
    scanf("%d", &choice1);
    printf("Please choose the output unit:\n1. Meter (m)\n2. Kilometer (km)\n3. Centimeter (cm)\n");
    scanf("%d", &choice2);
    
    if(choice1 == choice2) {
        printf("You chose the same units for input and output. Please re-run the program.\n");
        return 0;
    }
    
    printf("Please enter the input value: ");
    scanf("%f", &input);
    
    switch(choice1) {
        case 1: // Meter
            switch(choice2) {
                case 2: // Meter to kilometer
                    output = input/1000;
                    printf("%.2f m is equal to %.2f km.\n", input, output);
                    break;
                case 3: // Meter to centimeter
                    output = input*100;
                    printf("%.2f m is equal to %.2f cm.\n", input, output);
                    break;
                default:
                    printf("Invalid output unit choice. Please re-run the program.\n");
            }
            break;
        case 2: // Kilometer
            switch(choice2) {
                case 1: // Kilometer to meter
                    output = input*1000;
                    printf("%.2f km is equal to %.2f m.\n", input, output);
                    break;
                case 3: // Kilometer to centimeter
                    output = input*100000;
                    printf("%.2f km is equal to %.2f cm.\n", input, output);
                    break;
                default:
                    printf("Invalid output unit choice. Please re-run the program.\n");
            }
            break;
        case 3: // Centimeter
            switch(choice2) {
                case 1: // Centimeter to meter
                    output = input/100;
                    printf("%.2f cm is equal to %.2f m.\n", input, output);
                    break;
                case 2: // Centimeter to kilometer
                    output = input/100000;
                    printf("%.2f cm is equal to %.2f km.\n", input, output);
                    break;
                default:
                    printf("Invalid output unit choice. Please re-run the program.\n");
            }
            break;
        default:
            printf("Invalid input unit choice. Please re-run the program.\n");
    }
    return 0;
}