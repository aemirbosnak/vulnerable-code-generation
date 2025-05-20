//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAX_NODES = 10,
};

int map[MAX_NODES][MAX_NODES] = {0};


typedef struct {
    int x, y;
} Point;

typedef struct {
    Point start;
    Point end;
} Link;

enum {
    SIZE_NODE = 16,
    NODE_CHAR = '$',
    SIZE_LINK = 12,
    LINK_CHAR = '=',
    SIZE_BLANK = 8,
};

void print_nodes() {
    printf("\n%c ", NODE_CHAR);
    for (int i = 0; i < MAX_NODES; ++i) {
        printf(" %*c ", SIZE_NODE-1, i+'A');
    }
    for (int i = 0; i < MAX_NODES; ++i) {
        printf("\n %*c ", SIZE_NODE, i+'A');
        for (int j = 0; j < MAX_NODES; ++j) {
            if (map[i][j]) {
                printf(" %*d ", SIZE_NODE-1, map[i][j]);
            } else {
                printf(" %*c ", SIZE_NODE-1, '-');
            }
        }
    }
}

void print_links() {
    printf("\n%c ", LINK_CHAR);
    for (int i = 0; i < MAX_NODES; ++i) {
        printf(" %*c ", SIZE_LINK-1, i+'A');
    }
    printf("\n");
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            if (map[i][j]) {
                printf(" %*d |", SIZE_LINK-1, map[i][j]);
            } else {
                printf(" %*s |", SIZE_LINK-1, "");
            }
        }
        printf(" %c", i+'A');
        printf("\n%c ", LINK_CHAR);
        for (int j = 0; j < MAX_NODES; ++j) {
            printf(" %*c ", SIZE_BLANK, "");
            if (j == MAX_NODES-1) {
                printf(" ");
            } else if (map[i][j]) {
                printf("\\%*s", SIZE_LINK-2, "");
            } else {
                printf(" %*c ", SIZE_LINK-1, "");
            }
        }
        printf("\n");
    }
    printf("%*c", SIZE_LINK+2, "");
    for (int i = 0; i < MAX_NODES-1; ++i) {
        printf("/%*s", SIZE_LINK-1, "");
    }
    printf("\n");
}

void parse_input(char *line, Link *link) {
    link->start.x = line[0]-'A';
    link->start.y = line[1]-'A';
    link->end.x = line[3]-'A';
    link->end.y = line[4]-'A';
}

void generate_map() {
    while (1) {
        printf("\nEnter a link (ex. A-B): ");
        char line[16];
        if (fgets(line, 16, stdin) == NULL) {
            printf("Error: invalid input\n");
            continue;
        }
        if (strcmp(line, "quit\n") == 0) {
            break;
        }
        Link link;
        parse_input(line, &link);
        map[link.start.x][link.start.y] = 1;
        map[link.start.y][link.start.x] = 1;
        map[link.end.x][link.end.y] = 1;
        map[link.end.y][link.end.x] = 1;
        print_links();
        print_nodes();
    }
}

int main() {
    printf("Welcome to Retro Network Topology Mapper!\n");
    generate_map();
    return 0;
}