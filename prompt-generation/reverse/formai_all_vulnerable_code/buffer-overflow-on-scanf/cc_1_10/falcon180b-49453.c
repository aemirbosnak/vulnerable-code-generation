//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODES 100

struct ColorCode {
    char name[20];
    int value;
};

void addColorCode(struct ColorCode *colorCodes, int numColorCodes, char *name, int value) {
    if (numColorCodes >= MAX_COLOR_CODES) {
        printf("Error: Maximum number of color codes reached.\n");
        exit(1);
    }
    strcpy(colorCodes[numColorCodes].name, name);
    colorCodes[numColorCodes].value = value;
    numColorCodes++;
}

int main() {
    int numColorCodes = 0;
    struct ColorCode colorCodes[MAX_COLOR_CODES];
    char name[20];
    int value;
    char choice;
    int found = 0;

    do {
        printf("\nColor Code Converter\n");
        printf("---------------------\n");
        printf("1. Add a color code\n");
        printf("2. Convert a color code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the name of the color code: ");
                scanf("%s", name);
                printf("Enter the value of the color code: ");
                scanf("%d", &value);
                addColorCode(colorCodes, numColorCodes, name, value);
                printf("\nColor code added successfully.\n");
                break;
            case '2':
                printf("Enter the name of the color code you want to convert: ");
                scanf("%s", name);
                found = 0;
                for (int i = 0; i < numColorCodes; i++) {
                    if (strcmp(name, colorCodes[i].name) == 0) {
                        printf("\nThe value of %s is %d.\n", name, colorCodes[i].value);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nColor code not found.\n");
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}