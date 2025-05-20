//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for storing indexed data
struct Index {
  int id;
  char name[20];
  float score;
};

//Binary Search Tree node
struct BSTnode {
  struct BSTnode *left;
  struct Index data;
  struct BSTnode *right;
};

// Function to create a new BST node
struct BSTnode* newBSTnode(struct Index data) {
  struct BSTnode* node = (struct BSTnode*)malloc(sizeof(struct BSTnode));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

// Function to insert data into the BST
void insertBST(struct BSTnode** root, struct Index data) {
  if (*root == NULL) {
    *root = newBSTnode(data);
    return;
  }
  if (data.id < (*root)->data.id)
    insertBST(&(*root)->left, data);
  else if (data.id > (*root)->data.id)
    insertBST(&(*root)->right, data);
}

//Function to search data in BST
struct BSTnode* searchBST(struct BSTnode* root, int id) {
  if (root == NULL || root->data.id == id)
    return root;
  if (root->data.id > id)
    return searchBST(root->left, id);
  return searchBST(root->right, id);
}

//Function to print data in BST in in-order traversal format
void printBST(struct BSTnode* root) {
  if (root != NULL) {
    printBST(root->left);
    printf("ID: %d\n", root->data.id);
    printf("Name: %s\n", root->data.name);
    printf("Score: %.2f\n", root->data.score);
    printf("\n");
    printBST(root->right);
  }
}

//Hash Table node
struct HashTableNode{
  struct Index data;
  struct HashTableNode *next;
};

//Function to create new Hash Table node
struct HashTableNode* newHTnode(int id, char name[], float score) {
  struct HashTableNode* node = (struct HashTableNode*)malloc(sizeof(struct HashTableNode));
  node->data.id = id;
  strcpy(node->data.name, name);
  node->data.score = score;
  node->next = NULL;
  return node;
}

//Function to generate hash value
int generateHash(int id, int numBuckets){
  return id % numBuckets;
}

//Function to insert data into Hash Table
void insertHT(struct HashTableNode** ht, int id, char name[], float score, int numBuckets) {
  int index = generateHash(id, numBuckets);
  struct HashTableNode* node = newHTnode(id, name, score);
  if(ht[index] == NULL){
    ht[index] = node;
  }
  else{
    struct HashTableNode* temp = ht[index];
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = node;
  }
}

//Function to search data in Hash Table
struct HashTableNode* searchHT(struct HashTableNode** ht, int id, int numBuckets) {
  int index = generateHash(id, numBuckets);
  struct HashTableNode* temp = ht[index];
  while(temp != NULL){
    if(temp->data.id == id){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

//Function to print data in Hash Table
void printHT(struct HashTableNode** ht, int numBuckets) {
  for(int i=0;i<numBuckets;i++){
    struct HashTableNode* temp = ht[i];
    while(temp != NULL){
      printf("ID: %d\n", temp->data.id);
      printf("Name: %s\n", temp->data.name);
      printf("Score: %.2f\n", temp->data.score);
      printf("\n");
      temp = temp->next;
    }
  }
}

//Main function
int main() {
  int n, id, choice;
  char name[20];
  float score;
  struct BSTnode* bstroot = NULL;
  struct HashTableNode* ht[10] = {NULL};
  printf("Enter the number of records you want to insert: ");
  scanf("%d", &n);
  printf("Enter the records:\n");
  for (int i = 0; i < n; i++) {
    printf("Record %d:\n", i+1);
    printf("ID: ");
    scanf("%d", &id);
    printf("Name: ");
    scanf("%s", name);
    printf("Score: ");
    scanf("%f", &score);
    struct Index data = {id, name, score};
    //Insert into BST
    insertBST(&bstroot, data);
    //Insert into Hash Table
    insertHT(ht, id, name, score, 10);
  }
  printf("Data inserted into the Binary Search Tree and Hash Table successfully!\n");
  do {
    printf("Choose an operation:\n");
    printf("1. Search for record\n");
    printf("2. Display all records in Binary Search Tree\n");
    printf("3. Display all records in Hash Table\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter the record ID to search: ");
        scanf("%d", &id);
        //Search in BST
        struct BSTnode* bstresult = searchBST(bstroot, id);
        if (bstresult == NULL) {
          printf("Record with ID %d not found in Binary Search Tree!\n", id);
        }
        else {
          printf("Record found in Binary Search Tree!\n");
          printf("ID: %d\n", bstresult->data.id);
          printf("Name: %s\n", bstresult->data.name);
          printf("Score: %.2f\n", bstresult->data.score);
          printf("\n");
        }
        //Search in Hash Table
        struct HashTableNode* htresult = searchHT(ht, id, 10);
        if (htresult == NULL) {
          printf("Record with ID %d not found in Hash Table!\n", id);
        }
        else {
          printf("Record found in Hash Table!\n");
          printf("ID: %d\n", htresult->data.id);
          printf("Name: %s\n", htresult->data.name);
          printf("Score: %.2f\n", htresult->data.score);
          printf("\n");
        }
        break;
      case 2:
        printf("Data in Binary Search Tree:\n");
        printBST(bstroot);
        break;
      case 3:
        printf("Data in Hash Table:\n");
        printHT(ht, 10);
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 4);
  return 0;
}