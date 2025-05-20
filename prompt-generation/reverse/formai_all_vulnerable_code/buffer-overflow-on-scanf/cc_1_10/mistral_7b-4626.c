//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define F_MIN -459.67 // Absolute zero in Fahrenheit
#define C_MIN -273.15 // Absolute zero in Celsius

struct TempConversion {
    double celsius;
    double fahrenheit;
};

void convertTemp(struct TempConversion *temp) {
    temp->fahrenheit = (temp->celsius * 9 / 5) + 32;
}

int main(void) {
    int choice;
    double cel;
    struct TempConversion temp;

    printf("\n\t\t===============\n");
    printf("\t\t| Post-Apocalypse Temperature Converter |\n");
    printf("\t\t===============\n\n");

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter temperature in Celsius: ");
            scanf("%lf", &cel);

            temp.celsius = cel;
            convertTemp(&temp);

            printf("\n%0.2lf degrees Celsius is equal to %0.2lf degrees Fahrenheit\n", temp.celsius, temp.fahrenheit);
        }
        else if(choice == 2) {
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%lf", &cel);

            temp.fahrenheit = cel;
            convertTemp(&temp);

            printf("\n%0.2lf degrees Fahrenheit is equal to %0.2lf degrees Celsius\n", temp.fahrenheit, temp.celsius);
        }
        else {
            printf("\nExiting program...\n");
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}