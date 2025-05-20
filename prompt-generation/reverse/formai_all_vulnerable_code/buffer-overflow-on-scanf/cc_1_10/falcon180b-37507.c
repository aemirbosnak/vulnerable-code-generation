//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_list(int n){
    node* head = NULL;
    node* temp = NULL;
    int i;
    for(i=0;i<n;i++){
        temp = (node*)malloc(sizeof(node));
        temp->data = rand()%100;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            node* curr = head;
            while(curr->next!= NULL){
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    return head;
}

void print_list(node* head){
    node* curr = head;
    while(curr!= NULL){
        printf("%d -> ",curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void bubble_sort(node** head){
    node* curr = *head;
    node* prev = NULL;
    node* next = NULL;
    int swapped;
    do{
        swapped = 0;
        prev = NULL;
        while(curr!= NULL){
            next = curr->next;
            if(curr->data > prev->data){
                node* temp = curr->data;
                curr->data = prev->data;
                prev->data = temp;
                swapped = 1;
            }
            curr = next;
        }
        curr = *head;
        while(curr!= NULL){
            prev = curr;
            curr = curr->next;
        }
    }while(swapped);
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    node* head = create_list(n);
    printf("Original list:\n");
    print_list(head);
    bubble_sort(&head);
    printf("Sorted list:\n");
    print_list(head);
    return 0;
}