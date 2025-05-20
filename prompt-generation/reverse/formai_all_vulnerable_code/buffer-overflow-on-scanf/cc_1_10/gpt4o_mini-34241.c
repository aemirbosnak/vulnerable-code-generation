//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>

// Function declarations
void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float celsiusToKelvin(float celsius);
float kelvinToCelsius(float kelvin);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToFahrenheit(float kelvin);

int main() {
    float temperature;
    int choice;
    
    printf("Welcome to the Temperature Converter!\n");
    printf("Let's transform your temperature scales like magic! 🌡️✨\n\n");
    
    while(1) {
        displayMenu();  // Show menu options
        printf("Please select your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thanks for using Temperature Converter. Have a great day! 🌞\n");
            break;
        }
        
        if (choice < 1 || choice > 6) {
            printf("Oops! That's not a valid choice. Please try again! ❌\n");
            continue;
        }

        printf("Enter the temperature you want to convert: ");
        scanf("%f", &temperature);
        
        switch (choice) {
            case 1:
                printf("%.2f °C is equal to %.2f °F\n",
                        temperature, celsiusToFahrenheit(temperature));
                break;
            case 2:
                printf("%.2f °F is equal to %.2f °C\n",
                        temperature, fahrenheitToCelsius(temperature));
                break;
            case 3:
                printf("%.2f °C is equal to %.2f K\n",
                        temperature, celsiusToKelvin(temperature));
                break;
            case 4:
                printf("%.2f K is equal to %.2f °C\n",
                        temperature, kelvinToCelsius(temperature));
                break;
            case 5:
                printf("%.2f °F is equal to %.2f K\n",
                        temperature, fahrenheitToKelvin(temperature));
                break;
            case 6:
                printf("%.2f K is equal to %.2f °F\n",
                        temperature, kelvinToFahrenheit(temperature));
                break;
            default:
                printf("This shouldn't happen! Please check your code! 🤔\n");
        }
        
        printf("\nWould you like to convert another temperature? (yes/no): ");
        char response[4];
        scanf("%3s", response);
        
        if (response[0] == 'n' || response[0] == 'N') {
            printf("Alright! Catch you later! 👋\n");
            break;
        }
    }
    
    return 0;
}

// Function definitions

void displayMenu() {
    printf("\n--- Temperature Conversion Options ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("---------------------------------------\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}