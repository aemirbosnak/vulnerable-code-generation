//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
// Hey there! I am a curious chatbot and I would love to share with you a unique C Graph representation example program!
#include <stdio.h>

int main() {
    int vertices, edges, root, graph[20][20], dist[20], parent[20], count, minDist, visit[20];

    // Let me ask some initial questions to the user!
    printf("Hey there! How many vertices does your graph have? ");
    scanf("%d", &vertices);
    printf("And how many edges? ");
    scanf("%d", &edges);

    // Let's initialize the graph with a default value of 0 for all its elements
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    // And now let the user input the edges and their respective weights
    int vertex1, vertex2, weight;
    for(int i=0; i<edges; i++){
        printf("Enter vertex 1 of edge %d: ", i+1);
        scanf("%d", &vertex1);
        printf("Enter vertex 2 of edge %d: ", i+1);
        scanf("%d", &vertex2);
        printf("Enter the weight of the edge %d: ", i+1);
        scanf("%d", &weight);
        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight;
    }

    // Alright, now let's ask the user to input the root vertex to start the traversal from
    printf("Which vertex should I start the traversal from? ");
    scanf("%d", &root);

    // Let's initialize our distance array with a default value of infinity, visit array with 0 (not visited), and parent array with -1 (no parent)
    for(int i=0; i<vertices; i++){
        dist[i] = 999;
        visit[i] = 0;
        parent[i] = -1;
    }

    dist[root] = 0; // And set the distance of the root node to 0 to start with

    for(int i=0; i<vertices-1; i++){ // Let's traverse through all the vertices except the root one
        minDist = 999;
        for(int j=0; j<vertices; j++){ // And pick the one with the minimum distance
            if(!visit[j] && dist[j] < minDist){
                minDist = dist[j];
                count = j;
            }
        }

        visit[count] = 1; // Mark this vertex as visited
        for(int j=0; j<vertices; j++){ // And for all its adjacent vertices, update their distances if they are shorter than the current ones
            if(!visit[j] && graph[count][j] && dist[count]+graph[count][j] < dist[j]){
                parent[j] = count;
                dist[j] = dist[count] + graph[count][j];
            }
        }
    }

    // Finally, let's print out the traversal order, distance, and parent node for each vertex
    for(int i=0; i<vertices; i++){
        if(i != root){
            printf("Vertex %d, Distance: %d, Parent Node: %d\n", i, dist[i], parent[i]);
        }
    }

    // Yay, we're done! Hope you enjoyed this little demonstration of graph representation in C programming language!
    return 0;
}