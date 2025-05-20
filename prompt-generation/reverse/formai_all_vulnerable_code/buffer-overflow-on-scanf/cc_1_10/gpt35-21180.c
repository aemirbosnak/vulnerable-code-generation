//FormAI DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define structure for node
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function to insert a node at the beginning of the linked list
void insert(node** head, int value) {
    node* new_node = (node*)malloc(sizeof(node)); // Allocate memory for new node
    new_node->data = value; // Assign value to data field
    new_node->next = *head; // Set next field of new node to head
    *head = new_node; // Update head to new node
}

// Decentralized searching function
node* decentralized_search(node* start, int key) {
    node* current = start; // Set current to start of linked list
    node* temp; // Define temp variable for storing previous node

    while (current != NULL) { // Traverse the linked list
        if (current->data == key) { // if key found
            if (current != start) { // if current node is not the start
                temp->next = current->next; // update previous node's next to current node's next
                current->next = start; // update current node's next to start
                start = current; // update start to current node
            }
            return current; // return current node
        }
        else {
            temp = current; // store previous node to temp
            current = current->next; // update current to next node
        }
    }
    return NULL; // return NULL if key not found
}

int main() {
    node* head = NULL; // Create an empty linked list
    int n, key;

    // Read list elements from user
    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(&head, value);
    }

    // Read key to search from user
    printf("Enter key to search: ");
    scanf("%d", &key);

    // Call decentralized search function
    node* result = decentralized_search(head, key);

    // Display results
    if (result != NULL) {
        printf("Key found at address: %p\n", (void*)result);
        printf("Linked list after searching:\n");
        node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    else {
        printf("Key not found.\n");
    }

    return 0;
}