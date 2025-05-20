//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>

void display_menu();
void convert_temperature();
void display_conversion_history(char* history[], int count);
void add_to_history(char* history[], int* count, char* entry);

int main() {
    char* conversion_history[100];
    int history_count = 0;
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_temperature(conversion_history, &history_count);
                break;
            case 2:
                display_conversion_history(conversion_history, history_count);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                for (int i = 0; i < history_count; i++) {
                    free(conversion_history[i]); // Free allocated memory
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void display_menu() {
    printf("\nTemperature Converter\n");
    printf("1. Convert Temperature\n");
    printf("2. Display Conversion History\n");
    printf("3. Exit\n");
}

void convert_temperature(char* history[], int* count) {
    int choice;
    float temp, converted_temp;
    char entry[100];

    printf("\nSelect the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            converted_temp = (temp * 9 / 5) + 32;
            sprintf(entry, "%.2f Celsius = %.2f Fahrenheit", temp, converted_temp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            converted_temp = (temp - 32) * 5 / 9;
            sprintf(entry, "%.2f Fahrenheit = %.2f Celsius", temp, converted_temp);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            converted_temp = temp + 273.15;
            sprintf(entry, "%.2f Celsius = %.2f Kelvin", temp, converted_temp);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temp);
            converted_temp = temp - 273.15;
            sprintf(entry, "%.2f Kelvin = %.2f Celsius", temp, converted_temp);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            converted_temp = (temp - 32) * 5 / 9 + 273.15;
            sprintf(entry, "%.2f Fahrenheit = %.2f Kelvin", temp, converted_temp);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temp);
            converted_temp = (temp - 273.15) * 9 / 5 + 32;
            sprintf(entry, "%.2f Kelvin = %.2f Fahrenheit", temp, converted_temp);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("Result: %s\n", entry);
    
    // Allocate memory for history entry and store it
    history[*count] = malloc(strlen(entry) + 1);
    if (history[*count] != NULL) {
        strcpy(history[*count], entry);
        (*count)++;
    } else {
        printf("Memory allocation failed.\n");
    }
}

void display_conversion_history(char* history[], int count) {
    printf("\nConversion History:\n");
    if (count == 0) {
        printf("No conversions have been made yet.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%s\n", history[i]);
    }
}