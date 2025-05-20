//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include<stdio.h>

int main() {
    int choice;
    double value;
    printf("\n************************************\n");
    printf("\tWelcome to the Unit Converter!\n");
    printf("************************************\n\n");
    printf("Select an option below:\n");

    while(1) {
        printf("1. Miles to Kilometers\n");
        printf("2. Kilometers to Miles\n");
        printf("3. Inches to Centimeters\n");
        printf("4. Centimeters to Inches\n");
        printf("5. Fahrenheit to Celsius\n");
        printf("6. Celsius to Fahrenheit\n");
        printf("7. Quit\n");

        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter the number of miles:\n");
            scanf("%lf", &value);
            printf("%.2lf miles is equal to %.2lf kilometers\n\n", value, value * 1.60934);
        }
        else if(choice == 2) {
            printf("Enter the number of kilometers:\n");
            scanf("%lf", &value);
            printf("%.2lf kilometers is equal to %.2lf miles\n\n", value, value * 0.621371);
        }
        else if(choice == 3) {
            printf("Enter the number of inches:\n");
            scanf("%lf", &value);
            printf("%.2lf inches is equal to %.2lf centimeters\n\n", value, value * 2.54);
        }
        else if(choice == 4) {
            printf("Enter the number of centimeters:\n");
            scanf("%lf", &value);
            printf("%.2lf centimeters is equal to %.2lf inches\n\n", value, value * 0.393701);
        }
        else if(choice == 5) {
            printf("Enter the temperature in Fahrenheit:\n");
            scanf("%lf", &value);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius\n\n", value, (value - 32) * 5 / 9);
        }
        else if(choice == 6) {
            printf("Enter the temperature in Celsius:\n");
            scanf("%lf", &value);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit\n\n", value, (value * 9 / 5) + 32);
        }
        else if(choice == 7) {
            printf("Thank you for using the Unit Converter!\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n\n");
        }
    }
    return 0;
}