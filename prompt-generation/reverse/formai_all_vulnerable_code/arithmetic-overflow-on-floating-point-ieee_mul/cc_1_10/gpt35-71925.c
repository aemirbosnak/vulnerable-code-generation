//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include<stdio.h>

//Defining various unit constants
#define INCHES_PER_FOOT 12
#define CENTIMETERS_PER_INCH 2.54
#define MILLIMETERS_PER_INCH 25.4
#define METERS_PER_KILOMETER 1000
#define MILES_PER_KILOMETER 0.621371
#define YARDS_PER_METER 1.09361

//Function to convert feet to inches
double feet_to_inches(double feet){
    return feet * INCHES_PER_FOOT;
}

//Function to convert inches to feet
double inches_to_feet(double inches){
    return inches / INCHES_PER_FOOT;
}

//Function to convert inches to centimeters
double inches_to_centimeters(double inches){
    return inches * CENTIMETERS_PER_INCH;
}

//Function to convert inches to millimeters
double inches_to_millimeters(double inches){
    return inches * MILLIMETERS_PER_INCH;
}

//Function to convert kilometers to miles
double kilometers_to_miles(double kilometers){
    return kilometers * MILES_PER_KILOMETER;
}

//Function to convert miles to kilometers
double miles_to_kilometers(double miles){
    return miles / MILES_PER_KILOMETER;
}

//Function to convert meters to yards
double meters_to_yards(double meters){
    return meters * YARDS_PER_METER;
}

//Function to convert yards to meters
double yards_to_meters(double yards){
    return yards / YARDS_PER_METER;
}

//Main function to test the unit converter
int main(){

    double distance, converted_distance;
    int choice;

    //Displaying the menu to select the unit conversion type
    printf("Select the type of unit conversion:\n");
    printf("1. Feet to inches\n");
    printf("2. Inches to feet\n");
    printf("3. Inches to centimeters\n");
    printf("4. Inches to millimeters\n");
    printf("5. Kilometers to miles\n");
    printf("6. Miles to kilometers\n");
    printf("7. Meters to yards\n");
    printf("8. Yards to meters\n");

    scanf("%d", &choice);

    //Switch case statement to perform the selected unit conversion
    switch(choice){
        case 1:
            printf("Enter the distance in feet: ");
            scanf("%lf", &distance);
            converted_distance = feet_to_inches(distance);
            printf("The converted distance in inches is %.4f\n", converted_distance);
            break;
        case 2:
            printf("Enter the distance in inches: ");
            scanf("%lf", &distance);
            converted_distance = inches_to_feet(distance);
            printf("The converted distance in feet is %.4f\n", converted_distance);
            break;
        case 3:
            printf("Enter the distance in inches: ");
            scanf("%lf", &distance);
            converted_distance = inches_to_centimeters(distance);
            printf("The converted distance in centimeters is %.4f\n", converted_distance);
            break;
        case 4:
            printf("Enter the distance in inches: ");
            scanf("%lf", &distance);
            converted_distance = inches_to_millimeters(distance);
            printf("The converted distance in millimeters is %.4f\n", converted_distance);
            break;
        case 5:
            printf("Enter the distance in kilometers: ");
            scanf("%lf", &distance);
            converted_distance = kilometers_to_miles(distance);
            printf("The converted distance in miles is %.4f\n", converted_distance);
            break;
        case 6:
            printf("Enter the distance in miles: ");
            scanf("%lf", &distance);
            converted_distance = miles_to_kilometers(distance);
            printf("The converted distance in kilometers is %.4f\n", converted_distance);
            break;
        case 7:
            printf("Enter the distance in meters: ");
            scanf("%lf", &distance);
            converted_distance = meters_to_yards(distance);
            printf("The converted distance in yards is %.4f\n", converted_distance);
            break;
        case 8:
            printf("Enter the distance in yards: ");
            scanf("%lf", &distance);
            converted_distance = yards_to_meters(distance);
            printf("The converted distance in meters is %.4f\n", converted_distance);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}