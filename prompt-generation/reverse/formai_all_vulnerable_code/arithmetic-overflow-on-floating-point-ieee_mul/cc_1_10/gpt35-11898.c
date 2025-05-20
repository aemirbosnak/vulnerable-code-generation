//FormAI DATASET v1.0 Category: Temperature Converter ; Style: retro
#include<stdio.h>
#include<stdlib.h>

void temperature_converter();
void celsius_to_fahrenheit(float celsius, float* fahrenheit);
void fahrenheit_to_celsius(float fahrenheit, float* celsius);
void display_menu();

int main(){

    printf("\n+++ RETRO STYLE TEMPERATURE CONVERTER PROGRAM +++\n");

    temperature_converter();  //calling temperature converter function

    return 0;
}

/*
This function display the menu options
*/
void display_menu(){
    printf("\nChoose the temperature conversion type: ");
    printf("\n 1) Celsius to Fahrenheit");
    printf("\n 2) Fahrenheit to Celsius");
    printf("\n 3) Quit\n");
}

/*
This function converts Celsius to Fahrenheit
*/
void celsius_to_fahrenheit(float celsius, float* fahrenheit){    
    *fahrenheit = (celsius * 9/5) + 32;    
}

/*
This function converts Fahrenheit to Celsius
*/
void fahrenheit_to_celsius(float fahrenheit, float* celsius){    
    *celsius = (fahrenheit - 32) * 5/9;    
}

/*
This function implements the temperature converter program
*/
void temperature_converter(){

    int option;
    float celsius, fahrenheit;

    do{
        display_menu();

        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &celsius);
                
                celsius_to_fahrenheit(celsius, &fahrenheit);

                printf("\n%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
                break;
            case 2:
                printf("\nEnter the temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                
                fahrenheit_to_celsius(fahrenheit, &celsius);

                printf("\n%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
                break;
            case 3:
                printf("\nQuiting the program...\n");
                break;
            default:
                printf("\nInvalid option. Please choose a valid option.\n");
                break;
        }

    }while(option != 3);
}