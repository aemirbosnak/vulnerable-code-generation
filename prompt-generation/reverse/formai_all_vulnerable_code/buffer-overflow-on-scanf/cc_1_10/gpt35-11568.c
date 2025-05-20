//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to simulate the behavior of a classical AND gate
int AND(int a, int b){
    if(a == 1 && b == 1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to simulate the behavior of a classical OR gate
int OR(int a, int b){
    if(a == 0 && b == 0){
        return 0;
    }
    else{
        return 1;
    }
}

// Function to simulate the behavior of a classical NOT gate
int NOT(int a){
    if(a == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to simulate the behavior of a classical XOR gate
int XOR(int a, int b){
    if(a == b){
        return 0;
    }
    else{
        return 1;
    }
}

// Function to simulate the behavior of a classical NAND gate
int NAND(int a, int b){
    if(a == 1 && b == 1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int a, b, x, y, z;

    printf("Enter the values of a and b: ");
    scanf("%d %d", &a, &b);

    // Simulating the outputs of various classical gates
    x = AND(a, b);
    y = OR(a, b);
    z = XOR(a, b);

    //Printing the outputs of different classical gates
    printf("The output of AND gate: %d\n", x);
    printf("The output of OR gate: %d\n", y);
    printf("The output of XOR gate: %d\n", z);
    printf("The output of NOT gate for a: %d\n", NOT(a));
    printf("The output of NOT gate for b: %d\n", NOT(b));
    printf("The output of NAND gate: %d\n", NAND(a, b));

    return 0;
}