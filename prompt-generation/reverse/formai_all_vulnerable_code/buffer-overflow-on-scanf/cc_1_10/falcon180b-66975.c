//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

// Function to reverse the bits of a number
unsigned int reverseBits(unsigned int num){
    int count = 0;
    unsigned int reversed = 0;
    while(num > 0){
        if(num % 2 == 1){
            reversed += pow(2, count);
        }
        num /= 2;
        count++;
    }
    return reversed;
}

int main(){
    int choice;
    unsigned int num1, num2;

    // Menu options
    printf("1. Reverse bits of a number\n");
    printf("2. Bitwise AND operation\n");
    printf("3. Bitwise OR operation\n");
    printf("4. Bitwise XOR operation\n");
    printf("5. Bitwise NOT operation\n");
    printf("6. Bitwise left shift operation\n");
    printf("7. Bitwise right shift operation\n");
    printf("8. Exit\n");

    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter a number: ");
                scanf("%u", &num1);
                printf("Reversed bits: %u\n", reverseBits(num1));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%u %u", &num1, &num2);
                printf("AND operation result: %u\n", num1 & num2);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%u %u", &num1, &num2);
                printf("OR operation result: %u\n", num1 | num2);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%u %u", &num1, &num2);
                printf("XOR operation result: %u\n", num1 ^ num2);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%u", &num1);
                printf("NOT operation result: %u\n", ~num1);
                break;
            case 6:
                printf("Enter a number and a shift value: ");
                scanf("%u %u", &num1, &num2);
                printf("Left shift operation result: %u\n", num1 << num2);
                break;
            case 7:
                printf("Enter a number and a shift value: ");
                scanf("%u %u", &num1, &num2);
                printf("Right shift operation result: %u\n", num1 >> num2);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }while(choice!= 8);

    return 0;
}