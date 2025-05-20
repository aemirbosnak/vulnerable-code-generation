//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOL 256
#define MAX_HEAP_SIZE 65536

// Huffman coding functions
void build_tree(int *freq, int n, int *heap_size, int *heap_list);
void huffman_code(int *freq, int n, int *heap_size, int *heap_list, char *output);

// Huffman coding implementation
int main() {
    char input[100], output[100];
    int freq[MAX_SYMBOL], heap_size[MAX_HEAP_SIZE], heap_list[MAX_HEAP_SIZE];

    // Read input from user
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);

    // Count frequency of each symbol in the input
    int n = strlen(input);
    for (int i = 0; i < n; i++) {
        freq[input[i]]++;
    }

    // Build the Huffman tree
    build_tree(freq, n, heap_size, heap_list);

    // Output the Huffman code
    huffman_code(freq, n, heap_size, heap_list, output);

    // Display the input and output
    printf("Input:\n");
    printf("%s\n", input);
    printf("Output:\n");
    printf("%s\n", output);

    return 0;
}

// Build the Huffman tree
void build_tree(int *freq, int n, int *heap_size, int *heap_list) {
    int i, j, k, l, min_index;

    // Create a min-heap from the frequency array
    for (i = n - 1; i >= 0; i--) {
        heap_size[i] = freq[i];
        heap_list[i] = i;
        min_index = i;
        for (j = i - 1; j >= 0; j--) {
            if (freq[j] < freq[min_index]) {
                min_index = j;
            }
        }
        if (min_index!= i) {
            k = heap_list[i];
            l = heap_list[min_index];
            heap_size[i] += heap_size[min_index];
            heap_list[i] = l;
            heap_list[min_index] = k;
            heap_size[min_index] = heap_size[k];
        }
    }

    // Create the Huffman tree
    for (i = 0; i < n - 1; i++) {
        k = heap_list[i];
        l = heap_list[i + 1];
        heap_size[i] += heap_size[i + 1];
        heap_list[i] = l;
        heap_list[i + 1] = k;
        heap_size[i + 1] = heap_size[k];
    }
}

// Output the Huffman code
void huffman_code(int *freq, int n, int *heap_size, int *heap_list, char *output) {
    int i, j, k, l, c;

    // Initialize the output string
    for (i = 0; i < n; i++) {
        output[i] = '\0';
    }

    // Output the Huffman code
    for (i = 0; i < n; i++) {
        k = heap_list[i];
        l = heap_list[i + 1];
        if (k == l) {
            c = k;
            for (j = 0; j < heap_size[k]; j++) {
                output[i] = c;
            }
            i++;
        } else {
            c = '0';
            for (j = 0; j < heap_size[k]; j++) {
                c = '0' + c;
                output[i] = c;
            }
            output[i] = '1';
            i++;
            for (j = 0; j < heap_size[l]; j++) {
                output[i] = '1' + output[i];
            }
            i++;
        }
    }
}