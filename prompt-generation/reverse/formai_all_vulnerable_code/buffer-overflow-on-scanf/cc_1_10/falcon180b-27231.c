//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
    int n,i,j,k;
    double a[10][10],b[10][10],c[10][10];
    clock_t start,end;
    double cpu_time_used;
    srand(time(0));
    n=rand()%10+2;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d%d",&n,&n);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    n=rand()%10+2;
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d%d",&n,&n);
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&b[i][j]);
        }
    }
    start=clock();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            for(k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    end=clock();
    cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Product of entered matrices:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%lf\t",c[i][j]);
        }
        printf("\n");
    }
    printf("CPU time used: %lf seconds\n",cpu_time_used);
    return 0;
}