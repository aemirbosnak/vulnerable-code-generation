//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a person
typedef struct {
    char name[50];
    int age;
    char gender[10];
} Person;

// Define a structure for a linked list node
typedef struct node {
    Person data;
    struct node *next;
} Node;

// Define a structure for a linked list
typedef struct {
    Node *head;
    int size;
} LinkedList;

// Function to create a new node
Node *createNode(Person data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
LinkedList *createLinkedList() {
    LinkedList *newList = (LinkedList *) malloc(sizeof(LinkedList));
    if (newList == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a person to the linked list
void addPerson(LinkedList *list, char name[], int age, char gender[]) {
    Person newPerson;
    strcpy(newPerson.name, name);
    newPerson.age = age;
    strcpy(newPerson.gender, gender);
    Node *newNode = createNode(newPerson);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *currentNode = list->head;
        while (currentNode->next!= NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    list->size++;
}

// Function to print the linked list
void printLinkedList(LinkedList *list) {
    Node *currentNode = list->head;
    printf("Name\tAge\tGender\n");
    while (currentNode!= NULL) {
        printf("%s\t%d\t%s\n", currentNode->data.name, currentNode->data.age, currentNode->data.gender);
        currentNode = currentNode->next;
    }
}

// Main function
int main() {
    LinkedList *list = createLinkedList();
    addPerson(list, "John", 25, "Male");
    addPerson(list, "Jane", 30, "Female");
    addPerson(list, "Bob", 20, "Male");
    printLinkedList(list);
    return 0;
}