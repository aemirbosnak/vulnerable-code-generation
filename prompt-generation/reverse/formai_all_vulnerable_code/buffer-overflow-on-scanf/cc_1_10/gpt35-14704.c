//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("=============================\n");
    printf("Welcome to the Celsius converter!\n");
    printf("=============================\n\n");

    float celsius, fahrenheit, kelvin;

    printf("Please enter a temperature in Celsius: ");

    if (scanf("%f", &celsius) == 1) {
        printf("You have entered %.2f °C.\n\n", celsius);
    } else {
        printf("\nInvalid input. Exiting program.\n");
        exit(EXIT_FAILURE);
    }

    fahrenheit = celsius * 1.8 + 32;
    kelvin = celsius + 273.15;

    printf("Converting...\n\n");

    for(int i = 0; i < 10; i++) {
        printf("Calculating.");
        fflush(stdout);
        usleep(150000);
        printf(".");
        fflush(stdout);
        usleep(150000);
        printf(".");
        fflush(stdout);
        usleep(150000);
        printf(".\n");
        fflush(stdout);
        usleep(150000);
    }

    printf("\n%.2f °C is equivalent to:\n", celsius);
    printf("%.2f °F (Fahrenheit)\n", fahrenheit);
    printf("%.2f K (Kelvin)\n", kelvin);

    printf("\nWould you like to convert another temperature? (y/n) ");

    char choice;

    if (scanf(" %c", &choice) == 1) {
        if (choice == 'y' || choice == 'Y') {
            system("clear");
            main();
        } else if (choice == 'n' || choice == 'N') {
            printf("\nThank you for using the Celsius converter!\n");
            printf("=============================\n");
        } else {
            printf("\nInvalid input. Exiting program.\n");
        }
    } else {
        printf("\nInvalid input. Exiting program.\n");
    }

    return 0;
}