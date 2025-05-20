//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include<stdio.h>
#include<string.h>
#define MAX_CHARS 256

// Function to count frequency of each character in a string
void countFrequency(char str[], int freq[]) {
    int i, j = 0;
    for(i = 0; str[i]!= '\0'; i++) {
        freq[str[i]]++;
    }
    for(i = 0; i < MAX_CHARS; i++) {
        if(freq[i] > 0) {
            freq[i] = j++;
        }
    }
}

// Function to compress the string using frequency table
void compress(char str[], int freq[], char compressed[]) {
    int i, j = 0;
    compressed[j++] = '$';
    for(i = 0; str[i]!= '\0'; i++) {
        compressed[j++] = freq[str[i]];
    }
    compressed[j] = '\0';
}

// Function to decompress the compressed string using frequency table
void decompress(char compressed[], int freq[], char str[]) {
    int i, j, count = 0;
    for(i = 0; compressed[i]!= '\0'; i++) {
        if(compressed[i] == '$') {
            break;
        }
        j = freq[compressed[i]];
        str[count++] = (char)j;
    }
    str[count] = '\0';
}

// Main function to test the above functions
int main() {
    char str[100], compressed[100], decompressed[100];
    int freq[MAX_CHARS] = {0};

    printf("Enter a string to compress: ");
    scanf("%s", str);

    countFrequency(str, freq);
    compress(str, freq, compressed);

    printf("Compressed string: %s\n", compressed);

    decompress(compressed, freq, decompressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}