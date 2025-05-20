//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

// Function to print the tower of hanoi
void printTower(int n, char from, char to, char aux){
    int i;
    for(i=0; i<n; i++){
        if(i==0){
            printf("Move disk 1 from %c to %c\n",from,to);
        }
        else if(i==1){
            printf("Move disk %d from %c to %c\n",n-i,from,to);
        }
        else{
            printf("Move disk %d from %c to %c\n",n-i,from,to);
        }
    }
}

// Function to check if move is valid
int isValidMove(int n, char from, char to){
    if(from==to){
        return 0;
    }
    else if(from=='A' && to=='C' && n>0){
        return 1;
    }
    else if(from=='B' && to=='A' && n>0){
        return 1;
    }
    else if(from=='C' && to=='B' && n>0){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to solve the tower of hanoi problem
void towerOfHanoi(int n, char from, char to, char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",from,to);
        return;
    }
    towerOfHanoi(n-1,from,aux,to);
    printTower(n,from,to,aux);
    towerOfHanoi(n-1,aux,to,from);
}

// Main function
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n,'A','C','B');
    return 0;
}