//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: funny
#include <stdio.h>

void showWelcomeMessage() {
    printf("Welcome to the 'I-Didn't-Think-This-Through' unit converter!\n");
    printf("Where converting units is so easy, even your dog can do it... well, maybe not.\n\n");
}

void showMainMenu() {
    printf("Choose your conversion:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Grams to Pounds\n");
    printf("4. Quit (Somebody needs to stop this madness!)\n");
}

double kilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double gramsToPounds(double grams) {
    return grams * 0.00220462;
}

void triggerConversion(int choice) {
    double input, output;

    switch (choice) {
        case 1:
            printf("You chose to convert Kilometers to Miles. Nice!\n");
            printf("Enter the distance in kilometers (or the distance to the fridge): ");
            scanf("%lf", &input);
            output = kilometersToMiles(input);
            printf("%.2f Kilometers is approximately %.2f Miles! You can run a marathon now!\n",
                   input, output);
            break;

        case 2:
            printf("You chose to convert Celsius to Fahrenheit!\n");
            printf("Enter temperature in Celsius (or just scream into the void): ");
            scanf("%lf", &input);
            output = celsiusToFahrenheit(input);
            printf("%.2f Celsius is around %.2f Fahrenheit! Isn't science magical?\n",
                   input, output);
            break;

        case 3:
            printf("You want to convert Grams to Pounds? Very trendy!\n");
            printf("Enter weight in grams (or the amount of cheese you possess): ");
            scanf("%lf", &input);
            output = gramsToPounds(input);
            printf("%.2f Grams is about %.2f Pounds! Time to bench press that cheese!\n",
                   input, output);
            break;

        case 4:
            printf("Who let you in?! Hitting the escape button! Goodbye!\n");
            return;

        default:
            printf("I don't understand that option. Did you even press a button?!\n");
            break;
    }
}

int main() {
    int choice;

    showWelcomeMessage();

    do {
        showMainMenu();
        printf("Pick your poison (1-4): ");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 4) {
            triggerConversion(choice);
        } else {
            printf("Did you just hit random keys on your keyboard? Try again!\n");
        }

        printf("\nWould you like to convert something else (1: Yes, 0: No)? ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Thanks for using the 'I-Didn't-Think-This-Through' unit converter!\n");
    printf("Remember, with great power comes great responsibility... and confusion.\n");
    return 0;
}