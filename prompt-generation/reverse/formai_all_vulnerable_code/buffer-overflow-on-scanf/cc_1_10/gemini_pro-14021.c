//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: scientific
// Imperial and metric temperature conversion program

// Celsius to Fahrenheit conversion
double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Fahrenheit to Celsius conversion
double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Kelvin to Fahrenheit conversion
double convertKelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}

// Fahrenheit to Kelvin conversion
double convertFahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

// Celsius to Kelvin conversion
double convertCelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Kelvin to Celsius conversion
double convertKelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Main program
int main() {
    // Declare variables
    double temperature, convertedTemperature;
    char conversionType;

    // Get input from the user
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    printf("Enter the conversion type (C/F/K): ");
    scanf(" %c", &conversionType);

    // Convert the temperature
    switch (conversionType) {
        case 'C':
            convertedTemperature = convertCelsiusToFahrenheit(temperature);
            printf("The temperature in Fahrenheit is: %.2f\n", convertedTemperature);
            break;
        case 'F':
            convertedTemperature = convertFahrenheitToCelsius(temperature);
            printf("The temperature in Celsius is: %.2f\n", convertedTemperature);
            break;
        case 'K':
            convertedTemperature = convertKelvinToFahrenheit(temperature);
            printf("The temperature in Fahrenheit is: %.2f\n", convertedTemperature);
            break;
        default:
            printf("Invalid conversion type.");
    }

    return 0;
}