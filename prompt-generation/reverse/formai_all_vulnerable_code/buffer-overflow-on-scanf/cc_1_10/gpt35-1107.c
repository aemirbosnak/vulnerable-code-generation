//FormAI DATASET v1.0 Category: Compression algorithms ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node 
{
  char data;
  int freq;
  struct node* left;
  struct node* right;
}node;

typedef struct priority_queue
{
  int size;
  node** arr;
}priority_queue;

node* new_node(char data, int freq) //creating a new node with the given data and frequency
{
  node* new = (node*)malloc(sizeof(node));
  new->data = data;
  new->freq = freq;
  new->left = new->right = NULL;
  return new;
}

priority_queue* create_priority_queue(int capacity) //creating a priority queue of given capacity
{
  priority_queue* new = (priority_queue*)malloc(sizeof(priority_queue));
  new->size = 0;
  new->arr = (node**)malloc(capacity * sizeof(node*));
  return new;
}

void enqueue(priority_queue* pq, node* new) //to insert a new node in the priority queue and adjust it according to the frequency of the nodes.
{
  int i = ++pq->size;
  while(i != 1 && pq->arr[i/2]->freq > new->freq)
  {
    pq->arr[i] = pq->arr[i/2];
    i /= 2;
  }
  pq->arr[i] = new;
}

node* dequeue(priority_queue* pq) //to delete a node with highest priority(the node with the lowest frequency) from the priority queue
{
  if(pq->size == 0) return NULL;
  node* min = pq->arr[1];
  node* last = pq->arr[pq->size--];
  int i = 1, child = 2;
  while(child <= pq->size)
  {
    if(child < pq->size && pq->arr[child]->freq > pq->arr[child+1]->freq) child++;
    if(last->freq > pq->arr[child]->freq) pq->arr[i] = pq->arr[child];
    else break;
    i = child;
    child *= 2;
  }
  pq->arr[i] = last;
  return min;
}

int is_leaf(node* root) //check if the node is a leaf or not
{
  return (!(root->left) && !(root->right));
}

void print_codes(node* root, int arr[], int top) //generating Huffman codes for each character
{
  if(root->left)
  {
    arr[top] = 0;
    print_codes(root->left, arr, top+1);
  }

  if(root->right)
  {
    arr[top] = 1;
    print_codes(root->right, arr, top+1);
  }

  if(is_leaf(root))
  {
    printf("%c: ", root->data);
    for(int i=0; i<top; i++)
    {
      printf("%d", arr[i]);
    }
    printf("\n");
  }
}

void huffman(char data[], int freq[], int size) //main algorithm for Huffman coding
{
  node* left;
  node* right;
  node* top;
  int arr[size], top2=0;
  priority_queue* pq = create_priority_queue(size);
  for(int i=0; i<size; i++)
  {
    enqueue(pq, new_node(data[i], freq[i]));
  }

  while(pq->size != 1)
  {
    left = dequeue(pq);
    right = dequeue(pq);
    top = new_node('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    enqueue(pq, top);
  }
  print_codes(pq->arr[1], arr, top2);
}

int main()
{
  int size, i, freq[50];
  char data[50], temp;
  printf("Enter the number of characters (should be less than or equal to 50): ");
  scanf("%d", &size);
  printf("Enter the characters along with their frequencies: \n");
  for(i=0; i<size; i++)
  {
    printf("Enter the character: ");
    scanf(" %c", &data[i]);
    printf("Enter the frequency: ");
    scanf("%d", &freq[i]);
  }
  printf("Huffman Codes for given data:\n");
  huffman(data, freq, size);
  return 0;
}