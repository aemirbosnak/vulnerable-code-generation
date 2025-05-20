//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert units
void convert(char *from, char *to, float value) {
    char input[50];
    printf("Enter a value: ");
    scanf("%s", input);

    // Check if input is a number
    if(strspn(input, "0123456789. ")!= strlen(input)) {
        printf("Invalid input\n");
        return;
    }

    // Convert input to float
    float num = strtof(input, NULL);

    // Convert units
    switch(from[0]) {
        case 'k':
            switch(to[0]) {
                case'm':
                    printf("%f %s = %f %s\n", num, from, num / 1000, to);
                    break;
                case 'g':
                    printf("%f %s = %f %s\n", num, from, num * 1000, to);
                    break;
                default:
                    printf("Invalid conversion\n");
            }
            break;
        case'm':
            switch(to[0]) {
                case 'k':
                    printf("%f %s = %f %s\n", num, from, num * 1000, to);
                    break;
                case 'g':
                    printf("%f %s = %f %s\n", num, from, num / 1000, to);
                    break;
                default:
                    printf("Invalid conversion\n");
            }
            break;
        case 'g':
            switch(to[0]) {
                case 'k':
                    printf("%f %s = %f %s\n", num, from, num / 1000, to);
                    break;
                case'm':
                    printf("%f %s = %f %s\n", num, from, num * 1000, to);
                    break;
                default:
                    printf("Invalid conversion\n");
            }
            break;
        default:
            printf("Invalid conversion\n");
    }
}

int main() {
    char from[10], to[10];
    printf("Enter the unit to convert from: ");
    scanf("%s", from);
    printf("Enter the unit to convert to: ");
    scanf("%s", to);

    // Convert units
    convert(from, to, 0);

    return 0;
}