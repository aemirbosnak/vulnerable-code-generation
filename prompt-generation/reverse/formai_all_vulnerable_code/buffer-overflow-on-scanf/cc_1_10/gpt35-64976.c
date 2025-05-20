//FormAI DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_PHONE_LEN 20

struct person {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
};

struct index {
    char key[MAX_NAME_LEN];
    int offset;
};

struct index_node {
    struct index id;
    struct index_node *left;
    struct index_node *right;
};

struct index_tree {
    struct index_node *root;
};

void insert_index(struct index_tree *tree, struct index_node **node, struct index id, int offset) {
    if(*node == NULL) {
        *node = (struct index_node*)malloc(sizeof(struct index_node));
        (*node)->id = id;
        (*node)->id.offset = offset;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    else if(strcmp(id.key, (*node)->id.key) < 0) {
        insert_index(tree, &(*node)->left, id, offset);
    }
    else {
        insert_index(tree, &(*node)->right, id, offset);
    }
}

struct index_node* search_index(struct index_tree *tree, char *key) {
    struct index_node *current = tree->root;

    while(current != NULL) {
        if(strcmp(key, current->id.key) == 0) {
            return current;
        }
        else if(strcmp(key, current->id.key) < 0) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return NULL;
}

void init_db(char *filename) {
    FILE *fp;
    struct person p;

    fp = fopen(filename, "wb");

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    memset(&p, 0, sizeof(struct person));
    fwrite(&p, sizeof(struct person), 1, fp);

    fclose(fp);
}

void add_person(char *filename, struct index_tree *tree) {
    FILE *fp;
    struct person p;
    struct index id;

    fp = fopen(filename, "r+b");

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    id.offset = ftell(fp) / sizeof(struct person);

    printf("Enter name: ");
    scanf("%s", p.name);
    printf("Enter address: ");
    scanf("%s", p.address);
    printf("Enter phone: ");
    scanf("%s", p.phone);

    fwrite(&p, sizeof(struct person), 1, fp);

    memcpy(id.key, p.name, MAX_NAME_LEN);
    insert_index(tree, &tree->root, id, id.offset);

    fclose(fp);
}

void search_person(char *filename, struct index_tree *tree) {
    char name[MAX_NAME_LEN];
    struct index_node *node;
    struct person p;
    FILE *fp;

    printf("Enter name: ");
    scanf("%s", name);

    node = search_index(tree, name);

    if(node == NULL) {
        printf("Person not found\n");
        return;
    }

    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, node->id.offset * sizeof(struct person), SEEK_SET);
    fread(&p, sizeof(struct person), 1, fp);
    printf("Name: %s\nAddress: %s\nPhone:%s\n", p.name, p.address, p.phone);

    fclose(fp);
}

int main() {
    struct index_tree tree = {NULL};
    int choice;

    init_db("database.dat");

    do {
        printf("\n1. Add person\n");
        printf("2. Search person\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_person("database.dat", &tree);
                break;
            case 2:
                search_person("database.dat", &tree);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 3);

    return 0;
}