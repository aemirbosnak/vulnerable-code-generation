//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000

struct node {
    int data;
    struct node* next;
};

void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char filename[20];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found\n");
        exit(0);
    }
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*) malloc(filesize * sizeof(char));
    fread(buffer, sizeof(char), filesize, file);
    fclose(file);
    int key = rand() % 26 + 'a';
    printf("Enter the key: ");
    scanf(" %c", &key);
    int i;
    for (i = 0; i < filesize; i++) {
        if (isalpha(buffer[i])) {
            if (isupper(buffer[i])) {
                buffer[i] = key + (buffer[i] - 'A');
            } else {
                buffer[i] = key + (buffer[i] - 'a');
            }
        } else {
            buffer[i] = buffer[i];
        }
    }
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("File not found\n");
        exit(0);
    }
    fwrite(buffer, sizeof(char), filesize, file);
    fclose(file);
    printf("File encrypted successfully\n");
    return 0;
}