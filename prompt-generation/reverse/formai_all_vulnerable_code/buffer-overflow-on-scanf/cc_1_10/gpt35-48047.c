//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing symbol and its count in frequency table
typedef struct symbol_freq{
    char symbol;
    int freq;
} Symbol_Freq;

// Define a structure for storing huffman tree node
typedef struct huffman_node{
    char symbol;
    int freq;
    struct huffman_node* left_child;
    struct huffman_node* right_child;
} Huffman_Node;

// Define a function for comparing frequencies for sorting frequency table 
int compare_freq(const void* a, const void* b){
    Symbol_Freq* symbol_freq_a = (Symbol_Freq*)a;
    Symbol_Freq* symbol_freq_b = (Symbol_Freq*)b;
    return symbol_freq_a->freq - symbol_freq_b->freq;
}

// Define a recursive function to traverse huffman tree and generate codes
void generate_codes(Huffman_Node* node, char* code, int depth, char** codes){
    if(node->left_child == NULL && node->right_child == NULL){ // leaf node
        code[depth] = '\0';
        codes[node->symbol] = strdup(code);
        return;
    }
    code[depth] = '0';
    generate_codes(node->left_child, code, depth+1, codes);
    code[depth] = '1';
    generate_codes(node->right_child, code, depth+1, codes);
}

int main(){
    char input_string[1000];
    printf("Enter string to compress: ");
    scanf("%[^\n]s", input_string);
    int freq_table[256] = {0}; // initialize frequency table with all zeros
    for(int i=0; i<strlen(input_string); i++){
        freq_table[(int)input_string[i]]++; // increment count for corresponding symbol in frequency table
    }
    int total_symbols = 0;
    Symbol_Freq* symbol_freq_table = (Symbol_Freq*)malloc(sizeof(Symbol_Freq)*256); // allocate memory for symbol frequency table
    for(int i=0; i<256; i++){
        if(freq_table[i] > 0){
            symbol_freq_table[total_symbols].symbol = (char)i;
            symbol_freq_table[total_symbols].freq = freq_table[i];
            total_symbols++;
        }
    }
    qsort(symbol_freq_table, total_symbols, sizeof(Symbol_Freq), compare_freq); // sort symbol frequency table
    Huffman_Node* huffman_tree = (Huffman_Node*)malloc(sizeof(Huffman_Node)*total_symbols*2-1); // allocate memory for huffman tree
    for(int i=0; i<total_symbols; i++){ // initialize leaf nodes of huffman tree from symbol frequency table
        huffman_tree[i].symbol = symbol_freq_table[i].symbol;
        huffman_tree[i].freq = symbol_freq_table[i].freq;
        huffman_tree[i].left_child = NULL;
        huffman_tree[i].right_child = NULL;
    }
    int next_index = total_symbols;
    while(next_index < total_symbols*2-1){ // build huffman tree
        Huffman_Node* left_child = &huffman_tree[0];
        Huffman_Node* right_child = &huffman_tree[1];
        int left_index = 0;
        int right_index = 1;
        for(int i=2; i<next_index; i++){
            if(huffman_tree[i].freq < left_child->freq){
                right_child = left_child;
                right_index = left_index;
                left_child = &huffman_tree[i];
                left_index = i;
            }
            else if(huffman_tree[i].freq < right_child->freq){
                right_child = &huffman_tree[i];
                right_index = i;
            }
        }
        huffman_tree[next_index].symbol = '\0';
        huffman_tree[next_index].freq = left_child->freq + right_child->freq;
        huffman_tree[next_index].left_child = left_child;
        huffman_tree[next_index].right_child = right_child;
        next_index++;
        if(right_index != next_index-1){
            Huffman_Node temp = huffman_tree[right_index];
            huffman_tree[right_index] = huffman_tree[next_index-1];
            huffman_tree[next_index-1] = temp; 
        }
        if(left_index != next_index-2 && left_index != next_index-1){
            Huffman_Node temp = huffman_tree[left_index];
            huffman_tree[left_index] = huffman_tree[next_index-2];
            huffman_tree[next_index-2] = temp;
        }
    }
    char* codes[256] = {NULL}; // allocate memory for codes
    char code[256] = {0}; // initialize code buffer with all zeros
    generate_codes(&huffman_tree[total_symbols*2-2], code, 0, codes); // generate codes for symbols
    printf("Symbol\tFrequency\tCode\n");
    for(int i=0; i<total_symbols; i++){
        printf("%c\t%d\t\t%s\n", symbol_freq_table[i].symbol, symbol_freq_table[i].freq, codes[(int)symbol_freq_table[i].symbol]);
    }
    printf("\nCompressed string: ");
    for(int i=0; i<strlen(input_string); i++){ // print compressed string
        printf("%s", codes[(int)input_string[i]]);
    }
    printf("\n");
    return 0;
}