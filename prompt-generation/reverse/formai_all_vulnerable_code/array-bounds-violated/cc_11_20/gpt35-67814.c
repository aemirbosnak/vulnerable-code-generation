//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include<stdio.h>

int main(){
    int arr[100], n, i, j, freq=0, tmp, mode, count=1;
    float mean=0, median=0;
    
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    //Taking user input
    printf("Enter %d elements \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        mean+=arr[i];
    }
    mean=mean/n;
    
    //Bubble sorting
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    
    //Finding the median
    if(n%2==0){
        median=(arr[(n/2)-1]+arr[n/2])/2.0;
    }
    else{
        median=arr[n/2];
    }
    
    //Finding the mode
    for(i=0;i<n;i++){
        tmp=arr[i];
        for(j=i+1;j<n;j++){
            if(tmp==arr[j]){
                count++;
            }
        }
        if(count>freq){
            mode=tmp;
            freq=count;
        }
        count=1;
    }
    
    //Printing the output
    printf("Mean = %.2f\n",mean);
    printf("Median = %.2f\n",median);
    if(freq==1){
        printf("No mode found\n");
    }
    else{
        printf("Mode = %d with a frequency of %d\n",mode,freq);
    }
    
    return 0;
}