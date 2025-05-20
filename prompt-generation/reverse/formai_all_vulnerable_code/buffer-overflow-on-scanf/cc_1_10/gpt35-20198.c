//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include <stdio.h>

//Function to perform bitwise AND operation
void BitwiseAND(){
    int n1, n2, result;
    printf("Enter two integers to perform Bitwise AND operation:\n");
    scanf("%d %d",&n1, &n2);

    result = n1 & n2;
    
    printf("Bitwise AND of %d and %d is %d\n", n1, n2, result);
}

//Function to perform bitwise OR operation
void BitwiseOR(){
    int n1, n2, result;
    printf("Enter two integers to perform Bitwise OR operation:\n");
    scanf("%d %d",&n1, &n2);

    result = n1 | n2;
    
    printf("Bitwise OR of %d and %d is %d\n", n1, n2, result);
}

//Function to perform bitwise XOR operation
void BitwiseXOR(){
    int n1, n2, result;
    printf("Enter two integers to perform Bitwise XOR operation:\n");
    scanf("%d %d",&n1, &n2);

    result = n1 ^ n2;
    
    printf("Bitwise XOR of %d and %d is %d\n", n1, n2, result);
}

//Function to perform bitwise NOT operation
void BitwiseNOT(){
    int n, result;
    printf("Enter an integer to perform Bitwise NOT operation:\n");
    scanf("%d",&n);

    result = ~n;
    
    printf("Bitwise NOT of %d is %d\n", n, result);
}

//Function to perform bitwise left shift
void BitwiseLeftShift(){
    int n, shift, result;
    printf("Enter an integer to perform Bitwise left shift operation:\n");
    scanf("%d",&n);
    printf("Enter number of bits to shift:\n");
    scanf("%d",&shift);
    result = n << shift;
    
    printf("Bitwise left shift of %d by %d bits is %d\n", n, shift, result);
}

//Function to perform bitwise right shift
void BitwiseRightShift(){
    int n, shift, result;
    printf("Enter an integer to perform Bitwise right shift operation:\n");
    scanf("%d",&n);
    printf("Enter number of bits to shift:\n");
    scanf("%d",&shift);
    result = n >> shift;
    
    printf("Bitwise right shift of %d by %d bits is %d\n", n, shift, result);
}

int main(){
    printf("Welcome to Bitwise operation program!\n");
    printf("Select the operation you want to perform:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise left shift\n");
    printf("6. Bitwise right shift\n");    

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            BitwiseAND();           
            break;
        case 2:
            BitwiseOR();
            break;
        case 3:
            BitwiseXOR();
            break;
        case 4:
            BitwiseNOT();
            break;
        case 5:
            BitwiseLeftShift();
            break;
        case 6:
            BitwiseRightShift();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}