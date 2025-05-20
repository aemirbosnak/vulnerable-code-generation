//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINKS 100
#define MAX_CITY_NAME 100
#define MAX_LINK_NAME 100

typedef struct {
    char name[MAX_CITY_NAME];
    int x;
    int y;
} City;

typedef struct {
    char name[MAX_LINK_NAME];
    int start;
    int end;
    int cost;
} Link;

int num_nodes, num_links;
City nodes[MAX_NODES];
Link links[MAX_LINKS];

void read_nodes(FILE *fp) {
    char line[MAX_CITY_NAME];
    while (fgets(line, MAX_CITY_NAME, fp)!= NULL) {
        strcpy(nodes[num_nodes].name, line);
        sscanf(line, "%s %d %d", nodes[num_nodes].name, &nodes[num_nodes].x, &nodes[num_nodes].y);
        num_nodes++;
    }
}

void read_links(FILE *fp) {
    char line[MAX_LINK_NAME];
    while (fgets(line, MAX_LINK_NAME, fp)!= NULL) {
        strcpy(links[num_links].name, line);
        sscanf(line, "%s %d %d %d", links[num_links].name, &links[num_links].start, &links[num_links].end, &links[num_links].cost);
        num_links++;
    }
}

int main() {
    FILE *fp;
    fp = fopen("network.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    read_nodes(fp);
    read_links(fp);
    
    fclose(fp);
    
    // Do something with the network data
    
    return 0;
}