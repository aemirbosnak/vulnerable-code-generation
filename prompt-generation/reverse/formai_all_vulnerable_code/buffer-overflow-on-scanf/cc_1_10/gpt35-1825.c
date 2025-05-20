//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

/*Conversion constants*/
#define KILOMETERS_IN_MILES 1.60934
#define POUNDS_IN_KILOGRAMS 0.453592
#define GALLONS_IN_LITERS 3.78541

/*Menu choices*/
enum Choices {
    MILES_TO_KILOMETERS = 1,
    KILOMETERS_TO_MILES,
    POUNDS_TO_KILOGRAMS,
    KILOGRAMS_TO_POUNDS,
    GALLONS_TO_LITERS,
    LITERS_TO_GALLONS,
    EXIT = 10
};

/*Function prototypes*/
void print_menu();
float get_input(char* message);
void convert_units(int choice, float value);

/*Main function*/
int main() {
    int choice;
    float value;

    do {
        print_menu();
        scanf("%d", &choice);

        if(choice != EXIT) {
            value = get_input("Enter value to convert: ");
            convert_units(choice, value);
        }
    } while(choice != EXIT);

    printf("Bye!\n");

    return 0;
}

/*Prints out the menu*/
void print_menu() {
    printf("Please select an option:\n");
    printf("1. Convert miles to kilometers\n");
    printf("2. Convert kilometers to miles\n");
    printf("3. Convert pounds to kilograms\n");
    printf("4. Convert kilograms to pounds\n");
    printf("5. Convert gallons to liters\n");
    printf("6. Convert liters to gallons\n");
    printf("10. Exit\n");
}

/*Gets input from the user and returns it as a float*/
float get_input(char* message) {
    float input;
    printf("%s", message);
    scanf("%f", &input);
    return input;
}

/*Converts the value based on the selected choice*/
void convert_units(int choice, float value) {
    float converted_value;

    switch(choice) {
        case MILES_TO_KILOMETERS:
            converted_value = value * KILOMETERS_IN_MILES;
            printf("%.2f miles is equivalent to %.2f kilometers.\n", value, converted_value);
            break;
        case KILOMETERS_TO_MILES:
            converted_value = value / KILOMETERS_IN_MILES;
            printf("%.2f kilometers is equivalent to %.2f miles.\n", value, converted_value);
            break;
        case POUNDS_TO_KILOGRAMS:
            converted_value = value * POUNDS_IN_KILOGRAMS;
            printf("%.2f pounds is equivalent to %.2f kilograms.\n", value, converted_value);
            break;
        case KILOGRAMS_TO_POUNDS:
            converted_value = value / POUNDS_IN_KILOGRAMS;
            printf("%.2f kilograms is equivalent to %.2f pounds.\n", value, converted_value);
            break;
        case GALLONS_TO_LITERS:
            converted_value = value * GALLONS_IN_LITERS;
            printf("%.2f gallons is equivalent to %.2f liters.\n", value, converted_value);
            break;
        case LITERS_TO_GALLONS:
            converted_value = value / GALLONS_IN_LITERS;
            printf("%.2f liters is equivalent to %.2f gallons.\n", value, converted_value);
            break;
        default:
            printf("Invalid choice, please try again!\n");
            break;
    }
}