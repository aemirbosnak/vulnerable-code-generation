//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODES 4096

typedef struct {
    char ch;
    int freq;
    int code;
} node;

void calcFreq(char text[], int n, int freq[]) {
    int i;
    for(i=0; i<n; i++) {
        freq[text[i]]++;
    }
}

void buildTree(node arr[], int n) {
    int i, j;
    node temp[n];

    for(i=0; i<n; i++) {
        temp[i].ch = arr[i].ch;
        temp[i].freq = arr[i].freq;
        temp[i].code = 0;
    }

    for(i=n-1; i>=0; i--) {
        for(j=i-1; j>=0; j--) {
            if(temp[j].freq < temp[i].freq) {
                node temp1 = temp[i];
                temp[i] = temp[j];
                temp[j] = temp1;
            }
        }
    }

    int code[MAX_CHARS] = {0};
    int codeSize = 0;

    for(i=0; i<n; i++) {
        code[temp[i].ch] = codeSize;
        codeSize++;
    }

    for(i=0; i<n; i++) {
        arr[i].code = code[temp[i].ch];
    }
}

void encode(char text[], int n, node arr[]) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c -> %d\n", text[i], arr[i].code);
    }
}

void decode(char text[], int n, node arr[]) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d -> %c\n", arr[i].code, text[i]);
    }
}

int main() {
    char text[1000];
    int n = 0;
    int freq[MAX_CHARS] = {0};
    node arr[MAX_CHARS];

    printf("Enter the text to compress:\n");
    scanf("%[^\n]", text);
    n = strlen(text);

    calcFreq(text, n, freq);

    printf("Character\tFrequency\n");
    for(int i=0; i<MAX_CHARS; i++) {
        if(freq[i] > 0) {
            printf("%c\t%d\n", i, freq[i]);
        }
    }

    buildTree(arr, n);

    printf("\nHuffman Codes:\n");
    encode(text, n, arr);

    printf("\n\nDecoded Text:\n");
    decode(text, n, arr);

    return 0;
}