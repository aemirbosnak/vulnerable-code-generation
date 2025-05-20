//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 50
#define MAX_COLOR_CODE_LENGTH 7

// Structure to hold a color code and its corresponding name
typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} ColorCode;

// Function to convert a color name to its corresponding code
char* getColorCode(char* colorName) {
    ColorCode* colorCode = (ColorCode*)malloc(sizeof(ColorCode));
    strcpy(colorCode->name, colorName);
    strcpy(colorCode->code, "");

    // Loop through all known color codes and find a match
    FILE* fp = fopen("colors.txt", "r");
    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        if (strcmp(line, colorName) == 0) {
            strcpy(colorCode->code, line);
            break;
        }
    }
    fclose(fp);

    return colorCode->code;
}

// Main function to get user input and display the corresponding color code
int main() {
    char colorName[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name: ");
    scanf("%s", colorName);

    // Convert the color name to its corresponding code
    char* colorCode = getColorCode(colorName);

    // Display the color code
    if (colorCode!= NULL) {
        printf("The color code for %s is %s\n", colorName, colorCode);
    } else {
        printf("Sorry, %s is not a known color.\n", colorName);
    }

    return 0;
}