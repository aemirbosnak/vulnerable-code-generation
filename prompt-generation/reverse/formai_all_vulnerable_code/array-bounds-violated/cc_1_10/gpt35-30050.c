//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct huffman_node{
    char data;
    int freq;
    struct huffman_node *left, *right;
};

struct huffman_node* create_node(char data, int freq) {
    struct huffman_node* node = (struct huffman_node*) malloc(sizeof(struct huffman_node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void encode(struct huffman_node* root, char str[], int top) {
    if (root->left) {
        str[top] = '0';
        encode(root->left, str, top + 1);
    }
    if (root->right) {
        str[top] = '1';
        encode(root->right, str, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c - %s\n", root->data, str);
    }
}

void huffman(struct huffman_node* root, char str[]){
    if (!root)
        return;
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, str);
    }
    huffman(root->left, strcat(str, "0"));
    str[strlen(str) - 1] = '\0';
    huffman(root->right, strcat(str, "1"));
    str[strlen(str) - 1] = '\0';
}

int main() {
    char sentence[100];
    int i=0, j=0, k=0;
    printf("Enter a sentence: ");
    fgets(sentence,sizeof(sentence),stdin);
    int freq[128] = {0};
    while (sentence[i]) {
        freq[sentence[i]]++;
        i++;
    }
    struct huffman_node *nodes[i];
    for (i = 0; i < 128; i++) {
        if (freq[i] != 0) {
            nodes[j] = create_node(i, freq[i]);
            j++;
        }
    }
    while (j > 1) {
        int lowest_freq1 = 1000000, lowest_freq2 = 1000000;
        int lowest_index1 = -1, lowest_index2 = -1;
        for (i = 0; i < j; i++) {
            if (nodes[i]->freq < lowest_freq1) {
                lowest_index2 = lowest_index1;
                lowest_freq2 = lowest_freq1;
                lowest_index1 = i;
                lowest_freq1 = nodes[i]->freq;
            } else if (nodes[i]->freq < lowest_freq2) {
                lowest_index2 = i;
                lowest_freq2 = nodes[i]->freq;
            }
        }
        struct huffman_node *new_node = create_node('$', nodes[lowest_index1]->freq + nodes[lowest_index2]->freq);
        new_node->left = nodes[lowest_index1];
        new_node->right = nodes[lowest_index2];
        nodes[lowest_index2] = new_node;
        nodes[lowest_index1] = NULL;
        j--;
    }
    char str[10];
    printf("The Huffman code for each character is:\n");
    encode(nodes[0], str, 0);
    printf("\nThe Huffman code for the whole sentence is:\n");
    huffman(nodes[0],str);
    return 0;
}