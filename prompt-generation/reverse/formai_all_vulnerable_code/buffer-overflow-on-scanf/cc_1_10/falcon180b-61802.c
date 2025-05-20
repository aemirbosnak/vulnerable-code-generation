//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to compress the given string using Run Length Encoding
void runLengthEncoding(char str[], int len, char output[]) {
    int i, j, k;
    char temp[10];
    output[0] = '\0';
    for(i = 0; i < len; i++) {
        if(i == 0 || str[i]!= str[i-1]) {
            sprintf(temp, "%c%d", str[i], 1);
            strcat(output, temp);
        }
        else {
            k = 1;
            while(i+k < len && str[i] == str[i+k]) {
                k++;
            }
            sprintf(temp, "%c%d", str[i], k);
            strcat(output, temp);
            i += k-1;
        }
    }
}

// Function to decompress the compressed string back to its original form
void decompress(char input[], int len, char output[]) {
    int i, j, k;
    char temp[10];
    output[0] = '\0';
    for(i = 0; i < len; i += strlen(temp)) {
        strcpy(temp, input+i);
        if(temp[0]!= '\0') {
            if(temp[1] == '1') {
                strcat(output, temp[0]);
            }
            else {
                int count = atoi(temp+1);
                for(j = 0; j < count; j++) {
                    strcat(output, temp[0]);
                }
            }
        }
    }
}

int main() {
    char input[1000], output[1000];
    int len;

    printf("Enter the string to compress: ");
    scanf("%s", input);
    len = strlen(input);

    // Compress the input string
    runLengthEncoding(input, len, output);
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, strlen(output), input);
    printf("Decompressed string: %s\n", input);

    return 0;
}