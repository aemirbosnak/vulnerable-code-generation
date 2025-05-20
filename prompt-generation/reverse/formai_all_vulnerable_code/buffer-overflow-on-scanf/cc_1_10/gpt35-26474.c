//FormAI DATASET v1.0 Category: Unit converter ; Style: funny
#include<stdio.h>

int main(){
    printf("Welcome to the wackiest unit converter program you'll ever see!\n");
    printf("Enter the value you want to convert: ");
    float value;
    scanf("%f", &value);

    int choice;
    printf("Which unit do you want to convert from? \n1. Kilogram\n2. Meter\n3. Celsius\n");
    scanf("%d", &choice);
    float result;

    switch(choice){
        case 1:
            printf("Converting from Kilogram. What do you want to convert to?\n1. Pound\n2. Ounce\n");
            int option;
            scanf("%d", &option);
            if(option == 1){
                result = value * 2.20462;
                printf("%.2f kg is %.2f pounds\n", value, result);
            }
            else if(option == 2){
                result = value * 35.274;
                printf("%.2f kg is %.2f ounces\n", value, result);
            }
            else{
                printf("Invalid input. Sorry pal.\n");
            }
            break;
        case 2:
            printf("Converting from Meters. What do you want to convert to?\n1. Feet\n2. Inches\n");
            scanf("%d", &option);
            if(option == 1){
                result = value * 3.28084;
                printf("%.2f meters is %.2f feet\n", value, result);
            }
            else if(option == 2){
                result = value * 39.3701;
                printf("%.2f meters is %.2f inches\n", value, result);
            }
            else{
                printf("That's an invalid option my dude\n");
            }
            break;
        case 3:
            printf("Converting from Celsius. Which temperature scale do you want to convert to?\n1. Fahrenheit\n2. Kelvin\n");
            scanf("%d", &option);
            if(option == 1){
                result = (value * 1.8) + 32;
                printf("%.2f C is %.2f F\n", value, result);
            }
            else if(option == 2){
                result = value + 273.15;
                printf("%.2f C is %.2f K\n", value, result);
            }
            else{
                printf("Invalid input. Good luck next time, kid.\n");
            }
            break;

        default:
            printf("Hmm, looks like you entered something wrong there, buddy. Try again.\n");
            break;
    }

    printf("Thanks for using this crazy program. Have a great day.");
    return 0;
}