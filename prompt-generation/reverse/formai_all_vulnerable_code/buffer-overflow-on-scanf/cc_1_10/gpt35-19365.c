//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define the maximum length of the input string
#define MAX_LENGTH 1000

// define a structure to store the compressed string
struct pair {
    char character;
    int count;
};

// function prototypes
char* compress_string(char* str);
void print_compressed_string(struct pair* p, int len);
void copy_string(char* str1, char* str2);

int main() {
    // declare variables
    char str[MAX_LENGTH];
    char* compressed_str;
    
    // get the input string from the user
    printf("Enter the input string (maximum length %d): ", MAX_LENGTH);
    scanf("%[^\n]", str);
    
    // call the compression function to compress the string
    compressed_str = compress_string(str);
    
    // print the compressed string
    printf("\nThe compressed string is:\n%s\n", compressed_str);
    
    // free the memory allocated to the compressed string
    free(compressed_str);
    
    return 0;
}

char* compress_string(char* str) {
    // declare variables
    int len = strlen(str);
    struct pair* compressed_str = (struct pair*) malloc(len * sizeof(struct pair));
    int i, j, count;
    
    // initialize variables
    i = j = count = 0;
    compressed_str[j].character = str[i];
    compressed_str[j].count = 1;
    i++;
    
    // loop through the input string
    while(i < len) {
        // if the current character is same as previous character
        if(str[i] == compressed_str[j].character) {
            // increment the count of the previous character
            compressed_str[j].count++;
        }
        else {
            // add a new pair for the new character
            j++;
            compressed_str[j].character = str[i];
            compressed_str[j].count = 1;
        }
        i++;
    }
    
    // add a null character to the end of the compressed string
    j++;
    compressed_str[j].character = '\0';
    
    // print the compressed string
    print_compressed_string(compressed_str, j);
    
    // allocate memory for compressed string
    char* str_comp = (char*) malloc((2*j+1) * sizeof(char));
    
    // copy compressed string to new string
    for(i = 0; i < j; i++) {
        count = sprintf(str_comp+strlen(str_comp),"%c%d",compressed_str[i].character,compressed_str[i].count);
    }
    
    // free memory allocated to the compressed string
    free(compressed_str);
    
    // return the compressed string
    return str_comp;
}

void print_compressed_string(struct pair* p, int len) {
    // declare variables
    int i;
    
    // print the compressed string
    printf("\nThe compressed string is:\n");
    for(i = 0; i < len; i++) {
        printf("%c%d", p[i].character, p[i].count);
    }
}

void copy_string(char* str1, char* str2) {
    // loop through the string and copy characters
    int i = 0;
    while(str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    
    // add a null character to the end of the string
    str1[i] = '\0';
}