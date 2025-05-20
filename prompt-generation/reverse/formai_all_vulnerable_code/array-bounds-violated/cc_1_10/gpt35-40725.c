//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define MAX_LEN 100000

char compressed[MAX_LEN];

int compress(char* input, int len){
    int freq[26] = {0};
    int i, j=0, index;

    for(i=0; i<len; i++){
        freq[input[i]-'a']++;
    }

    for(i=0; i<len; i++){
        index = input[i]-'a';

        if(freq[index]>0){
            compressed[j++] = input[i];
            compressed[j++] = freq[index] + '0';
            freq[index] = 0;
        }
    }

    compressed[j] = '\0';

    return j;
}

int decompress(char* input, int len){
    int i, j, val, k=0;

    for(i=0; i<len; i++){
        if(input[i]>='a' && input[i]<='z'){
            compressed[k++] = input[i];
        }else{
            j = i+1;
            val = 0;
            while(input[j]>='0' && input[j]<='9'){
                val = val*10 + (input[j] - '0');
                j++;
            }

            for(int l=0; l<val; l++){
                compressed[k++] = input[i-1];
            }
            i=j-1;
        }
    }

    compressed[k] = '\0';

    return k;
}

int main(){
    char input[MAX_LEN], option[MAX_LEN];
    int len, comp_len, decomp_len;

    printf("Enter the data to compress: ");
    fgets(input, MAX_LEN, stdin);

    len = strlen(input);
    input[len-1] = '\0';
    len--;

    while(1){
        printf("\nSelect the option:\n1. Compress\n2. Decompress\n3. Exit\n");
        fgets(option, MAX_LEN, stdin);
        option[strlen(option)-1] = '\0';

        if(strcmp(option, "1")==0){
            comp_len = compress(input, len);
            printf("\nCompressed Data: %s\n", compressed);
        }else if(strcmp(option, "2")==0){
            decomp_len = decompress(compressed, comp_len);
            printf("\nDecompressed Data: %s\n", compressed);
        }else{
            break;
        }
    }

    return 0;
}