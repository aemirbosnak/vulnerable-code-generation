//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    float input = 0;
    char unit[4] = "";
    float output = 0;
    char convert_from[4] = "";
    char convert_to[4] = "";

    printf("Welcome to Retro Converter v1.0!\n");
    printf("Please enter a value to be converted: ");
    scanf("%f", &input);

    printf("Please enter the unit of measure (i.e. ft, lbs, etc.): ");
    scanf("%s", unit);

    printf("What unit would you like to convert from (i.e. M, L, W, etc.)? ");
    scanf("%s", convert_from);

    printf("What unit would you like to convert to (i.e. M, L, W, etc.)? ");
    scanf("%s", convert_to);

    if (strcmp(convert_from, "M") == 0 && strcmp(convert_to, "F") == 0) {
        output = input * 3.28;
    } else if (strcmp(convert_from, "F") == 0 && strcmp(convert_to, "M") == 0) {
        output = input / 3.28;
    } else if (strcmp(convert_from, "L") == 0 && strcmp(convert_to, "G") == 0) {
        output = input / 3.785;
    } else if (strcmp(convert_from, "G") == 0 && strcmp(convert_to, "L") == 0) {
        output = input * 3.785;
    } else if (strcmp(convert_from, "W") == 0 && strcmp(convert_to, "KG") == 0) {
        output = input / 2.205;
    } else if (strcmp(convert_from, "KG") == 0 && strcmp(convert_to, "W") == 0) {
        output = input * 2.205;
    } else if (strcmp(convert_from, "C") == 0 && strcmp(convert_to, "F") == 0) {
        output = (input * 9/5) + 32;
    } else if (strcmp(convert_from, "F") == 0 && strcmp(convert_to, "C") == 0) {
        output = (input - 32) * 5/9;
    } else if (strcmp(convert_from, "KG") == 0 && strcmp(convert_to, "G") == 0) {
        output = input * 1000;
    } else if (strcmp(convert_from, "G") == 0 && strcmp(convert_to, "KG") == 0) {
        output = input / 1000;
    } else {
        printf("Invalid conversion.\n");
    }

    printf("%.2f %s is equal to %.2f %s\n", input, unit, output, convert_to);
    
    return 0;
}