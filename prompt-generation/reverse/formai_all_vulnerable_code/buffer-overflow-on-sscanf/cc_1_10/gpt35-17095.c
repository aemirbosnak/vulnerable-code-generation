//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_KEY_LENGTH 10

struct record {
    char key[MAX_KEY_LENGTH];
    int value;
};

struct index_node {
    char key[MAX_KEY_LENGTH];
    int offset;
    struct index_node* next;
};

void add_to_index(struct index_node** index, char* key, int offset) {
    struct index_node* new_node = (struct index_node*)malloc(sizeof(struct index_node));
    strcpy(new_node->key, key);
    new_node->offset = offset;
    new_node->next = *index;
    *index = new_node;
}

void create_index(char* filename, struct index_node** index) {
    FILE* fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int offset = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        line[strcspn(line, "\r\n")] = 0; // remove newline
        struct record rec;
        sscanf(line, "%s %d", rec.key, &rec.value);
        add_to_index(index, rec.key, offset);
        offset = ftell(fp); // get offset of next line
    }

    fclose(fp);
}

void search_key(char* filename, struct index_node* index, char* key) {
    struct index_node* curr = index;
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            FILE* fp = fopen(filename, "r");
            fseek(fp, curr->offset, SEEK_SET);
            struct record rec;
            fscanf(fp, "%s %d", rec.key, &rec.value);
            printf("Found %s with value %d\n", rec.key, rec.value);
            fclose(fp);
            return;
        }
        curr = curr->next;
    }
    printf("Key %s not found\n", key);
}

int main() {
    struct index_node* index = NULL;
    create_index("data.txt", &index);
    search_key("data.txt", index, "abacus");
    search_key("data.txt", index, "banana");
    return 0;
}