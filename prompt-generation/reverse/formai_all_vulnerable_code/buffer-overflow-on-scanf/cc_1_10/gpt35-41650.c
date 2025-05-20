//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: imaginative
#include<stdio.h> 

int main() 
{ 
    int num[10], i, j, k; 
    int watermark[5] = {1, 0, 1, 1, 0}; 
    int watermarkSize = 5; 

    printf("Enter 10 numbers: "); 

    for(i=0;i<10;i++) 
    {
        scanf("%d",&num[i]); 
    }

    printf("\nOriginal numbers: "); 

    for(i=0;i<10;i++) 
    {
        printf("%d ",num[i]); 
    }

    printf("\nWatermark: ");

    for(i=0;i<watermarkSize;i++) 
    {
        printf("%d",watermark[i]); 
    }

    j = 0; 
    k = 0; 

    printf("\nWatermarked numbers: "); 

    for(i=0;i<10;i++) 
    { 
        if(k == watermarkSize) 
        { 
            k = 0; 
            num[i] = num[i] + watermark[j]; 
            j++; 
            j = j % watermarkSize; 
        } 
        else 
        { 
            num[i] = num[i] + watermark[k]; 
            k++; 
        } 

        printf("%d ",num[i]); 
    } 

    return 0; 
}