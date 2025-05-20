//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char keyword[15];
    int lineNo;
    struct Node* next;
};

void parseSyntax(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    char line[256];
    int lineNo = 1;
    struct Node* head = NULL;
    struct Node* temp = NULL;
    while (fgets(line, sizeof(line), fp)) {
        char* tok = strtok(line, " ");
        while (tok != NULL) {
            if (strcmp(tok, "int") == 0 || strcmp(tok, "float") == 0 || strcmp(tok, "char") == 0 || strcmp(tok, "double") == 0) {
                if (head == NULL) {
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    strcpy(newNode->keyword, tok);
                    newNode->lineNo = lineNo;
                    newNode->next = NULL;
                    head = newNode;
                    temp = head;
                } else {
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    strcpy(newNode->keyword, tok);
                    newNode->lineNo = lineNo;
                    newNode->next = NULL;
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            tok = strtok(NULL, " ");
        }
        lineNo++;
    }
    fclose(fp);
    temp = head;
    printf("Data Types:\n");
    while (temp != NULL) {
        printf("%s | Line %d\n", temp->keyword, temp->lineNo);
        struct Node* delNode = temp;
        temp = temp->next;
        free(delNode);
    }
}

int main() {
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);
    parseSyntax(filename);
    return 0;
}