//FormAI DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Mind-Bending Unit Converter!\n");
    printf("Please choose the unit type you want to convert:\n");
    printf("1. Distance\n");
    printf("2. Temperature\n");
    printf("3. Time\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Awesome choice! Let's convert some distances!\n");
            printf("Please enter the distance you want to convert: ");

            double distance;
            scanf("%lf", &distance);

            printf("Please choose the unit you want to convert:\n");
            printf("1. Kilometers\n");
            printf("2. Meters\n");
            printf("3. Centimeters\n");

            int distance_choice;
            scanf("%d", &distance_choice);

            double converted_distance;

            switch(distance_choice) {
                case 1:
                    converted_distance = distance * 1000;
                    printf("%.2lf kilometers is equal to %.2lf meters.\n", distance, converted_distance);
                    break;
                case 2:
                    converted_distance = distance * 1000 * 100;
                    printf("%.2lf kilometers is equal to %.2lf centimeters.\n", distance, converted_distance);
                    break;
                case 3:
                    converted_distance = distance * 1000 * 100 * 100;
                    printf("%.2lf kilometers is equal to %.2lf millimeters.\n", distance, converted_distance);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }

            break;
        
        case 2:
            printf("Nice choice! Let's convert some temperatures!\n");
            printf("Please enter the temperature you want to convert: ");

            double temperature;
            scanf("%lf", &temperature);

            printf("Please choose the unit you want to convert:\n");
            printf("1. Celsius\n");
            printf("2. Fahrenheit\n");

            int temperature_choice;
            scanf("%d", &temperature_choice);

            double converted_temperature;

            switch(temperature_choice) {
                case 1:
                    converted_temperature = (temperature * 9/5) + 32;
                    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", temperature, converted_temperature);
                    break;
                case 2:
                    converted_temperature = (temperature - 32) * 5/9;
                    printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", temperature, converted_temperature);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }

            break;

        case 3:
            printf("Great choice! Let's convert some time!\n");
            printf("Please enter the time you want to convert: ");

            double time;
            scanf("%lf", &time);

            printf("Please choose the unit you want to convert:\n");
            printf("1. Seconds\n");
            printf("2. Minutes\n");
            printf("3. Hours\n");

            int time_choice;
            scanf("%d", &time_choice);

            double converted_time;

            switch(time_choice) {
                case 1:
                    converted_time = time / 60;
                    printf("%.2lf seconds is equal to %.2lf minutes.\n", time, converted_time);
                    break;
                case 2:
                    converted_time = time / 60 / 60;
                    printf("%.2lf minutes is equal to %.2lf hours.\n", time, converted_time);
                    break;
                case 3:
                    converted_time = time * 60;
                    printf("%.2lf hours is equal to %.2lf minutes.\n", time, converted_time);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }

            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Thanks for using the Mind-Bending Unit Converter! See you again soon!");

    return 0;
}