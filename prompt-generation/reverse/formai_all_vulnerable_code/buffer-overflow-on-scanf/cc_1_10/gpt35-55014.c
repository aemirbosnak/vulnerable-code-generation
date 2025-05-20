//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
/* 
   This program takes in two arrays of integers and performs various arithmetic operations on them.
*/

#include<stdio.h>

// Function to add two arrays
void add(int a[], int b[], int n){
    int c[n];
    for(int i=0;i<n;i++){
        c[i] = a[i] + b[i];
    }
    printf("Addition of arrays:\n");
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
}

// Function to subtract two arrays
void subtract(int a[], int b[], int n){
    int c[n];
    for(int i=0;i<n;i++){
        c[i] = a[i] - b[i];
    }
    printf("\nSubtraction of arrays:\n");
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
}

// Function to multiply two arrays
void multiply(int a[], int b[], int n){
    int c[n];
    for(int i=0;i<n;i++){
        c[i] = a[i] * b[i];
    }
    printf("\nMultiplication of arrays:\n");
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
}

// Function to divide two arrays
void divide(int a[], int b[], int n){
    int c[n];
    for(int i=0;i<n;i++){
        c[i] = a[i] / b[i];
    }
    printf("\nDivision of arrays:\n");
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
}

// Main function
int main(){
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter the elements of first array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of second array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    add(a,b,n);
    subtract(a,b,n);
    multiply(a,b,n);
    divide(a,b,n);
    return 0;
}