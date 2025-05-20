//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include<stdio.h>

struct node{
    int data;
    int index;
};

int cmp(struct node a,struct node b){
    return a.data < b.data ? -1 : a.data == b.data ? 0 : 1;
}

void merge(struct node arr[],int l,int mid,int r){
    struct node temp[r-l+1];
    int i=l,j=mid+1,k=0;

    while(i<=mid && j<=r){
        if(cmp(arr[i],arr[j])<=0){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    for(int i=0;i<k;i++){
        arr[i+l]=temp[i];
    }
}

void mergeSort(struct node arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

void printIndex(struct node arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i].index);
    }
    printf("\n");
}

void createIndex(struct node arr[],int n){
    for(int i=0;i<n;i++){
        arr[i].index=i;
    }
}

int binarySearch(struct node arr[],int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(x==arr[mid].data){
            return mid;
        }
        else if(x<arr[mid].data){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main(){
    printf("Enter size of array: ");
    int n;
    scanf("%d",&n);

    struct node arr[n];

    printf("Enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i].data);
    }

    createIndex(arr,n);
    mergeSort(arr,0,n-1);

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i].data);
    }
    printf("\n");

    printf("Index of the array: ");
    printIndex(arr,n);

    printf("Enter the element to search: ");
    int x;
    scanf("%d",&x);

    int index=binarySearch(arr,n,x);
    if(index==-1){
        printf("%d is not present in the array.\n",x);
    }
    else{
        printf("%d is present at index %d.\n",x,arr[index].index);
    }
    return 0;
}