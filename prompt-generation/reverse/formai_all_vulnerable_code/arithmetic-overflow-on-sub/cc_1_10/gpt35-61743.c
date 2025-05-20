//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include<stdio.h>
int main()
{
    printf("Welcome to the Wacky World of Bitwise Operations!\n");
    printf("What would you like to do today? Choose an option:\n");
    printf("1. Check if a number is even or odd\n");
    printf("2. Complement a number\n");
    printf("3. Extract bits from a number\n");
    printf("4. Check if a number is power of 2 or not\n");
    printf("5. Exit the program\n");

    int choice, num, pos, bit;

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nTurn on your detective mode and let me know the number: ");
                scanf("%d", &num);
                if((num & 1) == 0)
                    printf("\nThe given number is even\n");
                else
                    printf("\nThe given number is odd\n");
                break;

            case 2:
                printf("\nEnter the number you want to complement: ");
                scanf("%d", &num);
                printf("\nTa-da! The complement of %d is %d\n", num, ~num);
                break;

            case 3:
                printf("\nEnter the number from which you want to extract bits: ");
                scanf("%d", &num);
                printf("Enter the position from where you want to extract bit: ");
                scanf("%d", &pos);
                bit = (num >> pos) & 1;
                printf("\nThe bit at position %d of number %d is %d\n", pos, num, bit);
                break;

            case 4:
                printf("\nEnter the number you want to check: ");
                scanf("%d", &num);
                if((num & (num - 1)) == 0)
                    printf("\nWow! The given number %d is power of 2\n", num);
                else
                    printf("\nSorry, the given number %d is not power of 2\n", num);
                break;

            case 5:
                printf("\nI hope you had a great time in the Wacky World of Bitwise Operations!\n");
                printf("Goodbye and see you soon!\n");
                exit(0);
                break;

            default:
                printf("\nOops! You entered a wrong choice. Please try again\n");
                break;
        }
    }
    return 0;
}