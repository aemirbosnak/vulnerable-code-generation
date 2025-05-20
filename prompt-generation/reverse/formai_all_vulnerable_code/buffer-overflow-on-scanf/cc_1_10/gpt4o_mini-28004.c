//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

float kg_to_lb(float kg) {
    return kg * 2.20462;
}

float lb_to_kg(float lb) {
    return lb / 2.20462;
}

float m_to_ft(float m) {
    return m * 3.28084;
}

float ft_to_m(float ft) {
    return ft / 3.28084;
}

float c_to_f(float c) {
    return (c * 9.0 / 5.0) + 32;
}

float f_to_c(float f) {
    return (f - 32) * 5.0 / 9.0;
}

float l_to_gal(float l) {
    return l * 0.264172;
}

float gal_to_l(float gal) {
    return gal / 0.264172;
}

void show_menu() {
    printf("\n---Ultimate Unit Converter---\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Liters to Gallons\n");
    printf("8. Gallons to Liters\n");
    printf("0. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    float input, result;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting... Have a great day!\n");
            break;
        }

        printf("Enter the value you wish to convert: ");
        scanf("%f", &input);

        switch (choice) {
            case 1:
                result = kg_to_lb(input);
                printf("%.2f Kilograms = %.2f Pounds\n", input, result);
                break;
            case 2:
                result = lb_to_kg(input);
                printf("%.2f Pounds = %.2f Kilograms\n", input, result);
                break;
            case 3:
                result = m_to_ft(input);
                printf("%.2f Meters = %.2f Feet\n", input, result);
                break;
            case 4:
                result = ft_to_m(input);
                printf("%.2f Feet = %.2f Meters\n", input, result);
                break;
            case 5:
                result = c_to_f(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input, result);
                break;
            case 6:
                result = f_to_c(input);
                printf("%.2f Fahrenheit = %.2f Celsius\n", input, result);
                break;
            case 7:
                result = l_to_gal(input);
                printf("%.2f Liters = %.2f Gallons\n", input, result);
                break;
            case 8:
                result = gal_to_l(input);
                printf("%.2f Gallons = %.2f Liters\n", input, result);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}