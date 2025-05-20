//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct Node Node;
struct Node {
    char data;
    Node* next;
};

Node* head = NULL;

void displayData(char* filedata, long size) {
    printf("Recovered Data from file:\n");
    for (int i = 0; i < size; i++) {
        printf("%c", filedata[i]);
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->data = filedata[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }
    printf("\n\n");
}

void writeToFile(char* filename) {
    FILE* fp;
    fp = fopen(filename, "w");

    Node* temp = head;
    while (temp != NULL) {
        fprintf(fp, "%c", temp->data);
        temp = temp->next;
    }

    fclose(fp);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char filedata[MAX_FILE_SIZE];

    printf("Enter filename to recover: ");
    scanf("%s", filename);

    FILE* fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File does not exist\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    fread(filedata, sizeof(char), size, fp);

    fclose(fp);

    displayData(filedata, size);

    printf("Enter filename to save recovered data: ");
    scanf("%s", filename);

    writeToFile(filename);

    printf("Data successfully recovered and saved to %s\n", filename);

    return 0;
}