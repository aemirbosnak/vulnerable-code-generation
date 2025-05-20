//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal, binary[100];
    char choice;

    do {
        printf("\nEnter 1 to Convert Decimal to Binary\n");
        printf("Enter 2 to Convert Binary to Decimal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimal);

                int i = 0, j = 0;
                while(decimal > 0) {
                    binary[i++] = decimal % 2;
                    decimal /= 2;
                }

                for(int k = i-1; k >= 0; k--) {
                    printf("%d", binary[k]);
                }

                printf("\n");
                break;

            case 2:
                printf("\nEnter a binary number: ");
                scanf("%s", binary);

                decimal = 0;
                for(int i = 0; binary[i]!= '\0'; i++) {
                    if(binary[i] == '1') {
                        decimal += pow(2, strlen(binary)-i-1);
                    }
                }

                printf("\nThe decimal equivalent is: %d", decimal);
                break;

            default:
                printf("\nInvalid choice!");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    return 0;
}