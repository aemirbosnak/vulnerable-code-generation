//FormAI DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* Donald Knuth inspired programming example */

/* This program takes an input file of integers, sorts them,
and prints out the sorted list to an output file. */

/* This program uses a merge sort algorithm to sort the list. */

/* Definition of singly linked list */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function prototypes */
Node* mergeSort(Node* head);
Node* merge(Node* a, Node* b);
void splitList(Node* source, Node** front, Node** back);
void push(Node** head_ref, int new_data);
void printList(Node *node);

/* Main function */
int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    int num;
    Node *head = NULL;

    /* Open input file */
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    /* Read in integers from input file and add to linked list */
    while (fscanf(inputFile, "%d", &num) != EOF) {
        push(&head, num);
    }

    /* Close input file */
    fclose(inputFile);

    /* Sort the linked list using merge sort algorithm */
    head = mergeSort(head);

    /* Open output file */
    outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(EXIT_FAILURE);
    }

    /* Print sorted list to output file */
    Node* current = head;
    while (current != NULL) {
        fprintf(outputFile, "%d\n", current->data);
        current = current->next;
    }

    /* Close output file */
    fclose(outputFile);

    /* Free memory used by linked list */
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

/* Merge sort algorithm implementation */
Node* mergeSort(Node* head) {
    Node* a;
    Node* b;

    /* Base case - list is empty or has one element */
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    /* Split the list into two halves */
    splitList(head, &a, &b);

    /* Recursively sort the two halves */
    a = mergeSort(a);
    b = mergeSort(b);

    /* Merge the two sorted halves */
    return merge(a, b);
}

/* Merge two sorted linked lists */
Node* merge(Node* a, Node* b) {
    Node* result = NULL;

    /* Base case - if either list is empty */
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    /* Compare the data in the two lists and merge */
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

/* Split a linked list into two halves */
void splitList(Node* source, Node** front, Node** back) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    /* Move fast pointer twice as fast as slow pointer */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* Split list in half at middle */
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

/* Add a new node to the beginning of a linked list */
void push(Node** head_ref, int new_data) {
    /* Allocate memory for new node */
    Node* new_node = (Node*)malloc(sizeof(Node));

    /* Set data for new node */
    new_node->data = new_data;
    new_node->next = (*head_ref);

    /* Update head to new node */
    (*head_ref) = new_node;
}

/* Print a linked list */
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}