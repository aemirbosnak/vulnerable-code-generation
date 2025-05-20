//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

//Defining the bucket pointer struct
struct bucket{
    int data;
    struct bucket* next;
};

//Function to create a new node of bucket type and return it
struct bucket* create_node(int val){
    struct bucket* new_node = (struct bucket*)malloc(sizeof(struct bucket));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

//Function to insert a node at the end of the linked list of the bucket
void insert_end(struct bucket** head, int val){
    struct bucket* new_node = create_node(val);
    if(*head == NULL)
        *head = new_node;
    else{
        struct bucket* temp = *head;
        while(temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

//Function to perform bucket sort
void bucket_sort(int arr[], int n, int bucket_count){
    //Creating the buckets
    struct bucket** buckets = (struct bucket**)malloc(sizeof(struct bucket*)*bucket_count);
    for(int i=0;i<bucket_count;i++)
        buckets[i] = NULL;
    
    //Inserting elements into respective buckets
    for(int i=0;i<n;i++){
        int bucket_index = arr[i]/bucket_count;
        insert_end(&buckets[bucket_index], arr[i]);
    }
    
    //Sorting each bucket individually 
    for(int i=0;i<bucket_count;i++){
        if(buckets[i] == NULL)
            continue;
        else{
            struct bucket* curr = buckets[i];
            int* temp = (int*)malloc(sizeof(int)*bucket_count);
            int j=0;
            while(curr){
                temp[j++] = curr->data;
                curr = curr->next;
            }
            for(int x=0;x<j-1;x++){
                for(int y=0;y<j-x-1;y++){
                    if(temp[y] > temp[y+1]){
                        int temp_val = temp[y];
                        temp[y] = temp[y+1];
                        temp[y+1] = temp_val;
                    }
                }
            }
            curr = buckets[i];
            j=0;
            while(curr){
                curr->data = temp[j++];
                curr = curr->next;
            }
            free(temp);
        }
    }
    
    //Storing the sorted elements back into the array
    int index=0;
    for(int i=0;i<bucket_count;i++){
        struct bucket* curr = buckets[i];
        while(curr){
            arr[index++] = curr->data;
            curr = curr->next;
        }
    }
    
    //Freeing the allocated memory
    for(int i=0;i<bucket_count;i++){
        struct bucket* curr = buckets[i];
        while(curr){
            struct bucket* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

//Main function to demonstrate the working of bucket sort
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int max_val = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    int bucket_count = max_val/10+1;
    bucket_sort(arr, n, bucket_count);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    free(arr);
    return 0;
}