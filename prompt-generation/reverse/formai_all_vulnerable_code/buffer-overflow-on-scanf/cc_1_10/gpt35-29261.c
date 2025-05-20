//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: peaceful
/* Huffman Coding Implementation in C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_HEAP_SIZE 100
#define MAX_SYMB 256

/* Structure for a Huffman node */
typedef struct min_heap_node {
  char data;
  unsigned freq;
  struct min_heap_node *left, *right;
} min_heap_node;

/* Structure for a min heap */
typedef struct min_heap {
  unsigned size;
  unsigned capacity;
  min_heap_node **array;
} min_heap;

/* Huffman Tree structure */
typedef struct Huffman_Tree {
  min_heap_node* root;
} Huffman_Tree;

/* Function to allocate a new min heap node */
min_heap_node* new_min_heap_node(char data, unsigned freq) {
  min_heap_node* node =
              (min_heap_node*) malloc(sizeof(min_heap_node));
  node->left = node->right = NULL;
  node->data = data;
  node->freq = freq;
  return node;
}

/* Function to create a new min heap */
min_heap* create_min_heap(unsigned capacity) {
  min_heap* heap =
             (min_heap*) malloc(sizeof(min_heap));
  heap->size = 0;
  heap->capacity = capacity;
  heap->array =
          (min_heap_node**) malloc(heap->capacity * sizeof(min_heap_node*));
  return heap;
}

/* Function to swap two min heap nodes */
void swap_min_heap_nodes(min_heap_node** a, min_heap_node** b) {
  min_heap_node* t = *a;
  *a = *b;
  *b = t;
}

/* Function to heapify a subtree */
void min_heapify(min_heap* heap, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
    smallest = left;
  if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
    smallest = right;
  if (smallest != index) {
    swap_min_heap_nodes(&heap->array[smallest], &heap->array[index]);
    min_heapify(heap, smallest);
  }
}

/* Function to check if a node is a leaf node */
int is_leaf_node(min_heap_node* node) {
  return !(node->left) && !(node->right);
}

/* Function to create a new min heap node */
min_heap* build_min_heap(char data[], int freq[], int size) {
  min_heap* heap = create_min_heap(size);
  for (int i = 0; i < size; ++i)
    heap->array[i] = new_min_heap_node(data[i], freq[i]);
  heap->size = size;
  for (int i = size / 2 - 1; i >= 0; --i)
    min_heapify(heap, i);
  return heap;
} 

/* Function to extract the minimum element from the min heap */
min_heap_node* extract_min_heap_node(min_heap* heap) {
  min_heap_node* node = heap->array[0];
  heap->array[0] = heap->array[heap->size - 1];
  --heap->size;
  min_heapify(heap, 0);
  return node;
}

/* Function to insert a new node to the min heap */
void insert_min_heap_node(min_heap* heap, min_heap_node* node) {
  ++heap->size;
  int i = heap->size - 1;
  while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
    heap->array[i] = heap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  heap->array[i] = node;
}

/* Function to build Huffman min heap tree */
min_heap* build_huffman_min_heap_tree(char data[], int freq[], int size) {
  min_heap_node *left, *right, *top;
  min_heap* heap = build_min_heap(data, freq, size);

  while (heap->size != 1) {
    left = extract_min_heap_node(heap);
    right = extract_min_heap_node(heap);
    top = new_min_heap_node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insert_min_heap_node(heap, top);
  }
  return heap;
}

/* Function to print Huffman codes from the root of the Huffman tree */
void print_huffman_codes(min_heap_node* root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    print_huffman_codes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    print_huffman_codes(root->right, arr, top + 1);
  }
  if (is_leaf_node(root)) {
    printf("%c: ", root->data);
    for (int i = 0; i < top; ++i)
      printf("%d", arr[i]);
    printf("\n");
  }
}

/* Function to generate Huffman codes */
void generate_huffman_codes(char data[], int freq[], int size) {
  min_heap* heap = build_huffman_min_heap_tree(data, freq, size);

  int arr[MAX_SYMB], top = 0;
  print_huffman_codes(heap->array[0], arr, top);
}

/* Main Function */
int main() {
  int size;
  char data[MAX_SYMB];
  int freq[MAX_SYMB];
  
  printf("Enter number of symbols : ");
  scanf("%d", &size);

  for (int i = 0; i < size; ++i) {
    printf("Enter symbol %d : ", i + 1);
    scanf("\n%c", &data[i]);
    printf("Enter frequency for symbol %d : ", i + 1);
    scanf("%d", &freq[i]);
  }

  generate_huffman_codes(data, freq, size);

  return 0;
}