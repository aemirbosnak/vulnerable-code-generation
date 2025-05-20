//FormAI DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>

// function to convert decimal to binary
void decToBin(int num)
{
    int binary[32] = {0};  // array to store binary digits
    int i = 0;

    while (num > 0) {
        binary[i++] = num % 2;  // get remainder and store in array
        num = num / 2;          // divide the number by 2
    }

    // print the binary number
    printf("Binary number: ");
    for (int j = i-1; j >= 0; j--)
        printf("%d",binary[j]);
    printf("\n");
}

int main()
{
    int a, b, choice;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    printf("Enter operation to perform:\n");
    printf("1. AND\n2. OR\n3. XOR\n4. NOT\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("a & b = %d\n",a&b);
            printf("In binary: ");
            decToBin(a&b);
            break;
        case 2:
            printf("a | b = %d\n",a|b);
            printf("In binary: ");
            decToBin(a|b);
            break;
        case 3:
            printf("a ^ b = %d\n",a^b);
            printf("In binary: ");
            decToBin(a^b);
            break;
        case 4:
            printf("~a = %d\n",~a);
            printf("In binary: ");
            decToBin(~a);
            printf("~b = %d\n",~b);
            printf("In binary: ");
            decToBin(~b);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}