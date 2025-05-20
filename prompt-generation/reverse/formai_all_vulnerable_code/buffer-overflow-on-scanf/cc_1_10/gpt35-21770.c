//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

int main() {
    float input, output;
    int choice;

    printf("C Unit Converter\n");
    printf("--------------------------\n");

    printf("Enter the input value: ");
    scanf("%f", &input);

    printf("Select the input unit:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Select the output unit:\n");
            printf("1. Fahrenheit\n");
            printf("2. Kelvin\n");
            scanf("%d", &choice);

            if(choice == 1){
                output = (input * 9/5) + 32;
                printf("%.2f°C is equal to %.2f°F", input, output);
            }
            else if(choice == 2){
                output = input + 273.15;
                printf("%.2f°C is equal to %.2fK", input, output);
            }
            else{
                printf("Invalid choice! Please try again.");
            }
            break;

        case 2:
            printf("Select the output unit:\n");
            printf("1. Celsius\n");
            printf("2. Kelvin\n");
            scanf("%d", &choice);

            if(choice == 1){
                output = (input - 32) * 5/9;
                printf("%.2f°F is equal to %.2f°C", input, output);
            }
            else if(choice == 2){
                output = (input - 32) * 5/9 + 273.15;
                printf("%.2f°F is equal to %.2fK", input, output);
            }
            else{
                printf("Invalid choice! Please try again.");
            }
            break;

        default:
            printf("Invalid choice! Please try again.");
            break;
    }

    return 0;
}