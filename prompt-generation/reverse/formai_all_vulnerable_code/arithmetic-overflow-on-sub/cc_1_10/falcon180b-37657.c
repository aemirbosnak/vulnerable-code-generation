//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//Function to print the tower
void printTower(int n, char from, char to, char aux){
    int i;
    for(i=0; i<n; i++){
        if(i==0){
            printf("Move disk 1 from %c to %c\n", from, to);
        }
        else if(i==n-1){
            printf("Move disk %d from %c to %c\n", n-1, from, to);
        }
        else{
            printf("Move disk %d from %c to %c\n", n-i-1, from, to);
        }
    }
}

//Function to check if move is valid
int isValid(int n, int from, int to){
    if(from==to){
        return 0;
    }
    if(from>to){
        return 0;
    }
    if(from<0 || to<0 || from>=n || to>=n){
        return 0;
    }
    return 1;
}

//Recursive function to solve the problem
void towerOfHanoi(int n, char from, char to, char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n-1, aux, to, from);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char from='A', to='C', aux='B';
    towerOfHanoi(n, from, to, aux);
    return 0;
}