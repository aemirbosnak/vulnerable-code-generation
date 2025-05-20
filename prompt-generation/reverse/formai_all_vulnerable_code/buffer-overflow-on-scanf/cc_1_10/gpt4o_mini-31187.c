//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHexLine(FILE *fp, char *hex, int lineNum) {
    fprintf(fp, "Line %d: 0x%s\n", lineNum, hex);
}

void convertToHex(int num, char *hex) {
    sprintf(hex, "%X", num);
}

void displayMenu() {
    printf("\n***************************************\n");
    printf("*       Hexadecimal Converter         *\n");
    printf("***************************************\n");
    printf("* 1. Convert an integer to Hex        *\n");
    printf("* 2. Quit                             *\n");
    printf("***************************************\n\n");
}

int main() {
    int choice, number;
    char hex[20];
    FILE *file;

    // Opening the file to store results
    file = fopen("hex_output.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing!\n");
        return 1;
    }

    do {
        displayMenu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                scanf("%d", &number);

                convertToHex(number, hex);
                printf("The hexadecimal representation of %d is: 0x%s\n", number, hex);
                printHexLine(file, hex, number);
                break;

            case 2:
                printf("Exiting the Hexadecimal Converter. Goodbye!\n");
                break;

            default:
                printf("Invalid choice, please try again!\n");
                break;
        }

    } while (choice != 2);

    fclose(file);
    return 0;
}