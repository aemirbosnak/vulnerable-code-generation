//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 5

typedef struct{
    int id;
    char name[50];
    int bid;
}item;

void display(item arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nItem %d:\n",arr[i].id);
        printf("Name: %s\n",arr[i].name);
        printf("Bid: %d\n",arr[i].bid);
    }
}

int compare(const void *a,const void *b){
    item *p1 = (item *)a;
    item *p2 = (item *)b;
    if(p1->bid > p2->bid){
        return 1;
    }
    else{
        return -1;
    }
}

void auction(item arr[],int n){
    int i,j,max;
    for(i=0;i<n;i++){
        printf("\nAuction for item %d:\n",arr[i].id);
        arr[i].bid = 0;
        while(1){
            printf("Enter your bid:\n");
            scanf("%d",&arr[i].bid);
            if(arr[i].bid > 0){
                break;
            }
            else{
                printf("Invalid bid. Please enter a positive integer.\n");
            }
        }
        printf("Current bid for item %d is %d.\n",arr[i].id,arr[i].bid);
        sleep(1);
    }
    qsort(arr,n,sizeof(item),compare);
    printf("\nHighest bidders:\n");
    for(i=0;i<n;i++){
        if(arr[i].bid > 0){
            printf("Item %d: %s with bid %d\n",arr[i].id,arr[i].name,arr[i].bid);
        }
    }
}

int main(){
    int n,i;
    printf("Enter number of items:\n");
    scanf("%d",&n);
    item arr[n];
    printf("\nEnter details of items:\n");
    for(i=0;i<n;i++){
        printf("Item %d:\n",i+1);
        printf("Name: ");
        scanf("%s",arr[i].name);
        printf("Initial bid: ");
        scanf("%d",&arr[i].bid);
    }
    auction(arr,n);
    return 0;
}