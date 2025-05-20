//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int value;
    struct node *next;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct node *appendNode(struct node *head, int value) {
    struct node *newNode = createNode(value);
    struct node *temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    FILE *fp;
    char filename[20];
    int i, j, k, value, mask, pos;
    struct node *head = NULL;
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = (char *)malloc(size + 1);
    fread(buffer, size, 1, fp);
    fclose(fp);
    for (i = 0; i < size; i++) {
        if (buffer[i] == '\n') {
            continue;
        }
        if (buffer[i] == '1') {
            for (j = i - 1; j >= 0 && buffer[j] == '1'; j--) {
                value = 0;
                mask = 1;
                for (k = j; k <= i; k++) {
                    if (buffer[k] == '1') {
                        value += mask;
                    }
                    mask <<= 1;
                }
                head = appendNode(head, value);
            }
        }
    }
    printList(head);
    return 0;
}