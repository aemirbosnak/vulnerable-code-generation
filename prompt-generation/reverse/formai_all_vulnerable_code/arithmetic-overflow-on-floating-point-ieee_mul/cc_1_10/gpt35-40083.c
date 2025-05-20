//FormAI DATASET v1.0 Category: Temperature Converter ; Style: protected
#include<stdio.h>

int main(){
    float celsius, fahrenheit, kelvin;
    int choice;

    do {
        printf("Welcome to Temperature Converter!\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
            {
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);

                fahrenheit = (celsius * 9/5) + 32;

                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
                break;
            }

            case 2:
            {
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);

                celsius = (fahrenheit - 32) * 5/9;

                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
                break;
            }

            case 3:
            {
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);

                kelvin = celsius + 273.15;

                printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, kelvin);
                break;
            }

            case 4:
            {
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &kelvin);

                celsius = kelvin - 273.15;

                printf("%.2f Kelvin is equal to %.2f Celsius\n", kelvin, celsius);
                break;
            }

            case 5:
            {
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);

                kelvin = (fahrenheit - 32) * 5/9 + 273.15;

                printf("%.2f Fahrenheit is equal to %.2f Kelvin\n", fahrenheit, kelvin);
                break;
            }

            case 6:
            {
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &kelvin);

                fahrenheit = (kelvin - 273.15) * 9/5 + 32;

                printf("%.2f Kelvin is equal to %.2f Fahrenheit\n", kelvin, fahrenheit);
                break;
            }

            case 7:
            {
                printf("Thank you for using Temperature Converter!\n");
                break;
            }

            default:
            {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 7);

    return 0;
}