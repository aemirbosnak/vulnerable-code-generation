//FormAI DATASET v1.0 Category: Bitwise operations ; Style: careful
#include<stdio.h>

//Function to display binary representation of a number
void binary(int num){
    if(num){
        binary(num>>1);
        printf("%d",(num & 1));
    }
}

int main(){
    int a,b,c;

    printf("\nEnter two numbers:\n");
    scanf("%d%d",&a,&b);

    //Using Bitwise AND operator
    c = a & b;
    printf("\nBitwise AND of %d and %d = %d\n\n",a,b,c);

    printf("%d in binary: ",a);
    binary(a);
    printf("\n");
    printf("%d in binary: ",b);
    binary(b);
    printf("\n");
    printf("%d in binary: ",c);
    binary(c);
    printf("\n\n");

    //Using Bitwise OR operator
    c = a | b;
    printf("Bitwise OR of %d and %d = %d\n\n",a,b,c);

    printf("%d in binary: ",a);
    binary(a);
    printf("\n");
    printf("%d in binary: ",b);
    binary(b);
    printf("\n");
    printf("%d in binary: ",c);
    binary(c);
    printf("\n\n");

    //Using Bitwise XOR operator
    c = a ^ b;
    printf("Bitwise XOR of %d and %d = %d\n\n",a,b,c);

    printf("%d in binary: ",a);
    binary(a);
    printf("\n");
    printf("%d in binary: ",b);
    binary(b);
    printf("\n");
    printf("%d in binary: ",c);
    binary(c);
    printf("\n\n");

    //Using Bitwise NOT operator
    c = ~a;
    printf("Bitwise NOT of %d = %d\n\n",a,c);

    printf("%d in binary: ",a);
    binary(a);
    printf("\n");
    printf("%d in binary: ",c);
    binary(c);
    printf("\n\n");

    //Using Bitwise Left Shift operator
    c = a << 1;
    printf("Bitwise Left Shift by 1 of %d = %d\n\n",a,c);

    printf("%d in binary: ",a);
    binary(a);
    printf("\n");
    printf("%d in binary: ",c);
    binary(c);
    printf("\n\n");

    //Using Bitwise Right Shift operator
    c = a >> 1;
    printf("Bitwise Right Shift by 1 of %d = %d\n\n",a,c);

    printf("%d in binary: ",a);
    binary(a);
    printf("\n");
    printf("%d in binary: ",c);
    binary(c);
    printf("\n\n");

    return 0;
}