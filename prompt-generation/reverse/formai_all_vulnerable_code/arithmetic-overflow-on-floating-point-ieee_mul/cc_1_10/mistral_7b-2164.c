//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PI 3.14159265358979323846

typedef struct {
    double fahrenheit;
    double celsius;
} Temperature;

void print_menu() {
    printf("**********************************************************\n");
    printf("*                                                        *\n");
    printf("*   Welcome to the Surrealist Temperature Converter!      *\n");
    printf("*                                                        *\n");
    printf("**********************************************************\n");
    printf("*                                                        *\n");
    printf("*      Press 1 to convert Fahrenheit to Celsius          *\n");
    printf("*      Press 2 to convert Celsius to Fahrenheit          *\n");
    printf("*      Press 3 to experience a surrealist temperature journey *\n");
    printf("*                                                        *\n");
    printf("**********************************************************\n");
}

void convert_fahrenheit_to_celsius(Temperature *temp) {
    temp->celsius = (temp->fahrenheit - 32) * 5.0 / 9.0;
}

void convert_celsius_to_fahrenheit(Temperature *temp) {
    temp->fahrenheit = temp->celsius * 9.0 / 5.0 + 32;
}

void surrealist_journey(Temperature *temp) {
    srand(time(NULL));

    if (temp->fahrenheit > 100) {
        temp->celsius = rand() % 100 + 30;
        printf("Your temperature is now %d degrees Celsius.\n", (int) temp->celsius);
    } else {
        temp->fahrenheit = rand() % 50 + 212.0;
        printf("Your temperature is now %d degrees Fahrenheit.\n", (int) temp->fahrenheit);
    }

    int choice = rand() % 3 + 1;

    switch (choice) {
        case 1:
            printf("The snow outside is melting and turning into soup.\n");
            break;
        case 2:
            printf("The air around you is thick with fog, making it hard to see.\n");
            break;
        case 3:
            printf("The temperature in the room is suddenly dropping, making you shiver.\n");
            break;
        default:
            break;
    }
}

int main() {
    Temperature temp;
    int choice;

    print_menu();

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temp.fahrenheit);
                convert_fahrenheit_to_celsius(&temp);
                printf("Your temperature is now %lf degrees Celsius.\n", temp.celsius);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp.celsius);
                convert_celsius_to_fahrenheit(&temp);
                printf("Your temperature is now %lf degrees Fahrenheit.\n", temp.fahrenheit);
                break;
            case 3:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temp.fahrenheit);
                surrealist_journey(&temp);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}