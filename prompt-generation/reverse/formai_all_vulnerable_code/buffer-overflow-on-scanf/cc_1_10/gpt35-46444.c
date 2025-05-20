//FormAI DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWelcome();

int main() {
    char input[10];
    int choice;
    printWelcome();
    scanf("%d", &choice);
    while (choice != 4){
        if (choice == 1){
            char hex[8];
            printf("Enter a hexadecimal color code: ");
            scanf("%s", hex);
            if (strlen(hex) != 6){
                printf("Invalid input! Enter a 6 digit hexadecimal code.\n");
            } else{
                printf("The RGB color code is: ");
                for (int i = 0; i < 6; i += 2){
                    int red = strtol(strndup(&hex[i], 2), NULL, 16);
                    printf("%d ",red);
                    int green = strtol(strndup(&hex[i + 2], 2), NULL, 16);
                    printf("%d ",green);
                    int blue = strtol(strndup(&hex[i + 4], 2), NULL, 16);
                    printf("%d",blue);
                }
                printf("\n");
            }
        } else if (choice == 2){
            int red, green, blue;
            printf("Enter the red, green and blue values (0-255): ");
            scanf("%d %d %d", &red, &green, &blue);
            printf("The hexadecimal color code is: #%02X%02X%02X\n", red, green, blue);
        } else if (choice == 3){
            printf("This is a color code converter. It converts between RGB and hexadecimal color codes.");
        } else {
            printf("Invalid input! Please enter a number between 1 and 4.\n");
        }
        printf("\n");
        printWelcome();
        scanf("%d", &choice);
    }
}

void printWelcome(){
    printf("\nWelcome to the color code converter!\n");
    printf("Enter 1 to convert hexadecimal code to RGB.\n");
    printf("Enter 2 to convert RGB to hexadecimal code.\n");
    printf("Enter 3 for help.\n");
    printf("Enter 4 to exit.\n");
    printf("Choice: ");
}