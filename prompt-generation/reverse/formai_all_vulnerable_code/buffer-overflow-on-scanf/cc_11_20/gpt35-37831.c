//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>

void delay(int n) {
    for (int i = 0; i < n * 1000000; ++i);
}

void print_digit(int digit) {
    switch(digit) {
        case 0:
            printf("   ___  \n" 
                   "  / _ \\ \n" 
                   " | | | |\n" 
                   " | | | |\n" 
                   " | |_| |\n" 
                   "  \\___/ \n" );
            break;
        case 1:
            printf("   /\\   \n" 
                   "  /  \\  \n" 
                   " |    | \n" 
                   " |    | \n" 
                   " |____| \n" 
                   "        \n" );
            break;
        case 2:
            printf("  ____  \n" 
                   " |___ \\ \n" 
                   "   __) |\n" 
                   "  |__ < \n" 
                   "  ___) |\n" 
                   " |____/ \n" );
            break;
        case 3:
            printf("  _____ \n" 
                   " |___ / \n" 
                   "   |_ \\ \n" 
                   "  ___) |\n" 
                   " |____/ \n" 
                   "        \n" );
            break;
        case 4:
            printf("  _  _   \n" 
                   " | || |  \n" 
                   " | || |_ \n" 
                   " |__   _|\n" 
                   "    | |  \n" 
                   "    |_|  \n" );
            break;
        case 5:
            printf("  ____  \n" 
                   " | ___| \n" 
                   " |___ \\ \n" 
                   "  ___) |\n" 
                   " |____/ \n" 
                   "        \n" );
            break;
        case 6:
            printf("    _   \n" 
                   "  / ___| \n" 
                   " | | __  \n" 
                   " | |/ /  \n" 
                   " |___ \\  \n" 
                   "  |____/ \n" );
            break;
        case 7:
            printf("  ______\n" 
                   " |____  |\n" 
                   "     / / \n" 
                   "    / /  \n" 
                   "   /_/   \n" 
                   "         \n" );
            break;
        case 8:
            printf("   ___  \n" 
                   "  / _ \\ \n" 
                   " | (_) |\n" 
                   "  > _ < \n" 
                   " | (_) |\n" 
                   "  \\___/ \n" );
            break;
        case 9:
            printf("   ___  \n" 
                   "  / _ \\ \n" 
                   " | (_) |\n" 
                   "  \\__, |\n" 
                   "    / / \n" 
                   "   /_/  \n" );
            break;
    }
}

int main() {
    int num1, num2, num3;
    printf("Enter 3 integer numbers to add: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("\nCalculating sum of %d, %d, and %d:\n\n", num1, num2, num3);
    delay(1);
    int sum = num1 + num2 + num3;
    int digit[5] = {0};
    int temp_sum = sum;
    for (int i = 4; i >= 0; --i) {
        digit[i] = temp_sum % 10;
        temp_sum /= 10;
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf(" ");
            if (i % 2 == 0) {
                if ((j == 0 && digit[0] != 1) || (j == 1 && digit[0] == 1) || (j == 2 && digit[0] % 2 == 0) || (j == 3 && digit[0] == 1) || (j == 4 && digit[0] != 1)) {
                    printf("_");
                } else {
                    printf(" ");
                }
            } else {
                if ((j == 0 && digit[1] != 0) || (j == 1 && digit[1] % 2 == 0) || (j == 2 && digit[1] != 0) || (j == 3 && digit[1] % 2 == 1) || (j == 4 && digit[1] != 9)) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n\nThe sum is: %d\n", sum);
    return 0;
}