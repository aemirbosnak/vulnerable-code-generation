//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#define max_size 100000

int arr[max_size];
int n;
int i,j,k;

void merge(int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int x=0;x<n1;x++){
        L[x]=arr[l+x];
    }
    for(int y=0;y<n2;y++){
        R[y]=arr[m+1+y];
    }
    int cmp=0;
    int k=l;
    while(cmp<n1 && cmp<n2){
        if(L[cmp]<=R[cmp]){
            arr[k]=L[cmp];
            cmp++;
        }
        else{
            arr[k]=R[cmp];
            cmp++;
        }
        k++;
    }
    while(cmp<n1){
        arr[k]=L[cmp];
        cmp++;
        k++;
    }
    while(cmp<n2){
        arr[k]=R[cmp];
        cmp++;
        k++;
    }
}

void merge_sort(int l,int r){
    if(l<r){
        int m=(l+r)/2;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,m,r);
    }
}

int main(){
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(0,n-1);
    printf("Sorted array\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}