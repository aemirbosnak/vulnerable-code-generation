//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// define struct for linked list
typedef struct node {
    int val;
    struct node* next;
} node;

// define function for bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    int i, j;

    // find maximum value in array
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // create buckets (linked lists)
    node** buckets = (node**) malloc(max_val * sizeof(node*));
    for (i = 0; i < max_val; i++) {
        buckets[i] = NULL;
    }

    // insert values into buckets
    for (i = 0; i < n; i++) {
        node* new_node = (node*) malloc(sizeof(node));
        new_node->val = arr[i];
        new_node->next = NULL;
        int bucket_index = (arr[i]-1) / max_val;
        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = new_node;
        } else {
            node* cur_node = buckets[bucket_index];
            while (cur_node->next != NULL) {
                cur_node = cur_node->next;
            }
            cur_node->next = new_node;
        }
    }

    // sort values within each bucket using insertion sort
    for (i = 0; i < max_val; i++) {
        node* cur_node = buckets[i];
        while (cur_node != NULL) {
            int val = cur_node->val;
            node* prev_node = NULL;
            node* next_node = cur_node->next;
            while ((prev_node == NULL || prev_node->val > val) && prev_node != cur_node) {
                next_node = prev_node;
                prev_node = prev_node == NULL ? cur_node : prev_node->next;
            }
            if (prev_node != cur_node) {
                cur_node->next = prev_node;
                if (prev_node == buckets[i]) {
                    buckets[i] = cur_node;
                } else {
                    node* node_before_prev = buckets[i];
                    while (node_before_prev->next != prev_node) {
                        node_before_prev = node_before_prev->next;
                    }
                    node_before_prev->next = cur_node;
                }
            }
            cur_node = next_node;
        }
    }

    // output sorted array
    int k = 0;
    for (i = 0; i < max_val; i++) {
        node* cur_node = buckets[i];
        while (cur_node != NULL) {
            arr[k++] = cur_node->val;
            cur_node = cur_node->next;
        }
    }

    // free memory
    for (i = 0; i < max_val; i++) {
        node* cur_node = buckets[i];
        while (cur_node != NULL) {
            node* next_node = cur_node->next;
            free(cur_node);
            cur_node = next_node;
        }
    }
    free(buckets);
}

int main() {
    int n, i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}