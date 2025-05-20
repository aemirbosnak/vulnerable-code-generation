//FormAI DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

//Structure to hold recovered data
typedef struct recoveredData {
    int data;
    struct recoveredData* next;
} RecoveredData;

//Function to recover data
RecoveredData* recoverData(int* arr, int len) {
    RecoveredData* head = NULL;
    RecoveredData* curr = NULL;
    int i;
    for(i=0; i<len; i++) {
        //If the data is negative, it is lost. We skip it.
        if(arr[i] < 0)
            continue;

        //Create the node to store recovered data
        RecoveredData* node = (RecoveredData*) malloc(sizeof(RecoveredData));
        node->data = arr[i];
        node->next = NULL;

        //If this is the first node being created, we point head to it
        if(head == NULL) {
            head = node;
            curr = node;
            continue;
        }

        //If the value of this node is less than the current node, we insert it before current node
        if(node->data <= curr->data) {
            node->next = curr;
            head = node;
            curr = node;
            continue;
        }

        //If the value of this node is greater than the current node, we move current node to its next and look for correct position
        RecoveredData* temp = curr;
        while(temp != NULL && temp->data < node->data) {
            curr = temp;
            temp = temp->next;
        }
        curr->next = node;
        node->next = temp;
        curr = node;
    }
    return head;
}

int main() {
    int len, i;
    printf("Enter the length of the data array: ");
    scanf("%d", &len);
    int* arr = (int*) malloc(len * sizeof(int));
    printf("Enter the data array:\n");
    for(i=0; i<len; i++)
        scanf("%d", &arr[i]);

    //Recover data
    RecoveredData* recoveredHead = recoverData(arr, len);

    //Print the recovered data
    printf("\n***Recovered Data***\n");
    RecoveredData* temp = recoveredHead;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}