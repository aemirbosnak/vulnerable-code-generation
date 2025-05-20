//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare structure for representing nodes in the Huffman tree
struct node {
  char data; //Character stored in the node
  int freq; //Frequency of the character in the text
  struct node *left, *right; //Pointers to the left and right child nodes
};

//Declare structure for heap (priority queue) used in the Huffman algorithm
struct heap_node {
  struct node *curr_node; //Pointer to the node stored in the heap node
  struct heap_node *next; //Pointer to the next heap node
};

//Create a new node with the specified character and frequency, and initialize its children to NULL
struct node* create_node(char data, int freq) {
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

//Create a new heap node with the specified node, and initialize the next pointer to NULL
struct heap_node* create_heap_node(struct node *curr_node) {
  struct heap_node* temp = (struct heap_node*) malloc(sizeof(struct heap_node));
  temp->curr_node = curr_node;
  temp->next = NULL;
  return temp;
}

//Insert a new heap node into the heap so that the heap remains ordered by frequency
void insert_heap_node(struct heap_node **head, struct heap_node *new_node) {
  if (*head == NULL || (*head)->curr_node->freq >= new_node->curr_node->freq) {
    new_node->next = *head;
    *head = new_node;
  } else {
    struct heap_node *curr_node = *head;
    while (curr_node->next != NULL && curr_node->next->curr_node->freq < new_node->curr_node->freq) {
      curr_node = curr_node->next;
    }
    new_node->next = curr_node->next;
    curr_node->next = new_node;
  }
}

//Remove the heap node with the lowest frequency from the heap and return its pointer
struct heap_node* remove_min(struct heap_node **head) {
  struct heap_node *min_node = *head;
  *head = (*head)->next;
  min_node->next = NULL;
  return min_node;
}

//Build a Huffman tree from the specified text
struct node* build_huff_tree(char *text) {
  int freq[256] = {0};
  for (int i = 0; text[i] != '\0'; i++) {
    freq[(int) text[i]]++;
  }
  struct heap_node *heap = NULL;
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      struct node *new_node = create_node((char) i, freq[i]);
      insert_heap_node(&heap, create_heap_node(new_node));
    }
  }
  while (heap->next != NULL) {
    struct node *new_node = create_node('\0', 0);
    new_node->left = remove_min(&heap)->curr_node;
    new_node->right = remove_min(&heap)->curr_node;
    new_node->freq = new_node->left->freq + new_node->right->freq;
    insert_heap_node(&heap, create_heap_node(new_node));
  }
  return remove_min(&heap)->curr_node;
}

//Recursively traverse the Huffman tree and generate a lookup table of codes for each character
void generate_codes(struct node *curr_node, char *code, char **codes) {
  if (curr_node == NULL) {
    return;
  }
  if (curr_node->left == NULL && curr_node->right == NULL) {
    codes[(int) curr_node->data] = (char*) malloc(sizeof(char) * (strlen(code) + 1));
    strcpy(codes[(int) curr_node->data], code);
    return;
  }
  char *left_code = (char*) malloc(sizeof(char) * (strlen(code) + 2));
  sprintf(left_code, "%s%s", code, "0");
  generate_codes(curr_node->left, left_code, codes);
  char *right_code = (char*) malloc(sizeof(char) * (strlen(code) + 2));
  sprintf(right_code, "%s%s", code, "1");
  generate_codes(curr_node->right, right_code, codes);
}

//Encode the specified text into Huffman code using the codes lookup table
char* encode_text(char *text, char **codes) {
  int len = strlen(text);
  char *encoded_text = (char*) malloc(sizeof(char) * (len * 10)); //Assume maximum size of encoded text is 10 times input text
  encoded_text[0] = '\0';
  for (int i = 0; text[i] != '\0'; i++) {
    strcat(encoded_text, codes[(int) text[i]]);
  }
  return encoded_text;
}

int main() {
  char text[1000];
  printf("Enter text to be encoded:\n");
  fgets(text, 1000, stdin);
  text[strcspn(text, "\n")] = '\0'; //Remove newline character from input
  
  struct node *root = build_huff_tree(text);
  char **codes = (char**) malloc(sizeof(char*) * 256);
  generate_codes(root, "", codes);
  
  printf("Huffman codes for each character:\n");
  for (int i = 0; i < 256; i++) {
    if (codes[i] != NULL) {
      printf("%c: %s\n", (char) i, codes[i]);
    }
  }
  
  char *encoded_text = encode_text(text, codes);
  printf("Encoded text:\n%s\n", encoded_text);
  
  return 0;
}