//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include<stdio.h>

float convertMass(float value, char unit);
float convertLength(float value, char unit);
float convertTemperature(float value, char unit);

int main(){
    int choice;
    float value, result;
    char unit;
    printf("Welcome to the Unit Converter program\n");
    printf("Choose the operation\n");
    printf("1. Mass Conversion\n");
    printf("2. Length conversion\n");
    printf("3. Temperature conversion\n");
    scanf("%d", &choice);
    printf("Enter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit of the value (kg, g, lb, oz for mass; m, cm, inch, feet for length; Celsius, Fahrenheit for temperature): ");
    scanf(" %c", &unit);
    switch(choice){
        case 1:
            result = convertMass(value, unit);
            printf("%.2f %c = %.2f %c\n", value, unit, result, unit=='k'?'g':unit=='g'?'k':unit=='l'?'o':'l');
            break;
        case 2:
            result = convertLength(value, unit);
            printf("%.2f %c = %.2f %c\n", value, unit, result, unit=='m'?'f':unit=='f'?'m':unit=='c'?'i':'c');
            break;
        case 3:
            result = convertTemperature(value, unit);
            printf("%.2f%c = %.2f%c\n", value, unit, result, unit=='c'?'f':'c');
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}

float convertMass(float value, char unit){
    if(unit == 'k'){
        return value * 1000;
    }
    else if(unit == 'g'){
        return value / 1000;
    }
    else if(unit == 'l'){
        return value * 0.035274;
    }
    else if(unit == 'o'){
        return value / 0.035274;
    }
    else{
        printf("Invalid unit. Valid units are kg, g, lb, and oz\n");
        return -1;
    }
}

float convertLength(float value, char unit){
    if(unit == 'm'){
        return value * 3.28;
    }
    else if(unit == 'f'){
        return value / 3.28;
    }
    else if(unit == 'c'){
        return value * 0.39;
    }
    else if(unit == 'i'){
        return value / 0.39;
    }
    else{
        printf("Invalid unit. Valid units are m, cm, inch, and feet\n");
        return -1;
    }
}

float convertTemperature(float value, char unit){
    if(unit == 'c'){
        return (value * 9/5) + 32;
    }
    else if(unit == 'f'){
        return (5/9) * (value - 32);
    }
    else{
        printf("Invalid unit. Valid units are Celsius and Fahrenheit\n");
        return -1;
    }
}