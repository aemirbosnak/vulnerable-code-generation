//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: decentralized
#include <stdio.h>
#include <limits.h>
#include <string.h>

// Hash function that returns 16-bit integer hash value
int hash(char *s) {
    // Initialize variables
    int hash = 0;
    int i = 0;
    int len = strlen(s);
    // Loop through input string
    while (i < len) {
        hash += s[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
        i++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    // Return 16-bit integer hash value
    return (hash & 0xFFFF);
}

// Decentralized hash function that hashes the hash values of multiple nodes
int decentralized_hash(char *s[], int num_nodes) {
    // Initialize variables
    int node_hashes[num_nodes];
    int i = 0;
    // Compute hash of each node's hash value
    while (i < num_nodes) {
        node_hashes[i] = hash(s[i]);
        i++;
    }
    i = 0;
    int hash = 0;
    // Combine node hash values
    while (i < num_nodes) {
        hash += node_hashes[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
        i++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    // Return final hash value
    return (hash & 0xFFFF);
}

int main() {
    // Test hash function
    char input[] = "Hello, world!";
    int h = hash(input);
    printf("Hash value of \"%s\": %d\n\n", input, h);

    // Test decentralized hash function with 3 nodes
    char nodes[3][20] = {"Node 1", "Node 2", "Node 3"};
    int dh = decentralized_hash(nodes, 3);
    printf("Decentralized hash value of nodes: %d\n", dh);

    return 0;
}