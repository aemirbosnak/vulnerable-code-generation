//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int decimal;
    int binary[100];
    int i, j;

    do {
        printf("\n");
        printf("Cyberpunk Binary Converter\n");
        printf("--------------------------------\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n");
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);

                printf("\n");
                printf("Binary equivalent of %d is:\n", decimal);

                for(i=0; decimal>0; i++) {
                    binary[i] = decimal%2;
                    decimal = decimal/2;
                }

                for(j=i-1; j>=0; j--) {
                    printf("%d", binary[j]);
                }

                break;

            case 2:
                printf("\n");
                printf("Enter a binary number: ");
                scanf("%s", binary);

                printf("\n");
                printf("Decimal equivalent of %s is:\n", binary);

                decimal = 0;
                for(i=0; binary[i]!='\0'; i++) {
                    if(binary[i]=='1') {
                        decimal = decimal + pow(2, strlen(binary)-i-1);
                    }
                }

                printf("%d\n", decimal);

                break;

            case 3:
                printf("\n");
                printf("Exiting...\n");
                break;

            default:
                printf("\n");
                printf("Invalid choice! Try again.\n");
        }

        printf("\n");
        printf("Press Enter to continue...");
        getchar();

    } while(choice!=3);

    return 0;
}