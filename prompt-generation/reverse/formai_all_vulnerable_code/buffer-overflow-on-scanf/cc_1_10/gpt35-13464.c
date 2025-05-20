//FormAI DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>

void displayMainMenu();
void displaySubMenu(char*);
void convertTemperature(char*);
void convertLength(char*);
void convertMass(char*);

int main() {
    displayMainMenu();
    return 0;
}

void displayMainMenu() {
    int selection;

    printf("-----MAIN MENU-----\n");
    printf("Select an option:\n");
    printf("1. Convert temperature\n");
    printf("2. Convert length\n");
    printf("3. Convert mass\n");
    printf("4. Quit\n");

    scanf("%d", &selection);

    switch(selection) {
        case 1:
            displaySubMenu("temperature");
            break;
        case 2:
            displaySubMenu("length");
            break;
        case 3:
            displaySubMenu("mass");
            break;
        case 4:
            printf("Goodbye!");
            break;
        default:
            printf("Invalid selection. Please try again.\n\n");
            displayMainMenu();
    }
}

void displaySubMenu(char* type) {
    int selection;
    
    printf("\n-----CONVERT %s-----\n", type);
    printf("Select an option:\n");
    printf("1. Convert from Celsius to Fahrenheit\n");
    printf("2. Convert from Fahrenheit to Celsius\n");
    printf("3. Convert from meters to feet\n");
    printf("4. Convert from feet to meters\n");
    printf("5. Convert from kilograms to pounds\n");
    printf("6. Convert from pounds to kilograms\n");
    printf("7. Return to main menu\n");

    scanf("%d", &selection);

    switch(selection) {
        case 1:
            convertTemperature("c_to_f");
            break;
        case 2:
            convertTemperature("f_to_c");
            break;
        case 3:
            convertLength("m_to_ft");
            break;
        case 4:
            convertLength("ft_to_m");
            break;
        case 5:
            convertMass("kg_to_lb");
            break;
        case 6:
            convertMass("lb_to_kg");
            break;
        case 7:
            displayMainMenu();
            break;
        default:
            printf("Invalid selection. Please try again.\n\n");
            displaySubMenu(type);
    }
}

void convertTemperature(char* type) {
    float value;

    printf("Enter value to convert: ");
    scanf("%f", &value);

    if(strcmp(type, "c_to_f") == 0) {
        float result = (value * 9/5) + 32;
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", value, result);
    }
    else if(strcmp(type, "f_to_c") == 0) {
        float result = (value - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", value, result);
    }

    displaySubMenu("temperature");
}

void convertLength(char* type) {
    float value;

    printf("Enter value to convert: ");
    scanf("%f", &value);

    if(strcmp(type, "m_to_ft") == 0) {
        float result = value * 3.28;
        printf("%.2f meters is %.2f feet\n", value, result);
    }
    else if(strcmp(type, "ft_to_m") == 0) {
        float result = value / 3.28;
        printf("%.2f feet is %.2f meters\n", value, result);
    }

    displaySubMenu("length");
}

void convertMass(char* type) {
    float value;

    printf("Enter value to convert: ");
    scanf("%f", &value);

    if(strcmp(type, "kg_to_lb") == 0) {
        float result = value * 2.20462;
        printf("%.2f kilograms is %.2f pounds\n", value, result);
    }
    else if(strcmp(type, "lb_to_kg") == 0) {
        float result = value / 2.20462;
        printf("%.2f pounds is %.2f kilograms\n", value, result);
    }

    displaySubMenu("mass");
}