//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    char name[MAX];
    int age;
} Person;

typedef struct {
    Person* data;
    int size;
    int capacity;
} Graph;

Graph* createGraph(int capacity) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->data = (Person*)malloc(capacity * sizeof(Person));
    graph->size = 0;
    graph->capacity = capacity;
    return graph;
}

int addPerson(Graph* graph, char* name, int age) {
    if (graph->size >= graph->capacity) {
        printf("Graph is full\n");
        return -1;
    }
    strcpy(graph->data[graph->size].name, name);
    graph->data[graph->size].age = age;
    graph->size++;
    return graph->size - 1;
}

int getPersonAge(Graph* graph, int index) {
    if (index >= 0 && index < graph->size) {
        return graph->data[index].age;
    }
    return -1;
}

int getPersonIndex(Graph* graph, char* name) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("%s - %d\n", graph->data[i].name, graph->data[i].age);
    }
}

int main() {
    Graph* graph = createGraph(MAX);
    char name[MAX];
    int age;
    while (1) {
        printf("Enter name and age (or type 'exit' to exit): ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }
        printf("Enter age: ");
        scanf("%d", &age);
        int index = addPerson(graph, name, age);
        if (index!= -1) {
            printf("Person added with index %d\n", index);
        }
    }
    printGraph(graph);
    return 0;
}