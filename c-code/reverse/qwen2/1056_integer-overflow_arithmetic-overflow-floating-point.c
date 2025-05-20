#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice1, choice2;
    float value, result;

    printf("Unit Converter\n");
    printf("1. Length\n2. Mass\n3. Time\n");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            printf("Convert from:\n1. Meters to Miles\n2. Kilometers to Miles\n");
            scanf("%d", &choice2);
            printf("Enter value: ");
            scanf("%f", &value);
            switch(choice2) {
                case 1:
                    result = value * 0.000621371;
                    break;
                case 2:
                    result = value * 0.621371;
                    break;
                default:
                    printf("Invalid choice.\n");
                    return 1;
            }
            break;
        case 2:
            printf("Convert from:\n1. Kilograms to Pounds\n");
            scanf("%d", &choice2);
            printf("Enter value: ");
            scanf("%f", &value);
            switch(choice2) {
                case 1:
                    result = value * 2.20462;
                    break;
                default:
                    printf("Invalid choice.\n");
                    return 1;
            }
            break;
        case 3:
            printf("Convert from:\n1. Seconds to Minutes\n");
            scanf("%d", &choice2);
            printf("Enter value: ");
            scanf("%f", &value);
            switch(choice2) {
                case 1:
                    result = value / 60;
                    break;
                default:
                    printf("Invalid choice.\n");
                    return 1;
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Result: %.2f\n", result);
    return 0;
}
