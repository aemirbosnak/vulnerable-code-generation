//FormAI DATASET v1.0 Category: Unit converter ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

void distance_converter();
void temperature_converter();
void weight_converter();
void time_converter();

int main()
{
    int choice;

    printf("Welcome to the Unique Unit Converter\n");
    printf("1. Distance Converter\n");
    printf("2. Temperature Converter\n");
    printf("3. Weight Converter\n");
    printf("4. Time Converter\n");
    printf("5. Exit");

    do {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                distance_converter();
                break;
            case 2:
                temperature_converter();
                break;
            case 3:
                weight_converter();
                break;
            case 4:
                time_converter();
                break;
            case 5:
                printf("Thank you for using the Unique Unit Converter\n");
                exit(0);
            default:
                printf("Invalid Input. Please try again.\n");
                break;
        }

    } while (choice!=0);

    return 0;
}

void distance_converter()
{
    float distance;
    int choice;

    printf("\nDISTANCE CONVERTER\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Exit");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter distance in kilometers: ");
                scanf("%f", &distance);
                printf("%.2f kilometers = %.2f miles\n", distance, distance/1.609);
                break;
            case 2:
                printf("Enter distance in miles: ");
                scanf("%f", &distance);
                printf("%.2f miles = %.2f kilometers\n", distance, distance*1.609);
                break;
            case 3:
                printf("Exiting Distance Converter\n");
                return;
            default:
                printf("Invalid Input. Please try again.\n");
                break;
        }

    } while (choice!=0);
}

void temperature_converter()
{
    float temperature;
    int choice;

    printf("\nTEMPERATURE CONVERTER\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, (temperature*9/5)+32);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, (temperature-32)*5/9);
                break;
            case 3:
                printf("Exiting Temperature Converter\n");
                return;
            default:
                printf("Invalid Input. Please try again.\n");
                break;
        }

    } while (choice!=0);
}

void weight_converter()
{
    float weight;
    int choice;

    printf("\nWEIGHT CONVERTER\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Exit");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter weight in Kilograms: ");
                scanf("%f", &weight);
                printf("%.2f Kilograms = %.2f Pounds\n", weight, weight*2.20462);
                break;
            case 2:
                printf("Enter weight in Pounds: ");
                scanf("%f", &weight);
                printf("%.2f Pounds = %.2f Kilograms\n", weight, weight/2.20462);
                break;
            case 3:
                printf("Exiting Weight Converter\n");
                return;
            default:
                printf("Invalid Input. Please try again.\n");
                break;
        }

    } while (choice!=0);
}

void time_converter()
{
    int time, hours, minutes, seconds;
    int choice;

    printf("\nTIME CONVERTER\n");
    printf("1. Seconds to Hours:Minutes:Seconds\n");
    printf("2. Hours:Minutes:Seconds to Seconds\n");
    printf("3. Exit");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter time in seconds: ");
                scanf("%d", &time);
                hours = time/3600;
                minutes = (time-(hours*3600))/60;
                seconds = time-(hours*3600)-(minutes*60);
                printf("%d Seconds = %d:%d:%d\n", time, hours, minutes, seconds);
                break;
            case 2:
                printf("Enter time in Hours:Minutes:Seconds format: ");
                scanf("%d:%d:%d", &hours, &minutes, &seconds);
                time = (hours*3600)+(minutes*60)+seconds;
                printf("%d:%d:%d = %d Seconds\n", hours, minutes, seconds, time);
                break;
            case 3:
                printf("Exiting Time Converter\n");
                return;
            default:
                printf("Invalid Input. Please try again.\n");
                break;
        }

    } while (choice!=0);
}