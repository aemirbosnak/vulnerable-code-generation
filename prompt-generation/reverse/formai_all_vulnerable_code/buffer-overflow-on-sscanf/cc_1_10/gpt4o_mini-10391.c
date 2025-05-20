//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to hold information about syntactic elements
typedef struct Node {
    char type[20]; // Type of the syntactic element
    char value[50]; // Value of the element
    struct Node* next; // Pointer to the next node
} Node;

// Structure for the linked list of parsed elements
typedef struct LinkedList {
    Node* head; // Head of the list
} LinkedList;

// Function to initialize the linked list
LinkedList* initList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

// Function to create a new node
Node* createNode(const char* type, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->type, type);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(LinkedList* list, const char* type, const char* value) {
    Node* newNode = createNode(type, value);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to parse a line of C code
void parseLine(LinkedList* list, const char* line) {
    char type[20], value[50];
    if (sscanf(line, "int %s", value) == 1) {
        strcpy(type, "Integer Declaration");
        addNode(list, type, value);
    } else if (sscanf(line, "printf(\"%[^\"]\")", value) == 1) {
        strcpy(type, "Print Statement");
        addNode(list, type, value);
    } else if (strstr(line, "=") != NULL) {
        strcpy(type, "Assignment");
        strcpy(value, line);
        addNode(list, type, value);
    }
}

// Function to print the parsed linked list
void printList(LinkedList* list) {
    Node* current = list->head;
    printf("Parsed C Code Elements:\n");
    while (current != NULL) {
        printf("Type: %s, Value: %s\n", current->type, current->value);
        current = current->next;
    }
}

// Cleanup function to free memory
void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

// Simulated apocalyptic environment for parsing
int main() {
    printf("Welcome to the Post-Apocalyptic C Code Parser!\n");
    LinkedList* list = initList();
    
    char buffer[100];
    while (1) {
        printf("Enter a line of C code (or 'exit' to terminate): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        parseLine(list, buffer);
    }
    
    printList(list);
    freeList(list);
    
    printf("Survival is not just about living. It's about coding too.\n");
    return 0;
}