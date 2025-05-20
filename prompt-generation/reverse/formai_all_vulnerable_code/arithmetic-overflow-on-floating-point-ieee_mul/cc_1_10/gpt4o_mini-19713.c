//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: romantic
#include <stdio.h>

// A gentle encounter with the stars, where Celsius meets the warm embrace of Fahrenheit
void display_welcome_message() {
    printf("==========================================\n");
    printf("Welcome to the Serene Temperature Converter\n");
    printf("==========================================\n");
    printf("Let your heart decide: Shall we convert Celsius to Fahrenheit or vice versa?\n");
    printf("==========================================\n");
}

void celsius_to_fahrenheit(double celsius) {
    // The passionate conversion that makes two lovers one
    double fahrenheit = (celsius * 9/5) + 32;
    printf("With a gentle touch, %.2f°C becomes %.2f°F.\n", celsius, fahrenheit);
}

void fahrenheit_to_celsius(double fahrenheit) {
    // The graceful reversal, as they kiss under the moonlight
    double celsius = (fahrenheit - 32) * 5/9;
    printf("In a tender moment, %.2f°F transforms into %.2f°C.\n", fahrenheit, celsius);
}

void display_menu() {
    printf("\nPlease choose the conversion you desire:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Your choice: ");
}

int main() {
    double temperature;
    int choice;

    // A steadfast loop that binds our destinies
    while (1) {
        display_welcome_message();
        display_menu();

        // The heart's gentle whisper - awaiting the user's decision
        scanf("%d", &choice);

        // How love stories have different chapters
        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &temperature);
                celsius_to_fahrenheit(temperature);
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                fahrenheit_to_celsius(temperature);
                break;
            case 3:
                printf("As the sun sets, we must part ways. Farewell!\n");
                return 0;
            default:
                printf("Alas, that choice does not exist in our fairytale. Try again!\n");
        }
        
        // A delicate pause for reflection – how romantic!
        printf("\nWhat a lovely conversion! Would you like to continue? (Press any key to return to the menu)\n");
        getchar(); // Clear the new line from buffer if needed
        getchar(); // Wait for user input to continue
    }

    return 0;
}