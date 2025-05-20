//FormAI DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void showOptions();
void convertLength();
void convertWeight();
void convertVolume();

int main(){
    int choice;
    printf("Welcome to Brave Converter!\n");

    do{
        showOptions();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertVolume();
                break;
            case 4:
                printf("Thank you for using Brave Converter!\n");
                break;
            default:
                printf("Invalid Choice! Please choose a number between 1 and 4.\n");
        }
    }while(choice != 4);

    return 0;
}

void showOptions(){
    printf("\nConversion Options:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Volume\n");
    printf("4. Exit\n");
}

void convertLength(){
    float meter, feet, inches;
    printf("\nLength Conversion: Meter to Feet and Inches\n");
    printf("Enter the length in meters: ");
    scanf("%f", &meter);

    // 1 meter = 3.28084 feet
    feet = meter * 3.28084;
    inches = feet * 12;

    printf("%.2f meters is equal to %.2f feet or %.2f inches.\n", meter, feet, inches);
}

void convertWeight(){
    float kg, lbs;
    printf("\nWeight Conversion: Kilograms to Pounds\n");
    printf("Enter the weight in kilograms: ");
    scanf("%f", &kg);

    // 1 kilogram = 2.20462 pounds
    lbs = kg * 2.20462;

    printf("%.2f kilograms is equal to %.2f pounds.\n", kg, lbs);
}

void convertVolume(){
    float liter, gallon;
    printf("\nVolume Conversion: Liters to Gallons\n");
    printf("Enter the volume in liters: ");
    scanf("%f", &liter);

    // 1 liter = 0.264172 gallons
    gallon = liter * 0.264172;

    printf("%.2f liters is equal to %.2f gallons.\n", liter, gallon);
}