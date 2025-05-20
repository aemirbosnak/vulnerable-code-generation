//FormAI DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

//Define conversion factors
#define CM_TO_IN 0.3937
#define IN_TO_CM 2.54
#define KG_TO_LB 2.2046
#define LB_TO_KG 0.4536

//Define function to convert centimeters to inches
double cm_to_in(double cm){
    double in;
    in = cm * CM_TO_IN;
    return in;
}

//Define function to convert inches to centimeters
double in_to_cm(double in){
    double cm;
    cm = in * IN_TO_CM;
    return cm;
}

//Define function to convert kilograms to pounds
double kg_to_lb(double kg){
    double lb;
    lb = kg * KG_TO_LB;
    return lb;
}

//Define function to convert pounds to kilograms
double lb_to_kg(double lb){
    double kg;
    kg = lb * LB_TO_KG;
    return kg;
}

int main(){
    //Declare variables
    int choice;
    double input, output;

    //Display menu
    printf("Welcome to Sherlock Holmes' Unit Converter\n");
    printf("----------------------------------------------\n");
    printf("Select an option:\n");
    printf("1. Centimeters to Inches\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("----------------------------------------------\n");

    //Get user input
    printf("Choice: ");
    scanf("%d", &choice);

    //Get input value
    printf("Enter value to convert: ");
    scanf("%lf", &input);

    //Perform conversion based on user's choice
    switch(choice){
        case 1:
            output = cm_to_in(input);
            printf("%.2lf cm = %.2lf in\n", input, output);
            break;
        case 2:
            output = in_to_cm(input);
            printf("%.2lf in = %.2lf cm\n", input, output);
            break;
        case 3:
            output = kg_to_lb(input);
            printf("%.2lf kg = %.2lf lb\n", input, output);
            break;
        case 4:
            output = lb_to_kg(input);
            printf("%.2lf lb = %.2lf kg\n", input, output);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}