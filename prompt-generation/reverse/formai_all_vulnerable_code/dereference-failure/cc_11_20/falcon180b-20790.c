//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
    int n,i,j,k;
    int *arr;
    double max,min;
    int max_index,min_index;
    int **bucket;
    int count=0;
    int *sorted_arr;
    int m;
    int temp;
    int sum=0;
    int avg;
    int upper,lower;
    int num;
    int flag=0;
    int *final_arr;
    int final_count=0;
    int final_sum=0;
    int final_avg;
    int final_upper,final_lower;
    int final_num;
    int final_flag=0;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    arr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    max=arr[0];
    min=arr[0];

    for(i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
            max_index=i;
        }
        if(min>arr[i]){
            min=arr[i];
            min_index=i;
        }
    }

    m=max-min+1;

    bucket=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++){
        bucket[i]=(int *)malloc(n*sizeof(int));
    }

    for(i=0;i<n;i++){
        k=(arr[i]-min)/(max-min)*m;
        bucket[k][count++]=arr[i];
    }

    for(i=0;i<m;i++){
        for(j=0;j<count;j++){
            printf("%d ",bucket[i][j]);
        }
        printf("\n");
    }

    sorted_arr=(int *)malloc(n*sizeof(int));

    for(i=0;i<m;i++){
        for(j=0;j<count;j++){
            sorted_arr[j]=bucket[i][j];
        }
        count=0;
        for(j=0;j<n;j++){
            if(arr[j]>=i*m && arr[j]<(i+1)*m){
                bucket[i][count++]=arr[j];
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d ",sorted_arr[i]);
    }

    free(arr);
    for(i=0;i<m;i++){
        free(bucket[i]);
    }
    free(bucket);
    free(sorted_arr);

    return 0;
}