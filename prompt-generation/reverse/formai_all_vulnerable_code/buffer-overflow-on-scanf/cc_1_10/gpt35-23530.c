//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

/*Function to convert Celsius to Fahrenheit*/
double celsiusToFahrenheit(double celsius)
{
    double fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

/*Function to convert Celsius to Kelvin*/
double celsiusToKelvin(double celsius)
{
    double kelvin = celsius + 273.15;
    return kelvin;
}

/*Function to convert Fahrenheit to Celsius*/
double fahrenheitToCelsius(double fahrenheit)
{
    double celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

/*Function to convert Fahrenheit to Kelvin*/
double fahrenheitToKelvin(double fahrenheit)
{
    double kelvin = (fahrenheit - 32) * 5/9 + 273.15;
    return kelvin;
}

/*Function to convert Kelvin to Celsius*/
double kelvinToCelsius(double kelvin)
{
    double celsius = kelvin - 273.15;
    return celsius;
}

/*Function to convert Kelvin to Fahrenheit*/
double kelvinToFahrenheit(double kelvin)
{
    double fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    return fahrenheit;
}

int main()
{
    double input_value;
    int choice;

    printf("Welcome to the Unit Converter!\n");

    do {
        /*Display the conversion options*/
        printf("\nPlease select a conversion option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Fahrenheit to Kelvin\n");
        printf("5. Kelvin to Celsius\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");

        /*Read the user's choice*/
        printf("Your choice: ");
        scanf("%d", &choice);

	/*Check if the user entered a valid choice*/
	if (choice < 1 || choice > 7) {
	    printf("Invalid choice. Please try again.\n");
	    continue;
	}

        /*Read the input value*/
        printf("Enter the input value: ");
        scanf("%lf", &input_value);

        /*Convert the input value based on the user's choice*/
        switch(choice) {
            case 1:
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", input_value, celsiusToFahrenheit(input_value));
                break;
            case 2:
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Kelvin.\n", input_value, celsiusToKelvin(input_value));
                break;
            case 3:
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", input_value, fahrenheitToCelsius(input_value));
                break;
            case 4:
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Kelvin.\n", input_value, fahrenheitToKelvin(input_value));
                break;
            case 5:
                printf("%.2lf degrees Kelvin is equal to %.2lf degrees Celsius.\n", input_value, kelvinToCelsius(input_value));
                break;
            case 6:
                printf("%.2lf degrees Kelvin is equal to %.2lf degrees Fahrenheit.\n", input_value, kelvinToFahrenheit(input_value));
                break;
            case 7:
                printf("Exiting the program...\n");
                break;
        }

    } while(choice != 7);

    return 0;
}