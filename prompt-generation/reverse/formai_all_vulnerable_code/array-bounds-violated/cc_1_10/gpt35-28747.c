//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include<stdio.h>

//Function to find the GCD of two numbers
int gcd(int num1, int num2){
    if(num2==0){
        return num1;
    }
    else{
        return gcd(num2,num1%num2);
    }
}

int main(){

    printf("Enter two numbers to find their GCD:\n");
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    int result=gcd(num1,num2);
    printf("The GCD of %d and %d is %d.\n",num1,num2,result);

    printf("\n-----------------------------------\n\n");

    printf("Enter the number of elements in the array:\n");
    int n;
    scanf("%d",&n);
    int arr[n],sum=0,max=-99999999,min=99999999;
    float avg;
    printf("Enter %d elements of the array:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    avg=(float)sum/n;
    printf("\nThe sum of the elements in the array is %d.\n",sum);
    printf("The average of the elements in the array is %f.\n",avg);
    printf("The maximum element in the array is %d.\n",max);
    printf("The minimum element in the array is %d.\n",min);

    printf("\n-----------------------------------\n\n");

    printf("Enter the number of terms in the Fibonacci series:\n");
    int terms;
    scanf("%d",&terms);
    int fib[terms];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<terms;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    printf("The first %d terms of the Fibonacci series are:\n",terms);
    for(int i=0;i<terms;i++){
        printf("%d ",fib[i]);
    }

    return 0;
}