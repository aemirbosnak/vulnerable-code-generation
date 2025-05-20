//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define maximum length of input string and output buffer. 
#define MAX_LEN 1000000

// Define a structure representing a Huffman Tree Node.
struct node
{
    char ch;
    int freq;
    struct node *left, *right;
};

// Define a structure representing the frequency table entries.
struct freq_table
{
    char ch;
    int freq;
};

// Utility function to swap integers.
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Utility function to swap character pointers.
void swap_char(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Utility function to swap frequency table entries.
void swap_ft(struct freq_table *a, struct freq_table *b)
{
    struct freq_table temp = *a;
    *a = *b;
    *b = temp;
}

// Utility function to convert an integer into a string.
char *int_to_str(int num)
{
    char *str = malloc(12);
    sprintf(str, "%d", num);
    return str;
}

// Utility function to allocate a new Huffman tree node.
struct node* new_node(char ch, int freq)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));

    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;

    return node;
}

// Utility function to calculate the frequency of each character in the input string.
struct freq_table* calc_freq(char *input, int *size)
{
    struct freq_table *ft = malloc(sizeof(struct freq_table) * 256);
    memset(ft, 0, sizeof(struct freq_table) * 256);
    int i = 0;
    while(input[i] != '\0')
    {
        ft[(int)input[i]].ch = input[i];
        ft[(int)input[i]].freq++;
        i++;
    }
    *size = i;
    return ft;
}

// Utility function to build a Huffman tree based on the frequency table.
struct node* build_huff_tree(struct freq_table *ft, int size)
{
    struct node **heap = malloc(sizeof(struct node*) * size);
    int heap_size = 0;
    for(int i = 0; i < 256; i++)
    {
        if(ft[i].freq > 0)
        {
            heap[heap_size++] = new_node(ft[i].ch, ft[i].freq);
        }
    }

    for(int i = (heap_size - 2) / 2; i >= 0; i--)
    {
        int j = i, min = 0;
        while(2 * j + 1 < heap_size)
        {
            if(2 * j + 2 == heap_size || heap[2 * j + 1]->freq <= heap[2 * j + 2]->freq)
            {
                min = 2 * j + 1;
            }
            else
            {
                min = 2 * j + 2;
            }

            if(heap[j]->freq > heap[min]->freq)
            {
                swap_int(&heap[j]->freq, &heap[min]->freq);
                swap_char(&heap[j]->ch, &heap[min]->ch);
                swap_int((int**)&heap[j], (int**)&heap[min]);
                j = min;
            }
            else
            {
                break;
            }
        }
    }

    while(heap_size > 1)
    {
        struct node *left = heap[0];
        swap_int(&heap[0]->freq, &heap[heap_size-1]->freq);
        swap_char(&heap[0]->ch, &heap[heap_size-1]->ch);
        swap_int((int**)&heap[0], (int**)&heap[heap_size-1]);
        heap_size--;

        int j = 0, min = 0;
        while(2 * j + 1 < heap_size)
        {
            if(2 * j + 2 == heap_size || heap[2 * j + 1]->freq <= heap[2 * j + 2]->freq)
            {
                min = 2 * j + 1;
            }
            else
            {
                min = 2 * j + 2;
            }

            if(heap[j]->freq > heap[min]->freq)
            {
                swap_int(&heap[j]->freq, &heap[min]->freq);
                swap_char(&heap[j]->ch, &heap[min]->ch);
                swap_int((int**)&heap[j], (int**)&heap[min]);
                j = min;
            }
            else
            {
                break;
            }
        }

        struct node *right = heap[0];
        swap_int(&heap[0]->freq, &heap[heap_size-1]->freq);
        swap_char(&heap[0]->ch, &heap[heap_size-1]->ch);
        swap_int((int**)&heap[0], (int**)&heap[heap_size-1]);
        heap_size--;

        int k = 0, min2 = 0;
        while(2 * k + 1 < heap_size)
        {
            if(2 * k + 2 == heap_size || heap[2 * k + 1]->freq <= heap[2 * k + 2]->freq)
            {
                min2 = 2 * k + 1;
            }
            else
            {
                min2 = 2 * k + 2;
            }

            if(heap[k]->freq > heap[min2]->freq)
            {
                swap_int(&heap[k]->freq, &heap[min2]->freq);
                swap_char(&heap[k]->ch, &heap[min2]->ch);
                swap_int((int**)&heap[k], (int**)&heap[min2]);
                k = min2;
            }
            else
            {
                break;
            }
        }

        struct node *parent = new_node('*', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        heap[heap_size++] = parent;
        int j2 = heap_size - 1;

        while(j2 > 0 && heap[(j2-1)/2]->freq > heap[j2]->freq)
        {
            swap_int(&heap[j2]->freq, &heap[(j2-1)/2]->freq);
            swap_char(&heap[j2]->ch, &heap[(j2-1)/2]->ch);
            swap_int((int**)&heap[j2], (int**)&heap[(j2-1)/2]);
            j2 = (j2-1)/2;
        }
    }

    struct node* root = heap[0];
    free(heap);
    return root;
}

// Utility function to recursively build Huffman codes for each character in the tree.
void build_codes(struct node* root, char *code, int depth, char **codes)
{
    if(root->left == NULL && root->right == NULL)
    {
        code[depth] = '\0';
        codes[(int)root->ch] = strdup(code);
    }
    else
    {
        if(root->left != NULL)
        {
            code[depth] = '0';
            build_codes(root->left, code, depth+1, codes);
        }

        if(root->right != NULL)
        {
            code[depth] = '1';
            build_codes(root->right, code, depth+1, codes);
        }
    }
}

// Utility function to encode the input string using Huffman codes.
char *huffman_encode(char *input)
{
    int size;
    struct freq_table *ft = calc_freq(input, &size);
    struct node* root = build_huff_tree(ft, size);
    char *codes[256];
    char code[256];
    memset(code, 0, sizeof(code));
    memset(codes, 0, sizeof(codes));
    build_codes(root, code, 0, codes);

    char *output = malloc((size + 1) * sizeof(char));
    memset(output, 0, (size + 1) * sizeof(char));
    int opos = 0;
    for(int i = 0; i < size; i++)
    {
        strcat(output, codes[(int)input[i]]);
    }

    free(root);
    for(int i = 0; i < 256; i++)
    {
        if(codes[i]!= NULL)
        {
            free(codes[i]);
        }
    }
    free(ft);

    return output;
}

// Utility function to decode the Huffman encoded string.
char *huffman_decode(char *input)
{
    char *output = malloc(MAX_LEN * sizeof(char));
    output[0] = '\0';
    int i = 0;
    struct node* root = new_node('*', 0);
    while(input[i] != '\0')
    {
        struct node* current = root;
        while(current->left != NULL && current->right != NULL && input[i] != '\0')
        {
            if(input[i] == '0')
            {
                current = current->left;
            }
            else if(input[i] == '1')
            {
                current = current->right;
            }
            i++;
        }

        if(current->left == NULL && current->right == NULL)
        {
            strncat(output, &current->ch, 1);
        }
        else
        {
            break;
        }
    }

    free(root);
    return output;
}

int main()
{
    char input[MAX_LEN];
    printf("Enter the input string: ");
    scanf("%[^\n]s", input);
    getchar(); // Clear the input buffer.

    char *encoded = huffman_encode(input);
    printf("Encoded string: %s\n", encoded);

    char *decoded = huffman_decode(encoded);
    printf("Decoded string: %s\n", decoded);

    free(encoded);
    free(decoded);

    return 0;
}