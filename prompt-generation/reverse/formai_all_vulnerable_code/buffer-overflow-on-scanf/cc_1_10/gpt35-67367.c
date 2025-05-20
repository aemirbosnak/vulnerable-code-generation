//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 2097152 // 2MB

struct node {
    char data;
    struct node* next;
};

void append(struct node** head_ref, char new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void recover_data(char* filename) {
    FILE* fp;
    char ch, buffer[MAX_FILE_SIZE];
    int i = 0;
    struct node* head = NULL;

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        buffer[i] = ch;
        i++;
    }

    fclose(fp);

    for (int j = 0; j < i; j++) {
        append(&head, buffer[j]);
    }

    printf("\nRecovered Data:\n");

    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
}

int main() {
    char filename[50];
    printf("Enter file name to recover data from: ");
    scanf("%s", filename);
    recover_data(filename);

    return 0;
}