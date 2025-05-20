//FormAI DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Node structure to create graph
struct GraphNode {
    int vertex;
    struct GraphNode* next;
};

int numPlayers; // total number of players in game
int* pArr; // array of player numbers
struct GraphNode** graph; // 2D array for graph

// function to create a new node in graph
struct GraphNode* createGraphNode(int v) {
    struct GraphNode* newNode = malloc(sizeof(struct GraphNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// function to add edge to the graph
void addEdge(int from, int to) {
    struct GraphNode* newNode = createGraphNode(to);
    newNode->next = graph[from];
    graph[from] = newNode;
}

// function to display graph
void displayGraph() {
    printf("\n--- Graph ---\n");
    for(int i=0; i<numPlayers; i++) {
        printf("Player %d -> ", pArr[i]);
        struct GraphNode* temp = graph[i];
        while(temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// function to initialize player array
void initPlayers() {
    pArr = malloc(numPlayers * sizeof(int)); // allocate memory for player array
    for(int i=0; i<numPlayers; i++) {
        pArr[i] = i+1; // set player number
    }
}

// function to shuffle player array
void shufflePlayers() {
    srand(time(NULL)); // seed random number generator
    for(int i=numPlayers-1; i>=1; i--) { // Fisher-Yates shuffle algorithm
        int j = rand() % (i+1);
        int temp = pArr[i];
        pArr[i] = pArr[j];
        pArr[j] = temp;
    }
}

// function to initialize graph
void initGraph() {
    graph = malloc(numPlayers * sizeof(struct GraphNode*)); // allocate memory for 2D array
    for(int i=0; i<numPlayers; i++) {
        graph[i] = NULL;
    }
    for(int i=0; i<numPlayers; i++) {
        // add edges for adjacent players
        if(i == 0) { // first player
            addEdge(i, i+1);
            addEdge(i, numPlayers-1); // wrap around to last player
        } else if(i == numPlayers-1) { // last player
            addEdge(i, 0); // wrap around to first player
            addEdge(i, i-1);
        } else { // middle players
            addEdge(i, i-1);
            addEdge(i, i+1);
        }
    }
}

int main() {
    // get input from user
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    // initialize player array and shuffle
    initPlayers();
    shufflePlayers();

    // initialize graph
    initGraph();

    // display graph
    displayGraph();

    return 0;
}