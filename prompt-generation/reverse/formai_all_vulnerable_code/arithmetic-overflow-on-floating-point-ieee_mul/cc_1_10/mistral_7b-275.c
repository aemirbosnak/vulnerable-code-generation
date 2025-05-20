//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char input[50];
    double fahrenheit, celsius;

    printf("\nWelcome, dear temperature seeker,\n");
    printf("to the mystical land of temperature conversion!\n");
    printf("Here we'll transform Fahrenheit to Celsius,\n");
    printf("and vice versa, with a dash of curious style!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("Your choice: ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        switch (atoi(input)) {
            case 1:
                printf("Enter Fahrenheit temperature: ");
                scanf("%lf", &fahrenheit);
                celsius = (fahrenheit - 32) * 5.0 / 9.0;
                printf("The temperature in Celsius is %.2lf degrees.\n", celsius);
                break;

            case 2:
                printf("Enter Celsius temperature: ");
                scanf("%lf", &celsius);
                fahrenheit = celsius * 9.0 / 5.0 + 32;
                printf("The temperature in Fahrenheit is %.2lf degrees.\n", fahrenheit);
                break;

            case 3:
                printf("Farewell, temperature traveler!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}