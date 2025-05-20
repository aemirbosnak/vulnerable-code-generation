//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_CODE_LEN 16

struct Node {
    int freq;
    int code;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int freq, int code) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->freq = freq;
    new_node->code = code;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node* build_tree(int freq[], int num_chars) {
    struct Node* root = create_node(0, 0);
    struct Node* curr_node = root;
    int curr_code = 0;
    int i;

    for (i = 0; i < num_chars; i++) {
        curr_node->freq = freq[i];
        curr_node->code = curr_code;
        curr_code++;
        curr_node->left = NULL;
        curr_node->right = NULL;

        int j;
        for (j = i - 1; j >= 0 && freq[j] > curr_node->freq; j--) {
            curr_node = curr_node->left;
        }

        curr_node = curr_node->right;
    }

    return root;
}

void print_tree(struct Node* root, char code[], int curr_code) {
    if (root == NULL) {
        code[curr_code] = '\0';
        printf("%s %d\n", code, curr_code);
        return;
    }

    curr_code++;
    code[curr_code] = '0';
    print_tree(root->left, code, curr_code);

    curr_code++;
    code[curr_code] = '1';
    print_tree(root->right, code, curr_code);
}

void create_huffman_code(int freq[], int num_chars) {
    struct Node* root = build_tree(freq, num_chars);
    char code[MAX_CODE_LEN];
    int curr_code = 0;

    print_tree(root, code, curr_code);
}

int main() {
    int freq[MAX_CHAR] = {0};
    int num_chars = 0;
    char input_string[MAX_CHAR];

    printf("Enter input string: ");
    scanf("%s", input_string);

    int i;
    for (i = 0; input_string[i]!= '\0'; i++) {
        freq[input_string[i]]++;
        num_chars++;
    }

    create_huffman_code(freq, num_chars);

    return 0;
}