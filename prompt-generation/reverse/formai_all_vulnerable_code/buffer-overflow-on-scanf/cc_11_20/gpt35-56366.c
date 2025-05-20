//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("========================================\n");
    printf("    C-Hexadecimal Converter Interface   \n");
    printf("========================================\n\n");

    char choice;
    do{
        printf("Enter 'd' to convert Decimal to Hexadecimal.\n");
        printf("Enter 'h' to convert Hexadecimal to Decimal.\n");
        printf("Enter 'x' to exit.\n");
        scanf("%c", &choice);

        if(choice == 'd'){
            long decimalNum;
            printf("Enter a Decimal number: ");
            scanf("%ld", &decimalNum);

            char hexNum[10];
            int i = 0;
            while(decimalNum != 0){
                int remainder = decimalNum % 16;
                if(remainder < 10){
                    hexNum[i] = remainder + 48;
                }else{
                    hexNum[i] = remainder + 55;
                }
                i++;
                decimalNum /= 16;
            }
            printf("Hexadecimal Number is: ");
            for(int j = i - 1; j >= 0; j--){
                printf("%c", hexNum[j]);
            }
            printf("\n\n");
        }else if(choice == 'h'){
            char hexNum[10];
            printf("Enter a Hexadecimal number: ");
            scanf("%s", &hexNum);

            long decimalNum = 0;
            int hexLen = 0;
            while(hexNum[hexLen] != '\0'){
                hexLen++;
            }
            int base = 1;
            for(int i = hexLen - 1; i >= 0; i--){
                if(hexNum[i] >= '0' && hexNum[i] <= '9'){
                    decimalNum += (hexNum[i] - 48) * base;
                    base *= 16;
                }else if(hexNum[i] >= 'A' && hexNum[i] <= 'F'){
                    decimalNum += (hexNum[i] - 55) * base;
                    base *= 16;
                }
            }
            printf("Decimal Number is: %ld\n\n", decimalNum);
        }else if(choice == 'x'){
            printf("Exited the program.\n");
            break;
        }else{
            printf("Invalid input!\n\n");
        }
        getchar(); // To clear the input buffer
    }while(1);

    return 0;
}