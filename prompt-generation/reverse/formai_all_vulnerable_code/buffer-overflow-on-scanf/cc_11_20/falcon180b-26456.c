//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int data[100],n,i,j,temp;
    float mean,median,mode,range,variance,sd;
    char ch;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&data[i]);
    }

    printf("Enter the type of calculation you want to perform:\n");
    printf("1. Mean\n2. Median\n3. Mode\n4. Range\n5. Variance\n6. Standard deviation\n");
    scanf("%d",&ch);

    switch(ch){

        case 1:
            mean=0;
            for(i=0;i<n;i++){
                mean+=data[i];
            }
            mean=mean/n;
            printf("The mean is: %f",mean);
            break;

        case 2:
            printf("Enter the position of the median: ");
            scanf("%d",&j);
            if(n%2==0){
                temp=data[j-1];
                data[j-1]=data[n/2];
                data[n/2]=temp;
            }
            printf("The median is: %d",data[(n-1)/2]);
            break;

        case 3:
            printf("The mode is: ");
            for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                    if(data[i]==data[j]){
                        printf("%d ",data[i]);
                    }
                }
            }
            break;

        case 4:
            printf("The range is: %d",data[n-1]-data[0]);
            break;

        case 5:
            variance=0;
            for(i=0;i<n;i++){
                variance+=pow(data[i]-mean,2);
            }
            variance=variance/n;
            printf("The variance is: %f",variance);
            break;

        case 6:
            sd=sqrt(variance);
            printf("The standard deviation is: %f",sd);
            break;

        default:
            printf("Invalid input");

    }

    return 0;
}