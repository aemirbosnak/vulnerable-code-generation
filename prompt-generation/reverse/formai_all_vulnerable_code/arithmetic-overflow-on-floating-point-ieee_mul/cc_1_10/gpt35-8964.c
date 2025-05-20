//FormAI DATASET v1.0 Category: Unit converter ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program is a unit converter that is both fun and functional!
   With conversions for distance, weight, and temperature 
   it's sure to help keep you on track with your units :) */

int main(){

    int option;
    float input, output;

    printf("Hello there! Welcome to the Unit Converter!\n");
    printf("What would you like to convert today?\n");
    printf("1. Distance\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if(option == 1) {
        printf("You have selected Distance\n");
        printf("Please enter the value in meters: ");
        scanf("%f", &input);
        printf("What would you like to convert it to?\n");
        printf("1. Kilometers\n");
        printf("2. Miles\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        if(option == 1){
            output = input / 1000;
            printf("%.2f meters is equal to %.2f kilometers\n", input, output);
        } else if(option == 2) {
            output = input * 0.000621371;
            printf("%.2f meters is equal to %.2f miles\n", input, output);
        } else {
            printf("Invalid choice!!\n");
            return 0;
        }
    } else if(option == 2) {
        printf("You have selected Weight\n");
        printf("Please enter the value in grams: ");
        scanf("%f", &input);
        printf("What would you like to convert it to?\n");
        printf("1. Kilograms\n");
        printf("2. Pounds\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        if(option == 1){
            output = input / 1000;
            printf("%.2f grams is equal to %.2f kilograms\n", input, output);
        } else if(option == 2) {
            output = input * 0.00220462;
            printf("%.2f grams is equal to %.2f pounds\n", input, output);
        } else {
            printf("Invalid choice!!\n");
            return 0;
        }
    } else if(option == 3) {
        printf("You have selected Temperature\n");
        printf("Please enter the value in Celsius: ");
        scanf("%f", &input);
        printf("What would you like to convert it to?\n");
        printf("1. Fahrenheit\n");
        printf("2. Kelvin\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        if(option == 1){
            output = (input * 9/5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", input, output);
        } else if(option == 2) {
            output = input + 273.15;
            printf("%.2f Celsius is equal to %.2f Kelvin\n", input, output);
        } else {
            printf("Invalid choice!!\n");
            return 0;
        }
    } else {
        printf("Invalid choice!!\n");
        return 0;
    }

    printf("Thank you for using the Unit Converter!\n");
    return 0;
}