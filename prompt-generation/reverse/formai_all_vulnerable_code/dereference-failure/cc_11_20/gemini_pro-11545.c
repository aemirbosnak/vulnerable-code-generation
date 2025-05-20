//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
} node;

int cmp(const void *a, const void *b) {
    node *na = (node *)a;
    node *nb = (node *)b;
    return nb->count - na->count;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char buf[1024];
    int size = 0;
    int capacity = 0;
    node *nodes = NULL;

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        char *ptr = buf;
        while (*ptr != '\0') {
            if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t') {
                *ptr = '\0';
                ptr++;
                while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t') {
                    ptr++;
                }
                if (*ptr == '\0') {
                    break;
                }
            }
            char *word = ptr;
            while (*ptr != '\0' && *ptr != ' ' && *ptr != '\n' && *ptr != '\t') {
                ptr++;
            }
            int len = ptr - word;
            int found = 0;
            for (int i = 0; i < size; i++) {
                if (strlen(nodes[i].word) == len && strncmp(nodes[i].word, word, len) == 0) {
                    found = 1;
                    nodes[i].count++;
                    break;
                }
            }
            if (!found) {
                if (size == capacity) {
                    capacity = capacity * 2 + 1;
                    nodes = (node *)realloc(nodes, capacity * sizeof(node));
                }
                nodes[size].word = (char *)malloc(len + 1);
                memcpy(nodes[size].word, word, len);
                nodes[size].word[len] = '\0';
                nodes[size].count = 1;
                size++;
            }
        }
    }

    fclose(fp);

    qsort(nodes, size, sizeof(node), cmp);

    for (int i = 0; i < size; i++) {
        printf("%s %d\n", nodes[i].word, nodes[i].count);
        free(nodes[i].word);
    }

    free(nodes);

    return 0;
}