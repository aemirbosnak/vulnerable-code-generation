//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Defining a Node structure with a mystical twist
struct Node {
    int data; 
    struct Node* next;
};

// A wizard's chant to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("The wizard has failed... Memory cannot be allocated!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// An elixir to insert a node at the end of the list
void insertEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("A new spell has been cast: %d\n", data);
        return;
    }
    
    struct Node* last = *head_ref;
    while (last->next) {
        last = last->next;
    }
    last->next = newNode;
    printf("Another charm born into the realm: %d\n", data);
}

// A mysterious spell to display the list
void displayList(struct Node* node) {
    printf("Behold the linked list: ");
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// A cunning charm to delete a given key from the list
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;
    
    if (temp && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("The spell has been broken: %d has vanished!\n", key);
        return;
    }
    
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("No such charm found to delete: %d\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("The dark magic has been undone: %d has been erased!\n", key);
}

// A magic incantation to search for a specific key
int search(struct Node* head, int key) {
    int position = 0;
    while (head) {
        if (head->data == key) {
            printf("A spirit has been found at position %d: %d!\n", position, key);
            return 1; // Found
        }
        head = head->next;
        position++;
    }
    printf("The quest was futile... %d was not found in the realm!\n", key);
    return 0; // Not found
}

// The grand finale!
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMystical Linked List Operations Menu:\n");
        printf("1. Insert Value at End\n");
        printf("2. Delete Value\n");
        printf("3. Display List\n");
        printf("4. Search Value\n");
        printf("5. Exit the Mystical Realm\n");
        printf("Choose your adventure (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a number to conjure: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter the number to banish: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter the number to search for: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 5:
                printf("You have chosen to leave the mystical realm. Farewell!\n");
                exit(0);
            default:
                printf("Alas! An unknown choice. Please seek wisdom...\n");
        }
    }

    return 0;
}