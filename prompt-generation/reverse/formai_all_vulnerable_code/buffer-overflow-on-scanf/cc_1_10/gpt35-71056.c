//FormAI DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a person
typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} Person;

// Structure to represent an index node
typedef struct _IndexNode {
    int key;
    int offset;
    struct _IndexNode* next;
} IndexNode;

// Function to read a person from the user
Person readPerson() {
    Person p;
    printf("Enter ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    return p;
}

// Function to print a person
void printPerson(Person p) {
    printf("ID: %d, Name: %s, Age: %d\n", p.id, p.name, p.age);
}

// Function to create a new index node
IndexNode* createIndexNode(int key, int offset) {
    IndexNode* node = (IndexNode*) malloc(sizeof(IndexNode));
    node->key = key;
    node->offset = offset;
    node->next = NULL;
    return node;
}

// Function to insert an index node into a linked list
void insertIndexNode(IndexNode** head, IndexNode* node) {
    if (*head == NULL) {
        *head = node;
    } else {
        IndexNode* current = *head;
        while (current->next != NULL && current->key <= node->key) {
            current = current->next;
        }
        if (current->key > node->key) {
            IndexNode* temp = current;
            current = node;
            node = temp;
        }
        current->next = node;
        node->next = NULL;
    }
}

// Function to create a new data file
void createDataFile(char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Cannot create data file!\n");
        return;
    }
    fclose(file);
}

// Function to create a new index file
void createIndexFile(char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Cannot create index file!\n");
        return;
    }
    fclose(file);
}

// Function to insert a person into the data file and index file
void insertPerson(char* dataFilename, char* indexFilename, Person p) {
    // Open data file
    FILE* dataFile = fopen(dataFilename, "ab");
    if (dataFile == NULL) {
        printf("Cannot open data file!\n");
        return;
    }

    // Write person to data file
    int offset = ftell(dataFile);
    fwrite(&p, sizeof(Person), 1, dataFile);

    // Close data file
    fclose(dataFile);

    // Open index file
    FILE* indexFile = fopen(indexFilename, "r+b");
    if (indexFile == NULL) {
        printf("Cannot open index file!\n");
        return;
    }

    // Read index nodes from index file
    IndexNode* head = NULL;
    IndexNode* node = NULL;
    while (1) {
        int key, offset;
        fread(&key, sizeof(int), 1, indexFile);
        if (feof(indexFile)) {
            break;
        }
        fread(&offset, sizeof(int), 1, indexFile);
        node = createIndexNode(key, offset);
        insertIndexNode(&head, node);
    }

    // Create new index node for person
    int key = p.id;
    node = createIndexNode(key, offset);
    insertIndexNode(&head, node);

    // Write updated index nodes to index file
    fseek(indexFile, 0, SEEK_SET);
    while (head != NULL) {
        fwrite(&head->key, sizeof(int), 1, indexFile);
        fwrite(&head->offset, sizeof(int), 1, indexFile);
        head = head->next;
    }

    // Close index file
    fclose(indexFile);
}

// Function to lookup a person in the data file and index file
Person lookupPerson(char* dataFilename, char* indexFilename, int id) {
    // Open index file
    FILE* indexFile = fopen(indexFilename, "rb");
    if (indexFile == NULL) {
        printf("Cannot open index file!\n");
        Person nullPerson = {-1, "", -1};
        return nullPerson;
    }

    // Read index nodes from index file into linked list
    IndexNode* head = NULL;
    IndexNode* node = NULL;
    while (1) {
        int key, offset;
        fread(&key, sizeof(int), 1, indexFile);
        if (feof(indexFile)) {
            break;
        }
        fread(&offset, sizeof(int), 1, indexFile);
        node = createIndexNode(key, offset);
        insertIndexNode(&head, node);
    }

    // Traverse linked list to find person
    Person p = {-1, "", -1};
    node = head;
    while (node != NULL) {
        if (node->key == id) {
            // Open data file and seek to offset for person
            FILE* dataFile = fopen(dataFilename, "rb");
            if (dataFile == NULL) {
                printf("Cannot open data file!\n");
                return p;
            }
            fseek(dataFile, node->offset, SEEK_SET);

            // Read person from data file
            fread(&p, sizeof(Person), 1, dataFile);

            // Close data file
            fclose(dataFile);

            break;
        }
        node = node->next;
    }

    // Close index file
    fclose(indexFile);

    return p;
}

int main() {
    char dataFilename[MAX_SIZE], indexFilename[MAX_SIZE];
    printf("Enter data filename: ");
    scanf("%s", dataFilename);
    printf("Enter index filename: ");
    scanf("%s", indexFilename);
    createDataFile(dataFilename);
    createIndexFile(indexFilename);
    int choice;
    do {
        printf("1. Insert Person\n");
        printf("2. Lookup Person\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                // Read person from user
                Person p = readPerson();
                // Insert person into data file and index file
                insertPerson(dataFilename, indexFilename, p);
                break;
            }
            case 2: {
                int id;
                printf("Enter ID to lookup: ");
                scanf("%d", &id);
                Person p = lookupPerson(dataFilename, indexFilename, id);
                if (p.id == -1) {
                    printf("Person not found!\n");
                } else {
                    printPerson(p);
                }
                break;
            }
            case 0: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (choice != 0);
    return 0;
}