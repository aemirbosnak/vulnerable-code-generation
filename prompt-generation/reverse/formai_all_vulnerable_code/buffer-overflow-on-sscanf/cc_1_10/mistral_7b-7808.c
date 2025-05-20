//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Temperature {
    char unit;
    float value;
} Temperature;

void convertFtoC(Temperature *temp) {
    temp->value = (temp->value - 32.0) * 5.0 / 9.0;
}

void convertCtoF(Temperature *temp) {
    temp->value = (temp->value * 9.0 / 5.0) + 32.0;
}

void printTemp(const Temperature *temp) {
    printf("%.2f%c", temp->value, temp->unit);
}

void getTempInput(Temperature *temp) {
    char input[30];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    temp->unit = input[strlen(input) - 1];
    temp->unit = toupper(temp->unit);

    if (temp->unit == 'F') {
        convertFtoC(temp);
    }

    sscanf(input, "%f", &temp->value);
}

int main() {
    Temperature temp;
    char choice;

    do {
        printf("\n Temperature Converter \n");
        printf("------------------------\n");
        printTemp(&temp);
        printf(" to Celsius (C) or Fahrenheit (F): ");
        scanf("%c", &choice);

        if (choice == 'C') {
            printf("Result: ");
            printTemp(&temp);
            printf(" degrees %c\n", temp.unit);
        } else if (choice == 'F') {
            convertFtoC(&temp);
            printf("Result: ");
            printTemp(&temp);
            printf(" degrees Celsius\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        getTempInput(&temp);
        printf("\n Press 'Q' to Quit or any other key to continue: ");
        scanf("%c", &choice);
    } while (choice != 'Q');

    return 0;
}