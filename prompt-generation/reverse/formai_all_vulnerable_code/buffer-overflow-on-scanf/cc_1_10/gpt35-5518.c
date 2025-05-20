//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include<stdio.h>

void display(int a[][100], int m, int n){
    //function to display the matrix
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void add(int a[][100], int b[][100], int c[][100], int m, int n){
    //function to add two matrices
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply(int a[][100], int b[][100], int c[][100], int m1, int n1, int m2, int n2){
    //function to multiply two matrices
    int i,j,k;
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            c[i][j] = 0;
            for(k=0;k<n1;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main(){
    int a[100][100], b[100][100], c[100][100], m1, n1, m2, n2, choice, i, j; 
    
    printf("Enter the number of rows and columns of first matrix : ");
    scanf("%d%d",&m1,&n1);
    
    printf("Enter the elements of first matrix : ");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns of second matrix : ");
    scanf("%d%d",&m2,&n2);
    
    printf("Enter the elements of second matrix : ");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
    printf("\nFirst Matrix : \n");
    display(a,m1,n1);
    
    printf("\nSecond Matrix : \n");
    display(b,m2,n2);
    
    printf("\nMenu\n1. Addition\n2. Multiplication\nEnter your choice : ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            if(m1==m2 && n1==n2){
                add(a,b,c,m1,n1);
                printf("\nResultant Matrix : \n");
                display(c,m1,n1);
            }
            else{
                printf("Addition not possible\n");
            }
            break;
            
        case 2:
            if(n1==m2){
                multiply(a,b,c,m1,n1,m2,n2);
                printf("\nResultant Matrix : \n");
                display(c,m1,n2);
            }
            else{
                printf("Multiplication not possible\n");
            }
            break;
            
        default:
            printf("Invalid Choice\n");
            break;
    }
    
    return 0;
}