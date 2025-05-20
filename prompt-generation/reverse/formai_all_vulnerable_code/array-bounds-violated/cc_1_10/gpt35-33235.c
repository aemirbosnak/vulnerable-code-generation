//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the maximum number of characters in the input string
#define MAX_CHARS 1000

// define the maximum number of unique characters in the input string
#define MAX_UNIQUE_CHARS 256

// define the Huffman tree node structure
typedef struct node {
    char data;
    int frequency;
    struct node* left;
    struct node* right;
} node;

// define the Huffman tree structure
typedef struct tree {
    node* root;
} tree;

// define the Huffman code structure
typedef struct code {
    char data;
    char* code;
} code;

// function to create a new Huffman node
node* new_node(char data, int frequency) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// function to create a new Huffman tree
tree* new_tree(node* root) {
    tree* new_tree = (tree*) malloc(sizeof(tree));
    new_tree->root = root;
    return new_tree;
}

// function to compare the frequency of two Huffman nodes
int compare_nodes(node* a, node* b) {
    return a->frequency > b->frequency;
}

// function to insert a new Huffman node into a priority queue
void insert_node(node** queue, int* queue_size, node* new_node) {
    int i = (*queue_size)++;
    while(i && compare_nodes(queue[(i - 1) / 2], new_node)) {
        queue[i] = queue[(i - 1) / 2];
        i = (i - 1) / 2; 
    }
    queue[i] = new_node;
}

// function to remove the Huffman node with the lowest frequency from a priority queue
node* remove_node(node** queue, int* queue_size) {
    int i, j;
    node* removed_node = queue[0];
    queue[0] = queue[--(*queue_size)];
    for(i = 0; i * 2 + 1 < (*queue_size); i = j) {
        j = i * 2 + 1;
        if(j + 1 < (*queue_size) && compare_nodes(queue[j], queue[j + 1])) {
            ++j;
        }
        if(compare_nodes(queue[j], queue[i])) {
            node* temp_node = queue[j];
            queue[j] = queue[i];
            queue[i] = temp_node;
        } else {
            break;
        }
    }
    return removed_node;
}

// recursive function to build the Huffman tree
node* build_tree(char* input_string, int* frequency_table, int* unique_chars) {
    node** queue = (node**) malloc(MAX_UNIQUE_CHARS * sizeof(node*));
    int queue_size = 0;
    int i;
    for(i = 0; i < 256; ++i) {
        if(frequency_table[i]) {
            insert_node(queue, &queue_size, new_node(i, frequency_table[i]));
            ++(*unique_chars);
        }
    }
    while(queue_size > 1) {
        node* left = remove_node(queue, &queue_size);
        node* right = remove_node(queue, &queue_size);
        insert_node(queue, &queue_size, new_node('\0', left->frequency + right->frequency));
        queue[queue_size - 1]->left = left;
        queue[queue_size - 1]->right = right;
    }
    node* root = remove_node(queue, &queue_size);
    free(queue);
    return root;
}

// recursive function to generate Huffman codes
void generate_codes(node* root, code* code_table, char* current_code) {
    if(root) {
        if(root->data != '\0') {
            code_table[root->data].data = root->data;
            code_table[root->data].code = (char*) malloc((strlen(current_code) + 1) * sizeof(char));
            strcpy(code_table[root->data].code, current_code);
        }
        char* left_code = (char*) malloc((strlen(current_code) + 2) * sizeof(char));
        strcpy(left_code, current_code);
        strcat(left_code, "0");
        generate_codes(root->left, code_table, left_code);
        free(left_code);
        char* right_code = (char*) malloc((strlen(current_code) + 2) * sizeof(char));
        strcpy(right_code, current_code);
        strcat(right_code, "1");
        generate_codes(root->right, code_table, right_code);
        free(right_code);
    }
}

// function to encode a string using Huffman codes
char* encode_string(char* input_string, code* code_table) {
    int input_size = strlen(input_string);
    int output_size = 0;
    int i;
    for(i = 0; i < input_size; ++i) {
        output_size += strlen(code_table[input_string[i]].code);
    }
    char* output_string = (char*) malloc((output_size + 1) * sizeof(char));
    int output_index = 0;
    for(i = 0; i < input_size; ++i) {
        char* code = code_table[input_string[i]].code;
        strcpy(output_string + output_index, code);
        output_index += strlen(code);
    }
    output_string[output_index] = '\0';
    return output_string;
}

// function to decode a string using Huffman codes
char* decode_string(char* input_string, node* root) {
    int input_size = strlen(input_string);
    char* output_string = (char*) malloc((input_size + 1) * sizeof(char));
    int output_index = 0;
    node* current_node = root;
    int i;
    for(i = 0; i < input_size; ++i) {
        if(input_string[i] == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
        if(!current_node->left && !current_node->right) {
            output_string[output_index++] = current_node->data;
            current_node = root;
        }
    }
    output_string[output_index] = '\0';
    return output_string;
}

// function to display the frequency table of the input string
void display_frequency_table(char* input_string, int* frequency_table) {
    int i;
    printf("Frequency Table:\n");
    for(i = 0; i < 256; ++i) {
        if(frequency_table[i]) {
            printf("%c: %d\n", i, frequency_table[i]);
        }
    }
}

int main() {
    char input_string[MAX_CHARS+1];
    int frequency_table[256] = {0};
    int unique_chars = 0;
    code code_table[MAX_UNIQUE_CHARS] = {0};
    node* root;
    printf("Enter the input string (maximum %d characters):\n", MAX_CHARS);
    fgets(input_string, MAX_CHARS+1, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';
    int input_size = strlen(input_string);
    int i;
    for(i = 0; i < input_size; ++i) {
        ++frequency_table[input_string[i]];
    }
    display_frequency_table(input_string, frequency_table);
    root = build_tree(input_string, frequency_table, &unique_chars);
    printf("Number of unique characters: %d\n", unique_chars);
    generate_codes(root, code_table, "");
    printf("Huffman Codes:\n");
    for(i = 0; i < 256; ++i) {
        if(code_table[i].code) {
            printf("%c: %s\n", code_table[i].data, code_table[i].code);
        }
    }
    char* output_string = encode_string(input_string, code_table);
    printf("Encoded String: %s\n", output_string);
    char* decoded_string = decode_string(output_string, root);
    printf("Decoded String: %s\n", decoded_string);
    free(output_string);
    free(decoded_string);
    for(i = 0; i < 256; ++i) {
        if(code_table[i].code) {
            free(code_table[i].code);
        }
    }
    return 0;
}