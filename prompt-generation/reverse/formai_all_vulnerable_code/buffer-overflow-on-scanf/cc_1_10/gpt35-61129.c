//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// Function to display the main menu
void displayMenu() {
    printf("\nSelect the conversion type: \n");
    printf("1. Distance\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    printf("4. Quit\n\n");
}

// Function to display the distance submenu
void displayDistanceMenu() {
    printf("\nSelect the distance conversion: \n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Quit\n\n");
}

// Function to display the temperature submenu
void displayTemperatureMenu() {
    printf("\nSelect the temperature conversion: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Quit\n\n");
}

// Function to display the weight submenu
void displayWeightMenu() {
    printf("\nSelect the weight conversion: \n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Quit\n\n");
}

// Function to convert distance from miles to kilometers
void milesToKilometers(float miles) {
    float kilometers = miles * 1.609;
    printf("%.2f miles is equal to %.2f kilometers.\n", miles, kilometers);
}

// Function to convert distance from kilometers to miles
void kilometersToMiles(float kilometers) {
    float miles = kilometers / 1.609;
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
}

// Function to convert temperature from Celsius to Fahrenheit
void celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert temperature from Fahrenheit to Celsius
void fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

// Function to convert weight from pounds to kilograms
void poundsToKilograms(float pounds) {
    float kilograms = pounds / 2.205;
    printf("%.2f pounds is equal to %.2f kilograms.\n", pounds, kilograms);
}

// Function to convert weight from kilograms to pounds
void kilogramsToPounds(float kilograms) {
    float pounds = kilograms * 2.205;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

// Main function
int main() {
    int choice1, choice2;
    float distance, temperature, weight;

    // Display the main menu
    displayMenu();

    // Get the choice of the user
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    // Process the choice of the user
    switch(choice1) {
        case 1:
            // Distance submenu
            do {
                displayDistanceMenu();
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                switch(choice2) {
                    case 1:
                        printf("Enter distance in miles: ");
                        scanf("%f", &distance);
                        milesToKilometers(distance);
                        break;
                    case 2:
                        printf("Enter distance in kilometers: ");
                        scanf("%f", &distance);
                        kilometersToMiles(distance);
                        break;
                    case 3:
                        printf("Returning to main menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Try again.\n");
                }
            } while (choice2 != 3);
            break;
        case 2:
            // Temperature submenu
            do {
                displayTemperatureMenu();
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                switch(choice2) {
                    case 1:
                        printf("Enter temperature in Celsius: ");
                        scanf("%f", &temperature);
                        celsiusToFahrenheit(temperature);
                        break;
                    case 2:
                        printf("Enter temperature in Fahrenheit: ");
                        scanf("%f", &temperature);
                        fahrenheitToCelsius(temperature);
                        break;
                    case 3:
                        printf("Returning to main menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Try again.\n");
                }
            } while (choice2 != 3);
            break;
        case 3:
            // Weight submenu
            do {
                displayWeightMenu();
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                switch(choice2) {
                    case 1:
                        printf("Enter weight in pounds: ");
                        scanf("%f", &weight);
                        poundsToKilograms(weight);
                        break;
                    case 2:
                        printf("Enter weight in kilograms: ");
                        scanf("%f", &weight);
                        kilogramsToPounds(weight);
                        break;
                    case 3:
                        printf("Returning to main menu.\n");
                        break;
                    default:
                        printf("Invalid choice. Try again.\n");
                }
            } while (choice2 != 3);
            break;
        case 4:
            // Quit the program
            printf("Thank you for using the unit converter!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
    }

    return 0;
}