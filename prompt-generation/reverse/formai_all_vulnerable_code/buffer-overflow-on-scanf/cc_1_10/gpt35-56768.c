//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 65536   // Maximum size of the dictionary

typedef unsigned char byte;   // Define byte as unsigned char

// Dictionary structure
typedef struct Dict{
    byte *data;              // Pointer to dictionary data
    int size;                // Size of the dictionary
    int used;                // Used space in the dictionary
} Dict;

// Add a string to the dictionary
void dict_add(Dict *dict, byte *str, int len){
    // Check if there is enough space in the dictionary
    if (dict->used + len + 1 > dict->size){
        dict->size = dict->size * 2;    // Double the size of the dictionary
        dict->data = realloc(dict->data, dict->size);
    }
    // Copy the string to the dictionary and add a null terminator
    memcpy(dict->data + dict->used, str, len);
    dict->data[dict->used + len] = '\0';
    dict->used += len + 1;              // Update used space
}

// Compress a string using LZW compression algorithm
void lzw_compress(char *input, Dict *dict){
    int len = strlen(input);
    byte *buf = malloc(len);
    int i, j, k;
    int code;
    char *str, *prev;
    for (i = 0; i < len; i++){
        buf[i] = (byte)input[i];        // Convert input to bytes
    }
    str = prev = malloc(1);
    for (i = 0; i < len; i++){
        str = malloc(1);
        str[0] = buf[i];
        for (j = 0; j < dict->used; j += k){
            k = strlen((char*)dict->data + j) + 1;
            if (strncmp((char*)dict->data + j, str, k - 1) == 0){
                code = j / k;           // Get dictionary code for the string
                break;
            }
        }
        if (j >= dict->used){
            dict_add(dict, (byte*)str, 1);
            str = prev;
            code = (int)prev[0];
        }
        printf("%d ", code);            // Output dictionary code
        prev = str;
    }
    free(str);
    free(prev);
    free(buf);
}

// Main function
int main(){
    char input[1024];
    Dict dict;
    dict.data = malloc(MAX_DICT_SIZE);
    dict.size = MAX_DICT_SIZE;
    dict.used = 0;
    printf("Enter a string to compress:\n");
    scanf("%[^\n]", input);
    getchar();
    printf("Compressed string:\n");
    lzw_compress(input, &dict);
    printf("\nDictionary:\n");
    fwrite(dict.data, 1, dict.used, stdout);  // Output dictionary contents
    printf("\n");
    free(dict.data);
    return 0;
}