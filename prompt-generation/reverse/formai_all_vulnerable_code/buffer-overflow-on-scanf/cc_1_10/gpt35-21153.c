//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

// Structure definition for compression dictionary
struct Dictionary {
    char c;
    int code;
};

// This function searches for a character in the dictionary
// and returns its corresponding code if found, else returns -1
int search_dict(struct Dictionary dict[], char c, int n) {
    for(int i=0; i<n; ++i) {
        if(dict[i].c == c) {
            return dict[i].code;
        }
    }
    return -1;
}

// This function adds a new entry to the compression dictionary
int add_dict(struct Dictionary dict[], char c, int code, int n) {
    dict[n].c = c;
    dict[n].code = code;
    return n+1;
}

// This function compresses the input string using LZW compression algorithm
void compress(char input[], int input_len) {
    struct Dictionary dict[MAX_SIZE];
    int i = 0, j = 0, k = 1, n = 0, code = 0, prev_code = 0;
    char buffer[MAX_SIZE], c;
    memset(dict, 0, sizeof(dict));
    memset(buffer, 0, sizeof(buffer));

    // Initialize the dictionary with all single characters
    for(i=0; i<256; ++i) {
        dict[i].c = i;
        dict[i].code = i;
    }

    // Main compression loop
    for(i=0; i<input_len; ++i) {
        c = input[i];
        code = search_dict(dict, c, n);
        if(code != -1) {
            prev_code = code;
            buffer[j++] = c;
        }
        else {
            printf("%d ", prev_code);
            n = add_dict(dict, c, k++, n);
            memset(buffer, 0, sizeof(buffer));
            strcpy(buffer, &c);
            j = 1;
            prev_code = search_dict(dict, c, n);
        }
    }
    printf("%d\n", prev_code);
}

// Driver function
int main() {
    char input[MAX_SIZE];
    printf("Enter the string to compress: ");
    scanf("%[^\n]s", input);
    int input_len = strlen(input);
    printf("Compressed codes: ");
    compress(input, input_len);
    return 0;
}