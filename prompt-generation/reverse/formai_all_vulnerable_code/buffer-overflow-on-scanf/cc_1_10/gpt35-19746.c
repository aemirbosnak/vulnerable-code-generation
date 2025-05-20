//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include<stdio.h>
#include<string.h>
#define MAX 100

int main() {
    char str[MAX], compressed[MAX], decompressed[MAX];
    int i, j, k, freq[MAX], length, compLength = 0;

    //input
    printf("Enter the string to be compressed: ");
    scanf("%s", str);

    length = strlen(str);

    //initiating freq array
    for(i = 0; i < length; i++)
        freq[i] = -1;

    //counting frequency of characters 
    //and storing it in freq array
    for(i = 0; i < length; i++) {
        k = 1;
        for(j = i+1; j < length; j++) {
            if(str[i] == str[j]) {
                k++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
            freq[i] = k;
    }

    //creating compressed string
    for(i = 0; i < length; i++) {
        if(freq[i] != 0) {
            compressed[compLength++] = str[i];
            compressed[compLength++] = freq[i] + '0';
        }
    }
    compressed[compLength] = '\0';

    //printing compressed string
    printf("Compressed string: %s\n", compressed);

    //decompressing string
    k = 0;
    for(i = 0; i < compLength; i+=2) {
        for(j = 0; j < compressed[i+1]-'0'; j++) {
            decompressed[k++] = compressed[i];
        }
    }
    decompressed[k] = '\0';

    //printing decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}