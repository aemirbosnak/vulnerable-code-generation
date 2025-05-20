//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char ch; 
    int freq; 
    struct Node *left_child, *right_child; 
}Node;

void display_huffman_tree(Node *root, int gap){
    if (root == NULL){
        return;
    }
    gap += 10; 
    display_huffman_tree(root->right_child, gap); 
    printf("\n");
    for (int i = 10; i < gap; i++){
        printf(" "); 
    }
    printf("%c:%d\n", root->ch, root->freq);
    display_huffman_tree(root->left_child, gap); 
}

Node *create_node(char ch, int freq){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

Node *create_huffman_tree(char *str){
    Node *heap[1000];
    memset(heap, 0, sizeof(heap));
    int heap_size = 0, freq_alphabets[1000];
    memset(freq_alphabets, 0, sizeof(freq_alphabets));
    int str_size = strlen(str);
    for (int i = 0; i < str_size; i++){
        freq_alphabets[(int)str[i]]++;
    }
    for (int i = 0; i < 1000; i++){
        if (freq_alphabets[i] != 0){
            heap[heap_size] = create_node(i, freq_alphabets[i]);
            heap_size++;
        }
    }
    while (heap_size != 1){
        Node *left = heap[heap_size - 1]; 
        Node *right = heap[heap_size - 2]; 
        int freq = left->freq + right->freq; 
        Node *new_node = create_node('X', freq);
        new_node->left_child = left;
        new_node->right_child = right;
        heap_size--;
        heap[heap_size - 1] = new_node;
        for (int i = heap_size - 1; i > 0; i--){
            if (heap[i]->freq > heap[i - 1]->freq){
                Node *temp = heap[i - 1];
                heap[i - 1] = heap[i];
                heap[i] = temp;
            }
            else{
                break;
            }
        }
    }
    return heap[0];
}

void encode(Node *root, char *code, char ch, FILE *output_file){
    if (root == NULL){
        return;
    }
    if (root->ch == ch){
        fprintf(output_file, "%s", code);
        return;
    }
    int len = strlen(code);
    char temp_code[100];
    strcpy(temp_code, code);
    if (root->left_child != NULL){
        temp_code[len] = '0';
        temp_code[len + 1] = '\0';
        encode(root->left_child, temp_code, ch, output_file);
    }
    if (root->right_child != NULL){
        code[len] = '1';
        code[len + 1] = '\0';
        encode(root->right_child, code, ch, output_file);
    }
}

void huffman_encoding(char *input_file_name, char *output_file_name, Node *root){
    FILE *input_file = fopen(input_file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");
    fseek(input_file, 0, SEEK_END);
    int len = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    char *str = (char*)malloc((len + 1) * sizeof(char));
    memset(str, '\0', sizeof(str));
    fread(str, len, 1, input_file);
    for (int i = 0; i < len; i++){
        char code[100];
        memset(code, '\0', sizeof(code));
        encode(root, code, str[i], output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main(){
    char input_file_name[100], output_file_name[100];
    memset(input_file_name, '\0', sizeof(input_file_name));
    memset(output_file_name, '\0', sizeof(output_file_name));
    printf("Welcome to the Huffman Coding program!\n");
    printf("\n");
    printf("This program takes a text file and encodes it using the Huffman Coding algorithm.\n");
    printf("\n");
    printf("Please enter the file name you wish to encode: ");
    scanf("%s", input_file_name);
    printf("Please enter the name of the output file: ");
    scanf("%s", output_file_name);
    printf("\n");
    printf("Creating Huffman Tree...\n");
    Node *root = create_huffman_tree(input_file_name);
    printf("Huffman Tree created.\n");
    printf("\n");
    printf("Displaying Huffman Tree:\n");
    display_huffman_tree(root, 0);
    printf("\n");
    printf("Encoding file...\n");
    huffman_encoding(input_file_name, output_file_name, root);
    printf("%s encoded successfully and saved as %s.\n", input_file_name, output_file_name);
    printf("\n");
    printf("Thank you for using the Huffman Coding program!\n");
    return 0;
}