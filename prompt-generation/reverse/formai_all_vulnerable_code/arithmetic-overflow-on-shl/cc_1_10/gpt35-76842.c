//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include<stdio.h>

//function to convert decimal to binary
void decToBin(int num)
{
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("\nBinary equivalent: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int a, b, c;
    printf("Enter values for a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    //perform bitwise AND operation between a and b
    int AndResult = a & b;
    printf("\nResult of a & b: %d", AndResult);
    decToBin(AndResult);
    
    //perform bitwise OR operation between a and b
    int OrResult = a | b;
    printf("\nResult of a | b: %d", OrResult);
    decToBin(OrResult);
    
    //perform bitwise NOT operation on c
    int NotResult = ~c;
    printf("\nResult of ~c: %d", NotResult);
    decToBin(NotResult);
    
    //perform bitwise XOR operation between a and b
    int XorResult = a ^ b;
    printf("\nResult of a ^ b: %d", XorResult);
    decToBin(XorResult);
    
    //perform right shift operation on a
    int RightShiftResult = a >> 2;
    printf("\nResult of a >> 2: %d", RightShiftResult);
    decToBin(RightShiftResult);
    
    //perform left shift operation on a
    int LeftShiftResult = a << 3;
    printf("\nResult of a << 3: %d", LeftShiftResult);
    decToBin(LeftShiftResult);

    return 0;
}