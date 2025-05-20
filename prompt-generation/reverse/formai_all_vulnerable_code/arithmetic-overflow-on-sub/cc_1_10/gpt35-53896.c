//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>

// This program demonstrates the implementation of "Shannon-Fano code".
// It takes the characters and their frequencies as inputs, and assigns unique binary codes to them.

#define MAX_CHARACTERS 128

typedef struct {
    char character;
    int freq;
    char code[MAX_CHARACTERS];
} node;

node nodes[MAX_CHARACTERS];

int n = 0;

void sort_nodes() {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (nodes[i].freq < nodes[j].freq) {
                node temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

void assign_codes(int start, int end, char code[], int depth) {
    if (start == end) {
        nodes[start].code[depth] = '\0';
        return;
    }
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += nodes[i].freq;
    }
    sum /= 2;
    int temp = start;
    while (sum > 0 && temp < end) {
        sum -= nodes[temp].freq;
        temp++;
    }
    for (int i = start; i < temp; i++) {
        code[depth] = '0';
        assign_codes(start, temp-1, code, depth+1);
    }
    for (int i = temp; i <= end; i++) {
        code[depth] = '1';
        assign_codes(temp, end, code, depth+1);
    }
}

int main() {
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    printf("Enter the characters and their frequencies: \n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &nodes[i].character, &nodes[i].freq);
    }
    sort_nodes();
    char code[MAX_CHARACTERS];
    assign_codes(0, n-1, code, 0);
    printf("Character\tFrequency\tCode\n");
    for (int i = 0; i < n; i++) {
        printf("%c\t\t%d\t\t%s\n", nodes[i].character, nodes[i].freq, nodes[i].code);
    }
    return 0;
}