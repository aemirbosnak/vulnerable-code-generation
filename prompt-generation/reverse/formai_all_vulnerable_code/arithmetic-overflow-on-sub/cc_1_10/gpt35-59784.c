//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include<stdio.h>
#include<string.h>

// structure for index
struct index{
    char key[20];
    int position;
};

// function to sort the index
void sort_index(struct index arr[],int n){
    int i,j;
    struct index temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(arr[j].key,arr[j+1].key)>0){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//function to search the index
void search_index(struct index arr[],int n,char key[]){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(strcmp(arr[i].key,key)==0){
            printf("Key found at position %d\n",arr[i].position);
            flag=1;
            break;
        }
    }
    if(flag==0) printf("Key not found\n");
}

int main(){
    struct index arr[100];
    int i,n;
    char key[20];
    printf("Enter number of elements in index : ");
    scanf("%d",&n);
    printf("Enter elements of index : \n");
    for(i=0;i<n;i++){
        scanf("%s%d",&arr[i].key,&arr[i].position);
    }
    sort_index(arr,n); //call to sort the index
    printf("Enter key to search in index : ");
    scanf("%s",&key);
    search_index(arr,n,key); //call to search the index
    return 0;
}