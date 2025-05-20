//FormAI DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main(){
    int choice;
    float temp, convertedTemp;
    printf("Welcome to the Temperature Converter!\n");

    //Start of the puzzling code 
    printf("\n");
    printf("I am a code that can convert the temperature values for you\n");
    printf("But every time you use this code, I will ask you a riddle too\n");
    printf("If you can solve it, the conversion will be perfectly done for you\n");
    printf("Otherwise, the temperature value will remain the same\n");
    printf("\n");
    printf("Let's see if you can solve my riddle!\n");
    printf("\n");  
    printf("What kind of room has no doors or windows?\n");
    printf("\n");
    printf("Enter your answer here: ");
    char answer[30];
    scanf("%s", answer);

    if(answer == "mushroom"){ //If the user inputs the correct answer
        printf("Congratulations! You have solved the riddle. Now, please select the temperature scale you want to convert from and input the temperature value:\n");
        printf("\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        printf("\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);

        switch(choice){ //Conversion based on selected temperature scale
            case 1:
                printf("You have selected Celsius.\n");
                printf("Enter temperature value: ");
                scanf("%f", &temp);
                convertedTemp = temp + 273.15;
                printf("%.2f Celsius is equal to %.2f Kelvin.\n", temp, convertedTemp);
                break;
            case 2:
                printf("You have selected Fahrenheit.\n");
                printf("Enter temperature value: ");
                scanf("%f", &temp);
                convertedTemp = (5*(temp - 32))/9 + 273.15;
                printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", temp, convertedTemp);
                break;
            case 3:
                printf("You have selected Kelvin.\n");
                printf("Enter temperature value: ");
                scanf("%f", &temp);
                convertedTemp = temp;
                printf("%.2f Kelvin is equal to %.2f Kelvin.\n", temp, convertedTemp);
                break;
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    }else{ //If the user inputs the incorrect answer
        printf("Wrong answer! Sorry, temperature value cannot be converted.\n");
    }
}