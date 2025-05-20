//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 255

typedef struct Node {
    char *identifier;
    struct Node *next;
} Node;

Node *parse_c_syntax(char *source) {
    Node *head = NULL;
    char *p = source;
    char identifier[MAX_IDENTIFIER_LENGTH];

    while (*p) {
        switch (*p) {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                identifier[0] = *p;
                identifier[1] = '\0';
                Node *newNode = malloc(sizeof(Node));
                newNode->identifier = strdup(identifier);
                newNode->next = head;
                head = newNode;
                break;
            default:
                break;
        }
        p++;
    }

    return head;
}

int main() {
    char *source = "int main() { printf(\"Hello, world!\"); }";
    Node *head = parse_c_syntax(source);

    for (Node *node = head; node; node = node->next) {
        printf("%s\n", node->identifier);
    }

    return 0;
}