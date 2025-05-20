//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000000 //maximum length of input string
#define MAX_NUM 100000000 //maximum number used in encoding
#define CODE_SIZE 32 //size of encoding code

typedef struct freq_table {
    char symbol;
    int frequency;
    struct freq_table *left, *right;
} freq_table;

typedef struct heap {
    int size;
    freq_table **table;
} heap;

typedef struct code_table {
    char symbol;
    char code[CODE_SIZE];
} code_table;

int freq[256] = {}; //initialize frequency table to 0

void print_code_table(code_table *table) {
    printf("Symbol\tCode\n");
    for(int i=0; i<256; i++) {
        if(table[i].symbol != '\0') {
            printf("%c\t%s\n", table[i].symbol, table[i].code);
        }
    }
}

int cmp_freq_table(const void *a, const void *b) {
    freq_table *fa = *(freq_table**)a;
    freq_table *fb = *(freq_table**)b;

    if(fa->frequency < fb->frequency) {
        return -1;
    } else if (fa->frequency > fb->frequency) {
        return 1;
    } else {
        return 0;
    }
}

heap* create_heap() {
    heap *min_heap = malloc(sizeof(heap));
    min_heap->size = 0;
    min_heap->table = malloc(MAX_LEN*sizeof(freq_table*));

    return min_heap;
}

void insert_heap(heap *min_heap, freq_table *node) {
    min_heap->size++;
    int i = min_heap->size-1;

    while(i > 0 && min_heap->table[(i-1)/2]->frequency > node->frequency) {
        min_heap->table[i] = min_heap->table[(i-1)/2];
        i = (i-1)/2;
    }

    min_heap->table[i] = node;
}

freq_table* remove_heap(heap *min_heap) {
    freq_table *node = min_heap->table[0];
    min_heap->table[0] = min_heap->table[min_heap->size-1];
    min_heap->size--;

    int i = 0;
    while(2*i+1 < min_heap->size) {
        int j = (2*i+2 < min_heap->size && min_heap->table[2*i+2]->frequency < min_heap->table[2*i+1]->frequency) ? 2*i+2 : 2*i+1;

        if(min_heap->table[i]->frequency > min_heap->table[j]->frequency) {
            freq_table *temp = min_heap->table[i];
            min_heap->table[i] = min_heap->table[j];
            min_heap->table[j] = temp;
            i = j;
        } else {
            break;
        }
    }

    return node;
}

freq_table* build_huffman_tree() {
    heap *min_heap = create_heap();

    for(int i=0; i<256; i++) {
        if(freq[i] > 0) {
            freq_table *temp = malloc(sizeof(freq_table));
            temp->symbol = (char)i;
            temp->frequency = freq[i];
            temp->left = temp->right = NULL;
            insert_heap(min_heap, temp);
        }
    }

    while(min_heap->size > 1) {
        freq_table *left_child = remove_heap(min_heap);
        freq_table *right_child = remove_heap(min_heap);

        freq_table *parent = malloc(sizeof(freq_table));
        parent->symbol = '\0';
        parent->frequency = left_child->frequency + right_child->frequency;
        parent->left = left_child;
        parent->right = right_child;

        insert_heap(min_heap, parent);
    }

    return remove_heap(min_heap);
}

void create_code_table(freq_table *node, code_table *table, char buffer[], int depth) {
    if(node->left != NULL) {
        buffer[depth] = '0';
        create_code_table(node->left, table, buffer, depth+1);
    }

    if(node->right != NULL) {
        buffer[depth] = '1';
        create_code_table(node->right, table, buffer, depth+1);
    }

    if(node->left == NULL && node->right == NULL) {
        for(int i=0; i<depth; i++) {
            table[(int)node->symbol].code[i] = buffer[i];
        }
        table[(int)node->symbol].symbol = node->symbol;
    }
}

void huffman_encoding(char *input_str, char *output_file) {
    FILE *out_file = fopen(output_file, "wb");
    
    int length = strlen(input_str);
    for(int i=0; i<length; i++) {
        freq[(int)input_str[i]]++;
    }

    freq_table *root = build_huffman_tree();
    code_table *table = malloc(256*sizeof(code_table));
    memset(table, 0, 256*sizeof(code_table));

    char buffer[CODE_SIZE];
    memset(buffer, '\0', CODE_SIZE);

    create_code_table(root, table, buffer, 0);

    fwrite(freq, sizeof(freq), 1, out_file); // encode the frequency table into file

    int cur_bit = 0;
    unsigned char byte = 0;
    for(int i=0; i<length; i++) {
        int code_len = strlen(table[(int)input_str[i]].code);
        for(int j=0; j<code_len; j++) {
            byte <<= 1;
            if(table[(int)input_str[i]].code[j] == '1') {
                byte |= 1;
            }

            cur_bit++;
            if(cur_bit == 8) {
                fwrite(&byte, 1, 1, out_file);
                byte = 0;
                cur_bit = 0;
            }
        }
    }

    if(cur_bit > 0) {
        byte <<= (8 - cur_bit);
        fwrite(&byte, 1, 1, out_file);
    }

    printf("Encoding successful! File saved as %s\n", output_file);
    print_code_table(table);

    fclose(out_file);
}

char* huffman_decoding(char *input_file) {
    FILE *in_file = fopen(input_file, "rb");

    fread(freq, sizeof(freq), 1, in_file);

    freq_table *root = build_huffman_tree();
    code_table *table = malloc(256*sizeof(code_table));
    memset(table, 0, 256*sizeof(code_table));

    char buffer[CODE_SIZE];
    memset(buffer, '\0', CODE_SIZE);

    create_code_table(root, table, buffer, 0);

    freq_table *cur_node = root;
    int cur_bit = 0;
    unsigned char byte;

    fseek(in_file, sizeof(freq), SEEK_SET); // skip the frequency table while reading

    char *output_str = malloc((MAX_LEN+1)*sizeof(char));
    memset(output_str, '\0', (MAX_LEN+1)*sizeof(char));
    int output_index = 0;
    int end_of_file = 0;

    while(!end_of_file) {
        fread(&byte, 1, 1, in_file);
        for(int i=0; i<8; i++) {
            cur_node = (byte & 0x80) ? cur_node->right : cur_node->left;
            byte <<= 1;
            cur_bit++;

            if(cur_node->left == NULL && cur_node->right == NULL) {
                output_str[output_index++] = cur_node->symbol;
                if(output_index > MAX_LEN) {
                    end_of_file = 1;
                    break;
                }
                cur_node = root;
            }
        }
    }

    fclose(in_file);

    printf("Decoding successful!\n");
    return output_str;
}

int main() {
    char input_str[MAX_LEN];
    printf("Enter input string: ");
    fgets(input_str, MAX_LEN, stdin);
    input_str[strlen(input_str)-1] = '\0'; // remove trailing newline character

    huffman_encoding(input_str, "encoded"); // encode the input string into file "encoded"

    char *output_str = huffman_decoding("encoded"); // decode the file "encoded"
    printf("Decoded string: %s\n", output_str);

    return 0;
}