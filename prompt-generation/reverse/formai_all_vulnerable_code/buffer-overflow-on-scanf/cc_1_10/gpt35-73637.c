//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include<stdio.h>
#include<stdlib.h>

void bucketSort(float arr[], int n){

	float bucket[10][10]={0};
	float bucketSorted[100]={0};
	int count[10]={0};
	int i,j,k;

	for(i=0;i<n;i++){
		int bucketIndex = arr[i]*10;
		bucket[bucketIndex][count[bucketIndex]] = arr[i];
		count[bucketIndex]++;
	}

	for(i=0;i<10;i++){
		//sorting the elements within the bucket
		for(j=0;j<count[i]-1;j++){
			for(k=0;k<count[i]-j-1;k++){
				if(bucket[i][k]>bucket[i][k+1]){
					float temp = bucket[i][k];
					bucket[i][k]=bucket[i][k+1];
					bucket[i][k+1]=temp;
				}
			}
		}
	}

	//merging the elements from buckets into bucketSorted array
	int index=0;
	for(i=0;i<10;i++){
		for(j=0;j<count[i];j++){
			bucketSorted[index++] = bucket[i][j];
		}
	}

	//printing sorted elements
	printf("\nBucket Sorted Array : ");
	for(i=0;i<n;i++){
		printf("%f ", bucketSorted[i]);
	}
}

int main(){

	int n,i;
	float arr[1000];

	printf("Enter the size of array : ");
	scanf("%d", &n);

	//input numbers to the array
	printf("\nEnter the elements of the Array :\n");
	for(i=0;i<n;i++){
		scanf("%f",&arr[i]);
	}
	
	//calling bucketSort function
	bucketSort(arr,n);

	return 0;
}