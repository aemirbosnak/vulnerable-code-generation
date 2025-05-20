//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/**
 * A variable length code compression algorithm using Huffman coding
 * 
 * @param data The data to be compressed
 * @param len The length of the data
 * @return The compressed data
 */ 
unsigned char* huffman_compress(unsigned char *data, unsigned int len) {
    // Initialize frequency count
    unsigned int freq[256] = {0};
    for(unsigned int i = 0; i < len; i++) {
        freq[data[i]]++;
    }
    
    // Create Huffman tree
    unsigned int tree_size = len * 2 - 1;
    unsigned int *tree = (unsigned int*) malloc(tree_size * sizeof(unsigned int));
    unsigned int max_depth = 0;
    for(unsigned int i = 0; i < len; i++){
        tree[i] = i;
    }
    for(unsigned int i = len; i < tree_size; i++){
        unsigned int min1 = len, min2 = len;
        for(unsigned int j = 0; j < i; j++) {
            if(tree[j] == len) continue;
            if(min1 == len || freq[tree[j]] < freq[tree[min1]]) {
                min2 = min1;
                min1 = j;
            }else if(min2 == len || freq[tree[j]] < freq[tree[min2]]) {
                min2 = j;
            }
        }
        tree[i] = len;
        tree[i*2+1] = min1;
        tree[i*2+2] = min2;
        freq[i] = freq[min1] + freq[min2];
        if(min1 < len && min2 < len) {
            max_depth = (max_depth > freq[tree[min1]] ? max_depth : freq[tree[min1]]);
        }
    }
    
    // Create mapping table
    unsigned int **code_table = (unsigned int**) malloc(256 * sizeof(unsigned int*));
    for(unsigned int i = 0; i < 256; i++) {
        code_table[i] = NULL;
    }
    unsigned int *code = (unsigned int*) malloc(max_depth * sizeof(unsigned int));
    code[max_depth-1] = 0;
    for(unsigned int i = len; i < tree_size; i++) {
        if(tree[i] < len) {
            if(code_table[tree[i]] == NULL) {
                code_table[tree[i]] = (unsigned int*) malloc(max_depth * sizeof(unsigned int));
                for(unsigned int j = 0; j < max_depth; j++) {
                    code_table[tree[i]][j] = code[j];
                }
            }
        }else{
            code[max_depth-freq[tree[i]]] = 0;
            unsigned int j = 0;
            while(tree[tree[i]*2+1] >= len) {
                code[max_depth-freq[tree[i]]-j-1] = 1;
                tree[i] = tree[tree[i]*2+1];
                j++;
            }
            code[max_depth-freq[tree[i]]-j-1] = 1;
            tree[i] = tree[tree[i]*2+1];
            code[max_depth-freq[tree[i]]-j-2] = 1;
            for(unsigned int k = max_depth-freq[tree[i]]-j; k < max_depth; k++){
                code_table[tree[i]][k] = code[k];
            }
        }
    }
    
    // Compress data
    unsigned char *compressed_data = (unsigned char*) malloc(2 * len * sizeof(unsigned char));
    unsigned int compressed_size = 0;
    unsigned int bit_count = 0;
    unsigned char temp = 0;
    for(unsigned int i = 0; i < len; i++) {
        unsigned int *code = code_table[data[i]];
        for(unsigned int j = 0; j < max_depth; j++) {
            temp |= code[j] << (7 - bit_count);
            bit_count++;
            if(bit_count >= 8) {
                compressed_data[compressed_size] = temp;
                compressed_size++;
                bit_count = 0;
                temp = 0;
            }
        }
    }
    if(bit_count != 0) {
        compressed_data[compressed_size] = temp;
        compressed_size++;
    }
    
    // Free memory
    free(tree);
    for(unsigned int i = 0; i < 256; i++) {
        free(code_table[i]);
    }
    free(code_table);
    free(code);
    
    return compressed_data;
}

/**
 * A variable length code decompression algorithm using Huffman coding
 * 
 * @param data The compressed data to be decompressed
 * @param len The length of the compressed data
 * @return The decompressed data
 */ 
unsigned char* huffman_decompress(unsigned char *data, unsigned int len) {
    // Determine Huffman tree structure from compressed data
    unsigned int tree_size = len * 4 + 1;
    unsigned int *tree = (unsigned int*) malloc(tree_size * sizeof(unsigned int));
    unsigned int cur = 0;
    unsigned int bit_count = 0;
    unsigned char temp = 0;
    while(cur < tree_size) {
        temp |= (data[0] >> (7 - bit_count)) & 1;
        bit_count++;
        if(bit_count >= 8) {
            data++;
            len--;
            bit_count = 0;
        }
        if(temp >= 2) {
            tree[cur] = temp - 2;
            cur++;
            temp = 0;
        }else{
            temp <<= 1;
        }
    }
    
    // Reconstruct Huffman tree
    unsigned int table_size = 0;
    for(unsigned int i = 0; i < cur; i++){
        if(tree[i] >= table_size) {
            table_size = tree[i]+1;
        }
    }
    unsigned int **code_table = (unsigned int**) malloc(table_size * sizeof(unsigned int*));
    for(unsigned int i = 0; i < table_size; i++) {
        code_table[i] = NULL;
    }
    unsigned int *code = (unsigned int*) malloc(cur * sizeof(unsigned int));
    unsigned int root = cur - 1;
    code[cur-1] = 1;
    for(unsigned int i = cur - 2; i >= 0; i--) {
        if(tree[i] < table_size && code_table[tree[i]] == NULL){
            code_table[tree[i]] = (unsigned int*) malloc(cur * sizeof(unsigned int));
            for(unsigned int j = i; j < cur; j++) {
                code_table[tree[i]][j] = code[j];
            }
        }
        if(tree[i] == root) {
            root = i;
            for(unsigned int j = i; j < cur; j++){
                code[j] = 0;
            }
        }
        code[i] = code[i+1] + 1;
    }
    
    // Decompress data
    unsigned char *decompressed_data = (unsigned char*) malloc(tree[root] * sizeof(unsigned char));
    unsigned int decompressed_size = 0;
    cur = root;
    bit_count = 0;
    temp = 0;
    while(decompressed_size < tree[root]) {
        temp |= (data[0] >> (7 - bit_count)) & 1;
        bit_count++;
        if(bit_count >= 8) {
            data++;
            len--;
            bit_count = 0;
        }
        cur = (temp == 0 ? tree[cur*2+1] : tree[cur*2+2]);
        temp = 0;
        if(cur < table_size) {
            decompressed_data[decompressed_size] = cur;
            decompressed_size++;
            cur = root;
        }
    }
    
    // Free memory
    free(tree);
    for(unsigned int i = 0; i < table_size; i++) {
        free(code_table[i]);
    }
    free(code_table);
    free(code);
    
    return decompressed_data;
}

int main() {
    // Test data
    unsigned char testData[100] = {0};
    for(unsigned int i = 0; i < 100; i += 4) {
        testData[i] = 'A';
        testData[i+1] = 'B';
        testData[i+2] = 'C';
        testData[i+3] = 'D';
    }
    
    // Compress data
    unsigned char *compressed_data = huffman_compress(testData, 100);
    printf("Compressed size: %d\n", sizeof(compressed_data));
    
    // Decompress data
    unsigned char *decompressed_data = huffman_decompress(compressed_data, sizeof(compressed_data));
    printf("Decompressed size: %d\n", sizeof(decompressed_data));
    
    // Compare original and decompressed data
    for(unsigned int i = 0; i < 100; i++) {
        if(testData[i] != decompressed_data[i]) {
            printf("ERROR: Data mismatch at index %d\n", i);
            break;
        }
    }
    
    // Free memory
    free(compressed_data);
    free(decompressed_data);
    
    return 0;
}