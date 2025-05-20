//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Welcome to the Mind-bending Hexadecimal Converter!\n");
    printf("Please enter an integer: ");

    // Take user input
    long int input;
    scanf("%ld", &input);

    // Convert decimal to hexadecimal
    char hex[100];
    int i = 0;
    while(input != 0) {
        int remainder = input % 16;
        if(remainder < 10) {
            hex[i] = remainder + 48;
            i++;
        } else {
            hex[i] = remainder + 55;
            i++;
        }
        input /= 16;
    }
    hex[i] = '\0';

    // Reverse the hex string
    int length = i;
    char hex_reversed[100];
    int j = 0;
    for(i = length - 1; i >= 0; i--) {
        hex_reversed[j] = hex[i];
        j++;
    }
    hex_reversed[j] = '\0';

    // Print the hexadecimal value
    printf("The hexadecimal value of the input is: %s\n", hex_reversed);
    printf("Would you like to convert another integer? (y/n): ");

    char choice;
    scanf(" %c", &choice);

    while(choice != 'n') {
        printf("Please enter an integer: ");
        scanf("%ld", &input);

        i = 0;
        while(input != 0) {
            int remainder = input % 16;
            if(remainder < 10) {
                hex[i] = remainder + 48;
                i++;
            } 
            else {
                hex[i] = remainder + 55;
                i++;
            }
            input /= 16;
        }
        hex[i] = '\0';

        length = i;
        j = 0;
        for(i = length - 1; i >= 0; i--) {
            hex_reversed[j] = hex[i];
            j++;
        }
        hex_reversed[j] = '\0';

        printf("The hexadecimal value of the input is: %s\n", hex_reversed);
        printf("Would you like to convert another integer? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Mind-bending Hexadecimal Converter!\n");
    return 0;
}