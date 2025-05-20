//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in an adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define the structure for the graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a node
struct Node* createNode(int vertex) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Uncomment to make it undirected
    // newNode = createNode(src);
    // newNode->next = graph->adjLists[dest];
    // graph->adjLists[dest] = newNode;
}

// Function to display the graph in a delightful way!
void displayGraph(struct Graph* graph) {
    printf("\n🎉 Welcome to the Happy Graph Display! 🎉\n");
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("🥳 Vertex %d: ", v);
        
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("🎈 End of Happy Graph! 🎈\n");
}

// Main function to run the program
int main() {
    int vertices, edges, src, dest;

    printf("💖 Let's create a colorful graph! 💖\n");
    printf("How many vertices does your graph have? ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("How many edges would you like to add? ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("✨ Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
        printf("🌟 Edge from %d to %d added! 🌟\n", src, dest);
    }

    displayGraph(graph);

    // Free memory
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    printf("🎉 Thank you for playing with the graph! Bye! 🎉\n");
    return 0;
}