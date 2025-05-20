//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 50
#define PROMPT "Enter temperature to convert: "
#define F_TO_C 0
#define C_TO_F 1

void clearScreen() {
    printf("\033[H\033[J");
}

void delay(int milliseconds) {
    clock_t end_time = clock() + milliseconds * (CLOCKS_PER_SEC / 1000);
    while (clock() < end_time) {
        // do nothing
    }
}

void displayLoadingAnimation() {
    printf("Processing");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        delay(500);
    }
    printf("\n");
}

void displayWelcomeMessage() {
    clearScreen();
    printf("###############################\n");
    printf("#      Cyberpunk Temp          #\n");
    printf("#     Converter 3000           #\n");
    printf("###############################\n\n");
    printf("Welcome to the future of temperature conversion!\n");
    delay(1500);
}

float convertTemperature(float temperature, int conversionType) {
    if (conversionType == F_TO_C) {
        return (temperature - 32) * 5 / 9;
    } else {
        return (temperature * 9 / 5) + 32;
    }
}

void getInput(char *input) {
    printf("%s", PROMPT);
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline character if present
}

void handleConversion(char *input) {
    float tempValue;
    int conversionType;
    
    // Check if it's a valid number
    if (sscanf(input, "%f", &tempValue) != 1) {
        printf("ERROR: Invalid temperature value.\n");
        return;
    }

    // Ask for conversion type
    printf("Choose conversion type:\n");
    printf("1: Fahrenheit to Celsius\n");
    printf("2: Celsius to Fahrenheit\n");
    printf("Enter your choice (1 or 2): ");
    
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n');  // Clear newline from buffer
    
    switch (choice) {
        case 1:
            conversionType = F_TO_C;
            printf("Converting %.2f °F to Celsius...\n", tempValue);
            break;
        case 2:
            conversionType = C_TO_F;
            printf("Converting %.2f °C to Fahrenheit...\n", tempValue);
            break;
        default:
            printf("ERROR: Invalid choice.\n");
            return;
    }
    
    displayLoadingAnimation();
    
    float convertedTemp = convertTemperature(tempValue, conversionType);
    if (conversionType == F_TO_C) {
        printf("Result: %.2f °F is equivalent to %.2f °C\n", tempValue, convertedTemp);
    } else {
        printf("Result: %.2f °C is equivalent to %.2f °F\n", tempValue, convertedTemp);
    }
}

int main() {
    char input[MAX_INPUT];
    
    displayWelcomeMessage();
    
    while (1) {
        getInput(input);
        
        if (strcmp(input, "exit") == 0) {
            printf("Exiting... The neon lights will guide you home!\n");
            break;
        }
        
        handleConversion(input);
        printf("\n");
    }
    
    return 0;
}