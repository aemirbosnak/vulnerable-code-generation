//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

// A declaration of the royal castle's noble functions
void convertToCelsius(float fahrenheit);
void convertToFahrenheit(float celsius);
void displayRoyalMessage();

// The grand hall of the Temperature Converter, where the noble functions reside
int main() {
    // A tale of temperatures shared by the realm
    float temperature;
    char choice;
    
    // The noble message to open the royal festivities
    displayRoyalMessage();

    // The knights of choice shall proceed within this mystical loop
    while (1) {
        // The royal inquiry of temperature to be converted
        printf("\nPray tell, what temperature dost thou wish to transmute? (enter '-1' to exit): ");
        scanf("%f", &temperature);
        
        // The knightly command for retreat
        if (temperature == -1) {
            printf("Farewell, noble traveler! May your journeys be warm and pleasant.\n");
            break;
        }

        // The herald shall declare the options of conversions
        printf("Dost thou wish to convert to (C)elsius or (F)ahrenheit? ");
        getchar(); // To consume the newline character
        choice = getchar();

        // The realm responds based on noble choice
        if (choice == 'C' || choice == 'c') {
            convertToCelsius(temperature);
        } else if (choice == 'F' || choice == 'f') {
            convertToFahrenheit(temperature);
        } else {
            printf("Alas! That choice is not known in the kingdom. Please try again.\n");
        }
    }
    
    return 0;
}

// This function doth convert from Fahrenheit to Celsius
void convertToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("Transforming %.2f degrees Fahrenheit to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

// This function doth convert from Celsius to Fahrenheit
void convertToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("Transforming %.2f degrees Celsius to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

// The noble function to proclaim a royal welcome
void displayRoyalMessage() {
    printf("~~~~~~~~~~~ The Royal Temperature Converter ~~~~~~~~~~~\n");
    printf("Greetings, noble traveler of the kingdom!\n");
    printf("Herein, thou shalt convert temperatures between Celsius and Fahrenheit.\n");
    printf("May your toils be light and your conversions true!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}