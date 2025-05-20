//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void printBits(int num) {
    printf("Bits for %d: ", num);
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int x, y, choice;
    
    printf("Welcome to the Bitwise Circus!\n");
    printf("Here we perform side-splitting binary operations!\n");
    
    printf("Enter two numbers to juggle with: ");
    scanf("%d %d", &x, &y);
    
    printf("You entered: x = %d, y = %d\n", x, y);
    
    while(1) {
        printf("Choose your trick (bitwise operation):\n");
        printf("1. Bitwise AND (x & y)\n");
        printf("2. Bitwise OR (x | y)\n");
        printf("3. Bitwise XOR (x ^ y)\n");
        printf("4. Bitwise NOT (~x)\n");
        printf("5. Left shift x (x << 1)\n");
        printf("6. Right shift y (y >> 1)\n");
        printf("7. Show Binary Representation\n");
        printf("8. Exit the Circus\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("The AND trick reveals: x & y = %d\n", x & y);
                printBits(x);
                printBits(y);
                break;
                
            case 2:
                printf("The OR trick shines: x | y = %d\n", x | y);
                printBits(x);
                printBits(y);
                break;
                
            case 3:
                printf("The XOR trick is magic: x ^ y = %d\n", x ^ y);
                printBits(x);
                printBits(y);
                break;

            case 4:
                printf("Behold the NOT trick: ~x = %d\n", ~x);
                printBits(x);
                break;

            case 5:
                printf("Shifting leftwards: x << 1 = %d\n", x << 1);
                printBits(x);
                break;

            case 6:
                printf("Shifting rightwards: y >> 1 = %d\n", y >> 1);
                printBits(y);
                break;

            case 7:
                printf("Let's see some binary magic!\n");
                printBits(x);
                printBits(y);
                break;

            case 8:
                printf("Thank you for visiting the Bitwise Circus! Come back soon!\n");
                exit(0);

            default:
                printf("Oops! That's not a valid trick. Please choose again!\n");
                break;
        }
        printf("\n");
    }
    
    return 0;
}