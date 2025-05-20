//FormAI DATASET v1.0 Category: QR code reader ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n=0, m=0, i=0, j=0;
    scanf("%d", &n);
    int **arr;
    arr=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        arr[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int **res;
    res=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        res[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            res[i][j]=0;
        }
    }
    int num=0, sum=0, flag=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==1){
                if(flag==0){
                    flag=1;
                    sum=1;
                }
                else{
                    sum*=2;
                }
            }
            else{
                if(sum>0){
                    res[num/m][num%m]=sum;
                    num++;
                    sum=0;
                    flag=0;
                }
            }
        }
        if(sum>0){
            res[num/m][num%m]=sum;
            num++;
            sum=0;
            flag=0;
        }
    }
    for(i=0;i<num;i++){
        printf("%d ", res[i/m][i%m]);
    }
    return 0;
}