//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include<stdio.h>

//Function declaration
void display_menu();
float convert_temperature(float, char, char);
float convert_length(float, char, char);
float convert_weight(float, char, char);

int main() {
    int choice;
    float value;
    char unit1, unit2;
    
    //Display the main menu
    display_menu();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        //Case for temperature conversion
        case 1:
            printf("Enter the temperature value: ");
            scanf("%f", &value);
            printf("Enter the input unit (C/F): ");
            scanf(" %c", &unit1);
            printf("Enter the output unit (C/F): ");
            scanf(" %c", &unit2);
            printf("\n\nResult: %.2f%c = %.2f%c\n", value, unit1, convert_temperature(value, unit1, unit2), unit2);
            break;
            
        //Case for length conversion
        case 2:
            printf("Enter the length value: ");
            scanf("%f", &value);
            printf("Enter the input unit (M/C/K): ");
            scanf(" %c", &unit1);
            printf("Enter the output unit (M/C/K): ");
            scanf(" %c", &unit2);
            printf("\n\nResult: %.2f%c = %.2f%c\n", value, unit1, convert_length(value, unit1, unit2), unit2);
            break;
            
        //Case for weight conversion
        case 3:
            printf("Enter the weight value: ");
            scanf("%f", &value);
            printf("Enter the input unit (K/G): ");
            scanf(" %c", &unit1);
            printf("Enter the output unit (K/G): ");
            scanf(" %c", &unit2);
            printf("\n\nResult: %.2f%c = %.2f%c\n", value, unit1, convert_weight(value, unit1, unit2), unit2);
            break;
            
        //Default case
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}

//Function definition for displaying the menu
void display_menu() {
    printf("========== Unit Converter ==========\n");
    printf("1. Temperature Conversion\n");
    printf("2. Length Conversion\n");
    printf("3. Weight Conversion\n");
}

//Function definition for temperature conversion
float convert_temperature(float value, char unit1, char unit2) {
    float result;
    if(unit1 == 'C' && unit2 == 'F') {
        result = (value * 9 / 5) + 32;
    }
    else if(unit1 == 'F' && unit2 == 'C') {
        result = (value - 32) * 5 / 9;
    }
    else {
        result = value;
    }
    return result;
}

//Function definition for length conversion
float convert_length(float value, char unit1, char unit2) {
    float result;
    if(unit1 == 'M' && unit2 == 'C') {
        result = value * 100;
    }
    else if(unit1 == 'M' && unit2 == 'K') {
        result = value / 1000;
    }
    else if(unit1 == 'C' && unit2 == 'M') {
        result = value / 100;
    }
    else if(unit1 == 'C' && unit2 == 'K') {
        result = value / 100000;
    }
    else if(unit1 == 'K' && unit2 == 'M') {
        result = value * 1000;
    }
    else if(unit1 == 'K' && unit2 == 'C') {
        result = value * 100000;
    }
    else {
        result = value;
    }
    return result;
}

//Function definition for weight conversion
float convert_weight(float value, char unit1, char unit2) {
    float result;
    if(unit1 == 'K' && unit2 == 'G') {
        result = value * 1000;
    }
    else if(unit1 == 'G' && unit2 == 'K') {
        result = value / 1000;
    }
    else {
        result = value;
    }
    return result;
}