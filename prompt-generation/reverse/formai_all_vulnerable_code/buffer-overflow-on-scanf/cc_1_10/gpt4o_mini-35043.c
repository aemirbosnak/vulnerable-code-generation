//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants for unit conversions
#define KM_TO_MILES    0.621371
#define MILES_TO_KM    (1 / KM_TO_MILES)
#define KG_TO_LBS      2.20462
#define LBS_TO_KG      (1 / KG_TO_LBS)
#define CM_TO_INCHES   0.393701
#define INCHES_TO_CM   (1 / CM_TO_INCHES)

// Function prototypes
void display_main_menu();
void convert_distance();
void convert_weight();
void convert_length();
void handle_conversion(int choice);

// Main entry point of the program
int main() {
    int user_choice;

    printf("Welcome to the Neon District's Cyberpunk Unit Converter\n");
    printf("==========================================\n");

    while (1) {
        display_main_menu();
        printf("Select a conversion type (1-3) or 0 to exit: ");
        scanf("%d", &user_choice);
        if(user_choice == 0) {
            printf("Exiting the matrix. Stay safe in the shadows.\n");
            break;
        }
        handle_conversion(user_choice);
    }

    return 0;
}

// Function to display the main menu
void display_main_menu() {
    printf("1. Distance Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Length Conversion\n");
}

// Function to handle user choice for conversion
void handle_conversion(int choice) {
    switch (choice) {
        case 1:
            convert_distance();
            break;
        case 2:
            convert_weight();
            break;
        case 3:
            convert_length();
            break;
        default:
            printf("Invalid selection. Step back into the digital mist.\n");
            break;
    }
}

// Function to convert distance
void convert_distance() {
    double km, miles;
    printf("Distance Conversion - KM to Miles\n");
    printf("Enter distance in kilometers: ");
    scanf("%lf", &km);
    miles = km * KM_TO_MILES;
    printf("%.2f kilometers is equivalent to %.2f miles.\n", km, miles);
}

// Function to convert weight
void convert_weight() {
    double kg, lbs;
    printf("Weight Conversion - KG to Pounds\n");
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    lbs = kg * KG_TO_LBS;
    printf("%.2f kilograms is equivalent to %.2f pounds.\n", kg, lbs);
}

// Function to convert length
void convert_length() {
    double cm, inches;
    printf("Length Conversion - CM to Inches\n");
    printf("Enter length in centimeters: ");
    scanf("%lf", &cm);
    inches = cm * CM_TO_INCHES;
    printf("%.2f centimeters is equivalent to %.2f inches.\n", cm, inches);
}

// Function to display a goodbye message
void goodbye_message() {
    printf("Thanks for using the Cyberpunk Unit Converter! Protect your data and take care in the neon-lit streets. Until next time!\n");
}