//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function prototypes
void addNode(Node **head, char *data);
void printList(Node *head);
void freeList(Node *head);

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_LINE_LENGTH], outputFileName[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Node *head = NULL;

    // Get input and output file names from command line arguments
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }
    strcpy(inputFileName, argv[1]);
    strcpy(outputFileName, argv[2]);

    // Open input and output files
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file '%s'.\n", inputFileName);
        exit(1);
    }
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file '%s'.\n", outputFileName);
        exit(1);
    }

    // Read input file line by line and add to linked list
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        addNode(&head, line);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Print linked list to output file
    printList(head);

    // Free linked list memory
    freeList(head);

    return 0;
}

// Function to add a node to the linked list
void addNode(Node **head, char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: could not allocate memory for new node.\n");
        exit(1);
    }
    newNode->data = strdup(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(Node *head) {
    while (head!= NULL) {
        printf("%s", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the linked list memory
void freeList(Node *head) {
    while (head!= NULL) {
        free(head->data);
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}