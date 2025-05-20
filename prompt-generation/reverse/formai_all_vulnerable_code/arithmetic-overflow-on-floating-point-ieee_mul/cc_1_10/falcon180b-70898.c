//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    float num, result;

    printf("Welcome to the Unit Converter!\n");
    printf("What unit would you like to convert?\n");
    printf("A. Length\n");
    printf("B. Weight\n");
    printf("C. Volume\n");
    printf("D. Temperature\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'A':
        case 'a':
            printf("What is the value you want to convert?\n");
            scanf("%f", &num);
            printf("What unit is the value in?\n");
            scanf("%s", &result);
            printf("The converted value is: %.2f\n", num * result);
            break;
        case 'B':
        case 'b':
            printf("What is the value you want to convert?\n");
            scanf("%f", &num);
            printf("What unit is the value in?\n");
            scanf("%s", &result);
            printf("The converted value is: %.2f\n", num * result);
            break;
        case 'C':
        case 'c':
            printf("What is the value you want to convert?\n");
            scanf("%f", &num);
            printf("What unit is the value in?\n");
            scanf("%s", &result);
            printf("The converted value is: %.2f\n", num * result);
            break;
        case 'D':
        case 'd':
            printf("What is the value you want to convert?\n");
            scanf("%f", &num);
            printf("What unit is the value in?\n");
            scanf("%s", &result);
            printf("The converted value is: %.2f\n", num * result);
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    return 0;
}