//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main () {
    int n,i,j;
    float fraction;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    //initialize an array of linked lists
    struct node *buckets[10];

    //initialize all the buckets with NULL
    for(i=0;i<10;i++) {
        buckets[i]=NULL;
    }

    //read the input elements and insert them into the appropriate bucket
    printf("Enter the elements:\n");
    for(i=0;i<n;i++) {
        //assuming that input elements are less than 1
        scanf("%f",&fraction);
        //multiply each fraction with 10 to fit into the range 0 - 9
        int index=fraction*10;
        //create a new node to store the element
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=fraction;
        newnode->next=NULL;

        //insert the element into the appropriate bucket
        if(buckets[index]==NULL) {
            buckets[index]=newnode;
        }
        else {
            struct node *ptr=buckets[index];
            struct node *prev=NULL;
            while(ptr!=NULL && ptr->data<fraction) {
                prev=ptr;
                ptr=ptr->next;
            }
            if(prev==NULL) {
                newnode->next=buckets[index];
                buckets[index]=newnode;
            }
            else {
                prev->next=newnode;
                newnode->next=ptr;
            }
        }
    }

    //concatenate all the linked lists
    struct node *start=NULL,*end=NULL;
    for(i=0;i<10;i++) {
        if(buckets[i]!=NULL) {
            if(start==NULL) {
                start=buckets[i];
                end=start;
            }
            else {
                end->next=buckets[i];
                end=buckets[i];
            }
        }
    }

    //display the sorted elements
    printf("The sorted order is:\n");
    struct node *ptr=start;
    while(ptr!=NULL) {
        printf("%f ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}