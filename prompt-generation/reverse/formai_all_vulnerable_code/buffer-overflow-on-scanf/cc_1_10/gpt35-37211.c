//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

//define all the conversion factors
#define INCHES_TO_CM 2.54
#define CM_TO_INCHES 0.3937
#define MILES_TO_KM 1.609
#define KM_TO_MILES 0.6214
#define POUNDS_TO_KG 0.4536
#define KG_TO_POUNDS 2.204

int main() {
    int choice; //for user's menu choice
    float value, result; //value to be converted and converted result
    
    printf("Welcome to the Unit Converter!\n\n");
    
    do { //print menu until user exits
        //print menu options
        printf("Please select a conversion option:\n");
        printf("1. Inches to Centimeters\n");
        printf("2. Centimeters to Inches\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Pounds to Kilograms\n");
        printf("6. Kilograms to Pounds\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: //inches to centimeters
                printf("Enter a value in inches: ");
                scanf("%f", &value);
                result = value * INCHES_TO_CM;
                printf("%.2f inches = %.2f centimeters\n", value, result);
                break;
                
            case 2: //centimeters to inches
                printf("Enter a value in centimeters: ");
                scanf("%f", &value);
                result = value * CM_TO_INCHES;
                printf("%.2f centimeters = %.2f inches\n", value, result);
                break;
                
            case 3: //miles to kilometers
                printf("Enter a value in miles: ");
                scanf("%f", &value);
                result = value * MILES_TO_KM;
                printf("%.2f miles = %.2f kilometers\n", value, result);
                break;
                
            case 4: //kilometers to miles
                printf("Enter a value in kilometers: ");
                scanf("%f", &value);
                result = value * KM_TO_MILES;
                printf("%.2f kilometers = %.2f miles\n", value, result);
                break;
                
            case 5: //pounds to kilograms
                printf("Enter a value in pounds: ");
                scanf("%f", &value);
                result = value * POUNDS_TO_KG;
                printf("%.2f pounds = %.2f kilograms\n", value, result);
                break;
                
            case 6: //kilograms to pounds
                printf("Enter a value in kilograms: ");
                scanf("%f", &value);
                result = value * KG_TO_POUNDS;
                printf("%.2f kilograms = %.2f pounds\n", value, result);
                break;
                
            case 7: //exit
                printf("Thank you for using the Unit Converter!\n");
                break;
                
            default: //invalid input
                printf("Invalid input, please try again.\n");
                break;
        }
        printf("\n");
        
    } while (choice != 7); //continue until user exits
    
    return 0;
}